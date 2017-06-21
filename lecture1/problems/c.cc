

int print_1(int num) {
	int one_count = 0;
	while (num) {
		if (num % 2 == 1) {
			one_count++;
		}
		num /= 2;
	}
	return one_count;
}
