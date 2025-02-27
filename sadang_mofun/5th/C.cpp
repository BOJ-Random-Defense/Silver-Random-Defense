/*
    1-cycle : 1, 3, 4
    1
    3
    4
    2-cycle : 2, 6, 5, 7, 8
    1 1 
    1 3
    3 3
    1 4 
    3 4
    4 4
    3-cycle : 
    1 1 1
    1 1 3 
    1 3 3
    3 3 3 
    1 1 4
    1 3 4 
    1 4 4 
    3 3 4
    3 4 4 

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
#include<set>
using namespace std;
bool isInIndex(int x, int y, int n, int m){
    return x >= 0 && x < n && y >= 0 && y < m;
}
int wok[105];
int dp[10101]; // N(dp배열의 인덱스) 그릇을 만들기 위한 횟수를 저장
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N, M;
    cin >> N >> M;
    for(int i=0;i<M;i++){
        cin >> wok[i];
    }

    // 웍을 상식적으로 21억번 쓸리는 없으니..
    // 일단 큰 값으로 세팅
    fill(dp, dp + N+5, INT_MAX-1);
    unordered_set<int> serve;

    // 한번에 한개의 웍만 쓰는 경우
    for(int i=0;i<M;i++){
        if(wok[i] <= N){
            serve.insert(wok[i]);
            dp[wok[i]] = 1;
        }
    }
    // 한번에 두개의 웍을 사용하는 경우
    for(int i=0;i<M;i++){
        for(int j=i+1;j<M;j++){
            int sum = wok[i] + wok[j];
            if(sum <= N){
                serve.insert(sum);
                dp[sum] = min(dp[sum], 1);
            }
        }
    }
    dp[0] = 0; // 0인분은 0번 요리 시에 사용 가능
    for(int i=1;i<=N;i++){
        if(dp[i] != INT_MAX-1){
            continue;
        }  // 1번 2번 쓰는 케이스는 이미 찾아뒀음
        // 모든 가능한 방식으로 i를 두 부분으로 나누어 최소 횟수 찾기
        for(int j=1; j<i; j++){
            // j 그릇을 만들 수 없거나 i-j 그릇을 만들 수 없는 경우 그대로 둔다
            if(dp[j] == INT_MAX-1 || dp[i-j] == INT_MAX-1) continue;
            dp[i] = min(dp[i], dp[j] + dp[i-j]);
        }
    }   
    // 결과 출력
    if(dp[N] == INT_MAX - 1){
        cout << "-1\n"; // 불가능한 경우
    } 
    else {
        cout << dp[N] << "\n";
    }
    return 0;
}