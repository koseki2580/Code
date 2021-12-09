N,K = map(int,input().split())
S = input()

box = [[-1] * (len(S)+1) for _ in range(26)]
for i in range(len(S)-1,-1,-1):
    
    for j in range(26):
        box[j][i] = box[j][i+1]
    pos = ord(S[i]) - ord("a")
    box[pos][i] = len(S) - i 
ans  =""
now = 0
for i in range(K,0,-1):
    
    for j in range(26):
        mozi = chr(j + ord("a"))
        mm = box[j][now]
        if box[j][now] >= i:
            now = len(S) - box[j][now] +1
            ans += mozi
            break
print(ans)