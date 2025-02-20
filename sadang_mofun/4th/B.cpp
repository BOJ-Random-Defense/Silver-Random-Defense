/*
    저렇게 풀면 한줄씩 내려가면서 ch 배열에서
    위에서부터 하나씩 뺴야하는데
    그걸 어떻게 해야할 지 모르겠네요
*/
#include<iostream>
#include<vector>
using namespace std;
char ch[1010][1010];
vector<string> v;
int main(){
    int R, C;
    cin >> R >> C;
    // 입력
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin >> ch[i][j];
        }
    }
    // 세로줄 떼서 string으로 바꾸고 벡터에 넣기
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            string str = "";
            str += ch[j][i];
            v.push_back(str);
        }
    }
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(v[i] == v[j]){
                break; // 같은 문자열 나오면 멈춰
            }
        }
    }
    return 0;
}