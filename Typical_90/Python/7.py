import bisect

N = int(input())
A = [int(i) for i in input().split()]
A.sort()
Q = int(input())
for i in range(Q):
    a = int(input())
    num = bisect.bisect_left(A,a);
    if num == N:
        num -= 1
    ans = min( abs(A[num] - a), abs(A[num-1] -a) )
    print(ans)