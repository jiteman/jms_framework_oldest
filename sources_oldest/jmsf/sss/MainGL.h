#pragma once


#include "temporary_windows_include.h"

#include "open_gl.h"


extern HGLRC hRC;		// ���������� �������� ����������
extern HDC hDC;			// ��������� �������� ���������� GDI
extern HWND		hWnd;// ���������� ����������� ����	   
extern DEVMODE dmScreenSettings;			// ����� ������


extern int WIDTH;
extern int HEIGHT;
extern int defWIDTH;
extern int defHEIGHT;
extern float BackColor[3];

void InitWindow();
void ChangeResolution(char res);
void SetResolution(char res);

void Begin2D ( void );
void End2D ( void );

GLvoid InitGL(GLsizei Width, GLsizei Height);
GLvoid ReSizeGLScene(GLsizei Width, GLsizei Height);
GLvoid OnCreate(HWND hWnd);
