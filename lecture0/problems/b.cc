int all_is(int arr[], int arr_len , int k) {

	for (int i = 0; i < arr_len; i++) {
		if (arr[i] != k) {
			return 0;
		}
	}
	return 1;
}