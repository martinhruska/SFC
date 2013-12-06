#! /bin/bash

for i in {A..M}
do
  for j in {A..M} 
  do
    X=`od -A n -t d -N 1 /dev/urandom`
    Y=`bc <<< $X%30`
    echo $i $j $Y
  done
done
