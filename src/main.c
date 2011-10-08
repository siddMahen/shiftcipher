// Written by Siddharth Mahendraker
// Copyright (c) 2011 

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){

	if(argv[1] == NULL || argv[1] == ""){
		printf("An error occured, a shift value is required. \n");
		exit(EXIT_FAILURE);
	}

	// Not really modulo, but still works as encryption because of
	// the range of Unicode

	int shift = atoi(argv[1]);
	int encrypt;

	if(argv[2] == NULL || argv[2] == ""){
		printf("An error occured, please use -e or -d to set the encryption/decryption mode. \n");
		exit(EXIT_FAILURE);
	} else {
		if(argv[2] == "-e"){
			encrypt = 1;
		}
		if(argv[2] == "-d"){
			encrypt = 0;
		}
		if(encrypt != 1 && encrypt != 0){
			printf("An error occured, please use -e or -d to set the encryption/decryption mode. \n");
			exit(EXIT_FAILURE);
		}
	}

	FILE *file = fopen(argv[3], "r");
	
	if(file == NULL){
		printf("An error occured opening the file %s. \n",argv[3]);
		exit(EXIT_FAILURE);
	}

	// Main body of the code begins here

	// Retreives the integer representation which correspond to
	// the first character and move the internal pointer forward

	int i = fgetc(file);
	
	// Loops through each of the characters in the file until the end of the
	// file is reached

	int ctxt;

	while(i != EOF){

		if(encrypt == 1){
			ctxt = shift+i;
		}else{
			ctxt = shift-i;
		}
		
		// Performs the shift and prints the resulting character
		char c = (char) ctxt;	
		printf("%c", c);
		i = fgetc(file);
	}

	fclose(file);

	return 0;
}
