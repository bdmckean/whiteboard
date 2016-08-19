#!/usr/bin/env python

array = [2,4,5,9,1,3,27,52,45,46,47,48,7,8,9,11]
vector = []
length = len(array)
longest = 0
thisLength = 1
lastNum = -1
count = 0
count2 = 0
for i in range(length):
    if (count == 0): 
    	vector.append( [array[count ]] )
        count += 1
        continue
    l = 0
    temp = [array[count]]
    print "D0:",vector,temp
    for j in vector:
    	print "D1:",j, array[count]
        if (j[-1] < array[count] and l < len(j)):
            l = len(j)
            temp = list(j)
            temp.append(array[count])
	    print "d3:",j,temp
    vector.append(temp)
    print vector
    count += 1

print "end"
for i in range(length):
	print vector[i-1]


