#!/usr/bin/env python3


words = input().split()

words = set(words)

ans = []
ana = {}
for w in words:
    w_sorted_letters = sorted(w)
    key = ''.join(w_sorted_letters)
    if key in ana:
        ana[key].append(w)
    else:
        ana[key] = [w]

for key,value in ana.items():
    if len(value) > 1:
        for w in value:
            ans.append(w)

print (ana)
print (ans)
