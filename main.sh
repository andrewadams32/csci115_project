#!/bin/bash
#b for revers, r for random, s for sorted, leave blank to choose in cpp program
if (( $# > 0 ))
    then
    sort=$1
    echo 'sorting with' $sort
fi
g++ Sorts.cpp -o sorts
echo 'program compiled'
./sorts $sort
echo 'prorgam ran'
python sorts.py
echo 'data graphed'