#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int t, h, w, arr[25][25], ans;
const int LBlock[4][2][2] = {  // 이거 만드는 거 개고생함, 케이스 나눌때 가지치기 할 수 있게 나누기!
	{{1,0},{0, 1}},
	{{1,0},{1,1}},
	{{0,1},{1,1}},
	{{0,1},{-1 ,1}}
};

void dfs(int height, int width, int cnt) {
	//cout << "going1 " << height << " " << width << " " << cnt << "  ans  " << ans << "\n";
	if (cnt == 0) {
		ans++;
		return;
	}
	if (height >= h || width >= w) return;
	if (!arr[height][width]) {
		if (width == w - 1) dfs(height + 1, 0, cnt);
		else dfs(height, width + 1, cnt);
		return;
	}
	//cout << "going " << height << " " << width << " " << cnt << "  ans  " << ans << "\n";
	arr[height][width] = 0;
	for (int i = 0; i < 4; i++) {
		int nexth[2], nextw[2];
		int ch = 0;
		for (int j = 0; j < 2; j++) {
			nexth[j] = height + LBlock[i][j][1];
			nextw[j] = width + LBlock[i][j][0];
			//cout << nexth[j] << "  " << nextw[j] << "  hihi\n";
			if (nexth[j] >= 0 && nexth[j] < h && nextw[j] >= 0 && nextw[j] < w && arr[nexth[j]][nextw[j]]) ch++;
		}
		if (ch == 2) {
			for (int j = 0; j < 2; j++) arr[nexth[j]][nextw[j]] = 0;
			if (width == w - 1) dfs(height + 1, 0, cnt - 3);
			else dfs(height, width + 1, cnt - 3);
			for (int j = 0; j < 2; j++) arr[nexth[j]][nextw[j]] = 1;
		}
	}
	arr[height][width] = 1;
}

int main() { 
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> h >> w;
		ans = 0;
		int cnt = 0;
		for (int i = 0; i < h; i++) {
			string tmp;
			cin >> tmp;
			for (int j = 0; j < w; j++) {
				if (tmp[j] == '#') arr[i][j] = 0;
				else {
					arr[i][j] = 1;
					cnt++;
				}
			}
		}
		if (cnt % 3) cout << "0\n"; // 예외처리 
		else {
			dfs(0, 0, cnt);
			cout << ans << "\n";
		}
	}
}
