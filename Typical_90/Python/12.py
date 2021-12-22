class UnionFind():
    def __init__(self, n):
        self.n = n
        self.parents = [-1] * n

    def find(self, x):
        if self.parents[x] < 0:
            return x
        else:
            self.parents[x] = self.find(self.parents[x])
            return self.parents[x]

    def union(self, x, y):
        x = self.find(x)
        y = self.find(y)

        if x == y:
            return

        if self.parents[x] > self.parents[y]:
            x, y = y, x

        self.parents[x] += self.parents[y]
        self.parents[y] = x

    def size(self, x):
        return -self.parents[self.find(x)]

    def same(self, x, y):
        return self.find(x) == self.find(y)

    def members(self, x):
        root = self.find(x)
        return [i for i in range(self.n) if self.find(i) == root]

    def roots(self):
        return [i for i, x in enumerate(self.parents) if x < 0]

    def group_count(self):
        return len(self.roots())

    def all_group_members(self):
        return {r: self.members(r) for r in self.roots()}

    def __str__(self):
        return '\n'.join('{}: {}'.format(r, self.members(r)) for r in self.roots())
    
H,W = map(int,input().split())
uni = UnionFind((H+3)*(W*3))
box = [[0] * (W+2) for _ in range(H+2)]
Q = int(input())
dx = [0,-1,0,1]
dy = [-1,0,1,0]
for i in range(Q):
    a = list(map(int,input().split()))
    if a[0] == 1:
        y = a[1]
        x = a[2]
        box[y][x] = 1
        for j in range(4):
            yy = y + dy[j]
            xx = x + dx[j]
            if box[yy][xx] == 1:
                uni.union(W*y+x, W*yy+xx);
    else:
        r1 = a[1]
        c1 = a[2]
        r2 = a[3]
        c2 = a[4]
        if box[r1][c1] == 1 and box[r2][c2] == 1 and uni.same(W*r1+c1, W*r2+c2) == True:
            print('Yes')
        else:
            print('No')