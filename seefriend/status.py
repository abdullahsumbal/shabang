#!/usr/bin/python

import cgi, cgitb
form = cgi.FieldStorage()

#figure out a way to get the username
status = form.getvalue('status')

print "Content-type: text/html\n\n"
print ' <a href="http://www.cs.mcgill.ca/~yzhu399/dashboard.py">Back to Dashboard</a>'
if status: 
	f = open("status.txt", "a")
	f.write(status + " \n\r")
	f.close()
