#! /usr/bin/python3

# 1. parameter file to get best of all paths and average

import sys
import math

if len(sys.argv) < 2:
  print ("Not enough arguments")
  exit()

inFile = open(sys.argv[1],"r")

best = 10000000.0
s = 0.0
it = 0

for i in inFile:
  t = float(i)
  it += 1
  s += t
  if best > t:
    best = t

print("Best path is: ",best," and average is: ", s/it)
