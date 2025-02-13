#include <bits/stdc++.h>
using namespace std;

int arr[200001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	int ans = 0, num, inout;
	cin >> n;
	for (int i = 0; i < 200001; i++) arr[i] = 2;
	for (int i = 0; i < n; i++) {
		cin >> num >> inout;
		// array[num] == inout > 값이 달라져야 함 && 첫 출입인데 0인경우
		if (arr[num] == inout || (arr[num] == 2 && inout == 0)) ans++;
		arr[num] = inout;
	}
	for (int i = 0; i < 200001; i++) {
		if (arr[i] == 1) ans++;
	}
	cout << ans;

	return 0;
}