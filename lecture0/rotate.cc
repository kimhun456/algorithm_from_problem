#include <iostream>

using namespace std;



void right_rotate(int arr[], int s, int e) {
	int i, last;

	last = arr[e];

	for (int i = e; i > s; i--) {
		arr[i] = arr[i - 1];
	}
	arr[s] = last;

}

void left_rotate(int arr[], int s, int e) {
	int first = arr[s];
	for (int i = s; i < e; i++) {
		arr[i] = arr[i + 1];
	}
	arr[e] = first;
}

/*
    temp 배열에 로테이트 시킬 배열을 미리 저장한 후에

    i+k 만큼 로테이트 시킨 값을 넣어준다.

*/
void right_rotate_k(int arr[], int s, int e, int k) {

	int temp[10];

	for (int i = s; i <= e; i++) {
		temp[i] = arr[i];
	}
	for (int i = s; i <= e; i++) {
		if (i + k <= e) {
			arr[i + k] = temp[i];
		}
		else {
			arr[i + k - e + s - 1] = temp[i];
		}
	}
}

int main() {
	int arr[10];

	for (int i = 0; i < 10; i++) {
		arr[i] = i;
	}

	right_rotate_k(arr, 0, 9, 1);
	

	for (int i = 0; i < 10; i++) {
		cout << arr[i] << endl;
	}


	return 0;
}