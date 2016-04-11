#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "parse.h"

#define BOOLEAN int
#define SEEFRIENDS_FILE "friends.txt"
#define CURRENTUSER_FILE "currentUser.txt"

// - these values are examples
char username[50];

int main(int argc, char* argv[]){

	printf("Content-Type:text/html\n\n");
	// - local variable 
	size_t length =256;
	char * line =NULL;
	char * current_token();

	// - open current_user.txt
	FILE *currentUser_file;
	currentUser_file = fopen(CURRENTUSER_FILE, "r");
	getline(&line, &length, (FILE*)currentUser_file);
	//username = line;
	strcpy (username, line);
//	username[strlen(username)-1]='\0';
	//username
	//username = "msumba";

	fclose(currentUser_file);

	// - display message on screen 
 	
     printf("<html>" );
	printf ( "<body style=\"background-color:#CA8E45\">" );
     printf("<title>See Friends</title>");
     



	// - open friends.tct
	FILE *file;
	file = fopen(SEEFRIENDS_FILE, "r");
	int read;

	// - if file not found dispay correct format and exit program
	if(!file){
		
		printf("The following file can not be found \n");
		printf("Correct Format :  ./a.out [file_name or path/file_name]\n");
		return 1;
	}

	// - get everyline 
    while ((read = getline(&line, &length, (FILE*)file)) != -1) {
        //printf("reading line -----> %s \n", line);
       	initBuffer(line);

       	// - find the user friends
       	if(strcmp(nextToken(),username) == 0){

       		printf("user %s friends are ",username);

       		printf("<form name=\"input\" action=\"http://cgi.cs.mcgill.ca/~eander40/friendpage.cgi\" method=\"get\">");

       		while(hasNextToken()){
       			char * friend = nextToken();
       			printf(" <input type=\"radio\" name=\"friendusername\" value=\" %s \" checked> %s<br> ",friend, friend);
       		}


       		printf("<input type=\"submit\" value=\"See profile \">");
       		printf("</form>");
       	}

    
    }
	printf ( "<a href=\"https://cgi.cs.mcgill.ca/~yzhu399/dashboard.py\">To Dashboard</a>" );
    printf("</body></html>");

	return 0;

}
