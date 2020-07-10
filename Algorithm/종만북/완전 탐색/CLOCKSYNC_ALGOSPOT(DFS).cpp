#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int arr[16], ans;// 시간에 따른 모든 경우의 수 저장

const int sw[10][16] = { // 이거 말고도 MAX를 설정할 수 있는 건 고정하자, 스위치 수, 시계수 등등
	{1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,0},
	{0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,1},
	{1,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,1,1,1,0,1,0,1,0,0,0},
	{1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1},
	{0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,1},
	{0,0,0,0,1,1,0,1,0,0,0,0,0,0,1,1},
	{0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,1,1,1,0,0,0,1,0,0,0,1,0,0}
}; //스위치 

void dfs(int num, int cnt) {
	if (num >= 10) {
		int ch = 1;
		for (int i = 0; i < 16; i++) if (arr[i] % 12) ch = 0;
		if (ch) ans = min(ans, cnt);
		return;
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 16; j++) if (sw[num][j]) arr[j] += 3 * i;// for 문 변수명 더 잘 써야 될듯
		dfs(num + 1, cnt + i);
		for (int j = 0; j < 16; j++) if (sw[num][j]) arr[j] -= 3 * i;
	}
	
}

int main() { 
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;// testcase
	cin >> t;
	while (t--) {
		ans = 987654321;
		for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) cin >> arr[i * 4 + j];
		dfs(0, 0);
		if(ans!=987654321) cout << ans << "\n";
		else cout << "-1\n"; // 예외처리 안해서 틀림
	}
}
