### Project Code for Team Pivot
To run the program, just run the "main.sh" shell script. Pass in optional parameters `r` for randomized input array, `b` for backwards(reverse) order array, or `s` for a sorted input array.
ex: `./main.sh r` 

The main driver will create arrays from size 10 to 1000 in increments of 10.

Each algorithm will receive exactly the same input array to ensure a level playing field.

Number of comparisons is counted by creating an int wrapper and overloading the comparison operators to count how many times they are called

Time taken is recorded by initializing a clock before each algorithm starts and subtracting that time from the time recorded directly after the sorting is complete.

#### Assumes that you gave g++ installed, python, and a few python packages (matplotlib, numpy, and pandas)
