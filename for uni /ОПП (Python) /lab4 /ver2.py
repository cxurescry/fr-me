import matplotlib
matplotlib.use('TkAgg')

import matplotlib.pyplot as plt
import matplotlib.cbook as cbook
import numpy as np
import os

# Установка общих параметров для всего рисунка в соответствии с вариантом 3
plt.rcParams.update({
    'font.family': 'Tahoma', # Шрифт заголовков
    'font.size': 14,         # Размер шрифта заголовков
    'font.weight': 'normal', # Жирность шрифта заголовков
    'font.style': 'italic',  # Стиль шрифта заголовков
})

# Создание многооконного рисунка (2 строки, 3 столбца)
fig, axes = plt.subplots(2, 3, figsize=(16, 12))
fig.suptitle('Лабораторная работа. Вариант 3', fontsize=16, fontweight='bold')

# --- Задание 1.1: Поместить в 1-ю область свою фотографию ---
image = plt.imread("/Users/asphoreabletellsuadreamils/Documents/ava.jpg")

ax1 = axes[0, 0] # Первая область (верхний левый угол)
ax1.imshow(image)
ax1.text(199, 499, "Моя фотография", size='x-large', color='white', bbox=dict(facecolor='black', alpha=0.7))
ax1.set_title('Задание 1.1: Фотография')
ax1.axis('off') # Отключаем оси для изображения


# --- Задание 1.2: Поместить во 2-ю область стандартный график Python с заливкой ---
# Читаем данные из файла "data.txt". В данном примере мы сгенерируем данные, так как файл не предоставлен.
# Данные для графика: строка с номером варианта + 1 (т.е. 4-я строка) будет использоваться для Y.
# Генерируем данные для демонстрации.
np.random.seed(42) # Для воспроизводимости
x = np.linspace(0, 12, 100)
y = np.sin(x) * np.exp(-x/10) # Пример функции

# Для варианта 3 заливка должна быть одним цветом для положительных значений и другим для отрицательных.
# Цвета задаются текстовой константой (например, 'red', 'blue').
ax2 = axes[0, 1] # Вторая область (верхний центр)
ax2.fill_between(x, y, where=(y >= 0), color='lightgreen', alpha=0.7, label='Положительные')
ax2.fill_between(x, y, where=(y < 0), color='lightcoral', alpha=0.7, label='Отрицательные')
ax2.plot(x, y, 'k-', linewidth=2, label='Функция')
ax2.grid(True, linestyle='--', alpha=0.6)
ax2.set_xlabel('Время', fontsize=12, fontfamily='Comic Sans MS')
ax2.set_ylabel('Температура', fontsize=12, fontfamily='Comic Sans MS')
ax2.set_title('Задание 1.2: График с заливкой')
ax2.legend(loc='upper right')


# --- Задание 2.1: Поместить в 3-ю область столбчатую диаграмму с аннотацией ---
# Генерируем данные для столбчатой диаграммы.
categories = ['Категория A', 'Категория B', 'Категория C', 'Категория D']
values = [25, 40, 30, 50]

ax3 = axes[0, 2] # Третья область (верхний правый угол)
bars = ax3.bar(categories, values, color=['#FFA500', '#87CEEB', '#90EE90', '#FF6347'], edgecolor='black')

# Аннотация: добавляем значения над каждым столбцом
for bar in bars:
    height = bar.get_height()
    ax3.annotate(f'{height}',
                 xy=(bar.get_x() + bar.get_width() / 2, height),
                 xytext=(0, 3),  # 3 points vertical offset
                 textcoords="offset points",
                 ha='center', va='bottom',
                 fontsize=10, fontfamily='Comic Sans MS')

ax3.set_title('Задание 2.1: Столбчатая диаграмма с аннотацией')
ax3.tick_params(axis='x', rotation=60, labelsize=11, labelrotation=60) # Поворот подписей делений на 60 градусов
ax3.set_ylabel('Значение', fontsize=12, fontfamily='Comic Sans MS')


# --- Задание 2.2: Поместить в 4-ю область график функций с легендой ---
# Генерируем данные для нескольких функций.
x_func = np.linspace(-2, 2, 100)
y1 = x_func ** 2
y2 = np.sin(x_func * np.pi)
y3 = np.exp(-x_func**2)

ax4 = axes[1, 0] # Четвертая область (нижний левый угол)
line1, = ax4.plot(x_func, y1, 'r-', linewidth=2, label='y = x^2')
line2, = ax4.plot(x_func, y2, 'b--', linewidth=2, label='y = sin(πx)')
line3, = ax4.plot(x_func, y3, 'g-.', linewidth=2, label='y = exp(-x^2)')
ax4.grid(True, linestyle=':', alpha=0.5)
ax4.set_xlabel('X', fontsize=12, fontfamily='Comic Sans MS')
ax4.set_ylabel('Y', fontsize=12, fontfamily='Comic Sans MS')
ax4.set_title('Задание 2.2: График функций с легендой')
ax4.legend(loc='upper right')


# --- Задание 2.3: Поместить в 5-ю область диаграммы рассеяния (разброса) ---
# Генерируем данные для диаграммы рассеяния.
np.random.seed(123)
x_scatter = np.random.randn(100)
y_scatter = 2 * x_scatter + np.random.randn(100) * 0.5

ax5 = axes[1, 1] # Пятая область (нижний центр)
scatter = ax5.scatter(x_scatter, y_scatter, c='purple', alpha=0.7, edgecolors='w', linewidth=2)
ax5.set_xlabel('Переменная X', fontsize=12, fontfamily='Comic Sans MS')
ax5.set_ylabel('Переменная Y', fontsize=12, fontfamily='Comic Sans MS')
ax5.set_title('Задание 2.3: Диаграмма рассеяния')
ax5.grid(True, linestyle='--', alpha=0.3)


# --- Задание 2.4: Поместить в 6-ю область график фигур Лиссажу ---
# Генерируем фигуры Лиссажу.
t = np.linspace(0, 2*np.pi, 1000)
a, b = 3, 2 # Соотношение частот
delta = np.pi / 2 # Разность фаз
x_lissajous = np.sin(a * t + delta)
y_lissajous = np.sin(b * t)

ax6 = axes[1, 2] # Шестая область (нижний правый угол)
ax6.plot(x_lissajous, y_lissajous, 'm-', linewidth=2)
ax6.set_xlabel('X', fontsize=12, fontfamily='Comic Sans MS')
ax6.set_ylabel('Y', fontsize=12, fontfamily='Comic Sans MS')
ax6.set_title('Задание 2.4: Фигуры Лиссажу')
ax6.grid(True, linestyle=':', alpha=0.5)
ax6.set_aspect('equal') # Для сохранения пропорций

# Настройка общего вида рисунка
plt.tight_layout(rect=[0, 0, 1, 0.96]) # Оставляем место для общего заголовка

# Сохранение рисунка в файл
output_filename = "lab_work_variant_3.png"
plt.savefig(output_filename, dpi=300, bbox_inches='tight')
print(f"Рисунок сохранен в файл: {output_filename}")

# Отображение рисунка
plt.show()
