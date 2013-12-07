#! /usr/bin/python3

# 1. parameter File to be tranformed to compatible

import sys
import math
def distance_on_unit_sphere(lat1, long1, lat2, long2):
  # Convert latitude and longitude to 
  # spherical coordinates in radians.
  degrees_to_radians = math.pi/180.0
      
  # phi = 90 - latitude
  phi1 = (90.0 - lat1)*degrees_to_radians
  phi2 = (90.0 - lat2)*degrees_to_radians
      
  # theta = longitude
  theta1 = long1*degrees_to_radians
  theta2 = long2*degrees_to_radians
      
  # Compute spherical distance from spherical coordinates.
      
  # For two locations in spherical coordinates 
  # (1, theta, phi) and (1, theta, phi)
  # cosine( arc length ) = 
  #    sin phi sin phi' cos(theta-theta') + cos phi cos phi'
  # distance = rho * arc length
  
  cos = (math.sin(phi1)*math.sin(phi2)*math.cos(theta1 - theta2) + 
         math.cos(phi1)*math.cos(phi2))
  arc = math.acos( cos )

  # Remember to multiply arc by the radius of the earth 
  # in your favorite set of units to get length.
  return arc

def convertToRad(x):
  PI = 3.141592

  deg = int (x)
  mini = x - deg
  rad = PI * (deg + 5.0 * mini/ 3.0) / 180.0
  return x

def computeDistance(x,y):
 RRR = 6378.388;

 q1 = math.cos( x[1] - y[1] )
 q2 = math.cos( x[0] - y[0] )
 q3 = math.cos( x[0] + y[0] )
 dij = int ( RRR * math.acos( 0.5*((1.0+q1)*q2 - (1.0-q1)*q3) ) + 1.0)
 return dij

if len(sys.argv) < 2:
  print ("Not enough arguments")
  exit()

inFile = open(sys.argv[1],"r")
nodes = {}

for i in inFile:
  i = i.replace('\n','')
  arr = i.split(' ')
  key = int (arr[0])
  nodes[key] = []
  # dist extern
  #nodes[key].append(float(arr[1]))
  #nodes[key].append(float(arr[2]))
  # radian by myself
  #nodes[key].append(convertToRad(float(arr[1])))
  #nodes[key].append(convertToRad(float(arr[2])))
  nodes[key].append(arr[1])
  nodes[key].append(arr[2])

d = {}
for i in nodes:
  d[i] = []
  for j in nodes:
    if j in d and i in d[j] or i == j:
      continue
    else:
      d[i].append(j)
      dx = float(nodes[i][0]) - float(nodes[j][0])
      dy = float(nodes[i][1]) - float(nodes[j][1])
      print("%d %d %.3f"%(i,j,math.sqrt(pow(dx,2)+pow(dy,2))))
      #print("%d %d %.3f"%(i,j,computeDistance(nodes[i],nodes[j]))) #dist mysefl
      #dist = 6373*distance_on_unit_sphere(nodes[i][0],nodes[i][1], nodes[j][0],nodes[j][1]) #dist extern
      #print("%d %d %.3f"%(i,j,dist))
