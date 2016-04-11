#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{

/*    char *username = "eander40\n";
    char *password = "pword\n";

    int check_password = 0;
    int lineNo = 0;
    int userMatch = 0;

    size_t length =256;
    char *line = NULL;
    FILE *file;
    file = fopen("users.txt", "r");
    int read;

    FILE *current;
    current = fopen("currentUser.txt", "w");

    if(!file)
    {
        
        system("touch currentUser.txt");
    }
  
    while ((read = getline(&line, &length, file)) != -1) 
    {

        lineNo++;
        if(lineNo % 4 == 1)
        {
            if(strcmp(line, username) == 0)
            {
                userMatch = 1;
                fprintf(current, "%s", line);
                continue;
            }  
        }

        if(userMatch == 1)
        {
            //printf("<%s>", line);
            if(strcmp(line, password) == 0)
            {
                fprintf(current, "%s", line);
                break;
            }
            userMatch = 0;
        }           

    }

    if(userMatch == 1)
    {
        lineNo--;
        int jobDes = lineNo + 4;
      
        int copyLine = 0;
        while ((read = getline(&line, &length, file)) != -1)
        {
            if (copyLine == 2) break;

            fprintf(current, "%s", line);
            copyLine++;
        }
    
       fclose(current);
    }

    fclose(file);
*/
    printf("Content-Type: text/plain\n\n");
    printf("Hello World");
    return 1; 
}
