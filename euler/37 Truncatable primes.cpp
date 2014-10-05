#include <iostream>

#define MAX 1000000

void handleMultiples(int,bool[]);
int nextPrime(int,bool[]);
int checkR(int, bool[]);
int checkL(int,bool[]);

int main(void){
	bool primes[MAX];
	memset(primes,true,sizeof(primes));
	int prime=2;
	primes[0]=false; primes[1]=false;

	int ans=0;
	
	for(int i=0;i*i<MAX;i++){
		handleMultiples(prime,primes);
		prime=nextPrime(prime,primes);
	}

	for(int i=10;i<MAX;i++){
		if(primes[i] && checkR(i,primes) && checkL(i,primes))
			ans+=i;
	}

	std::cout<<ans<<std::endl;

	return 0;
}

void handleMultiples(int n, bool primes[]){
	for(int i=n*n;i<MAX;i+=n) primes[i]=false;
}

int nextPrime(int prime,bool primes[]){
	prime++;
	while(!primes[prime]) prime++;
	return prime;
}
int checkL(int n,bool primes[]){
	std::string s = std::to_string(n);
	while(s.length()>0){
		if(!primes[std::stoi(s)]) return false;
		s = s.substr(1);
	}
	return true;
}
int checkR(int n,bool primes[]){
	while(n>0){
		if(!primes[n]) return false;
		n/=10;
	}
	return true;
}