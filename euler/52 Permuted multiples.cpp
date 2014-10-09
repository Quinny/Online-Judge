#include <iostream>

bool isPermutation(int, int);

int main(void){
	int check = 2;

	while(true){
		bool found=true;
		for(int i = 1;i <= 6;i++)
			found = found && isPermutation(check,check*i);
		if(found) break;
		check++;
	}

	std::cout<<check<<std::endl;

	return 0;
}

bool isPermutation(int n, int m){
	int occur[10];
	memset(occur,0,sizeof(occur));

	while( n > 0 ){
		occur[n%10]++;
		n/=10;
	}

	while( m > 0 ){
		occur[m%10]--;
		m/=10;
	}

	for(int i=0;i<10;i++){
		if( occur[i]!=0 ) return false;
	}

	return true;
}
