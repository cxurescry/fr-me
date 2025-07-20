n = int(input())
xs = [int(x) for x in input().split()]
ans1 = ans2 = 0
k = 0
while xs:
    if k % 2 == 0:
        if xs[-1] > xs[0]: ans1 += xs.pop()
        else: ans1 += xs.pop(0)
        # print("cur ans1:", ans1)
    else:
        if xs[-1] > xs[0]: ans2 += xs.pop()
        else: ans2 += xs.pop(0)
        # print("cur ans2:", ans2)
    k += 1
print(ans1, ans2)
