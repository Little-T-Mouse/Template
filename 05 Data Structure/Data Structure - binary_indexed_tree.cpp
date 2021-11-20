// 1D BIT update:
void update(int idx, int val) {
	for(int i=idx; i < limit; i += i & -i ) {
		bit[i] += val;
	}
}

// 2D BIT update:  // O(logn * logn)
void update(int r, int c, int val ) { 
	for(int i = r; i < row_limit; i += i & -i ) 
		for(int j = c; j < col_limit; j += j & -j ) 
			bit[i][j] += val;
}

// 1D BIT query:
int query (int idx ) { 
	int sum = 0;
	for(int i = idx;   i > 0; i -= i & -i ) {
		sum += bit[i];
	}
	return sum;
}

// 2D BIT query: // O(logn* logn) 
int query (int r, int c) { 
	int sum = 0;
	for(int i = r;   i > 0; i -= i & -i ) {
		for(int j=c; j>0; j -= j&-j){
			sum += bit[i][j];
		}
	}
	return sum;
}
