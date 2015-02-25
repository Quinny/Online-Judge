def max(a, b):
	if a > b:
		return a
	else:
		return b

def r(a, n):
	return ((a - 1) ** n + (a + 1) ** n) % a ** 2

def max_r(a):
	first = r(a, 1)
	m = max(first, r(a, 2))
	n = 3
	tmp = r(a, n)
	while tmp != first:
		n += 2
		tmp = r(a, n)
		m = max(tmp, m)
	return max(m, r(a, n + 2))

print sum(map(max_r, range(3, 1001)))
