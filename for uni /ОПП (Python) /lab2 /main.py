def replace_colums(xs):
    rows = len(xs)
    cols = len(xs[0])

    last_pos = None # создаем переменную для тех индексов, где в последний раз увиделм строку и столбец
    for i in range(rows):
        for j in range(cols):
            if xs[i][j] > 100:
                last_pos = (i, j)

    target_col = last_pos[1] # запоминаем столбец

    # в цикле для каждой строки 2 и наш столбец который щапомнили мкеякм местами
    for i in range(rows):
        xs[i][1], xs[i][target_col] = xs[i][target_col], xs[i][1]

    return xs


xs = [
    [12,  150,  3],
    [8,   95, 102],
    [11,   70,  99]
]
for row in xs: print(*row)
replace_colums(xs)
print()
for row in xs: print(*row)
