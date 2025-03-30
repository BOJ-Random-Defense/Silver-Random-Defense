/*
일단 set써서 나이브면 R^2logR * C라 터짐
결국 [x,R)에 대해서 단조성이 보장되므로 이분탐색가능
R(logR)^2 * C로 뚫린다
*/

#include <bits/stdc++.h>
#include <unordered_set> // 상수커팅하다가 TLE남 ㅋㅋㅠ;;
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll> 

int R, C;
char board[1005][1005];

// [x, R)이 valid한지 체크
bool check(int x) {
    set<string> st;
    for(int j = 0; j < C; j++) {
        string cur = "";
        for(int i = x; i < R; i++) {
            cur += board[i][j];
        }

        if(st.count(cur)) return false;
        st.insert(cur);
    }

    return true;
}

void solve() {
    cin >> R >> C;
    for(int i = 0; i < R; i++) {
        string s; cin >> s;
        for(int j = 0; j < C; j++) {
            board[i][j] = s[j];
        }
    }

    // 매개변수 탐색
    // 안 헷갈리게 짜는 팁 : 
    // while문에 lo + 1 < hi로, 
    // 항상 [lo, hi]에 경계를 두기 마지막에 어떤값을 쓸지 확인
    int lo = -1, hi = R + 1;
    while(lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if(check(mid)) lo = mid;
        else hi = mid;
    }

    cout << lo << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Tc = 1;
    // cin >> Tc;
    for(int tt = 1; tt <= Tc; tt++) {
        solve();
    }
    return 0;
}
