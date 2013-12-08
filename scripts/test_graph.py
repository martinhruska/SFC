#! /usr/bin/python3

# parameter 1 input file
# parameter 2 mode

import sys
import re

def printBest():
  for i in iterBest:
    print (i,iterBest[i])
  return

def printDist():
  for i in iterBest:
    print (i,float(iterBest[i])-float(allTimeBest))
  return

if len(sys.argv) < 3:
  print ("Not enough arguments")
  exit()

inFile = open(sys.argv[1],"r")
antsRes = {}
iterBest = {}
allIterBest = {}
allTimeBest = -1

for i in inFile:
  #m = re.match(r"([1-9][0-9]*). iterace",i)
  m = re.match(r"([1-9][0-9]*). iteration",i)
  if m != None: # get current iteration
    currentState = m.group(1)
    antsRes[currentState] = [] # init antsRes hash array
  #m = re.match(r"Mravenec.*cena ([1-9][0-9]*).*",i)
  m = re.match(r"Ant.*cost ([1-9][0-9]*).*",i)
  if m != None: # get ant value
    antsRes[currentState].append(m.group(1))
  #m = re.match(r"Nejlepsi cesta iterace.*cena ([1-9][0-9]*).*",i)
  m = re.match(r"Iteration best.*cost ([1-9][0-9]*).*",i)
  if m != None: # get best iteration value
    iterBest[currentState] = m.group(1)
  #m = re.match(r"Dosud nejlepsi reseni.*Cena ([1-9][0-9]*).*",i)
  m = re.match(r"Best all time.*Cost ([1-9][0-9]*).*",i)
  if m != None: # get best value so fat
    allIterBest[currentState] = m.group(1)
  #m = re.match(r"Nejlepsi nalezena cesta.*Cost ([1-9][0-9]*).*",i)
  m = re.match(r"Final result.*Cost ([1-9][0-9]*).*",i)
  if m != None: # get best value so fat
    allTimeBest = m.group(1)

if sys.argv[2] == "-b":
  printBest()
elif sys.argv[2] == "-d":
  printDist()
else:
  print ("No such parameter")
