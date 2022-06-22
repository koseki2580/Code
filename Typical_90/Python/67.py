
def base10int(value, base):
    if (value // base):
        return base10int(value // base, base) + str(value % base)
    return str(value % base)


N, K = map(int, input().split())
n = str(N)
for i in range(K):
    n = int(n, 8)
    n = base10int(n, 9)
    a = ""
    for j in range(len(n)):
        if n[j] == "8":
            a += "5"
        else:
            a += n[j]
    n = a
print(n)
