'''
                       1
                  /         \
                2             3
               /  \         /    \
              4    5       6     7 
            /  \   / \    / \     / \
           8    9 10  11 12  13  14 15 
の木構造を構築する
'''
# 枝が存在する頂点間を列挙
root =[[1,2],[1,3],[2,4],[2,5],[3,6],[3,7],[4,8],[4,9],[5,10],[5,11],[6,12],[6,13],[7,14],[7,15]]

# 隣接リスト表現で木を構築
tree_list = [[] for _ in range(16)]

# 隣接行列表現で木を構築
tree_matrix = [[0]*16 for _ in range(16)]

for a,b  in root:
    #　無向グラフの場合
    tree_list[a].append(b)
    tree_list[b].append(a) 
    tree_matrix[a][b] = 1
    tree_matrix[b][a] = 1
    """
    隣接リスト表現:                       隣接行列表現:
    1: 2 3                              1: 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0
    2: 1 4 5                            2: 0 1 0 0 1 1 0 0 0 0 0 0 0 0 0 0
    3: 1 6 7                            3: 0 1 0 0 0 0 1 1 0 0 0 0 0 0 0 0
    4: 2 8 9                            4: 0 0 1 0 0 0 0 0 1 1 0 0 0 0 0 0
    5: 2 10 11                          5: 0 0 1 0 0 0 0 0 0 0 1 1 0 0 0 0
    6: 3 12 13                          6: 0 0 0 1 0 0 0 0 0 0 0 0 1 1 0 0
    7: 3 14 15                          7: 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 1
    8: 4                                8: 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0
    9: 4                                9: 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0
    10: 5                               10: 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0
    11: 5                               11: 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0
    12: 6                               12: 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0
    13: 6                               13: 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0
    14: 7                               14: 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0
    15: 7                               15: 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0
    """
    # 有向グラフの場合
    tree_list[a].append(b)
    tree_matrix[a][b] = 1
    """
    隣接リスト表現:                       隣接行列表現:
    1: 2 3                              1: 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0
    2: 4 5                              2: 0 1 0 0 1 1 0 0 0 0 0 0 0 0 0 0
    3: 6 7                              3: 0 1 0 0 0 0 1 1 0 0 0 0 0 0 0 0
    4: 8 9                              4: 0 0 1 0 0 0 0 0 1 1 0 0 0 0 0 0
    5: 10 11                            5: 0 0 1 0 0 0 0 0 0 0 1 1 0 0 0 0
    6: 12 13                            6: 0 0 0 1 0 0 0 0 0 0 0 0 1 1 0 0
    7: 14 15                            7: 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 1
    8:                                  8: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
    9:                                  9: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
    10:                                 10: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
    11:                                 11: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
    12:                                 12: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
    13:                                 13: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
    14:                                 14: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
    15:                                 15: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
    """
