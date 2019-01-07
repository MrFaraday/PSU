#include <stack>
#include "reversi.h"
#include "globals.h"
#include <ctime>

struct Cell {
  int column;
  int row;
};

int flankPieces(std::stack<Cell> pieces);
void clearStack(std::stack<Cell>* cells);

int Reversi_move(unsigned short row, unsigned short column) {
  int
    sideToSet,
    opposite;

  if (whoMoves == BLACK_can_move) {
    sideToSet = BLACK_s;
    opposite = WHITE_s;
  }  else {
    sideToSet = WHITE_s;
    opposite = BLACK_s;
  }

  board[row][column] = sideToSet;
  
  // ����������� � ������ �� ����� �� ����� ����������� ������
  std::stack<Cell> pieces;
  Cell c;
  int
    x,
    y;
  
  // ����������� x -> 7
  x = column + 1;
  y = row;
  while (x < 8) {
    // ���� ���������� ��������������� �������
    if (board[y][x] == opposite) {
      c = { x, y };
      pieces.push(c);
      x++;
      continue;
    }
    // ���� ���������� "����" �������
    if (board[y][x] == sideToSet) {
      // ��� ���� ���� ������
      if (pieces.empty()) break;
      // �� ������
      if (flankPieces(pieces)) return 1;  // ����������� �����
      
      break;
    }
    
    // � ��������� ������� ��������� ����
    break;
  }
  clearStack(&pieces);

  // ����������� 0 <- x
  x = column - 1;
  y = row;
  while (x >= 0) {
    // ���� ���������� ��������������� �������
    if (board[y][x] == opposite) {
      c = { x, y };
      pieces.push(c);
      x--;
      continue;
    }
    // ���� ���������� "����" �������
    if (board[y][x] == sideToSet) {
      // ��� ���� ���� ������
      if (pieces.empty()) break;
      // �� ������
      if (flankPieces(pieces)) return 1;  // ����������� �����

      break;
    }

    // � ��������� ������� ��������� ����
    break;
  }
  clearStack(&pieces);

  // ��������� y -> 7
  x = column;
  y = row + 1;
  while (y < 8) {
    // ���� ���������� ��������������� �������
    if (board[y][x] == opposite) {
      c = { x, y };
      pieces.push(c);
      y++;
      continue;
    }
    // ���� ���������� "����" �������
    if (board[y][x] == sideToSet) {
      // ��� ���� ���� ������
      if (pieces.empty()) break;
      // �� ������
      if (flankPieces(pieces)) return 1;  // ����������� �����

      break;
    }

    // � ��������� ������� ��������� ����
    break;
  }
  clearStack(&pieces);

  // ��������� 0 <- y
  x = column;
  y = row - 1;
  while (y >= 0) {
    // ���� ���������� ��������������� �������
    if (board[y][x] == opposite) {
      c = { x, y };
      pieces.push(c);
      y--;
      continue;
    }
    // ���� ���������� "����" �������
    if (board[y][x] == sideToSet) {
      // ��� ���� ���� ������
      if (pieces.empty()) break;
      // �� ������
      if (flankPieces(pieces)) return 1;  // ����������� �����

      break;
    }

    // � ��������� ������� ��������� ����
    break;
  }
  clearStack(&pieces);

  // ��������� x -> 7, y -> 7
  x = column + 1;
  y = row + 1;
  while (y < 8 && x < 8) {
    // ���� ���������� ��������������� �������
    if (board[y][x] == opposite) {
      c = { x, y };
      pieces.push(c);
      x++;
      y++;
      continue;
    }
    // ���� ���������� "����" �������
    if (board[y][x] == sideToSet) {
      // ��� ���� ���� ������
      if (pieces.empty()) break;
      // �� ������
      if (flankPieces(pieces)) return 1;  // ����������� �����

      break;
    }

    // � ��������� ������� ��������� ����
    break;
  }
  clearStack(&pieces);

  // ��������� x -> 7, 0 <- y
  x = column + 1;
  y = row - 1;
  while (y >= 0 && x < 8) {
    // ���� ���������� ��������������� �������
    if (board[y][x] == opposite) {
      c = { x, y };
      pieces.push(c);
      x++;
      y--;
      continue;
    }
    // ���� ���������� "����" �������
    if (board[y][x] == sideToSet) {
      // ��� ���� ���� ������
      if (pieces.empty()) break;
      // �� ������
      if (flankPieces(pieces)) return 1;  // ����������� �����

      break;
    }

    // � ��������� ������� ��������� ����
    break;
  }
  clearStack(&pieces);

  // ��������� 0 <- x, 0 <- y
  x = column - 1;
  y = row - 1;
  while (y >= 0 && x >= 0) {
    // ���� ���������� ��������������� �������
    if (board[y][x] == opposite) {
      c = { x, y };
      pieces.push(c);
      x--;
      y--;
      continue;
    }
    // ���� ���������� "����" �������
    if (board[y][x] == sideToSet) {
      // ��� ���� ���� ������
      if (pieces.empty()) break;
      // �� ������
      if (flankPieces(pieces)) return 1;  // ����������� �����

      break;
    }

    // � ��������� ������� ��������� ����
    break;
  }
  clearStack(&pieces);

  // ��������� 0 <- x, y -> 7
  x = column - 1;
  y = row + 1;
  while (y < 8 && x >= 0) {
    // ���� ���������� ��������������� �������
    if (board[y][x] == opposite) {
      c = { x, y };
      pieces.push(c);
      x--;
      y++;
      continue;
    }
    // ���� ���������� "����" �������
    if (board[y][x] == sideToSet) {
      // ��� ���� ���� ������
      if (pieces.empty()) break;
      // �� ������
      if (flankPieces(pieces)) return 1;  // ����������� �����

      break;
    }

    // � ��������� ������� ��������� ����
    break;
  }
  clearStack(&pieces);

  return 0;
}

