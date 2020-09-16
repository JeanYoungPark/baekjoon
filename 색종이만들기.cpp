#include <iostream>
using namespace std;

int N, paper[128][128] = { 0 }, white = 0, blue = 0;

void fs(int size, int x, int y) {
	int color[2] = { 0 };

	for (int i = y; i < y+size; i++)
	{
		for (int j = x; j < x+size; j++) {
			color[paper[i][j]]++;
		}
		if (color[0] > 0 && color[1] > 0) break;
	}

	if (color[0] == size*size) {
		white++;
		return;
	}
	else if (color[1] == size * size) {
		blue++;
		return;
	}
	else {
		fs(size / 2, x, y);
		fs(size / 2, x + size / 2, y);
		fs(size / 2, x, y + size / 2);
		fs(size / 2, x + size / 2, y + size / 2);
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

	fs(N,0,0);
	cout << white << '\n' << blue;
}