#include<iostream>
using namespace std;
int check[202020];
int main(){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int data;
    cin >> data;
    int cnt = 0;
    for(int i=0;i<data;i++){
        int index, inOut;
        cin >> index >> inOut;
        if(check[index] == inOut){
            cnt++;
        }
        check[index] = inOut;
    }
    for(int i=1;i<=200000;i++){
        if(check[i] == 1){
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}