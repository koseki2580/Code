import heapq

box = [100,3,55,32,23,67,8,1,75,-3,53,-10,30,33]

# リストをヒープ化
heapq.heapify(box)
print(box) # [-10, -3, 8, 1, 3, 30, 33, 32, 75, 23, 53, 67, 55, 100]
# Pythonは最小値をpopで出力する
# 値に-1をかけて最大値を導出することが可能
print(heapq.heappop(box)) # -10
print(heapq.heappop(box)) # -3
print(box) # [1, 3, 8, 32, 23, 30, 33, 100, 75, 55, 53, 67]
