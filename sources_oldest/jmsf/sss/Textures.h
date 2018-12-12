#pragma once


#include "osl/libimage/il/il.h"
#include "osl/libimage/ilu/ilu.h"

#include "open_gl.h"


#define TEX_TYPES 22 //���-�� �������


#define TEXTURE_CURSOR global_Textures[0]
#define TEXTURE_MISSILE global_Textures[1]
#define TEXTURE_STATES global_Textures[2]
#define TEXTURE_WID global_Textures[3]
#define TEXTURE_DIGITS global_Textures[4]
#define TEXTURE_ARIAL_FONT global_Textures[5]
#define TEXTURE_ATTACK_CURSOR global_Textures[6]
#define TEXTURE_FRAME( unit_type ) global_Textures[ 7 + unit_type ]
#define FRAME_TYPES_NUM 3

#define TEXTURE_UNITS global_Textures[7+FRAME_TYPES_NUM]
#define TEXTURE_BASES global_Textures[8+FRAME_TYPES_NUM]
#define TEXTURE_BG2 global_Textures[9+FRAME_TYPES_NUM]
#define TEXTURE_POLY( unit_type ) global_Textures[10 + FRAME_TYPES_NUM + unit_type ]
#define POLY_TYPES_NUM 8
#define TEXTURE_ANIM global_Textures[10+FRAME_TYPES_NUM+POLY_TYPES_NUM]



#define TEXTURE_BASES_SELECTION TEXTURE_BASES
#define TEXTURE_UNITS_SELECTION(type) TEXTURE_UNITS


// �������� ��������� TextureImage ��� �������� ������ ��������.
struct TextureImage
{
	GLubyte *imageData;		// ������ ��������
	GLuint	bpp;			// ���� �� ������
	GLuint width,height;		// ������ � ������
	GLuint texID;			// ID ��������
};
 
 
// ����� �������. �������� � �������������.
class CTexture{
public:
 
	CTexture();
	~CTexture();
 
	// ����������, ����� ��� ������ ������� - � �� ������ 2 ������� - 
	// �������� � ������������ ������� =)
	void LoadTexture(ILenum FileType, char *filename, TextureImage *texture, bool bMultAlpha);
	void FreeTexture(TextureImage *texture);
};

extern CTexture *Texture;
extern TextureImage global_Textures[TEX_TYPES];

GLvoid LoadGLTextures(GLvoid);

void MultAlpha(TextureImage* txt);
