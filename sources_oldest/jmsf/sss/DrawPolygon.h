#pragma once

#include "myfuns.h"


#define POLY_TEXT_SCALE 0.08f
#define SHADOW_DIST 0.3f	//��� ������ // ����� ����
#define SHADOW_DIST_POLY 10  //��� ���������
#define SHADOW_DIST_POLY2 12  //��� ���������
#define SHADOW_DIST_POLY3 ((float)((SHADOW_DIST_POLY2-SHADOW_DIST_POLY)*SQRT2))  //��� ���������
#define SHADOW_KOEF 0.5f



;void DrawPolys();
//void DrawPoly();
void DrawPolyShadow();

void DrawVboPolys();
void DrawVboPolyFrames();
void DrawVboPolyShadows();

void GenVBOPoly(tka* p,float* arr,int* ind);
void GenVBOPolyFrame(tka* p,float** arr,int** ind);
void GenVBOPolyShadow(tka* p,float** arr,int** ind);

extern float PolyColor[3];
