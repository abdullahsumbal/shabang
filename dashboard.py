#!/usr/bin/python

print "Content-type: text/html\n\n"
print "<html>"
print "<head>"
print "<title> Dashboard </title>"
print "</head>"
print '<body bgcolor="white" text="black">'
print "<h1> Dashboard </h1>"
print'	<form name="input" action="status.py" method="get">'
print'		Post: <input type="text" name="status" />'
print'		<input type="submit" value="Post" />'
print"	</form>"
print "</body>"
print "</html>"
