# shiftcipher

This is a simple shift cipher, or Caesar cipher, written in C.

## Build:

This program requires the `GCC` compiler.

To build, run:

	make clean
	make

If you have edited the source, and wish to implement changes, run:

	make clean-all
	make

## Instructions:

	./shiftcipher [offset] [-e|-d] [file]

The `[-e|-d]` stands for encrypt and decrypt.

This version of shiftcipher will only process capital ASCII characters
in the range of 65-90. Therefore, please be sure to strip your plaintext
of punctuation etc, before using this cipher, or you may lose information.
