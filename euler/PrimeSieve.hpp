/*

Quinn Perfetto

Another helper class spawned by project euler.
There are a ton of questions that deal with prime numbers, and I found myself re-writing the code for
generate a sieve of eratosthenes, so I decided to make a class for it.

Important things to note:

- The primeAfter function will return 0 if it doesn't find another prime within the range
- The sieve will be generated from numbers 1...size_, not primes 1...size_
- The class DOES have a destructor, so if you are passing it around to functions PASS BY REFERENCE.  2 reasons:
	- copying is expensive
	- you shouldn't be modifying it
	- the destructor triggering prematurely may cause undefined behaviour

*/

#ifndef QP_PRIME_SIEVE_H__
#define QP_PRIME_SIEVE_H__

#include <vector>

class PrimeSieve{
	private:
		long long size_;
		bool* primes_;

	public:
		PrimeSieve(long long);
		~PrimeSieve(){ delete[] primes_; }

		int primeAfter(long long);
		int nthPrime(long long);
		bool isPrime(long long n){ return primes_[n]; }
		int size(){ return size_; }

		std::vector<long long> to_vector();

		bool operator [] (long long i) { return primes_[i]; }


	private:
		void elimMultiples(long long const&);


};

PrimeSieve::PrimeSieve(long long size){
	size_ = size;
	primes_ = new bool[size_];
	for(long long i = 0; i < size_; i++)
		primes_[i] = true;
	primes_[0] = false; primes_[1] = false;
	int prime = 2;

	for(long long i = 0; i * i < size_; i++){
		elimMultiples(prime);
		prime = primeAfter(prime);
	}
}

void PrimeSieve::elimMultiples(long long const& n){
	for(long long i = n*n; i < size_; i+=n) primes_[i] = false;
}

int PrimeSieve::primeAfter(long long n){
	while(n < size_ && !primes_[++n]);
	if( n >= size_) return 0;
	return n;
}

int PrimeSieve::nthPrime(long long n){
	long long p = 0;
	for(long long i = 0; i < n; i++) p = primeAfter(p);
	return p;
}

std::vector<long long> PrimeSieve::to_vector(){
	std::vector<long long> v;
	for(long long i = 0; i < size(); i++){
		if(primes_[i]) v.push_back(i);
	}
	return v;
}

#endif