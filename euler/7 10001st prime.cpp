#include <iostream>

using namespace std;

void handleMultiples(bool [],int);
int nextPrime(bool[],int);

int main(void){
	bool flags[110000];
	memset(flags,true,sizeof(flags));
	flags[0]=false;flags[1]=false;
	int prime=2;

	for(int i=0;i*i<110000;i++){
		handleMultiples(flags,prime);
		prime=nextPrime(flags,prime);
	}

	int count=0,i;
	for(i=0;count!=10001;i++){
		if(flags[i]) count++;
	}

	cout<<(i-1)<<endl;

}

void handleMultiples(bool flags[],int prime){
	for(int i=prime*prime;i<110000;i+=prime) flags[i]=false;
}

int nextPrime(bool flags[],int prime){
	prime++;
	while(!flags[prime]) prime++;

	return prime;
}