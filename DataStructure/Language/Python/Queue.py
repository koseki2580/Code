# Pythonの標準ライブラリ
from collections import deque 

# 初期化
box = deque()

# push 要素を一番後ろに追加する
box.append(1)
box.append(2)
box.append(3)
print(box) # deque([1, 2, 3])
box.append(4)
print(box) # deque([1, 2, 3, 4])

# pop 最初に入れた要素を取り出し
print(box.popleft()) # 1
print(box.popleft()) # 2
print(box) # deque([3, 4])