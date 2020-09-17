#include <vector>
#include <iostream>
using namespace std;

string tmp;
int N, paper[128][128] = { 0 };
vector <string> vec;

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
		vec.push_back("0");
		return;
	}
	else if (color[1] == size * size) {
		vec.push_back("1");
		return;
	}
	else {
		vec.push_back("(");
		fs(size / 2, x, y);
		fs(size / 2, x + size / 2, y);
		fs(size / 2, x, y + size / 2);
		fs(size / 2, x + size / 2, y + size / 2);
		vec.push_back(")");
	}
}

int main()
{
    cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		for (int j = 0; j < tmp.length(); j++) {
			paper[i][j] = tmp[j] - '0';
		}
	}

	fs(N,0,0);
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i];
	}
}