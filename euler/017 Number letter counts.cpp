#include <iostream>
#include <map>

int main(void){
	std::map<int, int> lengths{
		{0,0},
		{1,3},
		{2,3},
		{3,5},
		{4,4},
		{5,4},
		{6,3},
		{7,5},
		{8,5},
		{9,4},
		{10,3},
		{11,6},
		{12,6},
		{13,8},
		{14,8},
		{15,7},
		{16,7},
		{17,9},
		{18,8},
		{19,8},
		{20,6},
		{30,6},
		{40,5},
		{50,5},
		{60,5},
		{70,7},
		{80,6},
		{90,6},
		{100,7},
		{1000,8}
	};

	int ans = 0;
	for(int i = 1; i <= 1000; i++){
		int n = i;
		if(n >= 100 && n < 1000){
			ans += lengths[n/100];
			ans += lengths[100];
			if(n % 100 == 0) n = 0;
			else{
				n %= 100;
				ans += 3; // and
			}
		}
		if(n <= 20)
			ans += lengths[n];
		if(n > 20 && n < 100){
			ans += lengths[(n/10) * 10];
			ans += lengths[n % 10];
		}
		if(n == 1000)
			ans += lengths[n/1000] + lengths[1000];
	}
	
	std::cout << ans << std::endl;
	return 0;
}