int Reversi_posibleMovesClear() {
  for (size_t i = 0; i < 8; i++)
    for (size_t j = 0; j < 8; j++)
      if (board[i][j] == whoMoves) board[i][j] = 0;

  return 0;
}

int Reversi_setPosibleMoves() {
  int
    we,
    opposite;
  bool haveMoves = 0;

  if (whoMoves == BLACK_can_move) {
    we = BLACK_s;
    opposite = WHITE_s;
  }  else {
    we = WHITE_s;
    opposite = BLACK_s;
  }

  for (size_t i = 0; i < 8; i++)
    for (size_t j = 0; j < 8; j++) {
      if (board[i][j] != we) continue;

      // ����������� ������ �� ���� ������������
      int
        x,
        y,
        counter;

      // ����������� x -> 7
      x = j + 1;
      y = i;
      counter = 0;
      while (x < 8) {
        // ���� ���������� ��������������� �������
        if (board[y][x] == opposite) {
          x++;
          counter++;
          continue;
        }

        // � ��������� �������
        if (!counter || board[y][x] != 0) break;  // ���� ������� ������ ��� ������ �� ������
        board[y][x] = (char) whoMoves;
        haveMoves = 1;
        break;
      }

      // ����������� 0 <- x
      x = j - 1;
      y = i;
      counter = 0;
      while (0 <= x) {
        // ���� ���������� ��������������� �������
        if (board[y][x] == opposite) {
          x--;
          counter++;
          continue;
        }

        // � ��������� �������
        if (!counter || board[y][x] != 0) break;  // ���� ������� ������ ��� ������ �� ������
        board[y][x] = (char) whoMoves;
        haveMoves = 1;
        break;
      }

      // ��������� y -> 7
      x = j;
      y = i + 1;
      counter = 0;
      while (y < 8) {
        // ���� ���������� ��������������� �������
        if (board[y][x] == opposite) {
          y++;
          counter++;
          continue;
        }

        // � ��������� �������
        if (!counter || board[y][x] != 0) break;  // ���� ������� ������ ��� ������ �� ������
        board[y][x] = (char) whoMoves;
        haveMoves = 1;
        break;
      }

      // ��������� 0 <- y
      x = j;
      y = i - 1;
      counter = 0;
      while (0 <= y) {
        // ���� ���������� ��������������� �������
        if (board[y][x] == opposite) {
          y--;
          counter++;
          continue;
        }

        // � ��������� �������
        if (!counter || board[y][x] != 0) break;  // ���� ������� ������ ��� ������ �� ������
        board[y][x] = (char) whoMoves;
        haveMoves = 1;
        break;
      }

      // ��������� x -> 7, y -> 7
      x = j + 1;
      y = i + 1;
      counter = 0;
      while (x < 8 && y < 8) {
        // ���� ���������� ��������������� �������
        if (board[y][x] == opposite) {
          x++;
          y++;
          counter++;
          continue;
        }

        // � ��������� �������
        if (!counter || board[y][x] != 0) break;  // ���� ������� ������ ��� ������ �� ������
        board[y][x] = (char) whoMoves;
        haveMoves = 1;
        break;
      }

      // ��������� x -> 7, y -> 0
      x = j + 1;
      y = i - 1;
      counter = 0;
      while (x < 8 && y >= 0) {
        // ���� ���������� ��������������� �������
        if (board[y][x] == opposite) {
          x++;
          y--;
          counter++;
          continue;
        }

        // � ��������� �������
        if (!counter || board[y][x] != 0) break;  // ���� ������� ������ ��� ������ �� ������
        board[y][x] = (char) whoMoves;
        haveMoves = 1;
        break;
      }

      // ��������� x -> 0, y -> 0
      x = j - 1;
      y = i - 1;
      counter = 0;
      while (x >= 0 && y >= 0) {
        // ���� ���������� ��������������� �������
        if (board[y][x] == opposite) {
          x--;
          y--;
          counter++;
          continue;
        }

        // � ��������� �������
        if (!counter || board[y][x] != 0) break;  // ���� ������� ������ ��� ������ �� ������
        board[y][x] = (char) whoMoves;
        haveMoves = 1;
        break;
      }

      // ��������� x -> 0, y -> 7
      x = j - 1;
      y = i + 1;
      counter = 0;
      while (x >= 0 && y < 8) {
        // ���� ���������� ��������������� �������
        if (board[y][x] == opposite) {
          x--;
          y++;
          counter++;
          continue;
        }

        // � ��������� �������
        if (!counter || board[y][x] != 0) break;  // ���� ������� ������ ��� ������ �� ������
        board[y][x] = (char) whoMoves;
        haveMoves = 1;
        break;
      }
    }

  return haveMoves;
}

