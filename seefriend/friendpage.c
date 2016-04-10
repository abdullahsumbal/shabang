#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "parse.h"
#define USERS_TXT "users.txt"
#define STATUS_TXT "status.txt"


int main(int argc, char* argv[]){

	// - local variable 
	char * friendUserName;
	size_t length =256;
	char * line =NULL;

	printf("Content-Type:text/html\n\n");
    printf("<html>" );
    printf("<title>Friends page </title>");

    // - get the friends name
    char * data = getenv("QUERY_STRING");
    friendUserName = strtok( data, "+");
    friendUserName = strtok( NULL, "+");

    // - read his info from users.txt
    FILE *userFile;
    userFile = fopen(USERS_TXT, "r");
    int readUser;

    if(!userFile){
		
		printf("The user.txt can not be found \n");
		return 1;
	}

    // - read his info from status.txt
    FILE *statusFile;
    statusFile = fopen(STATUS_TXT, "r");
    int readStatus;

    if(!statusFile){
		
		printf("The status.txt can not be found \n");
		return 1;
	}

	// - finding user name in user.txt file
    while ((readUser = getline(&line, &length, (FILE*)userFile)) != -1) {

       	initBuffer(line);

       	// - find the user friends
       	if(strcmp(nextToken(),friendUserName) == 0){
       		getline(&line, &length, (FILE*)userFile);
			getline(&line, &length, (FILE*)userFile);
			initBuffer(line);
			printf("Username : %s<br/>", friendUserName);
			printf("Full name :%s<br/>", nextToken());
			getline(&line, &length, (FILE*)userFile);
			initBuffer(line);
			printf("Job Description :%s <br/>",nextToken());
       	}


    
    }
    fclose(userFile);

    // - finding user name in status.txt file
    while ((readStatus = getline(&line, &length, (FILE*)statusFile)) != -1) {

       	initBuffer(line);
       	if(strcmp(nextToken(),friendUserName) == 0){
       		char * status = strstr(line, " ");
       		printf("status :%s <br/>",status);

       	}

    }
    fclose(statusFile);


    printf("</html>");

     return 0;

}