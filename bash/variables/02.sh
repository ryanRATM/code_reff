#!/bin/sh

# special case for params

# testing with $@

for TOKEN_1 in $@
do
   echo $TOKEN_1
done

# testing with $*
for TOKEN_2 in $*
do
   echo $TOKEN_2
done
