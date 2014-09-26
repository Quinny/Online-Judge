#include <iostream>
#include <cmath>

using namespace std;

#define MAX 2000000

void handleMultiples(bool[],int);
int nextPrime(bool[],int);

int main(void){

	bool flags[MAX];
	memset(flags,true,sizeof(flags));

	unsigned long long ans=0;
	int prime=2;

	flags[0]=false;flags[1]=false;

	for(int i=0;i<sqrt(MAX);i++){

		handleMultiples(flags,prime);

		prime=nextPrime(flags,prime);
	}

	for(int i=0;i<MAX;i++){
		if(flags[i]) ans+=i;
	}

	cout<<(ans)<<endl;

	return 0;
}


void handleMultiples(bool flags[],int n){
	
	for(int i=n*n;i<MAX;i+=n) flags[i]=false;
}

int nextPrime(bool flags[],int prime){
	prime++;

	while(!flags[prime]) prime++;

	return prime;
}


