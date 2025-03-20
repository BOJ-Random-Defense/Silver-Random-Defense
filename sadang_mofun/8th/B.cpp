// BOJ 1263
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<climits>
#include<numeric>
#include<map>
#include<set>
using namespace std;
bool isInIndex(int x, int y, int n, int m){
    return x >= 0 && x < n && y >= 0 && y < m;
}
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
int N, M;
vector<pair<int, int>> table;
bool compare(pair<int, int> a, pair<int, int> b){
    // 마감시간이 가장 큰 놈 전까지 모두 일을 마쳐야 하므로
    // 내림차순으로 정렬하면 된다.
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second > b.second;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    cin >> N;
    // int timeCnt = 0;
    for(int i=0;i<N;i++){
        int time, due;
        cin >> time >> due;
        table.push_back({time,due});
        // timeCnt += time;
    }
    /*
        24시간이라는 조건을 넣었어서 틀렸는데
        생각해보니 문제에는 그런 조건이 없었던거임...
        timeCnt는 필요가 없었네요..
    */
    sort(table.begin(), table.end(), compare);
    int currentTime = table[0].second; // 일단 가장 마지막에 해도 되는 시간으로 맞춤
    for(auto i : table){
        // 작업의 마감시간 보다 더 늦게 시작하지 않도록 currentTime을 세팅하고
        // 작업에 필요한 시간을 해서 작업을 완료시킴
        currentTime = min(currentTime, i.second) - i.first;
    }
    if(currentTime < 0){
        cout << -1;
    }
    else{
        cout << currentTime;
    }
    return 0;
}