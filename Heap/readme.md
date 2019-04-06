This project uses a heap class (min heap) to implement a priority queue. The heap (a vector) maintains the smallest element at the 
top of the object. The main program takes a series of numbers, puts them into the min
heap structure. It then extracts the top 2 smallest numbers, adds them,
and reinserts the new value. Each sum is kept in an overall sum which is
reported as the "cost".

The problem as described by the UVa website is to take a series of integers
and find the lowest "cost" of summing these numbers with single summation
operations. For example 1+2=3 has a cost of 3. 1+5=6 has a cost of 6.
The lowest cost is achieved by the process described above.
