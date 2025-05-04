♛ N-Queens Problem Overview
Goal: Place N queens on an N x N chessboard such that no two queens threaten each other.
This means:

Only one queen per row, column, and diagonal.

🧠 Approach (Backtracking)
1.Try placing a queen in each row.

2.For every column in the row:

Check if the column and both diagonals are safe.

3.If safe, place the queen and move to the next row.

4.If all rows are filled, you've found a solution.

5.If not, backtrack (remove the last queen and try the next column).

