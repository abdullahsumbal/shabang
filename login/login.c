#include <stdio.h>
#include <string.h>
#include "parse.h"

int main(int argc, char *argv[]){

    // - given user name and password
    char * username = "abc\n";
    char * password = "password\n";
    char * username_file = username;
    char * password_file = password;
    int check_password = 0;
    int lineNo = 1;
    int userMatch = 0;

    // - class variables
    size_t length =256;
    char *line =NULL;//(char *)malloc(length);

    // - open users.text
    FILE *file;
    file = fopen("users.txt", "r");
    int read;

    // - if file not found dispay correct format and exit program
    if(!file)
    {
        
        printf("The following file can not be found \n");
        printf("Correct Format :  ./a.out [file_name or path/file_name]\n");
        return 1;
    }

    // - get everyline \
    
    while ((read = getline(&line, &length, (FILE*)file)) != -1) 
    {
        //printf("%s + LineNo <%d> + \n", line, lineNo);
        printf("UserMatch <%d>\n", userMatch);
        lineNo++;
        if(lineNo % 4 == 1)
        {
            if(strcmp(line, username_file) == 0)
            {
                userMatch = 1;
                printf("Here\n");
                continue;
            }  
        }

        if(userMatch = 1)
        {
            printf("<%s>", line);
            if(strcmp(line, password_file) == 0)
            {
                printf("There");
                break;
            }
            userMatch = 0;
        }

        

    }

    if(userMatch == 1)
    {
        int jobDes = lineNo + 4;

        printf("DOES THIS PRINT?!");
        FILE *current;
        current = fopen("currentUser.txt", "w");
        for(lineNo = lineNo - 1; lineNo < jobDes; lineNo++)
        {
            printf("line based off line number");
        }

    }


    fclose(file);



    return 0;
}

