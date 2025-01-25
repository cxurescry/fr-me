package main
import "fmt"

// пример стандартной функции
func odd() int { 
    count := 0 // объявление переменной
    // реализация цикла for и условного оператора
    for i := 0; i < 1000; i++ { 
        if i % 2 != 0 {
            count++
        }
    }
    return count
}

// пример бесконечного цикла
func example() {
   for {
       fmt.Println(odd())
   } 
}

// функция, которая возвращает несколько значений
func example2(x1 string, x2 string) (string, string) {
    return x1 + x2, x2 + x1
}

func main() {
    // анонимная функция
    learn := func(y1 string) {
        fmt.Println("пример анонимной функции")
    }
    fmt.Println(odd())
}
