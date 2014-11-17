#include <iostream>

/*

192
442
692
942
1192
1442
1692
1942
2192
2442
2692

I wrote a simple python script to find the first couple of number which satisfy this property.
I noticed that they were always exactly 250 apart, Interesting.

*/

int main(){
	int n;
	std::cin >> n;
	while(n--){
		long long k;
		std::cin >> k;
		long long ans = 192 + (250 * (k - 1));
		std::cout << ans << std::endl;
	}
	return 0;
}