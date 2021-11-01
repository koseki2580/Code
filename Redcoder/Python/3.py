S = input()
ans = 0
count = 0
for i in range(len(S)):
    a = S[i]
    if a == "A":
        count+=1
    elif a == "C":
        count += 1
    elif a == "G":
        count += 1
    elif a == "T":
        count += 1
    else:
        ans = max(ans,count)
        count = 0
ans = max(ans,count)
print(ans)