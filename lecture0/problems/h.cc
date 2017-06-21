#include <iostream>

using namespace std;

void find_i_and_j(int arr[], int n, int p) {

	int sum[20];
	for (int i = p; i >= 0; i--) {
		if (i == p) {
			sum[i] = arr[p];
			continue;
		}
		sum[i] = sum[i + 1] + arr[i];
	}

	for (int i = p; i < n; i++) {
		if (i == p) {
			sum[i] = arr[p];
			continue;
		}
		sum[i] = sum[i - 1] + arr[i];
	}

	int max_less_p = 0;
	int max_i;
	int max_more_p = 0;
	int max_j;

	for (int i = 0; i <= p; i++) {
		if (sum[i] > max_less_p) {
			max_less_p = sum[i];
			max_i = i;
		}
	}
	for (int i = p; i < n; i++) {
		if (sum[i] > max_more_p) {
			max_more_p = sum[i];
			max_j = i;
		}
	}

	cout << " i : " << max_i << " j : " << max_j << endl;
}


int main() {


	int arr[30] = { 0,1,-23,41,23,1,-23,21,-2,3,-12,-3,5,6,3 - 1,23 };

	find_i_and_j(arr, 17, 4);

	return 0;
}