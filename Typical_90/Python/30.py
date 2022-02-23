def calc(N,K):
    box = [0] *(N+1)
    for i in range(2,N+1):
        if box[i] != 0:
            continue
        for j in range(i,N+1,i):
            box[j] += 1
    ans = [0] * 10**4
    for i in range(N+1):
        ans[box[i]] += 1
    return sum(ans[K:])
N,K = map(int,input().split())
print(calc(N,K))