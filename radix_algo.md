# Radix (LSD) Sorting Algorithms

---

## Radix Sort (LSD):

- The LSD variant of radix sort performs a stable counting sort on the list for each digit, starting from the least significant (right-most) digit.

- **When learning about the radix sort (LSD) I'm reading that the initial input array has a "current digit". For example, it says 48 has a current digit of 8. What does current digit mean?**

- The "current digit" refers to the digit in the number being processed at a particular step in the radix sort algorithm. In the case of a Least Significant Digit (LSD) radix sort, the current digit refers to the rightmost digit of the number being processed.

  For example, if the input array consists of the numbers 48, 35, 12, 19, and the algorithm is processing the LSD, the current digit would be the rightmost digit of each number in the array. In the first step, the current digit would be 8, 5, 2, 9.

  Each digit of the numbers in the input array is processed from right to left, starting with the least significant digit (the LSD). After processing each digit, the input array is rearranged so that the numbers are in order based on their current digit. This process is repeated for each digit of the numbers in the array, until all the digits have been processed and the array is fully sorted.

```
input_array = [19, 48, 99, 71, 13, 52, 96, 73, 86, 7]
count_array = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
auxilliary_array = []
```

# Steps:

- Starting Radix Sort. We will process digits from right to left. The first step will be to count occurances of digits from the input array.

  - After first iteration through input_array:

```
input_array = [19, 48, 99, 71, 13, 52, 96, 73, 86, 7]
count_array = [0, 1, 1, 2, 0, 0, 2, 1, 1, 2]
auxilliary_array = []
```

- The next step is to do a rolling summation:

- **What is a rolling summation?:**

  - The term "rolling summation" is not commonly used in the context of the radix sort algorithm. Radix sort is a non-comparative integer sorting algorithm that sorts data with integer keys by grouping the keys by the individual digits which share the same significant position and value. The process does not involve any kind of summation.
    If you're referring to a different algorithm, please provide more context and I would be happy to assist you further.

- But first we subtract 1 from the 0 position so that the resulting sums yield correct positions in the Auxilliary array.

```
input_array = [19, 48, 99, 71, 13, 52, 96, 73, 86, 7]
count_array = [-1, 0, 1, 3, 3, 3, 5, 6, 7, 9]
auxilliary_array = []
```

- Now use the Count array to decide where to move values into the Auxilliary array

```
input_array = [19, 48, 99, 71, 13, 52, 96, 73, 86, 7]
count_array = [-1, -1, 0, 1, 3, 3, 3, 5, 6, 7]
auxilliary_array = [71, 52, 13, 73, 96, 86, 7, 48, 19, 99]
```

- Now we move the value back to the Input Array.
- We repeat the same process, but this time using the 1st digit.

```
input_array = [71, 52, 13, 73, 96, 86, 7, 48, 19, 99]
count_array = [-1, 0, 2, 2, 2, 3, 4, 4, 6, 7]
auxilliary_array = [7, 13, 19, 48, 52, 71, 73, 86, 96, 99]
```

- Now we move the value back to the input array.

```
input_array = [7, 13, 19, 48, 52, 71, 73, 86, 96, 99]
count_array = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
auxilliary_array = []
```

# Done sorting!
