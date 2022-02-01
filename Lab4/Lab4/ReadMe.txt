Lab 4

Team pineapple
Kyerra Norton 489940
Kiki Ogino 455003
Leung Wai Liu 472995

Contributions:
- We used Leung Wai's lab 3 to build this lab upon 
- We worked together on this lab on one computer (like studio) and alternated who was typing
- Kiki and Kyerra worked on fixing the public inheritance errors and the vector out of range printing errors
- Leung Wai fixed the draw() function for TicTacToe game using the Debugger

Methods & Modifications:
- We created a new base class called GameBase for which TicTacToe and Gomoku are derived classes of
- We created a new_game() method that creates a new game of either type Gomoku or TicTacToe depending on the user's input
- We changed the allowed command arguments from 2 arguments --> 3 arguments for Gomoku with n x n board dimensions & 4 arguments for 
Gomoku with n x n dimensions + n pieces to win
- We also added if statements to check if we have invalid command line arguments of <2 or >4 in new_game()
- We used setw function and a variable integer to keep track of the longest string input so that we can print "Blackstone"or "Whitestone"
on the Gomoku game board, and adjust the alignment of the squares
-The methods we copied from Lab3 to build our base class: turn(), draw(), prompt(), done(), play()

turn(): prompts the user to input a valid x,y coordinate and then stores the values in an x and y variable; after a player has finished 
choosing their piece and printing their play, it switches to the other player's turn

draw(): returns a boolean value indicating whether the game was a draw or not; the entire board is checked for empty playable spaces, and
if there is, we return false, else we return true and the game ends; for TicTacToe we use this base method because we have concrete board
dimensions and number of pieces to win; for Gomoku, we made a default setting for board dimension and number of pieces to win

prompt(): asks for user inputs and extracts them from the command line, then puts them into unsigned ints for the x and y coordinates, if 
they are invalid or unreadable argugments, it will loop until valid input is given or the user quits

done(): checks diagonally, horizontally, and vertically if there is consecutive pieces of the same type (x or y, black or white stones); if 
there is the game ends and we print the winner, if there isn't the game continues

play(): returns either TicTacToe or Gomoku, prints the blank game board then repeatedly calls turn(), done(), and draw() until the game ends
or the user quits; the plays by each player are also tracked

- We also added a print() funtion that we overload to print out the game board for Gomoku

Test Cases:
II. Running the game:
1. Initial run of the game: 
Input: Lab4.exe TicTacToe
Output: 
4
3
2
1
0
  0 1 2 3 4

Player X's turn:
Please enter a new coordinate, or type 'quit' to quit the game.

The board is displayed properly, and it asks for Player X to input the first coordinate. The program works as expected. 

2. Inputting gibberish data as coordinates:
Input: lksjdfklsdjflksdjf or 1, 1 (with a space between the comma or 1) or 1 1 (as two separate numbers)
Output: 
One or both values failed to be extracted. Input format should be like '1,1', as one continuous phrase. Please try again.
Please enter a new coordinate, or type 'quit' to quit the game.

The program only reads properly formatted coordinates "x,y" and "quit", so anything else will be rejected, and will show
the user how to input a proper

3. TicTacToe: Inputting a coordinate that is out of bounds:
Input: 4,4 or -1,-1 for example
Output: 
The coordinates are outside the range of this game. Please try again.
Please enter a new coordinate, or type 'quit' to quit the game.

Since the valid coordinates are only between 1 and 3, anything now within this range will be rejected, and a message will 
show the user to explain why. 

Gomoku: Our invalid arguments, when using the defaults are for example 23,4
or -1,1; 
When I enter the coordinates, we prompted the user with:
The coordinates are outside the range of this game. Please try again.
Please enter a new coordinate, or type 'quit' to quit the game.

4. Inputting a coordinate that has a piece there already:
Current Board:
1,2
4
3
2   O
1   X
0
  0 1 2 3 4

Player O: 1,2

Player X's turn:
Please enter a new coordinate, or type 'quit' to quit the game.

Input: 1,1
Output:
This space in the board has been taken by a piece already. Please try again.
Please enter a new coordinate, or type 'quit' to quit the game.

The program works as expected, as it sees that the space at coordinate 1,1 is not empty, and therefore
asks the player for another coordinate.

Gomoku: The program worked the same for Gomoku as well prompting:
This space in the board has been taken by a piece already. Please try again.
Please enter a new coordinate, or type 'quit' to quit the game.


5. When the user quits:
Input: quit
Output:
You have quit the game. Thank you for playing!
Total Turns Played: 2

echo %errorlevel%: 3 (for USERQUIT)
The program works as expected, as the program recognizes the 'quit' string, and terminates the program.

6. Once Player X goes, then it switches to Player O's turn:
Player X's turn:
Please enter a new coordinate, or type 'quit' to quit the game.
3,1
4
3
2   O   X
1   X O X
0
  0 1 2 3 4

Player X: 1,1; 3,1; 3,2

Player O's turn:
Please enter a new coordinate, or type 'quit' to quit the game.

The program is working as expected. The most up to date game board has shown, the previous player's moves are 
shown as well, and it switches to Player O's turn. 

