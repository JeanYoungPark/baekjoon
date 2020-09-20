#include <iostream>
using namespace std;

long long int fs(long long A, long long B, long long C) {
	if (!B) return 1;
	long long val = fs(A,B/2,C);
	val = val * val * C;

	if (B % 2) return val * A % C;
	else return val;
}

int main()
{
	long long int A, B, C;
	cin >> A >> B >> C;
	cout << fs(A, B, C);
}

//https://www.acmicpc.net/problem/1629