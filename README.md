# Counting_SpecialNames-Integers

Write a C++ program that accepts one command line argument for a file name, and ignores any extra command line arguments that may be provided after the first one. If no file name is provided, the program should print on a new line "NO SPECIFIED INPUT FILE NAME.", and exit. If the file cannot be opened, print on a new line "CANNOT OPEN THE FILE: ", followed by the file name, and exit. The program should read from the file lines until the end of file is found. If the input file is empty, it prints out the message "File is empty." on a new line and then exits.

The program should count the number of lines, the number of non-blank lines, the number of words that contain 5 or less characters, the number of words that contain more than 5 characters, the number of names (special names), and the number of unsigned integers, seen in the file.

A word is defined as a sequence of one or more non-whitespace characters separated by whitespace. A word is defined as a name if it starts by a letter and followed by zero or more letters, digits, underscores ‘_’, or ‘@’ characters. For example, value, val@l9, num234ten are valid names, but 9val, _num_45 and @num are not. A word is defined as an unsigned integer if it starts by a digit and followed by zero or more digits (ignoring signed integers). For example, 2345 is an unsigned integer word, while 44.75, -345 and 4today45 are not unsigned integers. Note that a line having only whitespace characters is a non-blank line as well.
