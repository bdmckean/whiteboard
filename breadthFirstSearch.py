#!/usr/bin/env python
import Queue


class Btree(object):
	def __init__(self, v = 0):
		self.value = v
		self.left = None
		self.right = None

def find_in_tree(tree, value):
	q = Queue.Queue()
	q.put(tree)

	while (q.qsize()):
		x = q.get()
		print x
		if (x.value ==value): return True
		if (x.left is not None): q.put(x.left)
		if (x.right is not None): q.put(x.right)

	return False 


root = Btree(6)



if (find_in_tree(root, 6)):
	print "Found"
else:
	print "Not found"




