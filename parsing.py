#!/bin/env python
# coding=UTF-8

# Global Variable Define
__OPERATOR_PRIORITY_HASH = {
    '+': set(),
    '-': set(),
    '*': {'+', '-'},
    '/': {'+', '-'},
    '^': {'+', '-', '*', '/'},
}


__PRIORITY_HASH = {
    '+': {'+': 1, '-': 1, '*': -1, '/': -1, '^': -1, '(': -1, ')': 1, '#': 1},
    '-': {'+': 1, '-': 1, '*': -1, '/': -1, '^': -1, '(': -1, ')': 1, '#': 1},
    '*': {'+': 1, '-': 1, '*': 1, '/': 1, '^': -1, '(': -1, ')': 1, '#': 1},
    '/': {'+': 1, '-': 1, '*': 1, '/': 1, '^': -1, '(': -1, ')': 1, '#': 1},
    '^': {'+': 1, '-': 1, '*': 1, '/': 1, '^': 1, '(': -1, ')': 1, '#': 1},
    '(': {'+': -1, '-': -1, '*': -1, '/': -1, '^': -1, '(': -1, ')': 0},
    ')': {'+': 1, '-': 1, '*': 1, '/': 1, '^': 1, ')': 1, '#': 1},
    '#': {'+': -1, '-': -1, '*': -1, '/': -1, '^': -1, '(': -1, '#': 0},
}


OPERATOR_FUNCTION_HASH = {
    '+': lambda x, y: x + y,
    '-': lambda x, y: x - y,
    '*': lambda x, y: x * y,
    '/': lambda x, y: x / y,
    '^': lambda x, y: x ** y,
}


################################################################################
# Juege Float Char
################################################################################

def __isFloat(tarChar):

    return tarChar.isdigit() or tarChar == '.'


################################################################################
# Split Expr To List
################################################################################

def tokenization(expr):

    tokens = []

    # Parse 'xx.xx' to xx.xx
    tmpNumStr = ''

    for nowChar in expr:

        # Case 1: Float
        if __isFloat(nowChar):
            tmpNumStr += nowChar

        # Case 2: Space
        elif nowChar.isspace():
            continue

        # Case 3: Operator
        else:

            # Dump number
            if tmpNumStr:
                tokens.append(float(tmpNumStr))
                tmpNumStr = ''

            # Dump operator
            tokens.append(nowChar)

    # Dump the last number
    if tmpNumStr:
        tokens.append(float(tmpNumStr))

    return tokens


################################################################################
# Judge if op1 > op2
################################################################################

def has_precedence(op1, op2):

    return op2 in __OPERATOR_PRIORITY_HASH[op1]


################################################################################
# Get Back Expression Stack
################################################################################

def __getBackExprStack(tokens):

    # '#' is a patch
    midExprStack  = list(reversed(tokens + ['#']))
    operatorStack = ['#']
    backExprStack = []

    while operatorStack:

        # Case 1: Float
        if isinstance(midExprStack[-1], float):
            backExprStack.append(midExprStack.pop())

        # Case 2: Operator
        else:

            # Now we need to compare the priority between the top of operator stack and now operator
            # Case 1: Stack top > now operator
            if __PRIORITY_HASH[operatorStack[-1]][midExprStack[-1]] == 1:
                backExprStack.append(operatorStack.pop())

            # Case 2: Stack top < now operator
            elif __PRIORITY_HASH[operatorStack[-1]][midExprStack[-1]] == -1:
                operatorStack.append(midExprStack.pop())

            # Case 3: '(' and ')' or '#' and '#'
            else:
                midExprStack.pop()
                operatorStack.pop()

    backExprStack.reverse()

    return backExprStack


################################################################################
# Calc Back Expression
################################################################################

def __calcBackExpression(backExprStack):

    calcStack = []

    while backExprStack:

        nowStackValue = backExprStack.pop()

        if isinstance(nowStackValue, float):
            calcStack.append(nowStackValue)
        else:
            valueB, valueA = calcStack.pop(), calcStack.pop()
            calcStack.append(OPERATOR_FUNCTION_HASH[nowStackValue](valueA, valueB))

    return calcStack[0]


################################################################################
# Evaluate An Expression List
################################################################################

def simple_evaluation(tokens):

    backExprStack = __getBackExprStack(tokens)
    calcResult    = __calcBackExpression(backExprStack)

    return calcResult


################################################################################
# Complex Evaluation (Both str and list available)
################################################################################

def complex_evaluation(tokens):

    if isinstance(tokens, str):
        tokens = tokenization(tokens)

    calcResult = simple_evaluation(tokens)

    return calcResult


################################################################################
# Main Program Define
################################################################################

def main():

    # tokenization
    tokens = tokenization('(3.1 + 6*2^2) * (2 - 1)')
    print(tokens)

    # has_precedence
    print(has_precedence('*', '+'))
    print(has_precedence('^', '+'))
    print(has_precedence('*', '/'))
    print(has_precedence('*', '^'))

    # simple_evaluation
    print(simple_evaluation(tokens))

    # complex_evaluation
    print(complex_evaluation(tokens))
    print(complex_evaluation('(3.1 + 6*2^2) * (2 - 1)'))


if __name__ == '__main__':
    main()