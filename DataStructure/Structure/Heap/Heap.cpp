#include <bits/stdc++.h>
#define rep(i,nn,n) for (int i = nn; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)



int main() {
    // priority_queueはヒープを用いて実装されたもの
    // 競プロ的にはこちらを使うことが多いと思うのでこちらでの処理を記載しています。
    // heapにするなら、vector型を用いてmake_heap(~~.begin(),~~.end());で可能
    priority_queue<int> queue;
    int box[14] = {100,3,55,32,23,67,8,1,75,-3,53,-10,30,33};
    rep(i,0,14){
        queue.push(box[i]);
    }
    // C++は最大値を出力する
    rep(i,0,14){
        printf("%d ", queue.top()); // 100 75 67 55 53 33 32 30 23 8 3 1 -3 -10
        queue.pop();
    }
    // popで要素を削除しているので再度代入
    rep(i,0,14){
        queue.push(box[i]);
    }
    cout << queue.top() << endl; // 100
    queue.pop();
    cout << queue.top() << endl; // 75
    queue.pop();
    rep(i,0,12){
        printf("%d ", queue.top()); // 100 75 67 55 53 33 32 30 23 8 3 1 -3 -10
        queue.pop(); // 67 55 53 33 32 30 23 8 3 1 -3 -10
    }
    return 0;
}