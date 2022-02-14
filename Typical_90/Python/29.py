def segfunc(x,y):
    return max(x,y)
segbase = 0
class SegTree_RMQ():
    def __init__(self,num, segfunc, segbase):
        self.nodeSize = 1
        self.count = 1
        while (self.nodeSize < num):
            self.nodeSize *= 2;
            self.count +=1
        self.__segfunc = segfunc
        self.__INF = segbase
        self.value = [self.__INF] * (2 * self.nodeSize)
        self.__lazy = [None]*(2 * self.nodeSize)

    # 伝搬対象の区間を求める
    def __gindex(self, l, r):
        L = (l + self.nodeSize) >> 1
        R = (r + self.nodeSize) >> 1
        
        if l & 1 :
            lc = 0 
        else:
            lc = (L & -L).bit_length()
        if r & 1: 
            rc = 0 
        else:
            rc = (R & -R).bit_length()
        for i in range(self.count):
            if rc <= i:
                yield R
            if L < R and lc <= i:
                yield L
            L >>= 1
            R >>= 1
    
    # 遅延伝搬処理
    def __propagates(self, *ids):
        for i in reversed(ids):
            v = self.__lazy[i-1]
            if v is None:
                continue
            self.__lazy[2*i-1] = v
            self.value[2*i-1] = v
            self.__lazy[2*i] = v
            self.value[2*i] = v
            self.__lazy[i-1] = None

        
    def RangeInit(self, array):
        n = len(array)
        for i in range(n):
            self.value[self.nodeSize+i-1] = array[i]
        for i in range(self.nodeSize-2,-1,-1):
            self.value[i] = self.__segfunc(self.value[2*i+1],self.value[2*i+2])
            
    def UpdateOnepoint(self,k, x):
        self.Update(k, k+1,x)
            
    # 区間[l, r)をxで更新
    def Update(self, l, r, x):
        *ids, = self.__gindex(l, r)
        
        self.__propagates(*ids)
        L = self.nodeSize  + l 
        R = self.nodeSize  + r
        while L < R:
            if R & 1:
                R -= 1
                self.__lazy[R-1] = x
                self.value[R-1] = x
            if L & 1:
                self.__lazy[L-1] = x
                self.value[L-1] = x
                L += 1
            L >>= 1
            R >>= 1
        for i in ids:
            self.value[i-1] = self.__segfunc(self.value[2*i-1], self.value[2*i])
    
    def Query(self, l, r):
        self.__propagates(*self.__gindex(l, r))
        L = l + self.nodeSize
        R = r + self.nodeSize
        s = self.__INF
        while L < R:
            if R & 1:
                R -= 1
                s = self.__segfunc(s, self.value[R-1])
    
            if L & 1:
                s = self.__segfunc(s, self.value[L-1])
                L += 1
            L >>= 1; R >>= 1
        return s




W,N = map(int,input().split())

seg = SegTree_RMQ(W+5,segfunc, segbase)
for i in range(N):
    l,r = map(int,input().split())
    r += 1
    ans = seg.Query(l,r) + 1
    
    seg.Update(l,r,ans)
    
    print(ans)