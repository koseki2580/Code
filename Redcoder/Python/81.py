n = int(input())
box = [0] * 1000_010
for i in range(n):
    a,b = map(int,input().split())
    box[a] +=1
    box[b+1] -= 1

s = [0] 
for i in range(len(box)):
    s.append(s[-1] + box[i])
ans = 0
for i in range(len(s)):
    ans = max(ans, s[i])
print(ans)