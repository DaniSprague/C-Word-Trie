/*
test_trie.c

Dani Sprague
February 2021
https://github.com/DaniSprague/C-Word-Trie

Unit tests for the trie.c Trie implementation.


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

#include <stdio.h>
#include "trie.h"

/*
 * assert_false
 * 
 * Asserts a condition is false.
 * 
 * returns: 0 upon succes, 1 upon failure.
 */
int assert_false() {
	return 0;
}

/*
 * assert_true
 * 
 * Asserts a condition is true.
 * 
 * returns: 0 upon success, 1 upon failure.
 */ 
int assert_true() {
	return 0;
}

int main() {
	int count = 0;
	create_trie();
	return count >= 1 ? 1 : 0;
}