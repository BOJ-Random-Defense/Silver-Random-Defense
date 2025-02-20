/*
    계속해서 아래로 내려갈수록 쭉쭉 중복되는 경우가 늘어나서
    탑다운으로 짜야하나 어쩌고 저쩌고 어떻게 처리해야할 지 생각하다가
    아예 1만을 이용하는 경우
    1과 2만을 사용하는 경우
    모두 사용하는 경우 3개로 나눠서 문제를 풀어야 겠다고 분기를 나눔
*/
#include<iostream>
using namespace std;
int dp[10101];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int N;
    cin >> N;
    dp[0] = 1;
    // 1 만을 이용해서 만드는 경우
    for(int i=1;i<=10000;i++){
        dp[i] += dp[i-1];
    }
    // 1과 2 만을 이용해서 만드는 경우
    for(int i=2;i<=10000;i++){
        dp[i] += dp[i-2];
    }
    // 1, 2, 3을 모두 이용해서 만드는 경우
    for(int i=3;i<=10000;i++){
        dp[i] += dp[i-3];
    }   
    while(N--){
        int query;
        cin >> query;
        cout << dp[query] << "\n";
    }
    return 0;
}