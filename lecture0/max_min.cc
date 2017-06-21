
int min(int x, int y){

    if(x < y)
        return x;
    return y;
}

int max(int x, int y){
    if(x > y){
        return x;
    }
    return y;
}

#define max(x,y) ((x) > (y) ? (x) : (y))
#define min(x,y) ( (x) < (y) ? (x) : (y))


int max_arr2(int arr[], int arr_len) {
	if (arr_len == 1) {
		return arr[0];
	}
	else
		return max(arr[arr_len - 1], max_arr2(arr, arr_len - 1));
}

int main() {

	int a[10001];
	for (int i = 0; i < 10001; i++) {
		a[i] = i;
	}

	max_arr2(a, 10000);


	return 0;
}