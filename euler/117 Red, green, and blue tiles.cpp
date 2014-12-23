#include <iostream>
#define SIZE 50
#define N_TILES 4

long num_layouts(int, const int[], long[]);

int main(){
	const int tile_lens[] = {1, 2, 3, 4};
	long cache[SIZE + 1] = {0};
	std::cout << num_layouts(SIZE, tile_lens, cache) << std::endl;
	return 0;
}

long num_layouts(int total_len, const int tile_lens[], long cache[]){
	if(total_len < 0) return 0; // we used to many, cant count it
	if(total_len == 0) return 1; // cant fit anymore, count it
	if(cache[total_len]) return cache[total_len];
	long ans = 0;
	for(int i = 0; i < N_TILES; i++)
		ans += num_layouts(total_len - tile_lens[i], tile_lens, cache);
	return cache[total_len] = ans;
}