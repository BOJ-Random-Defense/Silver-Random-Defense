/*
    최근에 동전 문제를 풀었는데
    이 문제가 그 문제류랑 똑같은 것 같아서
    바로 생각남
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
int arr[22];
bool isInIndex(int x, int y, int n, int m){
    return x >= 0 && x < n && y >= 0 && y < m;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    cin >> N;
    int smallest = 1; // 만들 수 있는 최소 자연수
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    sort(arr, arr+N);
    for(int i=0;i<N;i++){
        // 만약 만들어진 그 수가 최소 자연수보다 큰 경우에
        // 조건을 만족하지 않기 때문에 바로 끝내주면 된다.
        if (arr[i] > smallest) break;
        smallest += arr[i];
    }
    cout << smallest;
    return 0;
}