#! /usr/bin/python

# parameter 1 input file

import sys
import re

if len(sys.argv) < 2:
  print "Not enough argumets"

inFile = open(sys.argv[1],"r")
antsRes = {}
iterBest = {}
allIterBest = {}
allTimeBest = -1

for i in inFile:
  m = re.match(r"([1-9][0-9]*). iteration",i)
  if m != None: # get current iteration
    currentState = m.group(1)
    antsRes[currentState] = [] # init antsRes hash array
    iterBest[currentState] = []
    allIterBest[currentState] = []
  m = re.match(r"Ant.*cost ([1-9][0-9]*).*",i)
  if m != None: # get ant value
    antsRes[currentState].append(m.group(1))
  m = re.match(r"Iteration best.*cost ([1-9][0-9]*).*",i)
  if m != None: # get best iteration value
    iterBest[currentState].append(m.group(1))
  m = re.match(r"Best all time.*Cost ([1-9][0-9]*).*",i)
  if m != None: # get best value so fat
    allIterBest[currentState].append(m.group(1))
  m = re.match(r"Final result.*Cost ([1-9][0-9]*).*",i)
  if m != None: # get best value so fat
    allTimeBest = m.group(1)

