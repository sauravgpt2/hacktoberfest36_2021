
import random, sys

# Defining the Board
board = [i for i in range(9)]
player, computer = '', ''

# Corners, Centers and Others, Respectively
moves = ((1, 7, 3, 9), (5, ), (2, 4, 6, 8))

# Winner's Combinations
winners = ((0, 1, 2), (3, 4, 5), (6, 7, 8), (0, 3, 6), (1, 4, 7), (2, 5, 8), (0, 4, 8), (2, 4, 6))

# Table
tab = range(1, 10)


# Function to Display the Board
def printBoard():
    x = 1
    for i in board:
        end = ' | '
        if x % 3 == 0:
            end = ' \n'
            if i != 1:
                end += '---------\n'
        char = ' '
        if i in ('X', 'O'):
            char = i
        x += 1
        print(char, end = end)


#  For Computer
def selectChar():
    chars = ('X', 'O')
    if random.randint(0, 1) == 0:
        return chars[::-1]
    return chars


# Check if a Move is Valid
def canMove(brd, player, move):
    if move in tab and brd[move-1] == move-1:
        return True
    return False


# Check if a PLayer can win the Game
def canWin(brd, player, move):
    places = []
    x = 0
    for i in brd:
        if i == player:
            places.append(x)
        x += 1
    ein = True
    for tup in winners:
        win = True
        for ix in tup:
            if brd[ix] != player:
                win = False
                break
        if win:
            break

    return win


# Function to Make Move
def makeMove(brd, player, move, undo = False):
    if canMove(brd, player, move):
        brd[move - 1] = player
        win = canWin(brd, player, move)
        if undo:
            brd[move - 1] = move - 1
        return True, win
    return False, False


# Player 2 [Computer]
def computerMove():
    move = -1

    # If I can Win, Others Don't Matter
    for i in range(1, 10):
        if makeMove(board, computer, i, True)[1]:
            move = i
            break

    if move == -1:
        # If player can win, block him
        for i in range(1, 10):
            if makeMove(board, player, i, True)[1]:
                move = i
                break
                
    if move == -1:
        # Otherwise, try to take one of the desired positions
        for tup in moves:
            for mv in tup:
                if move == -1 and canMove(board, computer, mv):
                    move = mv
                    break

    return makeMove(board, computer, move)


# Check for OverFlow
def spaceExist():
    return board.count('X') + board.count('O') != 9


# Main Method
if __name__ == '__main__':

    player, computer = selectChar()
    print('Player is [%s] and Computer is [%s]' % (player, computer))
    result = '%%% Deuce ! %%%'

    # Tic-Tac-Toe Game
    while spaceExist():
        printBoard()
        print("# Make Your Move! [1-9] : ", end = "")
        move = int(input())
        moved, won = makeMove(board, player, move)
        if not moved:
            print(' >> Invalid Number! Please Try Again !')
            continue

        # Display Results
        if won:
            result = "*** Congratulations ! You Won ! ***"
            break
        elif computerMove()[1]:
            result = '=== You Lose ! ==='
            break
    printBoard()
    print(result)

