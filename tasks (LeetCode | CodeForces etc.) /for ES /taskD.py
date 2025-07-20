n, t = map(int, input().split())
xs = list(map(int, input().split()))
 
prfx = [0] * (n + 1)
for i in range(1, n + 1):
    prfx[i] = prfx[i - 1] + xs[i - 1]
 
mx = 0
l = 1
r = n
 
while l <= r:
    m = (l + r) // 2
    flag = False
    mn_sum = float('inf')
    
    
    for i in range(m, n + 1):
        cur_sum = prfx[i] - prfx[i - m]
        if cur_sum <= t:
            flag = True
            break
    
    if flag:
        mx = m
        l = m + 1
    else:
        r = m - 1
 
print(mx)
