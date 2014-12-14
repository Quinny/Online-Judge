def next_prime(p ,s):
	p += 1
	while(not s[p]):
		p += 1
	return p

def make(n):
	s = [True for i in range(n + 1)]
	s[0] = False
	s[1] = False
	p = 2
	i = 0
	while i * i <= n:
		for j in range (p * p, len(s), p):
			s[j] = False
		p = next_prime(p, s)
		i += 1
	return [i for i in range(len(s)) if s[i]]