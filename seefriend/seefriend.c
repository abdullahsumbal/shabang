#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "parse.h"

#define BOOLEAN int
#define SEEFRIENDS_FILE "friends.txt"

// - these values are examples
char * username = "msumba";

int main(int argc, char* argv[]){

	// - display message on screen 
 	 printf("Content-Type:text/html\n\n");
     printf("<html>" );
     printf("<title>See Friends</title>");
     printf("</html>");

	// - local variable 
	size_t length =256;
	char * line =NULL;
	char * current_token();

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
       		printf("<form name=\"input\" action=\"http://cgi.cs.mcgill.ca/~msumba/seefriend/friendpage.cgi\" method=\"get\">");
       		while(hasNextToken()){
       			char * friend = nextToken();
       			printf(" <input type=\"radio\" name=\"friendusername\" value=\" %s \" checked> %s<br> ",friend, friend);
       		}
       		printf("<input type=\"submit\" value=\"See profile \">");
       		printf("</form>");
       	}

    
    }

	return 0;

}
