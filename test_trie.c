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

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "test.h"
#include "trie.h"

/*
 * test_add_error_check
 * 
 * Verifies that add_to_trie() does not throw an error when adding one word.
 * 
 * returns: 0 upon success, 1 upon failure.
 */
int test_add_error_check() {
	int test;
	Trie* trie = create_trie();
	test = assert_true(add_to_trie(trie, "abcdefghijklmnopqrstuvwxyz") == 1, 
						"Trie adding did not throw an error for one entry");
	free_mem(trie);
	return test;
}

/*
 * test_add_check_validity1
 * 
 * Verifies that add_to_trie() rejects non-lowercase words.
 * 
 * returns: 0 upon success, 1 upon failure.
 */
int test_add_check_validity1() {
	int test;
	Trie* trie = create_trie();
	test = assert_true(add_to_trie(trie, "ABCDEFGHIJKLMNOPQRSTUVWXYZ") == -2,
						"Trie does not accept capitalized input");
	free_mem(trie);
	return test;
}

/*
 * test_add_check_validity2
 * 
 * Verifies that add_to_trie() rejects non-letters only words.
 * 
 * returns: 0 upon success, 1 upon failure.
 */
int test_add_check_validity2() {
	int test;
	Trie* trie = create_trie();
	test = assert_true(add_to_trie(trie, ".,!<>/\\`~\"\'") == -2,
						"Trie does not accept punctuation");
	free_mem(trie);
	return test;
}

/*
 * test_check_empty_trie
 * 
 * Verifies that check works with an empty trie.
 * 
 * returns: 0 upon success, 1 upon failure.
 */
int test_check_empty_trie() {
	int test;
	Trie* trie = create_trie();
	int count = 0;
	count += check_trie(trie, "oobleck");
	count += check_trie(trie, "bananas");
	count += check_trie(trie, "apples");
	test = assert_true(count == 0, "No words in empty trie");
	free_mem(trie);
	return test;
}

/*
 * test_check_invalid_word
 * 
 * Verifies that check works with an invalid word.
 * 
 * returns: 0 upon success, 1 upon failure.
 */
int test_check_invalid_word() {
	int test;
	Trie* trie = create_trie();
	add_to_trie(trie, "bananas");
	test = assert_true(check_trie(trie, "BaNaNaS") == 0,
						"An invalid word is not in the trie");
	free_mem(trie);
	return test;
}

/*
 * test_check_nonexistent_word
 * 
 * Verifies that check works with a single nonexistent word.
 * 
 * returns: 0 upon success, 1 upon failure.
 */
int test_check_nonexistent_word() {
	int test;
	Trie* trie = create_trie();
	add_to_trie(trie, "bananas");
	test = assert_true(check_trie(trie, "apples") == 0, 
						"\"apples\" not in trie");
	free_mem(trie);
	return test;
}

/*
 * test_check_single_word
 * 
 * Verifies that check works with a single existing word.
 * 
 * returns: 0 upon success, 1 upon failure.
 */
int test_check_single_word() {
	int test;
	Trie* trie = create_trie();
	add_to_trie(trie, "apples");
	test = assert_true(check_trie(trie, "apples"), "\"apples\" in trie");
	free_mem(trie);
	return test;
}

/**
 * test_clear_empty_trie
 * 
 * Verifies that clearing an empty trie doesn't return an error.
 * 
 * returns: 0 upon success, 1 upon failure.
 */
int test_clear_empty_trie() {
	int test;
	Trie* trie = create_trie();
	test = assert_true(clear_trie(trie) == 0, "Empty trie cleared");
	free_mem(trie);
	return test;
}


/**
 * test_clear_multiple
 * 
 * Verifies that clearing a trie with one word works.
 * 
 * returns: 0 upon success, 1 upon failure.
 */
int test_clear_multiple() {
	int test;
	Trie* trie = create_trie();
	int count = 0;
	add_to_trie(trie, "apples");
	add_to_trie(trie, "bananas");
	add_to_trie(trie, "banana");
	add_to_trie(trie, "oobleck");
	clear_trie(trie);
	count += check_trie(trie, "apples");
	count += check_trie(trie, "bananas");
	count += check_trie(trie, "banana");
	count += check_trie(trie, "oobleck");
	test = assert_true(count == 0, "Multi-word trie cleared");
	free_mem(trie);
	return test;
}

