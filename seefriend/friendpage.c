#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "parse.h"
#define USERS_TXT "users.txt"
#define STATUS_TXT "/home/2015/yzhu399/public_html/status.txt"
//#define STATUS_TXT "status.txt"

int main(int argc, char* argv[]){

	// - local variable 
	char * friendUserName;
	size_t length =256;
	char * line =NULL;

	printf("Content-Type:text/html\n\n");
    printf("<html><body style=\"background-color: #CA8E45\">" );
    printf("<title>Friends page </title>");

    // - back to see friend page
    printf("<a href = \"http://www.cs.mcgill.ca/~eander40/seefriend.cgi\">See Friend page</a> <br/>");

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
	char * current_Token = nextToken(); 
	if ( NULL != ( strstr ( line , friendUserName )))
	{
		printf ( " %s\n<br> " , line );
		
	}
/*
//	printf ( "%s<br>\n" , friendUserName );
	//printf ( " length current_Token %d : %s <br> " , strlen ( current_Token ) , current_Token );	
//	printf ( "username Length %d : %s <br> " , strlen ( friendUserName ) , friendUserName );
       	if(strcmp(current_Token,friendUserName) == 0){
       		char * status = strstr(line, " ");
       		printf("status :%s <br/>",status);

       	}
*/
    }
    fclose(statusFile);


    printf("</body></html>");

     return 0;

}
