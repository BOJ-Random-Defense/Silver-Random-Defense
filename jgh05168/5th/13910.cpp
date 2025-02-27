/*
필요 이상 크기의 웍을 사용하지 않음. 한 번에 2개까지 사용 ㄱㄴ
짜장면의 그릇 수에 딱 맞게 요리함.

풀이 : 진하게 나는 dp향기 ..
이번에도 topdown ?

*/
#include <iostream>
#include <vector>
#include <algorithm>
#define INf 10000000

using namespace std;

int n, m;
int wok[101];
int dp[10001];

int main() {
	cin >> n >> m;

	fill(dp, dp + 10001, INf);
	dp[0] = 0;

	int a;
	for (int i = 1; i < m + 1; i++) {
		cin >> wok[i];
	}

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = j + 1; k < m + 1; k++) {
				int tmp = i + wok[j] + wok[k];
				if (tmp <= n) {
					dp[tmp] = min(dp[tmp], dp[i] + 1);
				}
			}
		}
	}

	if (dp[n] >= INf) {
		dp[n] = -1;
	}
	cout << dp[n];

	return 0;
}
