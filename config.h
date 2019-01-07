/// Set LIST_TEST to 1 to execute test the linked list ADT.
/// Set SPELL_CHECK to 1 to execute the SPELL_CHECK program.
/// Only one value can be set to 1 at a time.
/// Values not set to 1 should be set to 0.

#ifndef CONFIG_H
#define CONFIG_H

#define LIST_TEST	0
#define SPELL_CHECK	1

/// Set FILE_NAME_LENGTH to the maximum number of characters
/// in the names of the input files.  Set MAX_WORD_LENGTH to
/// the maximum number of letters in the longest word in
/// the dictionary input file.  Account for terminating NULLs.

#define FILE_NAME_LENGTH 32
#define MAX_WORD_LENGTH 64

#endif // !CONFIG_H

