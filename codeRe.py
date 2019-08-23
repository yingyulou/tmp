#!/bin/env python
# coding=UTF-8

# Import Python Lib
import re

codeStr = 'localSession.query(sessionDB).filter_by(\n    sessid=sessionID[:16]).first()'

print re.sub(r'localSession\.query\((\w+)\)\.filter_by\(\s*(.+?)=(.+?)\)\.first\(\)',
    r'localSession.query(\1).filter(\n    \1.\2==\3).first()', codeStr)
