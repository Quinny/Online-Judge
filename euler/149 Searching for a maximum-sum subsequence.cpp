#include <iostream>
#define SIZE 2000

long kadanes_in_dir(long **a, int i, int j, int dx, int dy);

int main(){
	long **a = new long*[SIZE]; // have to allocate on free store cause stack cant handle it
	for(int i = 0; i < SIZE; i++)
		a[i] = new long[SIZE];
	long *s = new long[SIZE * SIZE + 1];
	long k = 1; // k has to be a long for multiplication with other longs.  CAUSED ME LOTS OF F*&^%KING GRIEF. remeber this.
	int mod = 1000000;
	for(int i = 0; i < SIZE; i++){
		for(int j = 0; j < SIZE; j++){
			if(k <= 55)
				s[k] = ((100003 - 200003 * k + 300007 * k * k * k) % mod + mod) % mod - 500000;
			else
				s[k] = ((s[k - 24] + s[k - 55] + 1000000) % mod + mod) % mod - 500000;
			a[i][j] = s[k];
			k++;
		}
	}
	delete[] s;
	long max = 0;
	for(int i = 0; i < SIZE; i++){
		max = std::max(max, kadanes_in_dir(a, i, 0, 0, 1)); // horizontal
		max = std::max(max, kadanes_in_dir(a, 0, i, 1, 0)); // vertical 
		max = std::max(max, kadanes_in_dir(a, 0, i, 1, 1)); // right down colwise
		max = std::max(max, kadanes_in_dir(a, SIZE - 1, i, -1, -1)); // from bottom left up
	}
	std::cout << max << std::endl;
	for(int i = 0; i < SIZE; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}

long kadanes_in_dir(long **a, int i, int j, int dx, int dy){
	long cur = a[i][j], max = cur;
	i += dx; j += dy;
	while(i + dx <= SIZE && i + dx >= 0 && j + dy <= SIZE && j + dy >= 0){
		cur = std::max(cur + a[i][j], 0L);
		max = std::max(cur, max);
		i += dx; j += dy;
	}
	return max;
}