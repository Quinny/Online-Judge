#include <iostream>
#define N 16

long gen_perms(int, bool, bool, bool, long cache[2][2][2][N + 1]);

int main(){
	long cache[2][2][2][N + 1] = {0};
	std::cout << std::uppercase << std::hex << gen_perms(0, false, false, false, cache) << std::endl;
	return 0;
}

long gen_perms(int len, bool zero, bool one, bool a, long cache[2][2][2][N + 1]){
	if(len == N) return zero && one && a;
	if(cache[zero][one][a][len]) return cache[zero][one][a][len];
	int start = 0;
	if(len == 0) start = 1;
	long ans = 0;
	for(int i = start; i < 16; i++)
		ans += gen_perms(len + 1, zero || i == 0, one || i == 1, a || i == 10, cache);
	return cache[zero][one][a][len] = ans;
}