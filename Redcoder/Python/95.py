A,B,K = map(int,input().split())

if A+B <=K :
    print("0 0")
else:
    K -= A
    if K < 0:
        print(str(A - (K+A)) + " " + str(B))
    else:
        print("0 " + str(B-K))