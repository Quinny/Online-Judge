#include <iostream>
#define MAX 1000000

void handleMultiples(int, bool[]);
int nextPrime(int, bool[]);

int main(void){
	bool primes[MAX+1];
	memset(primes,true,sizeof(primes));
	primes[0]=false; primes[1]=false;

	int prime=2;

	for(int i=0;i*i<MAX;i++){
		handleMultiples(prime,primes);
		prime=nextPrime(prime,primes);
	}

	int sum = 0;
	int terms = 0;
	int n = 0;
	int maxTerms = 0;
	for(int i=0;i<MAX;i++){
		for(int j=i;j<MAX;j++){
			if(primes[j]){
				sum+=j;
				terms++;
			}
			if(sum >= MAX) break;
			if(primes[sum]){
				if(terms > maxTerms){
					maxTerms = terms;
					n = sum;
				}
			}
		}
		sum = 0;
		terms = 0;
	}
	std::cout<<n<<std::endl;
}

void handleMultiples(int prime, bool primes[]){
	for(int i=prime*prime;i<MAX;i+=prime) primes[i]=false;
}
int nextPrime(int prime, bool primes[]){
	prime++;
	while(!primes[prime]) prime++;
	return prime;
}