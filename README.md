# max-subarray-comparison
C++ implementation comparing brute-force, divide-and-conquer, and hybrid algorithms for the Maximum Subarray Problem with performance timing.



# Maximum Subarray Algorithm Comparison

This project implements and compares three approaches to solving the Maximum Subarray Problem in C++:

1. Brute Force (O(n²))
2. Divide and Conquer / Recursive (O(n log n))
3. Hybrid approach using recursion with a brute-force base case for small inputs

The program also times each method to compare their practical runtime efficiency.

## Problem Statement

Given an array of integers (which may include negative numbers), find the contiguous subarray with the largest sum.

This is a classic problem in algorithm design, useful for understanding recursion, dynamic programming, and optimization.

## Algorithms Implemented

### 1. Brute Force

Loops through all possible subarrays and keeps track of the maximum sum.

**Time Complexity:** O(n²)

### 2. Recursive (Divide and Conquer)

Divides the array into halves recursively and calculates:
- Max subarray in the left half
- Max subarray in the right half
- Max subarray crossing the midpoint

**Time Complexity:** O(n log n)

### 3. Hybrid (Recursive + Brute Force)

Same as the recursive solution, but switches to brute-force if the subproblem size is < 45 elements for better real-world performance.

## How to Run

### On Mac/Linux

```bash
g++ max_subarray_comparison.cpp -o max_subarray
./max_subarray
```

### On Windows (with MinGW)

```bash
g++ max_subarray_comparison.cpp -o max_subarray.exe
max_subarray.exe
```

### Or Use Online:

Paste code into: https://www.onlinegdb.com/online_c++_compiler

## Sample Output

```
Max Sub Array Brute Force = 1469
Time for brute: 0.00023 seconds

Max Sub Array Recursive = 1469
Time for recursive: 0.00018 seconds

Max Sub Array Recursive With Brute = 1469
Time for recursive with brute base case: 0.00017 seconds
```

## File Overview

- `max_subarray_comparison.cpp`: Main C++ file with all algorithms and timing code

