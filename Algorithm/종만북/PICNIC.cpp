#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int t, n, m, ans;
vector<int> frd[15];//친구 관계 저장
int visit[15];// 짝 여부

void dfs(int start, int cnt) {
	if (cnt == n/2) {
		ans++;
		return;
	}
	if (start >= n) return;
	if (visit[start] == 1) {
		dfs(start + 1, cnt);
		return;
	}
	//cout << start << " hihi\n";
	visit[start] = 1;
	int l = frd[start].size();
	for (int i = 0; i < l; i++) {
		int next = frd[start][i];
		if (visit[next] == 0) {
			visit[next] = 1;
			dfs(start + 1, cnt + 1);
			visit[next] = 0;
		}
	}
	visit[start] = 0;
}

int main() { 
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> t;
	while (t--) {
		cin >> n >> m;
		ans = 0;
		for (int i = 0; i < 11; i++) frd[i].clear();
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			frd[a].push_back(b);
			frd[b].push_back(a);
		}
		dfs(0, 0);
		cout << ans << "\n";
	}
}
