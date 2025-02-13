/*
    그리디인지 모르고 그냥 풀었던 문제
    걸러내야 할 것
    1. 같은 음계가 들어오는 경우
    2. 등차수열의 조건을 만족하지 않는 경우
    만 체크해주면 금방 해결되는 문제이다
*/
#include<iostream>
using namespace std;
int arr[20202];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N, A, D;
    bool flag = false; // A를 찾았는가?
    int cnt = 0;
    cin >> N >> A >> D;
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    int temp = A;
    for(int i=0;i<N;i++){
        if(arr[i] == A && !flag){
            flag = true;
            cnt++;
        }
        if(flag && arr[i] == temp + D){
            cnt++;
            temp = temp + D;
        }
    }
    cout << cnt;
    return 0;
}