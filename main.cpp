#include<iostream>
#include<algorithm>
using namespace std;

int dp[505][505];
int v[505][505];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, Max = 0;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i+1; j++) {
			cin >> v[i][j];
		}
	}
	dp[1][1] = v[1][1];
	dp[2][1] = v[1][1] + v[2][1];
	dp[2][2] = v[1][1] + v[2][2];
	Max = dp[1][1];
	for (int i = 3; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = v[i][j] + max(dp[i-1][j], dp[i-1][j-1]);
			if (dp[i][j] > Max) Max = dp[i][j];
		}
	}
	cout << Max << '\n';
	return 0;
}