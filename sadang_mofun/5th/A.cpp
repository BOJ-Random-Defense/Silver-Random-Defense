/*
    반올림만 안했다면 한번에 AC 받았을 것 같음
    피타고라스 정리를 이용하여 거리를 계산하고 속도로 나누기
    그 후 정렬을 통해 선착순으로 출력배열 재배치
*/
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<climits>
#include<numeric>
#include<map>
using namespace std;
bool isInIndex(int x, int y, int n, int m){
    return x >= 0 && x < n && y >= 0 && y < m;
}
bool compare(pair<double,int> a, pair<double,int> b){
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<pair<double,int>> standing;
    int N;
    cin >> N;
    for(int i=1;i<=N;i++){
        int X, Y, V;
        cin >> X >> Y >> V;
        double len = sqrt(X * X + Y * Y); 
        standing.push_back({len / V, i});
    }
    sort(standing.begin(), standing.end(), compare);
    for(auto i : standing){
        cout << i.second << '\n';
    }
    return 0;
}