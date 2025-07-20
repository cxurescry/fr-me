import math
flag = 0
def lcm(l, x, y, r):
    return (l <= (x * y) // math.gcd(x, y) <= r) and (l <= x < y <= r) 
    
t = int(input())
for i in range(t):
    l, r = map(int, input().split())
    if not(any(lcm(l, x, y, r) == 1 for x in range(l, r) for y in range(x + 1, r + 1))):
           print(-1, -1)
    else:
        for x in range(l, r):
            for y in range(x + 1, r + 1):
                if lcm(l, x, y, r):
                    print(x, y)
                    flag = 1
                    break
            if flag == 1: break
