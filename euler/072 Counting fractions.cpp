#include <iostream>
#include <set>
#define D 1000000

int main(){
	long ans = 0;
	int phi[D + 1];
	for(int i = 0; i <= D; i++)
		phi[i] = i;
	for(int i = 2; i <= D; i++){
		if(phi[i] == i){
			for(int j = i; j <= D; j+=i)
				phi[j] = phi[j] / i * (i - 1);
		}
		ans += phi[i];
	}
	std::cout << ans << std::endl;
	return 0;
}