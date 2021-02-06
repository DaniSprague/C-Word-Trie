/*
trie.c

Dani Sprague
February 2021
https://github.com/DaniSprague/C-Word-Trie

A trie implementation that stores lowercase words. Supports adding, deleting,
creating, clearing, and checking membership in a tree.


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
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "trie.h"

#define ASCII_OFFSET 97 // The offset from 0 our first character is in ASCII
#define DICT_SIZE 26 // The number of characters in our dict
#define MAX_NODES 1000000 // Prevents memory overflowing.

/*
 * node 
 * 
 * The struct for a node in a trie.
 */
struct node {
	struct node* next[DICT_SIZE];
	int count;
	bool ends_word;
};

/*
 * is_word_valid
 * 
 * Verifies that a word is in a useable format (in this case, lowercase a-z).
 * 
 * word: A null-terminated string to check.
 * 
 * return: true upon success, false upon failure.
 */
bool is_word_valid(char* word) {
	bool valid = true;
	while(*word != '\0' && valid) {
		if (*word - ASCII_OFFSET < 0 || *word - ASCII_OFFSET >= DICT_SIZE) {
			valid = false;
		}
		word++;
	}
	return valid;
}

/*
 * add_multiple_to_trie
 * 
 * Adds multiple words to the trie.
 * 
 * head: The head of the trie to add the words to.
 * words: An array of lowercase words consisting only of [a-z] to add.
 * n: The number of words to add.
 * 
 * returns: The number of words added, or -1 upon error.
 */
int add_multiple_to_trie(struct node* head, char** words, int n) {
	return 0;
}

/*
 * add_to_trie
 * 
 * Adds a word to the trie.
 * 
 * head: The head node of the trie to add the words to.
 * word: A string with the lowercase word to add (consisting only of [a-z]).
 * 
 * returns: 1 if the word was added to the trie, 0 if the word was already in 
 * 			the trie, -1 upon failure due to the maximum size of the trie being 
 * 			exceeded, -2 upon bad words input, or -3 upon other failure.
 */
int add_to_trie(struct node* head, char* word) {
	if (!is_word_valid(word)) {
		return -2;
	}
	head -> count += 1;
	while (*word != '\0') {
		struct node* new_node = (struct node*) calloc(sizeof(struct node*), 1);
		if (new_node == NULL) { // Catch error in calloc
			return -3;
		}
		head -> next[*word - ASCII_OFFSET] = new_node;
		new_node -> count += 1;
		head = new_node;
		word++;
	}
	head -> ends_word = true;
	return 1;
}

/*
 * check_trie
 * 
 * Checks if a word is represented in the trie.
 * 
 * head: The head of the trie to check.
 * word: A string with the lowercase word (consisting only of [a-z]) to check
 * 			existence of in the trie.
 * 
 * returns: 1 upon membership, 0 upon no membership, -1 upon error.
 */
int check_trie(struct node* head, char* word) {
	return 0;
}

/*
 * clear_trie
 * 
 * Deletes all entries in the trie.
 * 
 * head: The head of the trie to clear.
 * 
 * returns: 0 upon success, -1 upon error.
 */
int clear_trie(struct node* head) {
	return 0;
}

/*
 * create_trie
 * 
 * Creates an empty trie.
 * 
 * returns: A pointer to the head of an empty trie, or NULL upon error.
 */
struct node* create_trie() {
	return (struct node*)calloc(sizeof(struct node), 1);
}

/*
 * delete_from_trie
 * 
 * Deletes a word from the trie.
 * 
 * head: The head trie to delete an entry from.
 * word: The lowercase string to delete from the trie.
 * 
 * returns: 1 if the word was deleted from the trie, 0 if the word was not in 
 * 				the trie, and -1 upon error.
 */
int delete_from_trie(struct node* head, char* word) {
	return 0;
}
