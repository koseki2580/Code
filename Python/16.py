import itertools

N = int(input())
P = [int(i) for i in input().split()]
Q = [int(i) for i in input().split()]

p = ""
q = ""
for i in range(N):
    p+=str(P[i])
    q+=str(Q[i])
a = [i for i in range(1,N+1)]
l = list(itertools.permutations(a))
b = []
for i in range(len(l)):
    c = ""
    for j in l[i]:
        c+= str(j)
    b.append(c)
    
b.sort()
aa = 0
bb = 0
for i in range(len(b)):
    if b[i] == p:
        aa = i+1
    if b[i] == q:
        bb = i+1

print(abs(aa-bb))