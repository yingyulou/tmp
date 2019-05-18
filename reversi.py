#!/bin/env python
# coding=UTF-8

# Import Python Lib
from copy import deepcopy

# Global Variable Define
__BOARD_TEMPLATE = '''
1| %s | %s | %s | %s | %s | %s | %s | %s |
----------------------------------
2| %s | %s | %s | %s | %s | %s | %s | %s |
----------------------------------
3| %s | %s | %s | %s | %s | %s | %s | %s |
----------------------------------
4| %s | %s | %s | %s | %s | %s | %s | %s |
----------------------------------
5| %s | %s | %s | %s | %s | %s | %s | %s |
----------------------------------
6| %s | %s | %s | %s | %s | %s | %s | %s |
----------------------------------
7| %s | %s | %s | %s | %s | %s | %s | %s |
----------------------------------
8| %s | %s | %s | %s | %s | %s | %s | %s |
----------------------------------
 | a | b | c | d | e | f | g | h |
'''


__DIRECT_TUPLE = (
    (-1, -1),
    (-1, 0),
    (-1, 1),
    (0, -1),
    (0, 1),
    (1, -1),
    (1, 0),
    (1, 1),
)


################################################################################
# Create A New Board
################################################################################

def new_board():

    board = [[0] * 8 for i in range(8)]
    board[3][3], board[4][4], board[3][4], board[4][3] = 2, 2, 1, 1

    return board


################################################################################
# Print Board
################################################################################

def print_board(board, validCoordList = []):

    for row, col in validCoordList:
        board[row][col] = 3

    print(__BOARD_TEMPLATE % tuple([(' ', 'B', 'W', '*')[j] for i in board for j in i]))

    for row, col in validCoordList:
        board[row][col] = 0


################################################################################
# Get Score
################################################################################

def score(board):

    scoreList = [0] * 3

    for i in board:
        for j in i:
            scoreList[j] += 1

    return scoreList[1], scoreList[2]


################################################################################
# Enclosing
################################################################################

def enclosing(board, player, pos, direct):

    midNum, tarNum = (1, 2) if player == 2 else (2, 1)
    (nowRow, nowCol), (dirRow, dirCol) = pos, direct

    nowRow += dirRow
    nowCol += dirCol

    # If 1 2 1 etc.
    midBool = False

    while 0 <= nowRow <= 7 and 0 <= nowCol <= 7:

        if board[nowRow][nowCol] == 0:
            break
        elif board[nowRow][nowCol] == midNum:
            midBool = True
        else:
            if midBool:
                return True
            else:
                break

        nowRow += dirRow
        nowCol += dirCol

    return False


################################################################################
# Juege If The Coord Is Possiable To Cheak
################################################################################

def __ifPossiable(board, tarRow, tarCol):

    if board[tarRow][tarCol]:
        return False

    for dirRow, dirCol in __DIRECT_TUPLE:

        nowRow, nowCol = tarRow + dirRow, tarCol + dirCol

        if 0 <= nowRow <= 7 and 0 <= nowCol <= 7 and board[nowRow][nowCol] != 0:
            return True

    return False


################################################################################
# Get Valid Moves
################################################################################

def valid_moves(board, player):

    validCoordList = []

    for nowRow in range(8):
        for nowCol in range(8):
            if __ifPossiable(board, nowRow, nowCol):
                for direct in __DIRECT_TUPLE:
                    if enclosing(board, player, (nowRow, nowCol), direct):
                        validCoordList.append((nowRow, nowCol))
                        break

    return validCoordList


################################################################################
# Get Next State
################################################################################

def next_state(board, player, pos):

    board = deepcopy(board)
    board[pos[0]][pos[1]] = player

    for direct in __DIRECT_TUPLE:
        if enclosing(board, player, pos, direct):

            nowRow, nowCol = pos
            dirRow, dirCol = direct
            nowRow += dirRow
            nowCol += dirCol

            while board[nowRow][nowCol] != player:
                board[nowRow][nowCol] = player
                nowRow += dirRow
                nowCol += dirCol

    nextPlayer = 2 if player == 1 else 1

    validCoordList = valid_moves(board, nextPlayer)

    if validCoordList:
        return board, nextPlayer, validCoordList

    else:

        validCoordList = valid_moves(board, player)

        if validCoordList:
            return board, player, validCoordList
        else:
            return board, None, validCoordList


################################################################################
# Get Position
################################################################################

def position(string):

    try:

        colChar, rowChar = string

        rowNum = int(rowChar) - 1
        colNum = ord(colChar) - 97

        if 0 <= rowNum <= 7 and 0 <= colNum <= 7:
            return rowNum, colNum
        else:
            return None

    except ValueError:
        return None


################################################################################
# Game Over
################################################################################

def __gameOver(board):

    print('Game Over!')

    scoreA, scoreB = score(board)

    if scoreA > scoreB:
        print('Player 1 Win!')
    elif scoreA < scoreB:
        print('Player 2 Win!')
    else:
        print('Draw!')


################################################################################
# Run Two Players
################################################################################

def run_two_players():

    board  = new_board()
    player = 1

    while True:

        validCoordList = valid_moves(board, player)
        print_board(board, validCoordList)

        while True:

            string = input('Player %d: ' % player)
            pos = position(string)

            if pos is not None and pos in validCoordList:
                break
            else:
                print('Wrong input!')

        board, player, validCoordList = next_state(board, player, pos)

        if player is None:
            __gameOver(board)
            break


################################################################################
# Run Single Player
################################################################################

def run_single_player():

    board  = new_board()
    player = 1

    while True:

        validCoordList = valid_moves(board, player)
        print_board(board, validCoordList)

        while True:

            string = input('Player %d: ' % player)
            pos = position(string)

            if pos is not None and pos in validCoordList:
                break
            else:
                print('Wrong input!')

        board, player, validCoordList = next_state(board, player, pos)

        while player != 1:

            # Game Over
            if player is None:
                __gameOver(board)
                return

            # Computer
            elif player == 2:
                maxScorePos = max(validCoordList, key = lambda pos: score(next_state(board, player, pos)[0])[1])
                board, player, validCoordList = next_state(board, player, maxScorePos)


################################################################################
# Main Program Define
################################################################################

def main():

    run_single_player()
#    run_two_players()


if __name__ == '__main__':
    main()