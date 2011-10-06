// Written by Siddharth Mahendraker
// Copyright (c) 2011 

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){

	if(argv[1] == NULL || argv[1] == ""){
		printf("An error occured, a shift value is required.\n");
		exit(EXIT_FAILURE);
	}

	int shift = atoi(argv[1]) % 26;
	FILE *file = fopen(argv[2], "r");
	
	if(file == NULL){
		printf("An error occured opening the file %s \n",argv[2]);
		exit(EXIT_FAILURE);
	}

	int i = fgetc(file);

	while(i != EOF){
		printf("%c",(char) i);
		i = fgetc(file);
	}

	// Do some stuff here

	fclose(file);

	return 0;
}


