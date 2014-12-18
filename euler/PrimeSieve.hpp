/*

Quinn Perfetto

Another helper class spawned by project euler.
There are a ton of questions that deal with prime numbers, and I found myself re-writing the code for
generate a sieve of eratosthenes, so I decided to make a class for it.

Important things to note:

- The prime_after function will return 0 if it doesn't find another prime within the range
- The sieve will be generated from numbers 1...size_, not primes 1...size_
- The class is templated for the size you require.  If you need more than 2 billion primes dont use int
- The copy constructor has been omitted because its expensive, I would suggest passing by reference.  This class
cannot be modified anyways

*/

#ifndef QP_PRIME_SIEVE_H__
#define QP_PRIME_SIEVE_H__

#include <vector>
#include <bitset>

namespace pe{ // project euler namespace

template <typename size_type = int>
class PrimeSieve{
	private:
		size_type size_;
		std::vector<bool> primes_;

	public:
		PrimeSieve(size_type);
		PrimeSieve operator=(PrimeSieve) = delete;
		static std::vector<size_type> make_vector(size_type s){
			PrimeSieve<size_type> p(s);
			return p.to_vector();
		}

		size_type next_prime(size_type);
		size_type nth_prime(const size_type);
		bool is_prime(const size_type n){ return primes_[n]; }
		size_type size(){ return size_; }

		std::vector<size_type> to_vector();

		bool operator [] (const size_type i) { return primes_[i]; }


	private:
		void elim_mult(const size_type);


};

template <typename size_type>
PrimeSieve<size_type>::PrimeSieve(const size_type size){
	size_ = size + 1;
	primes_.reserve(size_);
	for(size_type i = 0; i < size_; i++)
		primes_[i] = true;
	primes_[0] = false; primes_[1] = false;
	size_type prime = 2;

	for(size_type i = 0; i * i < size_; i++){
		elim_mult(prime);
		prime = next_prime(prime);
	}
}

template <typename size_type>
void PrimeSieve<size_type>::elim_mult(const size_type n){
	for(size_type i = n*n; i < size_; i+=n) primes_[i] = false;
}

template <typename size_type>
size_type PrimeSieve<size_type>::next_prime(size_type n){
	while(n < size_ && !primes_[++n]);
	if( n >= size_) return 0;
	return n;
}

template <typename size_type>
size_type PrimeSieve<size_type>::nth_prime(const size_type n){
	size_type p = 0;
	for(size_type i = 0; i < n; i++) p = next_prime(p);
	return p;
}

template <typename size_type>
std::vector<size_type> PrimeSieve<size_type>::to_vector(){
	std::vector<size_type> v;
	for(size_type i = 0; i < size(); i++){
		if(primes_[i]) v.push_back(i);
	}
	return v;
}

}

#endif