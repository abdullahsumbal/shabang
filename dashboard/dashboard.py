#!/usr/bin/python

import urllib, os

user = urllib.urlopen("http://www.cs.mcgill.ca/~eander40/currentUser.txt")
currentUser = user.read()

os.system("touch status.txt")
# if status.txt does not exist, it will be created
# error if this line is not here and status.txt does not exist

f = open("status.txt", "r")
lines = f.readlines()
f.close()

everyone = urllib.urlopen("http://www.cs.mcgill.ca/~eander40/friends.txt")

print "Content-type: text/html\n\n"
print "<html>"
print "<head>"
print "<title> Dashboard </title>"
print "</head>"
print '<body bgcolor="#CA8E45" text="black">'
print' <center>'
print ' <a href="http://www.cs.mcgill.ca/~eander40/makefriends.py">Make Friends</a>'
print ' <a href="http://www.cs.mcgill.ca/~eander40/seefriend.cgi">See Friends</a>'
print ' <a href="http://www.cs.mcgill.ca/~eander40">Logout</a>'
print "<h1> Dashboard </h1>"
print'	<form name="input" action="status.py" method="get">'
print'		Post: <input type="text" name="status" />'
print'		<input type="submit" value="Post" />'
print"	</form>"
# make a list
# reverse the list
# get the first 20 posts with friends usernames

for line in everyone:
	#look for user in first name
	
	line = line.replace("\r", "")

	if line.partition(' ')[0] == currentUser:
	 	friends = line
		friends = friends.split()
	
lines.reverse()
counter = 0

for status in lines:

	# check if the poster of each status is a friend
	# add it to a list
	# print the first 20 elements in the list
	
	if counter == 20: break

	status = status.replace("\r", "")

	if status.partition(' ')[0] in friends:
		print status + "<br>"
		counter = counter + 1
print "</center"
print "</body>"
print "</html>"
