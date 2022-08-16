#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pi;
#define fastio cin.tie(0)->sync_with_stdio(0)
#define X first
#define Y second


//------------------------------



bool f[2501][2501];
int d[2501], n;

int dp(int en) {

	if (en == 0) return 0;
	if (f[1][n]) return 1;
	if (d[en] != 0x3f3f3f3f) return d[en];
	
	
	
	
	for (int i = 1; i <= en; i++) {
		if (!f[i][en]) continue;
		d[en] = min(d[en], dp(i-1) + 1);		
	}

	return d[en];

}





int main () {
	fastio;
	memset(d, 0x3f3f3f3f, sizeof(d));
	string s;

	cin >> s;
	n = s.length();
	for (int i = 1; i <= n; i++) {
		f[i][i] = 1;
	}

	for (int i = 0; i < n-1; i++) {
		if (s[i] == s[i+1]) f[i+1][i+2] = 1;
	}

	for (int i = 2; i < n; i++) {
		for (int j = 0; j < n - i; j++) {
			if (s[i+j] == s[j] && f[j+2][j+i]) f[j+1][j+i+1] = 1; 
		}
	}		
		
	

	cout << dp(n);
	
	
}