void Reversi_setScore() {
  blackScore = 0;
  whiteScore = 0;

  for (size_t i = 0; i < 8; i++)
    for (size_t j = 0; j < 8; j++)
      if (board[i][j] == BLACK_s) blackScore++;
      else if (board[i][j] == WHITE_s) whiteScore++;
}

void Reversi_aiMove() {
  int count = 0;
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++) {
      if (board[i][j] == WHITE_can_move) count++;
      if (board[i][j] == WHITE_can_move && (i == 0 && j == 0 || i == 7 && j == 0 || i == 7 && j == 7 || i == 0 && j == 7)) {
        Reversi_move(i, j);
        Sleep(1000);
        return;
      }
    }
  
  srand((unsigned int) time(0));
  bool haveMoved = 0;
  int move = rand() % count;
  count = 0;
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++) {
      if (count == move && board[i][j] == WHITE_can_move && !haveMoved) {
        Reversi_move(i, j);
        haveMoved = 1;
      }
      if (board[i][j] == WHITE_can_move) count++;
    }
  Sleep(1000);
}

int flankPieces(std::stack<Cell> pieces) {
  while (!pieces.empty()) {
    int
      x = pieces.top().column,
      y = pieces.top().row;
    if (!(board[y][x] == BLACK_s || board[y][x] == WHITE_s)) return 1;

    if (board[y][x] == BLACK_s) board[y][x] = WHITE_s;
      else board[y][x] = BLACK_s;

    pieces.pop();
  }

  return 0;
}

void clearStack(std::stack<Cell>* cells) {
  while (!cells->empty()) cells->pop();
}
