#include <stdbool.h>
#include <stdio.h>

#define ROWS 6
#define COLS 6
#define EMPTY '-'
#define RED 'R'
#define YELLOW 'Y'

void printBoard(char gameBoard[][COLS]) {
  // prints board state
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      printf("%c", gameBoard[i][j]);
    }
    printf("\n");
  }
}

int getInput(char gameBoard[][COLS], char turn) {
  int col;
  // check valid col & top of column is empty
  do {
    printf("%s, please enter a valid column number (0-5): ",
           turn == RED ? "Red" : "Yellow");
    scanf("%d", &col);

  } while (((col < 0) | (col > 5)) | (gameBoard[0][col] != EMPTY));

  return col;
}

void insertPiece(char gameBoard[][COLS], int columnEntered, char turn) {
  // insets into first empty row in col
  for (int i = 5; i >= 0; i--) {
    if (gameBoard[i][columnEntered] == EMPTY) {
      gameBoard[i][columnEntered] = turn;
      return;
    }
  }
}

void switchTurn(char* turn) { *turn = *turn == RED ? YELLOW : RED; }

bool checkOneDirection(char gameBoard[][COLS], int row, int col, int rowDir,
                       int colDir) {
  char lastcolor = gameBoard[row][col];

  // prevents registering 4 empty in a row as a win
  if (lastcolor == EMPTY) {
    return false;
  }

  // takes 4 "steps" in directions, empty/not first color returns false
  for (int i = 0; i < 4; i++) {
    if (gameBoard[row + i * rowDir][col + i * colDir] != lastcolor) {
      return false;
    }
  }

  // must be 4 in a row
  return true;
}

bool checkWinner(char gameBoard[][COLS]) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      if (checkOneDirection(gameBoard, i, j, 1, 0)) {  // check all rows
        return true;
      }
      if (checkOneDirection(gameBoard, i, j, 0, 1)) {  // check all cols
        return true;
      }
      if (checkOneDirection(gameBoard, i, j, 1,
                            1)) {  // check all down right diag
        return true;
      }
      if (checkOneDirection(gameBoard, i, j, 1,
                            -1)) {  // check all down left diag
        return true;
      }
      if (checkOneDirection(gameBoard, i, j, -1,
                            1)) {  // check all up right diag
        return true;
      }
      if (checkOneDirection(gameBoard, i, j, -1,
                            -1)) {  // check all up left diag
        return true;
      }
    }
  }
  return false;
}

bool checkTie(char gameBoard[][COLS]) {
  // checks if all columns are full
  for (int i = 0; i < COLS; i++) {
    if (gameBoard[0][i] == EMPTY) {
      return false;
    }
  }
  return true;
}

void initializeBoard(char gameBoard[][COLS]) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      gameBoard[i][j] = EMPTY;
    }
  }
}

int main(void) {
  char gameBoard[6][6];
  initializeBoard(gameBoard);

  char turn = YELLOW;
  bool tie = false;
  bool win = false;

  do {
    switchTurn(&turn);

    printBoard(gameBoard);

    int dropcol = getInput(gameBoard, turn);
    insertPiece(gameBoard, dropcol, turn);

    tie = checkTie(gameBoard);
    win = checkWinner(gameBoard);

  } while ((win == false) && (tie == false));

  if (win) {
    printf("%s wins!\n", turn == RED ? "Red" : "Yellow");
  } else {
    printf("It's a tie\n");
  }

  printf("Final board: \n");
  printBoard(gameBoard);

  return 0;
}
