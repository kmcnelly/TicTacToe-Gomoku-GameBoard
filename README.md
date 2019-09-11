# TicTacToe-Gomoku-GameBoard
A program that allows the user to create a Tic-Tac-Toe or Gomoku game as well as modify the parameters of the game and gameboard.Part of the Object Oriented Progamming Class

How to Play!
run command: lab4-mcnelly.exe TicTacToe
Plays a full game of tic-tac-toe with Players X & O. First player always X. Program ends at end of game or on termination.  

run command: lab4-mcnelly.exe Gomoku
Plays a full game of Gomoku with Players B (Black) & W (White). The First player is always B. The Program ends at end of game or a user typing quit command(termination).
    Additional Options:
    Gomoku #
    Gomoku # #

*Notes:
    -pointer created by createGame destroyed when program ends
    -coordinates taken in as (x,y)
    -prompt only check if its a valid input of (int,int), boundary/valid move determined in turn class when prompt called
    -Turn only counted after user response processed
    -winLength may NOT be greater than the dimension of the board
    -Errors of incorrect user inputs addressed by one general usage message, 
        in order for cout to not be used in the Base class    
