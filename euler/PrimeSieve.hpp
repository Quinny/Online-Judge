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
		int size_;
		bool* primes_;

	public:
		PrimeSieve(int);
		~PrimeSieve(){ delete[] primes_; }

		int primeAfter(int);
		int nthPrime(int);
		bool isPrime(int n){ return primes_[n]; }
		int size(){ return size_; }

		std::vector<int> to_vector();

		bool operator [] (int i) { return primes_[i]; }


	private:
		void elimMultiples(int const&);


};

PrimeSieve::PrimeSieve(int size){
	size_ = size;
	primes_ = new bool[size_];
	for(int i = 0; i < size_; i++)
		primes_[i] = true;
	primes_[0] = false; primes_[1] = false;
	int prime = 2;

	for(int i = 0; i*i < size_; i++){
		elimMultiples(prime);
		prime = primeAfter(prime);
	}
}

void PrimeSieve::elimMultiples(int const& n){
	for(int i = n*n; i < size_; i+=n) primes_[i] = false;
}

int PrimeSieve::primeAfter(int n){
	while(n < size_ && !primes_[++n]);
	if( n >= size_) return 0;
	return n;
}

int PrimeSieve::nthPrime(int n){
	int p = 0;
	for(int i = 0; i < n; i++) p = primeAfter(p);
	return p;
}

std::vector<int> PrimeSieve::to_vector(){
	std::vector<int> v;
	for(int i = 0; i < size(); i++){
		if(primes_[i]) v.push_back(i);
	}
	return v;
}

#endif