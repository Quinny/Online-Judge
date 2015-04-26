#include <iostream>
#define LIMIT 120000

// generation of co - primes found here http://en.wikipedia.org/wiki/Coprime_integers#Generating_all_coprime_pairs

void co_primes(long, long, long rad[]);
int sum = 0;

int main(){
	long rad[LIMIT + 1]; // Sieve the radicals
	for (long i = 0; i <= LIMIT; i++)
	    rad[i] = 1;
	for (long i = 2; i < LIMIT; i++){
    	if (rad[i] == 1) {
        	rad[i] = i;
        	for (long j = i + i; j < LIMIT; j += i)
            	rad[j] *= i;
        }
    }
	co_primes(3, 1, rad); // generate all odd-odd coprime pairs
	co_primes(2, 1, rad); // generate all even-odd coprime pairs
	std::cout << sum << std::endl;
	return 0;
}

void co_primes(long m, long n, long rad[]){
	if(m + n >= 120000) return;
	long c = m + n;
	if(rad[m] * rad[n] * rad[c] < c) sum += c;
	co_primes(2 * m - n, m, rad);
	co_primes(2 * m + n, m, rad);
	co_primes(m + 2 * n, n, rad);
}
