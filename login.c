#include <stdio.h>
#include <string.h>

int inFile ( char * , FILE * );
void resetToken ( char * , int );
int main(int argc, char *argv[])
{

   
	printf("Content-Type: text/html\n\n");
	char *data = getenv("QUERY_STRING");
	//printf("%s", data);

	// so just use one string and check it against the file users.txt
	// loop through form and check that current string ie token is not present in the file

	// write to file
	// open file
	FILE * users;
	users = fopen ( "../users.txt" , "r" ); // r for read. a for append. PARENT DIR
	if ( users == NULL )
	{
		printf ( "FILE NOT FOUND" );
		 return 0;	
	}

	// need length of string to know howlong to loop for
	int length = strlen ( data );
	char token[50]; // will contain the string from password field or uname field. always terminates with '\0' because of resetToken function
	resetToken ( token , 50 );
	// online will store the username of the current userj
	char online [50];
	resetToken ( online , 50 );
	// url of dash
	char * dashUrl =  "https://cgi.cs.mcgill.ca/~yzhu399/dashboard.py"; 
	int i = 0; // counter for index in while
	int validCred = 0; // flag to determine if user entered valid username and password
	int isToken = 1; // flag for a token
	int tIndex = 0; // counter for index in token
	while ( i <= ( length + 1 )) // stops at end of string +1 because we need a final loop to check the last token. +1 includes the '\0'
	{
		if ( data[i] == '=' ) // reached field input
		{
			isToken = 0;
			tIndex = 0;
		}
		else if (( data[i] == '&' ) || ( data [i] == '\0' )) // field entry ended at & or end of string
		{
			isToken = 1; // reached end of field input. by field input I mean what the user entered in the text box in the form
			token[tIndex] = '\0'; // terminate token
			// Now we check if the token is in the file
			// if in file
			if ( inFile ( token , users ) == 0 ) 	// Valid username or password	
			{
				validCred ++; // we found a valid username or password
				//display success
				// redirect them to dashboard
				// write to currentUser.txt
				printf ( " token is : %s \n" , token );
				printf ( " and is in file users.txt\n" );	
				if ( validCred == 2 )
				{	
					FILE * currentUser = fopen ( "../currentUser.txt" , "w" );
					fprintf ( currentUser , online );
					printf ( "<h3><a href=\"%s\">MyDashboard</a></h3>" , dashUrl );
					return 0; // successful login
				}
				else if ( validCred == 1 ) // store the username in online
				{
					strcpy ( online , token );
				}
			}
			else // user entered invalid credentials
			{
				// display error
				printf ( " invalid " );				
				FILE * errorLogin; 
				errorLogin = fopen ( "../loginError.html" , "r" ); //pointer to login html page
				if ( errorLogin == NULL )
				{
					printf ( "<h1>Error</h1>");
					return;
				}
				char c = fgetc ( errorLogin ); // get char from html page
				while ( c != EOF ) // print error page to user
				{
					putchar ( c );
					c = fgetc ( errorLogin );
				}
				return 1;
			}	
		}
   		else if ( isToken == 0 )
		{
			token[tIndex] = data[i]; // begin to read into token cause we point to first char of user entry 
			tIndex ++; // fill next position
		} 
		else // reset token so that we always write a string terminating '\0'
		{
			resetToken( token , 50 ); // populates token array with '\0'
		}
		i ++; // index to loop through data
	}	

	//
	return 0;
}

// function to take an array an make every index '\0'void
void resetToken ( char * input , int size )
{
	int i = 0 ;
	for ( i; i < size; i ++ )
	{
		input[i] = '\0';
	}	 
}


// function to check if a string is in the file
// FILE should be a column of username|password|fullname|jobdescripton where | is newline
int inFile ( char * token , FILE * file )
{
	// so we will read each word into a buffer. We read into the buffer if the current char is between 33 and 122 ascii or between ! and z
	// once we reach a space ie 32 or something out of our range we terminate the buffer with '\0' 
	// then we strcmp buffer with token and if it matches token is in file
		// return 0
	//else
		// return 1
	char c = fgetc ( file );
	char buffer[50]; // holds current word
	int bCounter = 0; // bufferCounter index
	while ( c != EOF )
	{
		if (( c > 32 ) && ( c < 123 )) // read words into buffer
		{
			buffer[bCounter] = c;	
			bCounter ++;
		}
		else // terminate buffer and compare token to buffer
		{
			buffer[bCounter] = '\0'; // already at next index since bCounter ++ at last valid char
			//-----------compare now that buffer full------------------//
			if ( strcmp ( token , buffer ) == 0 )
			{
				return 0;	
			}

			bCounter = 0; // need to reset 
		}
		c = fgetc ( file ); // need to check first character of file

	}
	return 1; // token not in file
}

