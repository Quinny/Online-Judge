#thanks to this article http://www.had2know.com/academics/nearly-equilateral-heronian-triangles.html
limit = 333333333

v = [5, 65, 901]
while(v[-1] < limit):
	v.append((15 * v[-1]) - (15 * v[-2]) + v[-3]) #watch out for last one
v = v[0:-1]

w = [16, 240, 3360]
while(w[-1] < limit):
	w.append((15 * w[-1]) - (15 * w[-2]) + w[-3])
w = w[0:-1]

print sum(map(lambda x : x * 3 + 1, v)) + sum(map(lambda x : x * 3 + 2, w))