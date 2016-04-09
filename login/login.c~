#include <stdio.h>
#include <string.h>
#include "parse.h"

#define boolean int
#define FALSE 0

int main(int argc, char *argv[]){

	// - given user name and password
	char * username = "abc";
	char * password = "password";
	char * username_file;
	char * password_file;
	boolean check_password = FALSE;

	// - class variables
	size_t length =256;
	char *line =NULL;//(char *)malloc(length);

	// - open users.text
	FILE *file;
	file = fopen(argv[1], "r");
	int read;

	// - if file not found dispay correct format and exit program
	if(!file){
		
		printf("The following file can not be found \n");
		printf("Correct Format :  ./a.out [file_name or path/file_name]\n");
		return 1;
	}

	// - get everyline 
    while ((read = getline(&line, &length, (FILE*)file)) != -1) {
        printf("%s \n", line);
       	initBuffer(line);

       	// check username
       	if(hasNextToken() && strcmp("USERNAME", nextToken()) == 0){

       		// - get the username
       		username_file = nextToken();

       		if(strcmp(username_file,username)==0){
       			
       			// - get next line and check password
       			getline(&line, &length, (FILE*)file);
       			initBuffer(line);
       			printf("%s \n", line);

       			// - get the password
       			nextToken(); password_file = nextToken();

       			if(strcmp(password_file,password) == 0){
       				printf("the username and passowrd is coorect\n");
       				break;
       			}

       			
       		}
       	}


    }

     fclose(file);



	return 0;
}

