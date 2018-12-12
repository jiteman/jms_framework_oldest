#pragma once


#include "MyFuns.h"
#include "st.h"

#include <memory.h>


//////��������� ������/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define SOLDAOUTFIELD 0.1f  //��������� ����� �� ���� ����(����� �� ������� �� ����� ������)

#define SOLDA 0.005f  //��������� �����

#define SOLDTREN 0.9f  //����������
#define SOLDGIPTREN 0.8f
#define SOLDMAXVELSQ 0.04f

#define MANSIZE 1  //������ �����
#define MANSIZESQ 1 //������� ������� �����
#define MANREACHTARGET 0.3f // ������� �������� �������� �����
#define MANSIZE_DOUBLE_AND_SQ 4//  (MANSIZE*2)^2
#define PUSHKOEF 0.035f// ���� ������������
#define SMALLNAV 0.4f //��� ������, ��� ������ ��������� - �� ���������, � �� �� ���������  
#define SMALLNAV3 0.02f //��� ������, ��� ������ ��������� - ��� ��������
#define SMALLNAV2 0.01f //��� ������, ��� ������ ���������
#define SMALLVEL 0.001f //��������-���������

#define ANG_VAL_NUM 5//����� ��������� �������� ����� (� ���.: 0.5 1 2 4 8)

#define FORMKOEF 2 //���������� ������ � ������������� 
#define FORMSPREAD 3 //���������� ����� ������ 
#define MAN_LOOK_DIST 200 //������ ������ �����
#define MAN_LOOK_DIST_SQR 10000 //������� ������� ������ �����


#define MAX_DEFENDER_DIST 30


#define MAXSLD 20000
#define UNIT_TYPES 6//����� ����� ������ 
#define DEAD_SLD_NUM 1000// ��� ���-�� ������ ������ �� �����

//////��������� �����/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#define FIELDSIZEX 1024
//#define FIELDSIZEY 1024//������� ���� � �������
//#define KLET_SIZE 4//������ ������
//#define TOKLETSIZE(a) (int(a)>>2)

#define FIELDSIZEX 800
#define FIELDSIZEY 800//������� ���� � �������
#define KLET_SIZE 6//������ ������
#define TOKLETSIZE(a) (int(a)/KLET_SIZE)

#define OUT_FIELD 64//�������� ������� ����
#define SCROLLDIST 1  // 


struct sld_dead
{
	tka pos;
	char ang;
	char type;//&7 �����(������ 3 ����) ��������� - ��� �����

};
struct sld
{
	tka pos,nav,vel;
	__int16 a;
	__int16 enemy;
	__int16 group_id;
	stek<tka>way;//������� ��������(������.)
	
	char pl;//&7 �����(������ 3 ����)...&8-������, &16-������ ������� &32-�� ���������
	char type; 
	unsigned char zar;//�����������
	char life;//�����
	
	

};

extern sld Units[MAXSLD];// �����
extern sld_dead DeadUnits[DEAD_SLD_NUM];//����� ������
extern int Current_dead;

extern st<int>**QUNid;
//extern char **QUNex;// - ������� �������
extern char QUNex[FIELDSIZEX][FIELDSIZEY];

extern int UnitsNum;

extern unsigned int GameTime;

extern int SelInfo[UNIT_TYPES];//�������� ����� ���������� ������ ��������� �����
extern int UnInfo[PLAYERS_NUM][UNIT_TYPES];//�������� ����� ������ ��������� �����


extern unsigned char Zarad[UNIT_TYPES];//����� �����������
extern unsigned char Attack[UNIT_TYPES];//�����
extern unsigned char Defend[UNIT_TYPES];//������ �� ������� �����
extern unsigned char MissDefend[UNIT_TYPES];//������ �� �������
extern unsigned char ObserveDist[UNIT_TYPES];//1/2 ������� �������� ������ � ������ ������
extern unsigned char Velocity[UNIT_TYPES];//��������



void InitUnits();
void UnInitUnits();
void DeleteUnit(int i);
int AddUnit(tka pos,char pl,char type,tka send);

void CurrectTPoint(tka*t,tka from,tka to);

void CutRoute(sld*s);
void CorrectRoute(sld*s);

void MoveSld();


void MoveCheck(sld*s);

void UpdateDefenders();
tka CalcCenter(st<int> *s);
tka CalcCenterG(st<int> *s);
//void CurrectTPoint(tka*t,tka*from);

//���������� id �����, ���������� � ����� c �� ������ (ii,jj); ����� ��� � ������� rad ������, ������ ���� ������ �� ������� pl_filter
int Look(int ii,int jj,tka& c,int rad,char pl_filter);

void MakeAlert(int eni,st<int> *tmpst);

void FullClearField();
