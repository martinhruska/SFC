#! /usr/bin/python3

# 1. parameter number of vertices
# 2. parameter maximal distance between vertices
# 3. parameter probability that vertices are not connected by edge

import random
import sys

d = {}

for i in range(1,int (sys.argv[1])):
    d[i] = []
    for j in range(1,int (sys.argv[1])):
      if j in d and i in d[j] or i == j:
        continue
      else:
        d[i].append(j)
        if (random.uniform(0,1) > float (sys.argv[3])):
          print(i,j,random.uniform(1,int (sys.argv[2])))
        else:
          continue
