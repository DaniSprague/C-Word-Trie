/*
test.h

Dani Sprague
February 2021
https://github.com/DaniSprague/C-Word-Trie

A header file for the test_trie.c unit test framework functionality.


MIT License

Copyright (c) 2021 Dani Sprague

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

/*
 * assert_false
 * 
 * Asserts a condition is false.
 * 
 * condition: A boolean to assert if false.
 * name: The name of the condition to print out.
 * 
 * returns: 0 upon success, 1 upon failure.
 */
int assert_false(bool condition, char* name);

/*
 * assert_true
 * 
 * Asserts a condition is true.
 * 
 * condition: A boolean to assert if false.
 * name: The name of the condition to print out.
 * 
 * returns: 0 upon success, 1 upon failure.
 */ 
int assert_true(bool condition, char* name);

/*
 * run_test
 * 
 * Runs a test, incrementing the total test counter.
 * 
 * test: A pointer to the test function taking no arguments, returning 1 or 0.
 * total_tests: A pointer to the int representing the total number of tests ran.
 * 
 * returns: 0 upon success, 1 upon failure.
 */
int run_test(int (*test)(), int* total_tests);
