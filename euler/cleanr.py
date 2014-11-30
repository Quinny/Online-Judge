f = open("test.txt").readlines()
for line in f:
	print " ".join(line.replace("-","-1").replace("\n","").split(","))
