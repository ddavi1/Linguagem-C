#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define ROWS 20
#define COLS 40
#define BLOCK '#'
#define EMPTY ' '
#define BORDER '|'

char board[ROWS][COLS];
int current_block_x, current_block_y;
int score;

void init_board() {
  int i, j;

  for(i=0; i<ROWS; i++) {
    for(j=0; j<COLS; j++) {
      if(j == 0 || j == COLS-1) {
        board[i][j] = BORDER;
      } else {
        board[i][j] = EMPTY;
      }
    }
  }
}

void draw_board() {
  int i, j;

  system("cls");

  for(i=0; i<ROWS; i++) {
    for(j=0; j<COLS; j++) {
      printf("%c", board[i][j]);
    }
    printf("\n");
  }

  printf("Score: %d\n", score);
}

void new_block() {
  current_block_x = COLS/2;
  current_block_y = 1;
  board[current_block_y][current_block_x] = BLOCK;
}

int move_block(int x, int y) {
  if(board[y][x] != EMPTY) {
    return 0;
  }

  board[current_block_y][current_block_x] = EMPTY;
  current_block_x = x;
  current_block_y = y;
  board[current_block_y][current_block_x] = BLOCK;

  return 1;
}

void check_line() {
  int i, j;
  int full;

  for(i=ROWS-2; i>=0; i--) {
    full = 1;

    for(j=1; j<COLS-1; j++) {
      if(board[i][j] == EMPTY) {
        full = 0;
        break;
      }
    }

    if(full) {
      for(j=1; j<COLS-1; j++) {
        board[i][j] = EMPTY;
      }

      score += 10;

      for(j=i; j>=1; j--) {
        for(int k=1; k<COLS-1; k++) {
          board[j][k] = board[j-1][k];
        }
      }

      i++;
    }
  }
}

int main() {
  srand(time(NULL));
  int i;
  char key;

  init_board();

  while(1) {
    draw_board();

    if(kbhit()) {
      key = getch();

      switch(key) {
        case 'a':
          move_block(current_block_x-1, current_block_y);
          break;
        case 'd':
          move_block(current_block_x+1, current_block_y);
          break;
        case 's':
          move_block(current_block_x, current_block_y+1);
          break;
        case 'q':
          exit(0);
      }
    }

    if(rand()%10 == 0) {
      move_block(current_block_x, current_block_y+1);
    }

    if(!move_block(current_block_x, current_block_y+1)) {
      new_block();
      check_line();
    }

    Sleep(100);
  }

  return 0;
}
