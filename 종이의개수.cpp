#include <iostream>
using namespace std;

int N, paper[2187][2187] = { 0 }, num, cnt[3] = {0};
bool chk = true;

void fs(int size, int x, int y) {
	if (size == 1) {
		cnt[paper[y][x] + 1]++;
		return;
	}

	chk = true;

	for (int i = y; i < y + size; i++)
	{
		for (int j = x; j < x + size; j++) {
			if (i == y && j == x) num = paper[i][j];
			else if (num != paper[i][j]) {
				chk = false;
				break;
			}
		}
		if (!chk) break;
	}

	if (chk) {
		cnt[num + 1]++;
	}
	else {
		int tmp = size/3;

		fs(tmp, x, y);
		fs(tmp, x + tmp, y);
		fs(tmp, x + tmp * 2, y);

		fs(tmp, x, y + tmp);
		fs(tmp, x + tmp, y + tmp);
		fs(tmp, x + tmp * 2, y + tmp);

		fs(tmp, x, y + tmp * 2);
		fs(tmp, x + tmp, y + tmp * 2);
		fs(tmp, x + tmp * 2, y + tmp * 2);
	}
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++) {
			cin >> paper[i][j];
		}
	}

	fs(N, 0, 0);

	for (int i = 0; i < 3; i++) {
		cout << cnt[i] << '\n';
	}
}