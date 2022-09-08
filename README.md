# Practicing C

## Overview

Welcome dear programmer!
I'm glad to see you here, in my small repository for practicing C. Here you'll be able to find some tasks that I enjoyed doing while studying the basics of C.

I conditionally divided the tasks into 3 levels of difficulty:

* Level one includes tasks that help you get accuainted with:
    * Basic control structures;
    * Pointers and data input/output;
    * Sorting algorithms and arrays;
    * Matrices and memory allocation;
    * Strings.
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
    1.2 [Pointers and data input/output](#pointers-and-data-i/o) \
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
