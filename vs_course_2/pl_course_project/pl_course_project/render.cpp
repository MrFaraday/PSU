#pragma comment(lib, "C:/SDKs/OpenGL/LIBs/Win32/glut32.lib")
#pragma comment(lib, "C:/SDKs/OpenGL/LIBs/Win32/glaux.lib")

#include <C:/SDKs/OpenGL/include/GL/glut.h>
#include <C:/SDKs/OpenGL/include/GL/glaux.h>

#include <iostream>
#include "render.h"
#include "globals.h"

HWND    g_hWnd = NULL;
HDC     g_hDC  = NULL;
HGLRC   g_hRC  = NULL;
GLuint  base;  // ���� ������ ����������� ��� ������

GLvoid  glPrint(const WCHAR *, ...);
GLvoid  BuildFont(GLvoid);
GLvoid  StrokeEllipse(GLfloat xCenter, GLfloat yCenter, GLfloat rx, GLfloat ry, GLint pointCount = 360);
GLvoid  FillEllipse(GLfloat xCenter, GLfloat yCenter, GLfloat rx, GLfloat ry, GLint pointCount = 360);

void Render_glInit(unsigned int hWnd) {
  g_hWnd = (HWND) hWnd;

  PIXELFORMATDESCRIPTOR pfd;
  memset(&pfd, 0, sizeof(PIXELFORMATDESCRIPTOR));

  pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
  pfd.nVersion = 1;
  pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
  pfd.iPixelType = PFD_TYPE_RGBA;
  pfd.cColorBits = 16;
  pfd.cDepthBits = 16;

  g_hDC = GetDC(g_hWnd);
  GLuint iPixelFormat = ChoosePixelFormat(g_hDC, &pfd);
  SetPixelFormat(g_hDC, iPixelFormat, &pfd);

  if (iPixelFormat != 0) {
    PIXELFORMATDESCRIPTOR bestMatch_pfd;
    DescribePixelFormat(g_hDC, iPixelFormat, sizeof(pfd), &bestMatch_pfd);

    if (bestMatch_pfd.cDepthBits < pfd.cDepthBits) {
      return;
    }

    if (SetPixelFormat(g_hDC, iPixelFormat, &pfd) == FALSE) {
      DWORD dwErrorCode = GetLastError();
      return;
    }
  }
  else {
    DWORD dwErrorCode = GetLastError();
    return;
  }

  g_hRC = wglCreateContext(g_hDC);
  wglMakeCurrent(g_hDC, g_hRC);
  BuildFont();
}

void Render_shutDown(void) {
  if (g_hRC != NULL) {
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(g_hRC);
    g_hRC = NULL;
  }

  if (g_hDC != NULL) {
    ReleaseDC(g_hWnd, g_hDC);
    g_hDC = NULL;
  }
}

