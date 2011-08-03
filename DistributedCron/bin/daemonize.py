#!/bin/env python

import sys, os

def daemonize(stdin = '/dev/null', stdout = '/dev/null', stderr =
	'/dev/null'):

    # First fork, make sure our process is not the process group leader,
    # so next setsid() call will create a new session

    try:
	pid = os.fork()
	if pid > 0:
	    # Grand father exit
	    sys.exit(0)
    except OSError, e:
	sys.stderr.write('fork #1 failed: (%d) %s\n', (e.errno, e.strerror))
	sys.exit(1)


    # Creates a new session, make our process:
    #	1. is the leader of the new session,
    #	2. is the process group leader of the new process group,
    #	3. has no controlling tty. (So we will not receive signals unexpectedly, like SIGHUP)
    os.setsid()

    # Second fork
    try:
	pid = os.fork()
	if pid > 0:
	    # Father exit
	    sys.exit(0)
    except OSError, e:
	sys.stderr.write('fork #2 failed: (%d) %s\n', (e.errno, e.strerror))
	sys.exit(1)

    # Redirect standard descriptors
    for f in sys.stdout, sys.stderr: f.flush()

    si = file(stdin, 'r')
    so = file(stdout, 'a+')
    se = file(stderr, 'a+', 0)

    os.dup2(si.fileno(), sys.stdin.fileno())
    os.dup2(so.fileno(), sys.stdout.fileno())
    os.dup2(se.fileno(), sys.stderr.fileno())
