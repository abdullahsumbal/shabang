#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define BOOLEAN int


// global variables
int size = 1024;
int splited_buffer_size;
int hasNextToken_index;
int nextToken_index;

char splited_buffer[30][100];
char *copyInput;


void initBuffer(char *inputLine){
	
	// - function varialbe
	char *current_token = NULL;
	char buffer[3000];

	// - copying the inputline for rewinding (used later)
	copyInput = inputLine;
	
	// - copy inputline to buffer
	strcpy(buffer, inputLine);
	
	// - filling the buffer
	strcpy(buffer, inputLine);
	current_token = strtok( buffer, " ,");
	splited_buffer_size = 0;

	while(current_token !=NULL){

		// - Eliminating line feed and carraige return
		int i;	
		for(i = 0; i < strlen(current_token); i++){
			//current_token[i] = tolower(current_token[i]);
			if(current_token[i] == '\n' || current_token[i] == '\r'){
			current_token[i]='\0';
			break;
		} 
	}	

		strcpy(splited_buffer[splited_buffer_size], current_token); 
		current_token = strtok( NULL, " ,");
		splited_buffer_size++;
	}
	// - two index fo different functions. -2 & -1 because to get the first element
	hasNextToken_index = -2;
	nextToken_index = -1;
}

// - check to see if the token is available
BOOLEAN hasNextToken(){

	if(splited_buffer_size - 1 > hasNextToken_index + 1){

		// - elements in buffer exist
		return 1;

	}else{
		// - no element in the buffer 
		return 0;
	}
}

// - get the next token
char *nextToken(){

	if(hasNextToken() != 0){

		// - increase buffer index to correspond the current string
		nextToken_index++;
		hasNextToken_index++;
		return splited_buffer[nextToken_index];
	}else{

		return NULL;
	}
}

// - rewind the buffer back to begin of the string
void myRewind(){

	initBuffer(copyInput);
}
