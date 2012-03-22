// Written by Siddharth Mahendraker
// Copyright (c) 2011

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){

	if(argv[1] == NULL){
		printf("An error occured, a shift value is required. \n");
		exit(EXIT_FAILURE);
	}

	// Not really modulo, but still works as encryption because of
	// the range of Unicode

	int shift = atoi(argv[1]) % 26;
	int encrypt;

	if(argv[2] == NULL){
		printf("An error occured, please use -e or -d to set the encryption/decryption mode. \n");
		exit(EXIT_FAILURE);
	} else {
		if(strcmp((char *)argv[2], "-e") == 0){
			encrypt = 1;
		}
		if(strcmp((char *)argv[2], "-d") == 0){
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
        if(i >= 65 && i <= 90){

		    if(encrypt == 1){
			    ctxt = i+shift;
		    }else{
			    ctxt = i-shift;
		    }

            if(ctxt > 90){
                ctxt = 65 + (ctxt - 91);
            }

            if(ctxt < 65){
                ctxt = 91 - (65 - ctxt);
            }

		    // Performs the shift and prints the resulting character
		    char c = (char) ctxt;
            //printf("%i\n", ctxt);
		    printf("%c", c);
        }

		i = fgetc(file);
	}

	fclose(file);

	return 0;
}
