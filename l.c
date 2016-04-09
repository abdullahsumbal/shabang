// Test file for to read CGI packet contents
#include <stdio.h>
int main ( int argc , char * argv[])
{
	printf ( "Content-Type: text/html\n\n" );	
	printf ( "HHellolw");
	printf ( "<html><title>Hello</title><body>\n" );
	printf ( "comon\n" );
	printf ( "</body></html>" );
	char * data;
	data = getenv ( "QUERY_STRING" );
	if ( data == NULL )
	{
		printf ( "Error" );
	}
	else
	{
		printf ( "Success");
	}

	return 1;
}
