import sys

SIZE = 80

f = open("test.txt").readlines()
weights = []
for line in f:
	l = [int(i) for i in line.split(",")]
	weights.append(l)

def adjacent_nodes(m, u):
	nodes = set()
	if u[0] != 0: # UP
		nodes.add((u[0] - 1, u[1]))
	if u[0] < SIZE - 1: #DOWN
		nodes.add((u[0] + 1, u[1]))
	if u[1] < SIZE - 1: # RIGHT
		nodes.add((u[0], u[1] + 1))
	if u[1] != 0:
		nodes.add((u[0], u[1] - 1)) #LEFT
	return nodes


def dijkstra(m, start):
	dists = {None: sys.maxint}
	previous = {}
	unvisited = set()
	for row in xrange(len(m)):
		for col in xrange(len(m[row])):
			dists[(row,col)] = sys.maxint #initialize all distances to infinity
			previous[(row, col)] = None #start the parents at null
			unvisited.add((row, col)) #havent seen it yet
	dists[start] = m[start[0]][start[1]] # we know the weight of the start

	while unvisited:
		u = None
		for node in unvisited:
			if dists[node] < dists[u]: #find the smallest unvisited node
				u = node
		unvisited.discard(u)

		# intersect the unvisited nodes with the ajacent to minimal ones
		verts = unvisited & adjacent_nodes(m, u)
		for v in verts:
			new_dist = dists[u] + m[v[0]][v[1]] #relaxing, just like muhko
			if new_dist < dists[v]:
				dists[v] = new_dist
				previous[v] = u

	return previous 

def sum_path(m, prev, end):
	s = 0;
	if end not in prev:
		return sys.maxint
	while end:
		s += m[end[0]][end[1]]
		end = prev[end]
	return s

path = dijkstra(weights, (0,0))
ans = sum_path(weights, path, (SIZE - 1, SIZE -1))
print ans