7. When Player X wins:
Output:
Player X's turn:
Please enter a new coordinate, or type 'quit' to quit the game.
3,3
4
3       X
2   O O X
1   X O X
0
  0 1 2 3 4

Player X: 1,1; 3,1; 3,2; 3,3
Player X has won the game! Thank you for playing!

The program is working as expected. All the moves that Player X made is shown, and it displays a message that Player X has won the game.

8. When Player O wins:
Output:

Player O's turn:
Please enter a new coordinate, or type 'quit' to quit the game.
3,1
4
3   O
2   X O
1   X X O
0
  0 1 2 3 4

Player O: 1,3; 2,2; 3,1
Player O has won the game! Thank you for playing!

The program is working as expected. All the moves that Player O made is shown, and it displays a message that Player O has won the game.

9. When there is a draw:
Input: Lab4.exe TicTacToe
Output (an entire runthrough of the game):
4
3
2
1
0
  0 1 2 3 4

Player X's turn:
Please enter a new coordinate, or type 'quit' to quit the game.
3,1
4
3
2
1       X
0
  0 1 2 3 4

Player X: 3,1

Player O's turn:
Please enter a new coordinate, or type 'quit' to quit the game.
2,2
4
3
2     O
1       X
0
  0 1 2 3 4

Player O: 2,2

Player X's turn:
Please enter a new coordinate, or type 'quit' to quit the game.
1,3
4
3   X
2     O
1       X
0
  0 1 2 3 4

Player X: 1,3; 3,1

Player O's turn:
Please enter a new coordinate, or type 'quit' to quit the game.
2,2
This space in the board has been taken by a piece already. Please try again.
Please enter a new coordinate, or type 'quit' to quit the game.
1,1
4
3   X
2     O
1   O   X
0
  0 1 2 3 4

Player O: 1,1; 2,2

Player X's turn:
Please enter a new coordinate, or type 'quit' to quit the game.
3,3
4
3   X   X
2     O
1   O   X
0
  0 1 2 3 4

Player X: 1,3; 3,1; 3,3

Player O's turn:
Please enter a new coordinate, or type 'quit' to quit the game.
3,2
4
3   X   X
2     O O
1   O   X
0
  0 1 2 3 4

Player O: 1,1; 2,2; 3,2

Player X's turn:
Please enter a new coordinate, or type 'quit' to quit the game.
1,2
4
3   X   X
2   X O O
1   O   X
0
  0 1 2 3 4

Player X: 1,2; 1,3; 3,1; 3,3

Player O's turn:
Please enter a new coordinate, or type 'quit' to quit the game.
2,3
4
3   X O X
2   X O O
1   O   X
0
  0 1 2 3 4

Player O: 1,1; 2,2; 2,3; 3,2

Player X's turn:
Please enter a new coordinate, or type 'quit' to quit the game.
2,1
4
3   X O X
2   X O O
1   O X X
0
  0 1 2 3 4

Player X: 1,2; 1,3; 2,1; 3,1; 3,3
The game is a draw. Thank you for playing!
Total Turns Played: 9

echo %errorlevel%: 4 (for GAMEDRAW)

The program is working as expected. In the end, when there is a draw, it displays a message to the user saying that there is a draw,
and shows the total turns that both players played, which is 9 (correct for this particular run of the game).

For Gomoku, our test cases were:
- default 19 x 19 board, 5 to win, diagonally starting from 11; we played for whitestone to win, and we were prompted with the correct end game message
- we tried a 10 x 10 , 3 to win, we tried vertically and horizontally, both times as blackstone(for the win), these cases were both successful as well 
and prompted the correct message
- we tried to end the game in a draw by doing a 3 x 3 board with 3 to win, and it perfomed as expected, with: The game is a draw. Thank you for playing!






Errors and Warnings:
- Vector print out of range upon printing the initial board - we modified the start and end index to use the "rows" and "cols" 
member variables instead of using enums, that fixed the issue. 
- Draw did not work properly for TicTacToe - fixed the bounds for the inner board (when switching from enums to variables, the enums
were not set properly)
- We have 3 Swarnings regarding arithmetic overflow, adding and multiplying 4 byte values and casting the result to an 8 byete value

Extra Credit:
- As we were implementing our new base class GameBase, we had already begun to think about the n x n gameboard for Gomoku. It seemed rather
intuitive to think about this part at the beginning because we have done similar projects of taking in user input to draw something. We 
created a new member variable in the GomokuGame class that takes in the fourth command line argument(number of pieces to win), and uses
it to decide when there is a win in the done() method. We also had to account for possibility of diagonals througout the board, if we
were given a large board dimension and a small number of needed to win as our third and fourth argument. We checked from the bottom left corner 
up and from the leftmost column to the right, and checking both diagonal directions. We'd keep track of each number of consecutive pieces of
the same type then at the end check if they met the number of pieces needed and returned. For prompt(), we had to change it to loop through board of user given dimensions by
wrapping the user input into a istringstream, and then use the input in the draw method for board dimensions and looping through for empty
space. We kept the same prompt method and play method.  
