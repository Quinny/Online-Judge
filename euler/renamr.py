import os

for f in os.listdir("."):
	toks = f.split(" ")
	if len(toks) > 1:
		n = "0" * (3 - len(toks[0])) + toks[0]
		new_name =  n + " " + " ".join(toks[1:])
		os.system("mv \"" + f + "\" \"" + new_name +"\"")
		#print new_name