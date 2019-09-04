#!/bin/env python
# coding=UTF-8

# Import Python Lib
import re

oriStr = '''<a>
1
2
3
</a>
<b>
4
5
6
</b>
<c>
7
8
9
</c>
'''

print([findGroupList[1].split() for findGroupList in re.findall(r'<(\w+)>([\w\n]*?)</\1>', oriStr)])