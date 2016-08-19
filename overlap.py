#!/usr/bin/env python


class mydate:
	def __init__(self, m, d, y):
		self.month = m
		self.day = d
		self.year = y

class myrange:
	def __init__(self,x,y):
		self.start = x
		self.end = y


def overlap(x,y):
	o = False
	while(1):
		if ( x.start.year > y.end.year): break
		if ( y.start.year > x.end.year): break
		if ( x.start.month > y.end.month): break
		if ( y.start.month > x.end.month): break
		if ( x.start.day > y.end.day): break
		if ( y.start.day > x.end.day): break
		o = True
		break
	return o

a = myrange(mydate(1,1,2000),mydate(1,29,2010))

b = myrange(mydate(1,30,2010),mydate(12,31,2013))


ans = overlap(a,b)

print "answer = "+str(ans)


	
	
