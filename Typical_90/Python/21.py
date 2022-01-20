# 強連結成分分解(SCC): グラフGに対するSCCを行う
# 入力: <N>: 頂点サイズ, <G>: 順方向の有向グラフ, <RG>: 逆方向の有向グラフ
# 出力: (<ラベル数>, <各頂点のラベル番号>)
import sys
sys.setrecursionlimit(10**6)
def scc(N, G, RG):
    order = []
    used = [0]*N
    group = [None]*N
    def dfs(s):
        used[s] = 1
        for t in G[s]:
            if not used[t]:
                dfs(t)
        order.append(s)
    def rdfs(s, col):
        group[s] = col
        used[s] = 1
        for t in RG[s]:
            if not used[t]:
                rdfs(t, col)
    for i in range(N):
        if not used[i]:
            dfs(i)
    used = [0]*N
    label = 0
    for s in reversed(order):
        if not used[s]:
            rdfs(s, label)
            label += 1
    return label, group

# 縮約後のグラフを構築
def construct(N, G, label, group):
    G0 = [set() for i in range(label)]
    GP = [[] for i in range(label)]
    for v in range(N):
        lbs = group[v]
        for w in G[v]:
            lbt = group[w]
            if lbs == lbt:
                continue
            G0[lbs].add(lbt)
        GP[lbs].append(v)
    return G0, GP

N,M = map(int,input().split())
box = [[] for _ in range(N)]
r_box = [[] for _ in range(N)]
for i in range(M):
    a,b = map(int,input().split())
    a -= 1
    b -= 1
    box[a].append(b)
    r_box[b].append(a)

label, group = scc(N, box, r_box)
G0,Gp = construct(N,box, label, group)

ans = 0
for i in Gp:
    ans += len(i) * (len(i)-1) //2
print(ans)