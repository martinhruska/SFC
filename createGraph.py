#! /bin/python3

import random

d = {}

for i in range(1,25):
    d[i] = []
    for j in range(1,25):
      if j in d and i in d[j] or i == j:
        continue
      else:
        d[i].append(j)
        if (random.uniform(0,1) > 0.3):
          print(i," ",j,random.uniform(1,30))
        else:
          continue
