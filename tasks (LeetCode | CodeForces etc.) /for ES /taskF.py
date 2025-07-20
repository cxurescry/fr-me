n = int(input())
for i in range(n):
    s = input()
    m = len(s)
    for l in range(len(s)):
        for r in range(l, l + m):
            c = s[l:r + 1]
            if c.count("1") >= 1 and c.count("2") >= 1 and c.count("3") >= 1:
                m = min(m, len(c))
                break
    if m == len(s): print(0)
    else: print(m)
