xs = {
    1: ["A", "E", "I", "L", "N", "O", "R", "S", "T", "U"],
    2: ["D", "G"],
    3: ["B", "C", "M", "P"],
    4: ["F", "H", "V", "W", "Y"],
    5: ["K"],
    8: ["J", "X"],
    10: ["Q", "Z"]
}


def calculate_score(word):
    score = 0
    for letter in word.upper():
        score += xs1[letter]
    return score
try:
    xs1 = {letter: score for score, letters in xs.items() for letter in letters}
    print(calculate_score("sasadsadsa"),file=open("output.txt","w"))
    for i in xs.items():
        print(*i,file=open("output.txt","a"))
except Exception:
    print("ошибка")

