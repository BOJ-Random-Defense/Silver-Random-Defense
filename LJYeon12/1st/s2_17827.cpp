#include <bits/stdc++.h>
using namespace std;


long long c[200002];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m, v;
	int cal;
	cin >> n >> m >> v;
	for (int i = 1; i < n + 1; i++) {
		cin >> c[i];
	}
	while (m--)
	{
		cin >> cal;
		if (cal < n) cout << c[cal + 1] << "\n"; // n보다 작을 경우
		else {
			cal -= 10;
			cout << c[v + (cal % (n - v + 1))] << "\n"; // n보다 클 경우
		}
	}

	return 0;
}