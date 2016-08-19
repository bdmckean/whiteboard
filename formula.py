#!/usr/bin/env python3

def fadd(a,b):
	return (a+b)

def fsub(a,b):
	return (a-b)

def fdiv(a,b):
	return (a/b)

def fmul(a,b):
	return (a*b)

func = [fadd, fsub, fdiv, fmul]
fs = ['+','-','/','*']

nums,v = map(int,input().split(','))

a = int((nums/100)) 
b = int((nums/10)) %10
c = nums % 10

print(a,b,c,v)

for i in range(4):
	for j in range(4):
		if j == i: continue
		x = (func[i](a,b))
		y = (func[j](x,c))
		if y == v:
			print(a,fs[i],b,fs[j],c,"=",v)
		else:
			print(a,fs[i],b,fs[j],c,"=",y,"==>!=",v)




 
