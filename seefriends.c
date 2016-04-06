#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    FILE *fp;
    char *line = NULL;
    int lineNum = 0;
    size_t len = 0;
    ssize_t read;
    fp = fopen("users.txt", "r");

    printf("Content-Type:text/html\n\n");
    printf("<html>");
    printf("<body>");

    // error opening the file
    if(fp == NULL)
    {
        printf("ERROR OPENING THE FILE\n");
        return 1;
    }

    while ((read = getline(&line, &len, fp)) != -1)
    {
        printf(line);
		printf("<br>");
	}
	printf("</body></html>");
    free(line);
    fclose(fp);

    return 0;
}
