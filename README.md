# Practicing C

![title_image](misc/images/title.png)

## Overview

Welcome dear programmer!
I'm glad to see you here, in my small repository for practicing C. Here you'll be able to find some tasks that I enjoyed doing while studying the basics of C.

I conditionally divided the tasks into 3 levels of difficulty:

* Level one includes tasks that help you get accuainted with:
    * Basic control structures;
    * Pointers and data input/output;
    * Sorting algorithms and arrays;
    * Matrices and memory allocation;
    * Strings;
* Level two contains tasks for practicing:
    * Structures;
    * Callbacks and varargs;
    * Binary trees;
    * Text files processing;
    * Binary files processing;
* Level three includes some bigger projects, such as:
    * Pong game;
    * Game of Life;
    * Snake game;
    * Reverse polish notation and drawing graphics;
    * Custom database.

I'm still working at some of these tasks so the repository will be regularly updated.

## Detailed contents

1. [Level 1](#level-1) \
    1.1 [Basic control structures](#basic-control-structures) \
    1.2 [Pointers and data input and output](#pointers-and-data-input-and-output) \
    1.3 [Sorting algorithms and arrays](#sorting-algorithms-and-arrays) \
    1.4 [Matrices and memory allocation](#matrices-and-memory-allocation) \
    1.5 [Strings](#strings)
2. [Level 2](#level-2) \
    2.1 [Structures](#structures) \
    2.2 [Callbacks and varargs](#callbacks-and-varargs) \
    2.3 [Binary trees](#binary-trees) \
    2.4 [Text files processing](#text-files-processing) \
    2.5 [Binary files processing](#binary-files-processing)
3. [Level 3](#level-3) \
    3.1 [Pong game](#pong-game) \
    3.2 [Game of Life](#game-of-life) \
    3.3 [Snake game](#snake-game) \
    3.4 [Reverse polish notation and graphics](#Reverse-polish-notation) \
    3.5 [Custom database](#custom-database)

## Level 1

## Basic control structures

* **1948.c** recreates Tom Kilburn's route (_In the spring of 1948 he created the first program that was fully stored in computer memory and was supposed to find the largest prime divisor of any predetermined number a, not using division or the operation of taking the remainder of the division since the hardware did not support the operation of division_).

* **char_decode.c** takes operation mode as a command-line parameter: 0 stands for encodind, 1 – for decoding the text. When decoding, the program must take a string of space-separated hexadecimal integers from stdin and output space-separated decoded characters to stdout. Encoding is a reverse operation. A line break character is a sign of the end of the input.

* **fibonacci.c** displays a number from the Fibonacci sequence (e.g. 18) using a recursive algorithm. The number is entered via stdin.

* **math_functions.c** calculates and displays a table with three functions: the witch of Agnesi with diameter one, the lemniscate of Bernoulli with a unit interval in the positive half-plane (Y > 0), and a quadratic hyperbola. The first column lists the values of the X-axis from minus Pi through plus Pi, there should be 42 measurements at this interval; the second, third, and fourth columns describe the values ​​of the functions at a point.


## Pointers and data input and output

* **maxmin.c** finds max and min out of 3 integer numbers and displays them on the screen. The 3 integers are entered via stdin.

* **squaring.c** receives an array of integers via stdin, squares them and outputs the result to stdout. The size of the array is received via stdin before the array itself.

* **stat.c** receives an array of integers via stdin, displays it, calculates and displays on the new line a set of statistical metrics – maxima and minima, the expected value, and variance (assuming that we are dealing with a discrete uniform distribution).

* **search.c** receives an array of integers via stdin and finds the first occurrence of a number that meets the following requirements in the array: it's an even number, it's equal to or above the expected value, it follows the three-sigma rule and it doesn't equal 0. The number is displayed via stdout. If such number doesn't exist, the program outputs 0.

## Sorting algorithms and arrays

* **sort.c** expects an stdin array with the length of 10 integers for input and outputs the same array sorted in ascending order (bubble sort is used here).

* **fast_sort.c** sorts an array of 10 integer elements in ascending order using two different sorting algorithms with theoretical estimates of computational complexity no higher than nlog(n) (I used quicksort and heapsort).

* **array_even_els_sum.c** receives the array's length and an array of integers. Outputs in stdout the sum of the even elements of the array and the newly formed array from the elements of the old one, by which the previously calculated sum is divided evenly.

* **cycle_shift.c** receives a number `n` (size of the array), an array with `n` integers, and a number `c` by which all elements of the array must rotate to the left. If the value of `c` is negative, the shift in the array occurs to the right. A modified array is output via stdout.

* **large_ints_arithmetic.c** returns the result of addition and subtraction of two very large numbers that were passed to the program as input in the form of arrays. Maximum number length: 100 elements of type int. The integers you enter are decimal digits.

## Matrices and memory allocation

* **matrix.c** inputs and outputs integer matrices. Matrix memory allocation is implemented in 4 types: one static and 3 dynamic ones. You can find the descriptions of the latter in `materials` folder. The first integer passed via stdin is the way of memory allocation. Then you have to pass 2 arguements for the size of the matrix and finally - tha matrix itself.

* **matrix_extended.c** calculates the maximum elements of the matrix in each of its rows and the minimum elements in each of its columns. The programm outputs these values as two arrays (an array of maximum elements in each row and an array of minimum elements in each column).
* **matrix_sort.c** sorts the given matrix, putting rows with the minimum sum of elements first, followed by rows with the maximum sum of elements.

* **matrix_arithmetic.c** performs one of the three operations: 1 – addition of two matrices, 2 – multiplication, or 3 – transposition.

* **electro_snake.c** performs the sorting of the given matrix in a snake-like order vertically and horizontally, and outputs the sorted matrices in the same order, one after another, with an empty line in between. The size of the matrix is passed via stdin (2 intengers). Then the matrix itself is passed.

* **det.c** calculates and outputs the determinant of the given square matrix with float numbers.

* **invert.c** calculates and outputs the inverse matrix for the given square matrix with float numbers.

## Strings

Here I studied some of the basic functions from `string.h` standard library. To do that I recreated the following functions on my own:

* strlen;
* strcmp;
* strcpy;
* ctrcat;
* strchr;
* strstr;
* strtok;

To create my own `strtok` I also had to recreate `strcspn` and `strspn`.

For each function there are corresponding tests (in `strings_tests.c` file). To compile a certain block of tests you can use `Makefile`. The stage names are: `my_strlen_tests`, `my_strcmp_tests` and so on. The executable files are compiled to the `build` folder under the names: `Test_1`, `Test_2` and so on.
