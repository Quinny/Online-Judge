#include <iostream>

bool nChooseR(int,int);

int main(void){
	int ans=0;
	for(int n=2;n<=100;n++){
		int r=n;
		while(r > 0){
			if(nChooseR(n,r))
				ans++;
			r--;
		}
	}
	std::cout<< ans <<std::endl;
	return 0;
}

bool nChooseR(int n, int r){
	double nStart = n;
	double nEnd = (n-r)+1;
	double prod = 1;
	for(double i = nStart; i >= nEnd; i--){
		prod *= i / r;
		r--;
		if(prod > 1000000) return true;
 	}
 	return false;
}