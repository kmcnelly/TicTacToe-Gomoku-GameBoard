Kenneth McNelly
457250
Lab4

run command: lab4-mcnelly.exe TicTacToe
(same from Lab 3)Plays a full game of tic-tac-toe with Players X & O. First player always X. Program ends at end of game or on termination.  

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

Error:=================================================================

1) GameBase class undefined, at declaration of derived tictactoe class
    Solution: remove #include TicTacToe.h from lab4.h

2) createGame() isnt found
    Solution: GameBase:: scope
    
3) new TicTacToeGame() not being recognized
    Solution: added back #include TicTacToe.h to base.cpp
    
4) game.play(); no such method
    Solution: DEREFERENCE ->
    
5) while index (unsigned) > -1 (signed):  -1 is largest in unsigned
    solution: static_cast<long> index

Tests: ================================================================
(all TicTacToe code tested in Lab3. Works exactly same)

lab4-mcnelly.exe
    Invalid Command!
    usage: lab4-mcnelly.exe Incorrect input! Required: 'TicTacToe' or 'Gomoku'

lab4-mcnelly.exe Goku
    Invalid Command!
    usage: lab4-mcnelly.exe Incorrect input! Required: 'TicTacToe' or 'Gomoku'

lab4-mcnelly.exe TicTacToe
    4 |   |   |   |   |   |
    3 |   |   |   |   |   |
    2 |   |   |   |   |   |
    1 |   |   |   |   |   |
    0 |   |   |   |   |   |
        0   1   2   3   4
    Player X's Turn:
    Enter the word 'quit' to end game or a valid coord: 'x, y' to play!
    '1,1' to ' 3,3'

lab4-mcnelly.exe Gomoku
    19 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
    18 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
    17 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
    16 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
    15 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
    14 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
    13 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
    12 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
    11 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
    10 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
     9 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
     8 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
     7 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
     6 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
     5 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
     4 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
     3 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
     2 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
     1 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
     X    1    2    3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18   19
    Black's Turn:
    Enter the word 'quit' to end game or a valid coord: 'x, y' to play!
    '1,1' to ' 19,19'

Coordinate Inputs:
Black's Turn:
Enter the word 'quit' to end game or a valid coord: 'x, y' to play!
'1,1' to ' 19,19'
    
    -1,2
        Invalid row coord! Must be from 1 and 19
    20,10
        Invalid row coord! Must be from 1 and 19
    2,-4
        Invalid col coord! Must be between 1 and 19
    18,20
        Invalid col coord! Must be between 1 and 19
        
    19 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
    18 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
    17 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
    16 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
    15 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
    14 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
    13 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
    12 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
    11 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
    10 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
     9 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
     8 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
     7 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
     6 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
     5 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
     4 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
     3 |    |    |  B |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
     2 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
     1 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
     X    1    2    3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18   19
    Player B: 3, 3;
    White's Turn
    Enter the word 'quit' to end game or a valid coord: 'x, y' to play!
    '1,1' to ' 19,19'
    3,3
    Position 3, 3 Taken! Pick from available 
    
    quit
        *Exiting Game
        USER TERMINATED: 2 turn(s) played.


1) Diagonal DOWN (down, right): ------------------------------
    10 |    |    |    |    |    |    |    |    |    |  W |
     9 |    |    |    |    |    |    |    |    |  W |    |
     8 |  W |    |    |    |    |    |    |  B |    |    |
     7 |    |    |    |    |    |    |    |    |    |    |
     6 |    |    |    |    |    |    |    |    |    |    |
     5 |    |    |    |    |    |  B |    |    |    |    |
     4 |  B |    |    |    |  W |    |  B |    |    |    |
     3 |  B |    |    |    |    |    |    |  B |    |    |
     2 |  W |  W |  W |    |    |    |    |    |  B |    |
     1 |    |    |    |    |    |    |    |    |    |  B |
     X    1    2    3    4    5    6    7    8    9   10

    Player B: 1, 4; 1, 3; 8, 8; 10, 1; 9, 2; 8, 3; 7, 4; 6, 5;

    Congrats Player Black!
    Black WON.
    
 1.1)Diagonal Down in Top left corner:
     6 |  B |    |    |  B |    |    |
     5 |    |  B |    |    |    |    |
     4 |  W |  W |  B |    |    |  W |
     3 |  B |  W |  W |  B |    |    |
     2 |  B |    |  W |    |  B |    |
     1 |  W |    |    |    |    |    |
     X    1    2    3    4    5    6

    Player B: 1, 2; 1, 3; 2, 5; 5, 2; 4, 3; 4, 6; 1, 6; 3, 4;

    Congrats Player Black!
    Black WON.
    
