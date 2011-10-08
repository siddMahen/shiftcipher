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

## Test:

Run the following test in the `shiftcipher` directory to make
sure `shiftcipher` works.

	./shiftcipher 10 -e README.md > test.txt
	./shiftcipher 10 -d test.txt

The output should be the contents of this document.

