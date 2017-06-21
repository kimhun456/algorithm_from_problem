#include <iostream>
#define N 10
using namespace std;

void print_10_to_2(int num) {
	if (num == 1) {
		cout << "1";
		return;
	}
	if (num == 0) {
		cout << "0";
		return;
	}
	if (num % 2 == 1) {
		print_10_to_2(num / 2);
		cout << "1";
	}
	else {
		print_10_to_2(num / 2);
		cout << "0";
	}

}

int main() {
	int n;
	cin >> n;

	print_10_to_2(n);

	cout << endl;
	return 0;
}