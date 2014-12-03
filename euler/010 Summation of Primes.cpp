#include <iostream>
#include "PrimeSieve.hpp"

using namespace std;

#define MAX 2000000

int main(void){
	pe::PrimeSieve<int> s(MAX);
	unsigned long long ans = 0;
	for(int i = 0; i <= MAX; i++){
		if(s[i]) ans += i;
	}

	cout<<(ans)<<endl;
	return 0;
}