N = int(input())
S = input()
box = [0] * N
for i in range(N):
    if S[i] == "b":
        box[i] = 1
    elif S[i] == "c":
        box[i] = 2

ans = 0
while True:
    s = [0] * (N+1)
    flag = True
    for i in range(N):
        if box[i] != 0:
            ans += box[i]
            s[i-1] += box[i]
            box[i] = 0
            flag = False

    for i in range(N-2, -1, -1):
        s[i] += s[i+1]
        # s[i] %= 3
    for i in range(N):
        box[i] = s[i]
    if flag == True:
        break

print(ans)
