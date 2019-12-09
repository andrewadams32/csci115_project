#!/bin/bash
#b for reverse, r for random, s for sorted, leave blank to choose in cpp program
if (( $# > 0 ))
    then
    sort=$1
fi
echo 'compiling program'
g++ -std=c++11 Sorts.cpp -o sorts
echo 'running prorgam'
./sorts $sort
echo 'graphing data'
python sorts.py