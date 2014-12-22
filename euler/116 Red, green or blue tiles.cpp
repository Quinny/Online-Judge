#include <iostream>
#define SIZE 50

long num_layouts(int, int, long[]);

int main(){
	long ans = 0;
	for(int i = 2; i <= 4; i++){
		long cache[SIZE + 1];
		memset(cache, 0, sizeof(cache));
		ans += num_layouts(SIZE, i, cache);
	}
	std::cout << ans << std::endl;
	return 0;
}

long num_layouts(int total_len, int tile_len, long cache[]){
	if(total_len < tile_len) return 0; // cant fit anymore
	long ans = 0;
	if(cache[total_len]) return cache[total_len];
	for(int i = 0; i <= total_len - tile_len; i++)
		ans += 1 + num_layouts(total_len - tile_len - i, tile_len, cache);
	return cache[total_len] = ans;
}