1.2) Diagonal Up in Bottom left corner:


2) Diagonal UP (up, right): -----------------------------------
    10 |    |    |    |    |    |    |    |    |    |  W |
     9 |    |    |    |    |    |    |    |    |  W |    |
     8 |    |    |    |    |    |    |    |  W |    |    |
     7 |    |    |    |    |    |    |  W |    |    |    |
     6 |    |    |    |    |    |  W |    |    |    |    |
     5 |    |    |    |    |    |    |    |    |    |    |
     4 |    |  B |    |    |    |    |    |    |    |    |
     3 |    |    |  B |    |    |  B |    |    |    |    |
     2 |    |  B |    |    |    |    |    |    |    |    |
     1 |    |    |    |  B |    |    |    |    |    |    |
     X    1    2    3    4    5    6    7    8    9   10

    Player W: 10, 10; 9, 9; 8, 8; 7, 7; 6, 6;

    Congrats Player White!
    White WON.

3) Column: ---------------------------------------------------------------------------------------------
    19 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |  W |
    18 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
    17 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
    16 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
    15 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
    14 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
    13 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
    12 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |  W |
    11 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
    10 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
     9 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
     8 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
     7 |    |  W |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
     6 |  W |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
     5 |  B |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
     4 |  B |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
     3 |  B |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
     2 |  B |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
     1 |  B |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
     X    1    2    3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18   19

    Player B: 1, 1; 1, 2; 1, 3; 1, 4; 1, 5;

    Congrats Player Black!
    Black WON.
    
     6 |    |    |    |    |    |  W |
     5 |    |    |    |    |    |  W |
     4 |    |    |  B |    |    |  W |
     3 |  B |  B |    |    |    |  W |
     2 |    |  B |    |    |    |  W |
     1 |  B |  B |    |    |    |  W |
     X    1    2    3    4    5    6

    Player W: 6, 1; 6, 6; 6, 3; 6, 2; 6, 5; 6, 4;

    Congrats Player White!
    White WON.

4) Row: ---------------------------------------------------------------------------------------------
    19 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |  W |  W |  W |  W |  W |
    18 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |  W |
    17 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
    16 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
    15 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
    14 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
    13 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
    12 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
    11 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
    10 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
     9 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
     8 |    |  B |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
     7 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
     6 |    |    |    |  B |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
     5 |    |  B |    |    |  B |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
     4 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
     3 |    |    |  B |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
     2 |  B |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
     1 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
     X    1    2    3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18   19

    Player W: 19, 19; 19, 18; 18, 19; 17, 19; 16, 19; 15, 19;

    Congrats Player White!
    White WON.

5) Draw: ------------------------------------------

 6 |    |  B |  W |  W |    |  B |
 5 |  W |    |  W |  B |    |  W |
 4 |    |  B |  B |  W |  B |    |
 3 |  B |  W |  W |  B |    |    |
 2 |  B |  B |  B |  W |  W |  B |
 1 |  W |  W |  B |    |  B |  W |
 X    1    2    3    4    5    6

Player B: 1, 2; 1, 3; 2, 2; 2, 4; 3, 2; 3, 4; 6, 2; 2, 6; 5, 1; 3, 1; 6, 6; 5, 4; 4, 3; 4, 5;

DRAW (no winning moves remain): 26 turn(s) played.

 3 |  B |  W |    |
 2 |  W |  B |  B |
 1 |  W |  B |  W |
 X    1    2    3

Player W: 1, 1; 3, 1; 1, 2; 2, 3;

DRAW (no winning moves remain): 7 turn(s) played.

 6 |  W |  B |    |  B |  B |  W |
 5 |  B |  B |    |  W |  B |  W |
 4 |  B |  W |  W |  W |  W |  B |
 3 |  B |  W |  W |  B |  B |    |
 2 |  W |    |  B |  W |  B |  W |
 1 |  B |  W |    |  B |  W |    |
 X    1    2    3    4    5    6

