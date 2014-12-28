#include <iostream>

long num_layouts(int, int, long[]);

int main(){
	long layouts = 0;
	int n = 49;
	while(layouts < 1000000){
		n++;
		long cache[n + 1];
		memset(cache, 0, sizeof(cache));
		layouts = num_layouts(n, 50, cache);
	}
	std::cout << n << std::endl;
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