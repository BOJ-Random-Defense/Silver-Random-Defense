/*
    LIS인거 알고 풀었구
    처음에 LIS로직을 짜서 문제 풀다가
    조건식에 만족하는 경우를 생각해보니 굳이 그럴 필요는 없고
    다음에 들어올 것이라 예정된 수와 다음 수가 1차이만 나면 되기 때문에
    굳이 어렵게 생각 할 필요 없었던 것.
*/
#include<iostream>
using namespace std;
int arr[101010];
int dp[1010101];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    cin >> N;
    fill(dp, dp + N, 0);
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    int longest = 0;
    for(int i=0;i<N;i++) {
        // 앞의 수랑 1 차이나는지 아닌지만 확인하면 된다.
        dp[arr[i]] = max(dp[arr[i]-1]+1, dp[arr[i]]);
        longest = max(dp[arr[i]], longest);
    }
    cout << longest;
    return 0;
}