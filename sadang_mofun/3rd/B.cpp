/*
    못풀었어요..
    1~9까지는 9개 숫자
    나머지 부터는 줄당 20개의 숫자를 사용하기 때문에
    최대 string 길이가 50이라서 29까지 숫자를 받을 수 있다 생각해서
    1 옆에 오는 숫자가 뭐인지 확인하고
    그 숫자를 했다는 걸 chk 배열에 저장하고 이렇게 할라구 했는데
    안되네요...
*/
#include<iostream>
using namespace std;
bool check[33];
int main(){
    string str;
    cin >> str; 
    bool chk = false; // 2자릿수 확인
    for(int i=0;i<str.length();i++){
        if(str.length() > 49){
            
        }
        else if(str.length() > 29){
            
        }
        else if(str.length() > 9){
            if(str[i] == '1'){
                chk = true;
                cout << str[i] << ' ';
                if(check[1] == false){
                    check[1] = true;
                }
                else{
                    continue;
                }
            }
            if(chk == true){
                cout << str[i] << ' ';
                chk = false;
                char s[2];
                /*
                s[0] = str[i-1]
                s[1] = str[i];
                check[stoi(to_string(s))-'0'] = true;
                */
            }
            else{
                cout << str[i] << ' ';
            }
        }
        else{
            cout << str[i] << ' ';
        }
    }
    return 0;
}


/*

1 2 3 4 5 6 7 8 9 9
10 11 12 13 14 15 16 17 18 19  29
20 21 22 23 24 25 26 27 28 29  49
*/
