def digits(n):
	c = 0
	while(n > 0):
		c+=1
		n /= 10
	return c

ans = 0
for i in range (1,10):
	j = 1
	while(digits(i ** j) == j):
		ans+=1
		j+=1
print ans