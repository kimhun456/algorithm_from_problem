
/*
    cpp style
    use reference value
*/
void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

/*
    C style
    use pointer value
*/ 
void swap2(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

