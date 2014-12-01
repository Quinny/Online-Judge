def digits(n):
	d = 0
	while(n > 0):
		d+=1
		n /= 10
	return d

n = 3
d = 2
ans = 0
for i in range(1000):
	if digits(n) > digits(d):
		ans += 1
	n = n + (d * 2)
	d = n - d
print ans