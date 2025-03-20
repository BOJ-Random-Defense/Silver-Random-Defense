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
    long long N, L;
    cin >> N >> L;
    // 등차수열의 합 공식 이용용
    for(int i=L;i<=100;i++){
        if((2*N) % i == 0){
            long long temp = (2*N) / i-(i-1);
            if (temp >= 0 && temp % 2 == 0){
                long long first = temp / 2;
                for (int i = 0; i < i; i++){
                    cout << first + i << " ";
                }
                return 0;
            }
        }
    }
    
    // 조건을 만족하는 수열이 없는 경우
    cout << -1;

    return 0;
}