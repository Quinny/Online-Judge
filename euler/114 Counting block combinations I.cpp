#include <iostream>
#define SIZE 50

long num_layouts(int, int, long[]);

int main(){
	long cache[SIZE + 1] = {0};
	std::cout << num_layouts(SIZE, 3, cache) << std::endl;
	return 0;
}

long num_layouts(int total_len, int tile_len, long cache[]){
	if(total_len < 0) return 1; // run out of space
	if(cache[total_len]) return cache[total_len];
	long ans = 1; // there is always a possibilty of filling up all blacks
	for(int i = 0; i <= total_len - tile_len; i++){
		for(int j = tile_len; j <= total_len - i; j++)
			ans += num_layouts(total_len - i - j - 1, tile_len, cache); // minus 1 for black inbetween
	}
	return cache[total_len] = ans;
}