#include <iostream>
#include <algorithm>
#include <string>

#define MAX 1000000

bool checkRotate(int, bool[]);
void handleMultiples(int, bool[]);
int nextPrime(int, bool[]);

int main(void){
	bool primes[MAX+1];
	memset(primes,true,sizeof(primes));
	primes[0]=false;primes[1]=false;
	int prime = 2;

	for(int i = 0; i*i < MAX; i++){
		handleMultiples(prime,primes);
		prime = nextPrime(prime,primes);
	}

	int ans = 0;
	for(int i = 0; i < MAX; i++){
		if(primes[i] && checkRotate(i,primes)) ans++;
	}
	std::cout << ans << std::endl;

	return 0;
}

bool checkRotate(int n, bool primes[]){
	std::string s = std::to_string(n);
	for(int i = 0; i < s.length(); i++){
		std::rotate(s.begin(),s.end()-1,s.end());
		if(!primes[stoi(s)]) return false;
	}
	return true;
}

void handleMultiples(int n, bool primes[]){
	for(int i = n*n; i < MAX; i+=n) primes[i]=false;
}

int nextPrime(int prime, bool primes[]){
	prime++;
	while(!primes[prime]) prime++;
	return prime;
}