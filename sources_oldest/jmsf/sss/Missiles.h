#pragma once


#include "myfuns.h"


//////��������� ��������/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define MAX_MISSILES 2000// max ����� �������� � �����
#define MISSSIZE 0.6f//������
#define MISSSIZE_TODRAW 0.6f
#define MISSVEL 1//��������
#define MISSDES 160//���������
#define MANSIZE_PLUS_MISSSIZE_AND_SQ 1.69  //(MANSIZE+MISSSIZE)^2
#define MISSPUSHKOEF 0.3f//������
#define MISSSPREAD 0.03f//��������
#define MISSATTACK 24
#define MESS_SIZE 15


struct miss
{
	tka pos,vel;
	int des;
	char pl;
	miss(){}
	miss(float nx,float ny,float nvx,float nvy,int ndes){pos.setBoth(nx,ny);vel.setBoth(nvx,nvy);des=ndes;pl=0;}
};


extern miss ms[MAX_MISSILES];//�������
extern int MisNum;

void AddMiss(float nx,float ny,float nvx,float nvy,int ndes,char npl);
void AddMiss(tka npos,tka nv,int ndes,char npl);
void DelMiss(int i);
void FlyMiss();
