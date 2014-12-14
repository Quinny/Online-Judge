import prime_sieve

def r(pn, n):
	return 2 * pn * n

n = 2
primes = prime_sieve.make(1000000)
while(r(primes[n - 1], n) < 10 ** 10):
	n += 1
print primes[-1]
print n + 1