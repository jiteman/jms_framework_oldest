#pragma once


#include "Units.h"

//////��������� AI/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define FORMATION_SIZE 200 // ������ ��������
#define MAX_FORMATIONS 1000 // max ����� ��������
#define AI_TIME 1000 // ������ ����������� ��
#define COMPUTER_AI( pl ) ( comp & ( 1 << ( pl ) ) )


struct Formation {
	int num;
	sld *first;
	st< int > un;
};

extern char enemy;
extern unsigned int score[ PLAYERS_NUM ];
//extern int GOOD_F_COST[PLAYERS_NUM]; // ���������� ����������� ��������
extern int Fnum;
extern Formation *global_formations;

void UpDateEnemy();
void ActAI();
void RenullAI();