void Render_renderScene(void) {
  glClearColor((float) 0x17/255, (float) 0x72/255, (float) 0x45/255, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  
  // ������ �����
  int rowOffset = 0;
  int cellSize = (int) (boardSize / 8);
  for (size_t i = 0; i < 8; i++) {
    int columnOffset = 0;
    for (size_t j = 0; j < 8; j++) {
      // ������� ������
      glColor3ub(255, 255, 0);
      glBegin(GL_LINE_LOOP);
      glVertex2i(xInit + columnOffset, yInit + rowOffset);
      glVertex2i(xInit + columnOffset + cellSize, yInit + rowOffset);
      glVertex2i(xInit + columnOffset + cellSize, yInit + rowOffset + cellSize);
      glVertex2i(xInit + columnOffset, yInit + rowOffset + cellSize);
      glEnd();

      // ��������� ��������� ������
      USHORT
        xCentre = xInit + columnOffset + cellSize / 2,
        yCentre = yInit + rowOffset + cellSize / 2,
        circR = 15,
        circR_m = 5;

      switch (board[i][j]) {
      case BLACK_s: {
        glColor3ub(255, 255, 255);
        FillEllipse(xCentre, yCentre, circR, circR);
        glColor3ub(0, 0, 0);
        FillEllipse(xCentre, yCentre, circR - 1, circR - 1);

        break;
      }
      case WHITE_s: {
        glColor3ub(0, 0, 0);
        FillEllipse(xCentre, yCentre, circR, circR);
        glColor3ub(255, 255, 255);
        FillEllipse(xCentre, yCentre, circR - 1, circR - 1);

        break;
      }
      case BLACK_can_move: {
        glColor3ub(255, 255, 255);
        FillEllipse(xCentre, yCentre, circR_m, circR_m);
        glColor3ub(0, 0, 0);
        FillEllipse(xCentre, yCentre, circR_m - 1, circR_m - 1);

        break;
      }
      case WHITE_can_move: {
        glColor3ub(0, 0, 0);
        FillEllipse(xCentre, yCentre, circR_m, circR_m);
        glColor3ub(255, 255, 255);
        FillEllipse(xCentre, yCentre, circR_m - 1, circR_m - 1);

        break;
      }
      default:
        break;
      }

      columnOffset += cellSize;
    }

    // ��������� ���

    rowOffset += cellSize;
  }

  //=============================   �������
  USHORT
    boardHeight = 100,
    leftEdge = 9,
    stringWidth = fieldWidth - 9 - leftEdge,
    stringHeight = (boardHeight - 13) / 2,
    firstStringY = fieldHeight - boardHeight + 4 + (boardHeight - 13) / 2,
    secondStringY = fieldHeight - boardHeight + 4;

  // ������� - ��������� ����
  switch (whoMoves) {
  case BLACK_can_move: {
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2i(leftEdge + stringWidth / 15, firstStringY + 10);
    glVertex2i(leftEdge + stringWidth / 15 + 20, firstStringY + stringHeight / 2);
    glVertex2i(leftEdge + stringWidth / 15, firstStringY + stringHeight - 10);
    glEnd();

    break;
  }
  case WHITE_can_move: {
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2i(leftEdge + stringWidth / 15, secondStringY + 10);
    glVertex2i(leftEdge + stringWidth / 15 + 20, secondStringY + stringHeight / 2);
    glVertex2i(leftEdge + stringWidth / 15, secondStringY + stringHeight - 10);
    glEnd();

    break;
  }
  default:
    break;
  }

  // ����� ������
  glRasterPos2i(leftEdge + (stringWidth / 15) * 3, firstStringY + 15);
  glPrint(firstString_buff);
  glRasterPos2i(leftEdge + (stringWidth / 15) * 3, secondStringY + 15);
  glPrint(secondString_buff);

  if (whoMoves) {
    // ����
    glColor3ub(255, 255, 255);
    glRasterPos2i(leftEdge + (stringWidth / 15) * 12, firstStringY + 15);
    glPrint(L"%u", blackScore);
    glRasterPos2i(leftEdge + (stringWidth / 15) * 12, secondStringY + 15);
    glPrint(L"%u", whiteScore);

    // ������ �����
    USHORT circR = 15;
    // ׸����
    glColor3ub(255, 255, 255);
    FillEllipse(leftEdge + (stringWidth / 15) * 10, firstStringY + stringHeight / 2, circR, circR);
    glColor3ub(0, 0, 0);
    FillEllipse(leftEdge + (stringWidth / 15) * 10, firstStringY + stringHeight / 2, circR - 1, circR - 1);
    // �����
    glColor3ub(0, 0, 0);
    FillEllipse(leftEdge + (stringWidth / 15) * 10, secondStringY + stringHeight / 2, circR, circR);
    glColor3ub(255, 255, 255);
    FillEllipse(leftEdge + (stringWidth / 15) * 10, secondStringY + stringHeight / 2, circR - 1, circR - 1);
  }

  //=================================================================================

  SwapBuffers(g_hDC);
}

void Render_glResize(int nWidth, int nHeight) {
  fieldWidth = nWidth;
  fieldHeight = nHeight;
  glViewport(0, 0, nWidth, nHeight);	// ������� OpenGL

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, nWidth, 0, nHeight);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

GLvoid glPrint(const WCHAR *fmt, ...) {
  WCHAR    text[256];      // ����� ��� ����� ������
  va_list    ap;          // ��������� �� ������ ����������

  if (fmt == NULL) return;
  va_start(ap, fmt);           // ������ ������ ����������
  wvsprintf(text, fmt, ap); // � ��������������� �������� � �������� ����

  va_end(ap);                  // ��������� ���������� � ������

  glPushAttrib(GL_LIST_BIT);      // ����������� ���� ������ �����������
  
  glListBase(base/* - 32*/);          // ������ ���� ������� � 0
  glCallLists(wcslen(text), GL_UNSIGNED_SHORT, text);  // ����� �������� �����������

  glPopAttrib(); // ������� ����� ������ �����������
}

GLvoid BuildFont(GLvoid) {
  HFONT font;  // ������������� ������
  base = glGenLists(0x0450);  // ������� ����� ��� ��������
  
  font = CreateFont(
    -24,          // ������ ������
    0,            // ������ ������
    0,            // ���� ���������
    0,            // ���� �������
    FW_BOLD,      // ������ ������
    FALSE,        // ������
    FALSE,        // �������������
    FALSE,        // ��������������
    DEFAULT_CHARSET,      // ������������� ������ ��������
    OUT_TT_PRECIS,      // �������� ������
    CLIP_DEFAULT_PRECIS,    // �������� ���������
    ANTIALIASED_QUALITY,    // �������� ������
    FF_DONTCARE | DEFAULT_PITCH,  // ��������� � ���
    L"Arial"      // ��� ������
  );

  SelectObject(g_hDC, font);        // ������� �����, ��������� ����

  wglUseFontBitmaps(g_hDC, 0x0, 0x0450, base); // ��������� ������� ������� � �������
}

void Render_killFont(void) {
  glDeleteLists(base, 0x0450);  // �������� ���� 96 ������� �����������
}

GLvoid StrokeEllipse(GLfloat xCenter, GLfloat yCenter, GLfloat rx, GLfloat ry, GLint pointCount) {
  const float step = float(2 * M_PI / pointCount);

  // ������ ����������� � ���� ����������� ������� �����, �����������
  // pointCount ����� �� ��� ������� � ����� 2*PI/pointCount
  glBegin(GL_LINE_STRIP);
  for (float angle = 0; angle < float(2 * M_PI); angle += step) {
    const float dx = rx * cosf(angle);
    const float dy = ry * sinf(angle);
    glVertex2f(dx + xCenter, dy + yCenter);
  }

  glEnd();
}

GLvoid FillEllipse(GLfloat xCenter, GLfloat yCenter, GLfloat rx, GLfloat ry, GLint pointCount) {
  const float step = float(2 * M_PI) / pointCount;

  // ������ ����������� � ���� "�����" �� �������������
  glBegin(GL_TRIANGLE_FAN);
  // ��������� ����� ����� ������������� � ������ �������
  glVertex2f(xCenter, yCenter);
  // ��������� ����� - ���������� �� ��� �������
  for (float angle = 0; angle <= float(2 * M_PI); angle += step) {
    float a = (fabsf(angle - float(2 * M_PI)) < 0.00001f) ? 0.f : angle;
    const float dx = rx * cosf(a);
    const float dy = ry * sinf(a);
    glVertex2f(dx + xCenter, dy + yCenter);
  }

  glEnd();
}