#include <bits/stdc++.h>
using namespace std;

stack <char> arr;
int main() {
    string s;
    cin >> s;

    stack<char> st;
    int ans = 0;

    for (char c : s) {
        if (c == '(') { 
            st.push(c);
        }
        else {
            if (st.empty()) { // ���ÿ� (�� ������
                ans++;
            }
            else { // () �����ǹǷ� pop
                st.pop();
            }
        }
    }
    cout << ans + (int)st.size() << endl;

    return 0;
}