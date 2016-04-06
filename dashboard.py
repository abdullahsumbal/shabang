#!/usr/bin/python

f = open("status.txt", "r")
last20Lines = f.readlines()[-21:]
f.close()

print "Content-type: text/html\n\n"
print "<html>"
print "<head>"
print "<title> Dashboard </title>"
print "</head>"
print '<body bgcolor="white" text="black">'
print ' <a href="http://www.cs.mcgill.ca/~eander40/friends.py">Make Friends</a>'
print ' <a href="http://www.cs.mcgill.ca/~eander40">Logout</a>'
print "<h1> Dashboard </h1>"
print'	<form name="input" action="status.py" method="get">'
print'		Post: <input type="text" name="status" />'
print'		<input type="submit" value="Post" />'
print"	</form>"
for line in last20Lines:
	print "%s<br>" % line
print "</body>"
print "</html>"



