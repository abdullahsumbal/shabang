#!/usr/bin/python
# my first python script
import cgitb
import sys
import itertools
cgitb.enable()

print "Content-type: text/html\n\n"
# the big string below generates the webpage	
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
with open ( "users.txt" , "r" ) as users: # opens file, reads and prints four lines. We need the usernames in form to write friends.txt w/usernames 
	count = 3 
	for line in users:
		count += 1
		if count % 4 == 0:
			print "<input type=\"checkbox\" name=\"fullname\" value=\"" + line + "\">" + line + "<br>" # makes name in form the actual fullname
				# then the newfriends.py will use the contents in cgi format to 
				# write to the friends.txt file


print """
				<input type=\"submit\" value=\"addfriend\"> 
			</form>
			<a href="https://cgi.cs.mcgill.ca/~yzhu399/dashboard.py">To Dashboard</a>
			</center>
		</body>
		</html> 
"""


