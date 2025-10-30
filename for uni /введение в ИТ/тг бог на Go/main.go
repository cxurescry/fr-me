package main

import (
	"bufio"
	"fmt"
	"log"
	"math/rand"
	"os"
	"path/filepath"
	"strings"
	"time"

	tgbotapi "github.com/go-telegram-bot-api/telegram-bot-api/v5"
)

func main() {
	rand.Seed(time.Now().UnixNano())

	// -----------------------------
	// Настройки: токен и папки
	// -----------------------------
	token := "7221783273:AAFaxIJH7u7NleHqgHOQ2lhC767KIkkt0_k"
	memesDir := "memes"
	jokesDir := "jokes"

	// -----------------------------
	// Создаем бота
	// -----------------------------
	bot, err := tgbotapi.NewBotAPI(token)
	if err != nil {
		log.Fatalf("Failed to create bot: %v", err)
	}
	bot.Debug = false
	log.Printf("Authorized on account %s", bot.Self.UserName)

	// -----------------------------
	// Устанавливаем список команд (всплывающее меню "/")
	// -----------------------------
	commands := []tgbotapi.BotCommand{
		{Command: "help", Description: "Показать справку и список тем"},
		{Command: "cats", Description: "Показать мем с котом 🐱"},
		{Command: "work", Description: "Показать рабочий мем 💼"},
		{Command: "food", Description: "Показать мем про еду 🍔"},
		{Command: "joke", Description: "Рассказать случайную шутку 😂"},
	}

	if _, err := bot.Request(tgbotapi.NewSetMyCommands(commands...)); err != nil {
		log.Printf("Не удалось установить команды: %v", err)
	} else {
		log.Println("Меню команд Telegram успешно установлено")
	}

	// -----------------------------
	// Настройка тем и ключевых слов
	// -----------------------------
	themes := map[string][]string{}
	themeKeywords := map[string][]string{
		"cats": {"кот", "котик", "котяра", "коты", "мемасики про котов", "мем про котиков"},
		"work": {"работ", "работа", "job", "рабоч"},
		"food": {"еда", "поесть", "кушать", "food"},
	}

	for theme := range themeKeywords {
		p := filepath.Join(memesDir, theme)
		files := gatherFiles(p)
		themes[theme] = files
	}

	// -----------------------------
	// Получаем обновления
	// -----------------------------
	u := tgbotapi.NewUpdate(0)
	u.Timeout = 60
	updates := bot.GetUpdatesChan(u)

	for update := range updates {
		if update.Message == nil {
			continue
		}

		lower := strings.ToLower(strings.TrimSpace(update.Message.Text))
		if lower == "" {
			continue
		}

		// --------------------------------------
		// Обработка системных команд Telegram "/"
		// --------------------------------------
		switch lower {
		case "/start", "/help":
			name := update.Message.From.FirstName
			if name == "" {
				name = update.Message.From.UserName
			}
			msg := fmt.Sprintf("Привет, %s! 👋\n\nЭтот бот показывает мемы по ключевым словам или командам:\n\n"+
				"/cats — котики\n/work — работа\n/food — еда\n/joke — шутка\n\n"+
				"Также можно просто написать слова: кот, работа, еда или шутка.", name)
			bot.Send(tgbotapi.NewMessage(update.Message.Chat.ID, msg))
			continue

		case "/cats":
			sendRandomMeme(bot, update.Message.Chat.ID, "cats", themes)
			continue

		case "/work":
			sendRandomMeme(bot, update.Message.Chat.ID, "work", themes)
			continue

		case "/food":
			sendRandomMeme(bot, update.Message.Chat.ID, "food", themes)
			continue

		case "/joke":
			j, err := randomJoke(jokesDir)
			if err != nil {
				bot.Send(tgbotapi.NewMessage(update.Message.Chat.ID, "Не удалось найти шутку."))
			} else {
				bot.Send(tgbotapi.NewMessage(update.Message.Chat.ID, j))
			}
			continue
		}

		// --------------------------------------
		// Поддержка обычных текстовых сообщений
		// --------------------------------------
		if strings.Contains(lower, "шутк") || strings.Contains(lower, "прикол") {
			j, err := randomJoke(jokesDir)
			if err != nil {
				bot.Send(tgbotapi.NewMessage(update.Message.Chat.ID, "Не удалось найти шутку."))
			} else {
				bot.Send(tgbotapi.NewMessage(update.Message.Chat.ID, j))
			}
			continue
		}

		// Мемы по ключевым словам
		matchedTheme := ""
		for theme, kws := range themeKeywords {
			for _, kw := range kws {
				if strings.Contains(lower, kw) {
					matchedTheme = theme
					break
				}
			}
			if matchedTheme != "" {
				break
			}
		}

		if matchedTheme == "" {
			bot.Send(tgbotapi.NewMessage(update.Message.Chat.ID,
				"Не понял запрос. Попробуйте /help или слова: кот, работа, еда."))
			continue
		}

		sendRandomMeme(bot, update.Message.Chat.ID, matchedTheme, themes)
	}
}

// -----------------------------
// Функции
// -----------------------------

func sendRandomMeme(bot *tgbotapi.BotAPI, chatID int64, theme string, themes map[string][]string) {
	files := themes[theme]
	if len(files) == 0 {
		bot.Send(tgbotapi.NewMessage(chatID, fmt.Sprintf("Нет изображений в теме '%s'.", theme)))
		return
	}

	// Выбираем случайное изображение
	choice := files[rand.Intn(len(files))]

	// Определяем подпись по теме
	var caption string
	switch theme {
	case "cats":
		caption = "рандомные котятки"
	case "work":
		caption = "заряд на работу"
	case "food":
		caption = "твоё блюдо сегодня"
	default:
		caption = fmt.Sprintf("Мем из темы '%s'", theme)
	}

	// Отправляем фото с подписью
	photo := tgbotapi.NewPhoto(chatID, tgbotapi.FilePath(choice))
	photo.Caption = caption
	if _, err := bot.Send(photo); err != nil {
		log.Printf("Не удалось отправить мем '%s': %v", choice, err)
		bot.Send(tgbotapi.NewMessage(chatID, "Не удалось отправить изображение."))
	}
}

func gatherFiles(dir string) []string {
	var res []string
	_ = filepath.Walk(dir, func(path string, info os.FileInfo, err error) error {
		if err != nil || info.IsDir() {
			return nil
		}
		ext := strings.ToLower(filepath.Ext(path))
		if ext == ".jpg" || ext == ".jpeg" || ext == ".png" || ext == ".gif" || ext == ".webp" {
			res = append(res, path)
		}
		return nil
	})
	return res
}

func randomJoke(dir string) (string, error) {
	entries, err := os.ReadDir(dir)
	if err != nil {
		return "", err
	}
	var files []string
	for _, e := range entries {
		if e.IsDir() {
			continue
		}
		if strings.ToLower(filepath.Ext(e.Name())) == ".txt" {
			files = append(files, filepath.Join(dir, e.Name()))
		}
	}
	if len(files) == 0 {
		return "", fmt.Errorf("no jokes")
	}
	choice := files[rand.Intn(len(files))]
	f, err := os.Open(choice)
	if err != nil {
		return "", err
	}
	defer f.Close()

	var sb strings.Builder
	scanner := bufio.NewScanner(f)
	for scanner.Scan() {
		sb.WriteString(scanner.Text())
		sb.WriteString("\n")
	}
	return sb.String(), nil
}
