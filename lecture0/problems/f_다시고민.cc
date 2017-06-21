#include <iostream>
#define N 10
using namespace std;

int main() {
	int x = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			for (int k = j; k < N; k++) {
				cout << " i : " << i << " j : " << j << " k : " << k << endl;
				x++;
			}
		}
	}
	cout << x << endl;

	return 0;
}