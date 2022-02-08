N = int(input())
box = {}
for i in range(N):
    a = input()
    try:
        box[a] += 1
    except:
        print(i+1)
        box[a] = 0