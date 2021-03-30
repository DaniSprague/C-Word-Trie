/*
trie.h

Dani Sprague
February 2021
https://github.com/DaniSprague/C-Word-Trie

A header for a trie implementation.


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

#ifndef TRIE_H
#define TRIE_H

/*
 * trie 
 * 
 * The struct for a trie.
 */
typedef struct node Trie;

/*
 * add_to_trie
 * 
 * Adds a word to the trie.
 * 
 * trie: The trie to add the words to.
 * word: A string with the lowercase word to add (consisting only of [a-z]).
 * 
 * returns: 1 if the word was added to the trie, 0 if the word was already in 
 * 			the trie, -1 upon failure due to the maximum size of the trie being 
 * 			exceeded, -2 upon bad words input, or -3 upon other failure.
 */
int add_to_trie(Trie* trie, char* word);

/*
 * check_trie
 * 
 * Checks if a word is represented in the trie.
 * 
 * trie: The trie to check.
 * word: A string with the lowercase word (consisting only of [a-z]) to check
 * 			existence of in the trie.
 * 
 * returns: 1 upon membership, 0 upon no membership, or -1 upon an error.
 */
int check_trie(Trie* trie, char* word);

/*
 * clear_trie
 * 
 * Deletes all entries in the trie. Does not delete the head node.
 * 
 * trie: The trie to clear.
 * 
 * returns: 0 upon success, -1 upon error.
 */
int clear_trie(Trie* trie);

/*
 * create_trie
 * 
 * Creates an empty trie.
 * 
 * returns: A pointer to an empty trie, NULL upon error.
 */
Trie* create_trie();

/*
 * delete_from_trie
 * 
 * Deletes a word from the trie.
 * 
 * trie: The trie to delete an entry from.
 * word: The lowercase string to delete from the trie.
 * 
 * returns: 1 if the word was deleted from the trie, 0 if the word was not in 
 * 				the trie, and -1 upon error.
 */
int delete_from_trie(Trie* trie, char* word);

#endif
