import math
for i in range(int(raw_input())):x=float(raw_input());print round(sum([((-1)**i)*(x**(2*i+1))/math.factorial(2*i+1)for i in range(5)]),3);print round(sum([((-1)**i)*(x**(2*i))/math.factorial(2*i)for i in range(5)]),3)
