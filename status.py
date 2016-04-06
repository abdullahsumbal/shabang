#!/usr/bin/python

import cgi, cgitb
form = cgi.FieldStorage()

#figure out a way to get the username
status = form.getvalue('status')

print "Content-type: text/html\n\n"
print "%s" % status

if status: 
	f = open("status.txt", "a")
	f.write( status + " \n\r")
	f.close()