Player W: 2, 1; 2, 4; 2, 3; 6, 2; 3, 3; 4, 2; 5, 1; 6, 5; 4, 4; 1, 2; 4, 5; 1, 6; 6, 6; 3, 4; 5, 4;

DRAW (no winning moves remain): 29 turn(s) played.

 6 |  W |  W |    |  B |    |  W |
 5 |    |  B |  W |  B |  B |    |
 4 |  B |  B |  B |  W |    |    |
 3 |  W |  B |  W |  B |  B |  B |
 2 |  W |  B |  W |  W |  W |  W |
 1 |  B |  W |  B |    |  W |  B |
 X    1    2    3    4    5    6

Player B: 1, 1; 2, 3; 2, 2; 3, 4; 5, 3; 2, 4; 4, 5; 2, 5; 4, 3; 6, 3; 3, 1; 5, 5; 1, 4; 6, 1; 4, 6;

DRAW (no winning moves remain): 28 turn(s) played.


================== EXTRA CREDIT ======================
Gomoku // default Gomoku Game
Gomoku # //Gomoku Game with modded dimension and default valid winlength
Gomoku # //Gomoku Game with modded dimension and modded winlength

Testing: ----------------------------------------
lab4-mcnelly.exe Gomoku 1
Invalid Command!
usage: lab4-mcnelly.exe Incorrect inputs! Required: lab4-mcnelly.exe 'TicTacToe' or 'Gomoku' or 'Gomoku #(>=3)' or 'Gomoku #(>=3) #(>=3)'

lab4-mcnelly.exe Gomoku 4 2
Invalid Command!
usage: lab4-mcnelly.exe Incorrect inputs! Required: lab4-mcnelly.exe 'TicTacToe' or 'Gomoku' or 'Gomoku #(>=3)' or 'Gomoku #(>=3) #(>=3)'

lab4-mcnelly.exe Gomoku 3
     3 |    |    |    |
     2 |    |    |    |
     1 |    |    |    |
     X    1    2    3
    Black's Turn:
    Enter the word 'quit' to end game or a valid coord: 'x, y' to play!
    '1,1' to ' 3,3'
     3 |    |    |    |
     2 |    |  W |  W |
     1 |  B |  B |  B |
     X    1    2    3
    Player B: 1, 1; 2, 1; 3, 1;
    Congrats Player Black!
    Black WON.
    
lab4-mcnelly.exe Gomoku 4, 4 
    WORKS

lab4-mcnelly.exe Gomoku 6, 10
    Invalid Command!
    usage: lab4-mcnelly.exe Incorrect inputs! Required: lab4-mcnelly.exe 'TicTacToe' or 'Gomoku' or 'Gomoku #(>=3)' or 'Gomoku #(>=3) #(>=3)'

lab4-mcnelly.exe Gomoku plz help
    Invalid Command!
    usage: lab4-mcnelly.exe Incorrect inputs! Required: lab4-mcnelly.exe 'TicTacToe' or 'Gomoku' or 'Gomoku #(>=3)' or 'Gomoku #(>=3) #(>=3)'

Valid Modified Dimension and Winlength (20 10)
    20 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
    19 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
    18 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
    17 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
    16 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
    15 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
    14 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
    13 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
    12 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
    11 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
    10 |  B |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
     9 |  B |    |    |    |    |    |    |    |  W |    |    |    |    |    |    |    |    |    |    |    |
     8 |  B |    |    |    |    |  W |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
     7 |  B |    |    |    |    |    |  W |    |    |    |    |    |    |    |    |    |    |    |    |    |
     6 |  B |    |  W |  W |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
     5 |  B |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
     4 |  B |    |    |    |    |    |  W |    |    |    |    |    |    |    |    |    |    |    |    |    |
     3 |  B |  W |    |    |    |  W |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
     2 |  B |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
     1 |  B |  W |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
     X    1    2    3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18   19   20

    Player B: 1, 1; 1, 3; 1, 2; 1, 4; 1, 6; 1, 8; 1, 7; 1, 5; 1, 9; 1, 10;

    Congrats Player Black!
    Black WON.
