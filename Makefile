# Basic Makefile for the Trie project
# Nothing fancy at all due to small scale

# Build and run tests
check: test_trie.c trie.c
	gcc -Wall -o test_trie test_trie.c trie.c
	./test_trie

# Build test file without running
no_test_run: test_trie.c trie.c
	gcc -Wall -o test_trie test_trie.c trie.c