/**
 * test_clear_single
 * 
 * Verifies that clearing a trie with one word works.
 * 
 * returns: 0 upon success, 1 upon failure.
 */
int test_clear_single() {
	int test;
	Trie* trie = create_trie();
	add_to_trie(trie, "apples");
	clear_trie(trie);
	test = assert_true(check_trie(trie, "apples") == 0, 
						"Single-word trie cleared");
	free_mem(trie);
	return test;
}

/*
 * test_create
 * 
 * Verifies that create_trie() returns a pointer with address > 0.
 * 
 * returns: 0 upon success, 1 upon failure.
 */
int test_create() {
	struct node* trie = create_trie();
	bool cond = trie > 0;
	free_mem(trie);
	return assert_true(cond, "Trie pointer > 0");
}

/*
 * test_delete_invalid_ret
 * 
 * Verifies that delete_from_trie() returns correctly for a word not in the trie.
 * 
 * returns: 0 upon success, 1 upon failure.
 */
int test_delete_invalid() {
	struct node* trie = create_trie();
	bool cond;
	cond = delete_from_trie(trie, "apples") == 0;
	free_mem(trie);
	return assert_true(cond, "Deleting from trie handled for word not in trie");
}

/*
 * test_delete_substring
 * 
 * Verifies that delete_from_trie() does remove the superstring.
 * 
 * returns: 0 upon success, 1 upon failure.
 */
int test_delete_substring() {
	struct node* trie = create_trie();
	bool cond;
	add_to_trie(trie, "apples");
	add_to_trie(trie, "apple");
	delete_from_trie(trie, "apple");
	cond = check_trie(trie, "apples") == 1 && check_trie(trie, "apple") == 0;
	free_mem(trie);
	return assert_true(cond, "Only substring deleted from trie");
}

/*
 * test_delete_valid
 * 
 * Verifies that delete_from_trie() removes a word from the trie from the trie.
 * 
 * returns: 0 upon success, 1 upon failure.
 */
int test_delete_valid() {
	struct node* trie = create_trie();
	bool cond;
	add_to_trie(trie, "apples");
	delete_from_trie(trie, "apples");
	cond = check_trie(trie, "apples") == 0;
	free_mem(trie);
	return assert_true(cond, "Word in trie deleted from trie");
}

/*
 * test_delete_valid_ret
 * 
 * Verifies that delete_from_trie() returns correctly when removing a word from
 * the trie that is already in the trie.
 * 
 * returns: 0 upon success, 1 upon failure
 */
int test_delete_valid_ret() {
	struct node* trie = create_trie();
	bool cond;
	add_to_trie(trie, "apples");
	cond = delete_from_trie(trie, "apples") == 1;
	free_mem(trie);
	return assert_true(cond, "Word in trie deleted from trie returned good");
}

/* ============================= TEST FRAMEWORK ============================= */

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
int assert_false(bool condition, char* name) {
	if (condition) {
		printf("TEST FAILURE: %s evaluated as true.\n", name);
	}
	return condition ? 1 : 0;
}

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
int assert_true(bool condition, char* name) {
	if (!condition) {
		printf("TEST FAILURE: %s evaluated as false.\n", name);
	}
	return condition ? 0 : 1;
}

/*
 * free_mem
 * 
 * Frees the memory associated with a trie used in testing.
 */
void free_mem(Trie* head) {
	clear_trie(head);
	free(head);
}

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
int run_test(int (*test)(), int* total_tests) {
	*total_tests += 1;
	return test();
}

/*
 * main
 * 
 * Runs all tests, printing out the pass rate.
 * 
 * returns: 0 upon all tests passed, 1 otherwise.
 */
int main() {
	int count = 0;
	int total_tests = 0;
	int (*tests[])() = {&test_create, &test_add_error_check, 
						&test_add_check_validity1, &test_add_check_validity2, 
						&test_check_single_word, &test_check_nonexistent_word, 
						&test_check_empty_trie, &test_check_invalid_word,
						&test_clear_empty_trie, &test_clear_single,
						&test_clear_multiple, &test_delete_valid,
						&test_delete_valid_ret, &test_delete_invalid,
						&test_delete_substring, NULL};

	for (int i = 0; tests[i] != NULL; i++) {
		count += run_test(tests[i], &total_tests);
	}

	printf("%d / %d tests passed.\n", total_tests - count, total_tests);
	return count >= 1 ? 1 : 0;
}
