from decimal import getcontext, Decimal
getcontext().prec = 102
total = 0
for i in range(2, 100):
	x = Decimal(i).sqrt()
	y = str(x * (10**99))[:100]
	tmp = reduce(lambda x, y: int(x) + int(y), list(y))
	if tmp > 10:
		total += tmp
print total