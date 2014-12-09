def minify(s):
	replace =[
		("VIIII", "IX"), # simplify 9
		("IIII", "IV"), # simplify 4
		("LXXXX", "XC"), # simplify 90
		("XXXX", "XL"), # 40
		("DCCCC", "CM"),
		("CCCC", "CD")
	]
	for a, b in replace:
		s = s.replace(a, b);
	return s

f = open("roman.txt").readlines()
savings = 0
for line in f:
	savings += len(line) - len(minify(line))
print savings