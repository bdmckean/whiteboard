#!/usr/bin/env python3
#
# copyright 2016 Brian McKean
# 
# Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
# 
#     THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.kkkkk
# 
# 
 

import argparse
import itertools



parser = argparse.ArgumentParser(description='Analyze a etxt file.')
parser.add_argument('filename', type=str)
args = parser.parse_args()

print(args)
print(args.filename)

words = []
word_counts = {}
num_sentences = 0

line = ""

fname = args.filename
with open(fname) as f:

    text = f.read()
    endsentence = ".?!"
    sentences = itertools.groupby(text, lambda x: any(x.endswith(punct) for punct in endsentence))
    sentences = list(sentences) 
    words = text.split()
    for i,w in enumerate(words):
        w = w.lower()
        w  = w.strip('.,;?!":')
        words[i] = w
        if w in word_counts:
            word_counts[w] = word_counts[w] + 1
        else:
            word_counts[w] = 1 

print("Sentence count = ",len(sentences))
print("Average length of a sentance in words =",len(words)/len(sentences))
print("Word count = ",len(words))
print("Number of unqique words = ",len(set(words)))

print("word counts")
for w in sorted(word_counts, key=word_counts.get, reverse=True):
    print (w, word_counts[w])


