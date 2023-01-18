board = [[' ',' ',' '],
         [' ',' ',' '],
         [' ',' ',' ']]

def print_board():
    for row in board:
        print(row)

def check_win(player):
    # check rows
    for row in board:
        if row == [player, player, player]:
            return True
    # check columns
    for col in range(3):
        if board[0][col] == player and board[1][col] == player and board[2][col] == player:
            return True
    # check diagonals
    if board[0][0] == player and board[1][1] == player and board[2][2] == player:
        return True
    if board[0][2] == player and board[1][1] == player and board[2][0] == player:
        return True
    return False

def tic_tac_toe():
    player = 'X'
    while True:
        print_board()
        move = input("Player %s, enter your move (row col): " % player)
        row, col = move.split()
        row, col = int(row), int(col)
        if board[row][col] != ' ':
            print("This space is already occupied. Try again.")
            continue
        board[row][col] = player
        if check_win(player):
            print_board()
            print("Player %s wins!" % player)
            break
        if player == 'X':
            player = 'O'
        else:
            player = 'X'

tic_tac_toe()
