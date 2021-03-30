# C Word Trie (WIP)

An implementation of the [trie](https://en.wikipedia.org/wiki/Trie) data structure for C. This trie supports lowercase
words with only the characters from a-z, inclusive. (Though the code has been designed to be expanded to support any
contiguous sequence of ASCII characters given enough memory through use of macros.)

## Functionality

- Create: Use `create_trie()` to create the trie (get the head node).
- Add: Use `add_to_trie()` to add a word to the trie.
- Check Membership: Use `check_trie()` to check for word membership in a trie.
- Delete: Use `delele_from_trie()` to delete a word from the trie.
- Clear: Use `clear_trie()` to clear all entries from the trie.

## Notes

Though the trie was designed to support lowercase words from a-z only, it can be expanded to support any contiguous
sequence of ASCII characters given enough memory through modification of macros in `trie.c`.

WARNING: This trie does not have a maximum nodes limit, which could be used maliciously to fill up memory.

## Motivation

The two main driving factors for this project were to learn more about C and to practice some Test-Driven Development.
