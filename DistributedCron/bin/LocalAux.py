#!/bin/env python26
# -*- coding: gbk -*-

import sys
import re

import smtplib
from email.MIMEText import MIMEText

import logging 

L = logging.getLogger('LocalAux')

class ConfigError(RuntimeError):
    pass

def get_value_set(flag, start, stop):
    if flag == '*':
	return set(range(start, stop))

    if re.match('\d+(,\d+)?', flag):
	value_set = set()
	for num in flag.split(','):
	    num = int(num)
	    if num < start or num >= stop:
		raise ConfigError('Invalid flag value(%d), flag should >= %d and < %d' %(
			num, start, stop))

	    value_set.add(num)

	return value_set

    m = re.match('\*/(\d+)', flag)
    if m:
	step = int(m.group(1))
	return set(range(start, stop, step))
	
	
    raise ConfigError("Invalid flag format: %s" % flag)

def parse_run_time_flags(flags):
    p = flags.strip().split()
    if len(p) != 2:
	raise ConfigError("Invalid run_time_flags: %s" % flags)

    minute_set = get_value_set(p[0], 0, 60)
    hours_set = get_value_set(p[1], 0, 24)

    return minute_set, hours_set

SMTP_SERVER_OP_PORTAL =  'op-portal'
mail_sender = 'guoshiwei@sogou-inc.com'
def send_mail(to_list, sub, content):
    ''' 
    to_list:发给谁
    sub:主题
    content:内容
    send_mail("aaa@126.com","sub","content")
    '''

    L.warning("No mail sent: %s" % sub)
    return False

    me = 'TaskRunner<%s>' % mail_sender
    msg = MIMEText(content)
    msg['Subject'] = sub 
    msg['From'] = me
    msg['To'] = ";".join(to_list)
    try:
        s = smtplib.SMTP()
        s.connect(SMTP_SERVER_OP_PORTAL)
        s.sendmail(me, to_list, msg.as_string())
        s.close()
        return True
    except Exception, e:
        print str(e)
        return False

mail_reciver = ('guoshiwei@sogou-inc.com',) 

def is_stdin_tty():
    return subprocess.call(['/usr/bin/tty', '-s']) == 0

def ReportSuccessExec(cmd):
    sub = 'EXEC_SUCCEED "%s"' % cmd

    L.info(sub)
    send_mail(mail_reciver, sub , '')
    L.info("SENDMAIL %s to %s SUCCEED" % (sub, mail_reciver))

def ReportFailExec(cmd, returncode, info):
    sub = 'EXEC_FAILED returncode=%d "%s"' % (returncode, cmd)
    L.info(sub)
    L.info(info)

    content = info
    send_mail(mail_reciver, sub , info)
    L.info("SENDMAIL %s to %s SUCCEED" % (sub, mail_reciver))

import unittest
class TaskConfigUnitTest(unittest.TestCase):

    def _one_test(self, flags, expect_minutes, expect_hours):
	minute_set, hours_set = parse_run_time_flags(flags)
	self.failUnlessEqual(minute_set, set(expect_minutes))
	self.failUnlessEqual(hours_set, set(expect_hours))
	return self

    def testparse_run_time_flags(self):
	self._one_test('* *', range(60), range(24))
	self._one_test('23 *', (23,), range(24))
	self._one_test('23 13', (23,), (13, ))
	self._one_test('23 */2', (23,), range(0, 24, 2))
	self._one_test('23,12,35 */2', (23,12,35,), range(0, 24, 2))

if __name__ == '__main__':
    sys.exit(unittest.main())
