#include "Textures.h"

#include "Filer.h"
#include "GUI.h"

#include "jmsf/stdal/stdal_stl.h"


CTexture *Texture;
TextureImage global_Textures[TEX_TYPES];


GLvoid LoadGLTextures(GLvoid)
{
	Texture->LoadTexture(IL_PNG,"textures\\cursor.png",&global_Textures[0],0);   
	Texture->LoadTexture(IL_PNG,"textures\\missile.png",&global_Textures[1],1);   
	Texture->LoadTexture(IL_PNG,"textures\\states.png",&global_Textures[2],0);   
	Texture->LoadTexture(IL_PNG,"textures\\wid.png",&global_Textures[3],0);   
	Texture->LoadTexture(IL_PNG,"textures\\digits.png",&global_Textures[4],0);   
	Texture->LoadTexture(IL_PNG,"textures\\arial_font.png",&global_Textures[5],0);   
	Texture->LoadTexture(IL_PNG,"textures\\attack_cursor.png",&global_Textures[6],0);   
	Texture->LoadTexture(IL_PNG,"textures\\frame1.png",&global_Textures[7],0);   
	Texture->LoadTexture(IL_PNG,"textures\\frame2.png",&global_Textures[8],0);   
	Texture->LoadTexture(IL_PNG,"textures\\frame3.png",&global_Textures[9],0);   

	Texture->LoadTexture(IL_PNG,"textures\\Units.png",&global_Textures[10],1);   
	Texture->LoadTexture(IL_PNG,"textures\\Bases.png",&global_Textures[11],1);   
	Texture->LoadTexture(IL_JPG,"textures\\bg2.jpg",&global_Textures[12],1);   
	

	Texture->LoadTexture(IL_TGA,"textures\\p1.tga",&global_Textures[13],1);   
	Texture->LoadTexture(IL_TGA,"textures\\p2.tga",&global_Textures[14],1);   
	Texture->LoadTexture(IL_TGA,"textures\\p3.tga",&global_Textures[15],1);   
	Texture->LoadTexture(IL_TGA,"textures\\p4.tga",&global_Textures[16],1);   
	Texture->LoadTexture(IL_TGA,"textures\\p5.tga",&global_Textures[17],1);   
	Texture->LoadTexture(IL_TGA,"textures\\p6.tga",&global_Textures[18],1);   
	Texture->LoadTexture(IL_TGA,"textures\\p7.tga",&global_Textures[19],1);   
	Texture->LoadTexture(IL_TGA,"textures\\p8.tga",&global_Textures[20],1);   
	
	Texture->LoadTexture(IL_PNG,"textures\\anim.png",&global_Textures[21],1);   


	CFile f1;
	if(!f1.Open("arial_font",OPEN_EXISTING))return;
	f1.Read(ArialFont.ch,224*sizeof(FontChar));
	ArialFont.txt=&TEXTURE_ARIAL_FONT;
	f1.Close();	
}

void MultAlpha(TextureImage* txt)
{
	unsigned i,j;
	double koef;
	if(txt->bpp!=4)
		return;
	for(i=0;i<txt->height*txt->width;i++)
	{
		koef=txt->imageData[4*i+3]/255.0;
		for(j=0;j<3;j++)
			txt->imageData[4*i+j]=(GLubyte)(txt->imageData[4*i]*koef);
	}
}

CTexture::CTexture()
{
	// � ������������ �������������� ���������� IL � ILU.
	// ���� ����� �� �������, ��������� ����� ����������� � �������.
	ilInit();
	iluInit();
}
 
// ����������
CTexture::~CTexture()
{
}
 
// �������, ��������������� ����������� �������� � ���������� ���������.
// � ������� ���������� ��� �����, ��� ����� � ��������� �� ��������.
void CTexture::LoadTexture(ILenum FileType, char *filename, TextureImage *texture, const bool bMultAlpha)
{
	// ������ DevIL ��������� ����
	::ilLoad( FileType, std::toWideString( filename ).c_str() );
 
	// ���������, ��� �� ������ ��� �������� �����
	int err=::ilGetError();
	if(err!=IL_NO_ERROR)
	{
		const wchar_t *strError = ::iluErrorString( err );
		MessageBox(NULL, strError, L"������ ��� ��������!", MB_OK);
		exit(1);
	}
 
	// �������� ������ ��������
	texture->width = ilGetInteger(IL_IMAGE_WIDTH);			// ������
	texture->height = ilGetInteger(IL_IMAGE_HEIGHT);		// ������
	texture->bpp = ilGetInteger(IL_IMAGE_BYTES_PER_PIXEL);		// ���� �� �������
 
	// ��������� ������ � ���� ��������
	texture->imageData = ilGetData();
 
	ilEnable(IL_CONV_PAL);
 
	// ��� ������ �����������
	unsigned int type = ilGetInteger(IL_IMAGE_FORMAT);
 
	// ���������� ��������
	glGenTextures(1, &texture->texID);
 
	// ����������� ������ �������� � ID
	glBindTexture(GL_TEXTURE_2D,texture->texID);

	if(bMultAlpha) MultAlpha(texture);
 
	// ������ ���-����
	gluBuild2DMipmaps(GL_TEXTURE_2D, texture->bpp, texture->width,
		texture->height, type, GL_UNSIGNED_BYTE, texture->imageData);
 
	// ������������� �������� �������
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
}
 
void CTexture::FreeTexture(TextureImage *texture)
{
 
}
