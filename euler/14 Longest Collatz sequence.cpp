#include <iostream>

#define LIMIT 1000000
using namespace std;

int collatz(long long,int[]);

int main(void){

	int cache[LIMIT+1];
	memset(cache,-1,sizeof(cache));

	int max=0;
	int n=0;

	for(int i=2;i<LIMIT;i++){
		int tmp=collatz(i,cache);
		if(tmp>max){
			max=tmp;
			n=i;
		}
	}

	cout<<n<<endl;

	return 0;
}


int collatz(long long n,int cache[]){
	int len=0;
	long long m=n;
	while(m!=1){

		if(m<LIMIT && cache[m]!=-1){
			len=cache[m]+len;
			break;
		}

		if(m%2==0)m/=2;
		else m=3*m+1;
		len++;
	}
	cache[n]=len;
	return len;
}