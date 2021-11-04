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

# pop 一番後ろ（新しい）要素を取り出し
print(box.pop()) # 4
print(box.pop()) # 3
print(box) # deque([1, 2])