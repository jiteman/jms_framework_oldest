#pragma once


#include "Units.h"
#include "Bases.h"


#define VBO_NUM 10

class VBO_drawer
{
public:
	unsigned un_txtId[ UNIT_TYPES ][ 4 ]; // ��� ������� ���� �����(� ��� ������� �� 4-� ����� �����������) ���� ���������� �����.
	unsigned b_txtId[BASE_LEVEL_NUM];//��� ���
	unsigned fog_colId;//��� ������� ������
	
private:
	unsigned vertexId[ VBO_NUM ];
	unsigned indexId[ VBO_NUM ];
	//0-������� �����  1-������� ���� 2-������� �������(� ����������� �����.)
	//3-���� ��� ������ ����� 4-��� ������� "��������"

public:
	unsigned *_obstacleVertexIdentifiers;//��� �����������-���������
	unsigned *_obstacleIndexIdentifiers;

	unsigned *_obstacleFrameVertexIdentifiers;//��� ����� �����������-���������
	unsigned *_obstacleFrameIndexIdentifiers;
	unsigned *_obstacleFrameIndexNumbers;//����� ��������(������� ���������)

	unsigned *_obstacleShadowVertexIdentifiers;//��� ����� �����������-���������
	unsigned *_obstacleShadowIndexIdentifiers;
	unsigned *_obstacleShadowIndexNumbers;

public:	
	bool InitVBO();
	void UnInitVBO();



	void StartUnit();
	void StartBase();
	void StartMissile();
	void StartKrug();

	

	void SwitchToUnit(char type,char life);
	void SwitchToBase(char type);

	void InitUnitsVBO();
	void InitBasesVBO();
	void InitMissilesVBO();
	void InitKrugVBO();
	void InitPolyVBO();

	void UnInitPolyVBO();

	VBO_drawer(){_obstacleVertexIdentifiers=0;}
	
};

extern VBO_drawer vbo;

void transfering_to_vector_addElemVBO( float *el, size_t sizeOfElement, float **arr, int **ind );
void AddElemVBO(float* el,int el_size,float**arr,int**ind);
