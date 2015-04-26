#ifndef QP_PRIME_SIEVE_H__
#define QP_PRIME_SIEVE_H__

#include <bitset>
#include <vector>

namespace pe {

using size_type = unsigned long;

template <size_type SIZE>
class PrimeSieve {
	private:
		std::bitset<SIZE> primes_;

	public:
		PrimeSieve();
		PrimeSieve operator=(PrimeSieve) = delete;

		size_type next_prime(size_type) const;
		constexpr size_type size() const { return SIZE; }

		bool operator[] (const size_type i) const { return primes_[i]; }

		std::vector<size_type> to_vector() const;
		static std::vector<size_type> make_vector(){
			PrimeSieve<SIZE> p;
			return p.to_vector();
		}

	private:
		void elim_multi(const size_type);
};

template<size_type SIZE>
PrimeSieve<SIZE>::PrimeSieve(){
	primes_.set();
	primes_[0] = 0; primes_[1] = 0;
	size_type prime = 2;
	for(size_type i = 0; i * i < SIZE; i++){
		elim_multi(prime);
		prime = next_prime(prime);
	}
}

template<size_type SIZE>
void PrimeSieve<SIZE>::elim_multi(const size_type n){
	for(size_type i = n * n; i < SIZE; i += n) primes_[i] = 0;
}

template<size_type SIZE>
size_type PrimeSieve<SIZE>::next_prime(size_type n) const{
	while(n < SIZE && !primes_[++n]);
	return n;
}

template<size_type SIZE>
std::vector<size_type> PrimeSieve<SIZE>::to_vector() const {
	std::vector<size_type> v(primes_.count());
	unsigned long c = 0;
	for(size_type i = 0; i < SIZE; i++){
		if(primes_[i])
			v[c++] = i;
	}
	return v;
}

}
#endif
