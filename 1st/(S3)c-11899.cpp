#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<char> myStack;
    stack<char> noInput;
    string gwal;
    cin >> gwal;
    for(int i=0;i<gwal.length();i++){
        char ch = gwal[i];
        if(ch == '('){
            myStack.push(ch);
        }
        else{
            if(myStack.empty() == false){
                myStack.pop();
            }
            else{
                noInput.push(ch);
            }
        }
    }
    cout << myStack.size() + noInput.size();
    return 0;
}