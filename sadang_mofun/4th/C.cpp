/*
    기분좋게 쉬운 문제를 만나 완전 탐색으로 범위조건에 맞게
    합을 계산했더니 아래에 완탐으로 풀면 터진다고 힌트를 발견
    그 후 누적합 테크닉을 떠올렸고 그것을 활용하여 문제를 해결
*/
#include<iostream>
#include<algorithm>
#include<numeric>
int arr[303030]; // 2 5 1 4 3 이 들어온다음 sort
int prefix[303030]; // 하면 0 1 3 6 10 15 가 되고
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    fill(prefix, prefix+N, 0); // init
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    sort(arr, arr+N);
    prefix[0] = 0;
    for(int i=1;i<=N;i++){
        prefix[i] = prefix[i-1] + arr[i-1];
    }
    for(int i=0;i<Q;i++){
        int start, end;
        cin >> start >> end;
        int sum = 0;
        sum = prefix[end]-prefix[start-1];
        cout << sum << '\n';
    } // 차를 구하면 끝
    return 0;
}