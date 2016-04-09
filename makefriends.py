#!/usr/bin/python
# my first python script
import cgitb
import sys
import itertools
cgitb.enable()

print "Content-type: text/html\n\n"
print
print 
	
string = """<!DOCTYPE html>
		<html>
		<head>
		</head>
		<body>
			<center>
				<h1>Make Friends</h1>
			<form action="http://cgi.cs.mcgill.ca/~eander40/newfriends.py" method="gets">	
 """ 
print string
with open ( "users.txt" , "r" ) as users: # opens file, reads and prints everyother line
	count = 1
	for line in users:
		count += 1
		if count % 2 == 0:
			if count % 4 == 0:
				print "<input type=\"checkbox\" name=\"fullname\" value=\"" + line + "\">" + line + "<br>" # makes name in form the actual fullname
				# need to make it so that the form submits the fullname
				# then the newfriends.py will use the contents in cgi format to 
				# write to the friends.txt file
			else:
				print "<h1>user: " + line + "</h1>"

	

print """
				<input type=\"submit\" value=\"addfriend\"> 
			</form>
			</center>
		</body>
		</html> 
"""


