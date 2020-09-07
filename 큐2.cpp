#include <queue>
#include <iostream>
using namespace std;

int main() {
	int N, num;
	string order;
	queue <int> que;
	cin >> N;
	for ( i = 0; i < N; i++)
	{
		cin >> order;
		if (order == "push") {
			cin >> num;
			que.push(num);
		}
		else if (order == "pop") {
			if (!que.empty()) {
				cout << que.front() << '\n';
				que.pop();
			}
			else cout << -1;
		}
		else if (order == "size") cout << que.size() << '\n';
		else if (order == "empty") cout << (!que.empty() ? 0 : 1) << '\n';
		else if (order == "front") cout << (!que.empty() ? que.front() : -1) << '\n';
		else if (order == "back") cout << (!que.empty() ? que.back() : -1) << '\n';
	}
}