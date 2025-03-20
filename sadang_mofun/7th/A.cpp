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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    cin >> N;
    cout << (int)sqrt(N);

    return 0;
}