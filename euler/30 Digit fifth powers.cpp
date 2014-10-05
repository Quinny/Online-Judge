#include <iostream>
#define MAX 500000

bool isValid(int);

int main(void){
	int ans;
	for(int i=2;i<MAX;i++){
		if(isValid(i))
			ans+=i;
	}
	
	std::cout<<ans<<std::endl;

	return 0;	
}

bool isValid(int n){
	int sum=0;
	int tmp=n;
	while(tmp>0){
		int d=tmp%10;
		int tmp2=d;
		for(int i=0;i<4;i++)
			d*=tmp2;
		sum+=d;
		tmp/=10;
	}
	return sum == n;
}