#!/usr/bin/python
# This python script runs when the user wants to add the friends checked
import cgitb # lets us interpret cgi formating
import sys
import cgi
cgitb.enable() # enables some debuggin???

print "Content-type: text/html\n\n" # line that lets the client browser know we write html
form = cgi.FieldStorage()


fullname = form.getvalue ( 'fullname' ) # get the fullname stored in value attribute of html. html form name="fullname" has value
print fullname
http://cgi.cs.mcgill.ca/~yzhu399/friends.txt
'''
form now contains name="fullname" value="actualFullNameOfUser"
parse the form and write the actualFullNameOfUser to friends.txt file
need to know the format of the form what does it look like?
form needs to contain the fullnames of users
then write to friends.txt

'''
print "hey"

'''
	need to parse the form and write to the friends.txt file correctly
'''
