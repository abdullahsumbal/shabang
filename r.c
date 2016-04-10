#include <string.h>
#include <stdio.h>

int inFile ( char * , FILE * );
void resetToken ( char * , int ); 
int main ( int argc , char * argv )
{
	// let browser know we will write html
	printf ( "Content-Type: text/html\n\n" );
	
//	Gets the form data from the shell var QUERY_STRING 
	char * data = getenv ( "QUERY_STRING" );


	
	// so just use one string and check it against the file users.txt
	// loop through form and check that current string ie token is not present in the file

	// write to file
	// open file
	FILE * users;
	FILE * toAdd; // pointer for appending
	users = fopen ( "../users.txt" , "r" ); // r for read. a for append. PARENT DIR
	

	// need length of string to know howlong to loop for
	int length = strlen ( data );
	char token[50]; // will contain the string from one of the 4 fields. always terminates with '\0' because of resetToken function
	resetToken ( token , 50 );

	int i = 0; // counter for index in while
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
			if ( inFile ( token , users ) == 0 ) 		
			{
				//display error
				FILE * registrationError = fopen ( "../registerError.html" , "r" ); // html is in parent dir!!!
				char c = getc ( registrationError );
				while ( c != EOF )
				{
					putchar ( c ); // write each char from file to client browser
					c = fgetc ( registrationError ); // get the next character
				}
				return 0; // break program
			}
			else // append to file. We can append the tokens in order because thats the order we read them in. uname|passw|fulln|jobdes
			{
				// append to file with puts?
				toAdd = fopen ( "../users.txt" , "a" ); // PARENT DIR
				// need to change '\0' to '\n' so fputs formats file correctly
				token[tIndex] = '\n'; // NOTE that it was '\0' for inFile function
				fputs ( token , toAdd ); // WHY DID THIS WORK?? I tried it on a hunch but don't totally understand
				fclose ( toAdd ); // close file we just wrote to	
			}	
		}
   		else if ( isToken == 0 )
		{
			token[tIndex] = data[i];
			tIndex ++; // fill next position
		} 
		else // reset token so that we always write a string terminating '\0'
		{
			resetToken( token , 50 ); // populates token array with '\0'
		}
		i ++; // index to loop through data
	}	

	// if we make it through the above while that means we appended to the users.txt file
	// now we display the success html page	
	FILE * registrationSuccess;
	registrationSuccess = fopen ( "../registerSuccess.html" , "r" ); // html file is above dir where cgi runs......!!!
	if ( registrationSuccess == NULL )
		printf ( "<h1>ERROR</h1>" );
	int c = fgetc ( registrationSuccess );
	while ( c != EOF )
	{
		printf ( "%c" , c ); // write each char from file to client browser
		c = fgetc ( registrationSuccess ); // get the next character
	}
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
