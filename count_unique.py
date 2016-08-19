#!/usr/bin/env python


x =  set()

def count_unique( s):
	for i in range(1 ,len(s)):
		x.add(s[i])
	print "They are:",
	print x
	return len(x)	
	

s = "This is a string with letters"

count = count_unique(s)

print "count is "+str(count)
	
print "They are:",
print x

y = set(s)
print y
