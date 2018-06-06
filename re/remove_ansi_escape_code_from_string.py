#!/usr/bin/env python
import re

# See https://en.wikipedia.org/wiki/ANSI_escape_code
def escape_ansi(line):
    ansi_escape =re.compile(r'(\x9B|\x1B\[)[0-?]*[ -\/]*[@-~]')
    return ansi_escape.sub('', line)
print escape_ansi(line = u'\t\u001b[0;35mSomeText\u001b[0m\u001b[0;36m172.18.0.2\u001b[0m')
