#!/usr/bin/env python

import pexpect
import getpass
import time
import sys

# SMTP:25 IMAP4:143 POP3:110
tunnel_command = 'ssh -CTN -D 127.0.0.1:1080 %(user)s@%(host)s'

user = 'sshprxy'
host = 'benguo.me'
X = '123456'
def start_tunnel ():
    try:
        ssh_tunnel = pexpect.spawn (tunnel_command % globals(),
		timeout=None)
        ssh_tunnel.expect ('password:')
	ssh_tunnel.logfile_read=sys.stdout
        time.sleep (0.1)
        ssh_tunnel.sendline (X)
	print "Password sent, tunnel started on port 1080"
        ssh_tunnel.expect (pexpect.EOF)

    except Exception, e:
        print str(e)

def main ():
    while True:
	start_tunnel()
	print "ssh exists, start it 1 seconds later ..."
	time.sleep(1)

if __name__ == '__main__':
    main ()
