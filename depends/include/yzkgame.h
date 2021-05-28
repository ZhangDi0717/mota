#ifndef YZKGAME_H
#define YZKGAME_H

#ifdef YZKGAME_EXPORTS //dll��Ŀ���ڡ�Ԥ���������塱�ж�����YZKGAME_EXPORTS������YZKGAME_API����������������������ʹ������������û����YZKGAME_EXPORTS�����Ծ���������������
#define YZKGAME_API __declspec(dllexport)
#else
#define YZKGAME_API __declspec(dllimport)
#endif

#ifndef __BOOL__
#define __BOOL__
typedef int                 BOOL;
#endif

#ifndef FALSE
#define FALSE               0
#endif

#ifndef TRUE
#define TRUE                1
#endif

#define RP_KEY_F1			1
#define RP_KEY_F2			2
#define RP_KEY_F3			3
#define RP_KEY_F4			4
#define RP_KEY_F5			5
#define RP_KEY_F6			6
#define RP_KEY_F7			7
#define RP_KEY_F8			8
#define RP_KEY_F9			9
#define RP_KEY_F10			10
#define RP_KEY_F11			11
#define RP_KEY_F12			12
#define RP_KEY_LEFT			100
#define RP_KEY_UP			101
#define RP_KEY_RIGHT			102
#define RP_KEY_DOWN			103
#define RP_KEY_PAGE_UP		104
#define RP_KEY_PAGE_DOWN		105
#define RP_KEY_HOME			106
#define RP_KEY_END			107
#define RP_KEY_INSERT			108

YZKGAME_API int getRPGameVersion();
YZKGAME_API void setGameSize(int width, int height);
YZKGAME_API int getGameWidth();
YZKGAME_API int getGameHeight();
YZKGAME_API void setViewPortPosition(int x, int y);//�����ӿڵ����½�����
YZKGAME_API int getViewPortPositionY();//��ȡ�ӿڵ�����X
YZKGAME_API int getViewPortPositionX();//��ȡ�ӿڵ�����Y

YZKGAME_API int getMousePositionX();//��ȡ���ĵ�ǰλ��X�������½�Ϊԭ�㣩
YZKGAME_API int getMousePositionY();//��ȡ���ĵ�ǰλ��Y�������½�Ϊԭ�㣩
YZKGAME_API BOOL isMouseLeftButtonDown();//�ж��������Ƿ���
YZKGAME_API void showMouseCursor();//��ʾ���ָ��
YZKGAME_API void hideMouseCursor();//�������ָ��


YZKGAME_API void clearGameUI();//������Ϸ����
YZKGAME_API void setBgColor(float red, float green, float b);//������Ϸ������ɫ
YZKGAME_API void pauseGame(int millSeconds);
YZKGAME_API void setGameTitle(char* title);
YZKGAME_API void playSound(char* soundName, BOOL repeat);
YZKGAME_API void closeSound(char* soundName);
YZKGAME_API int getPressedKeyCode();//�˷������Ƽ�ʹ�ã���ʹ��getPressedNormalKeyCode����getPressedSpecialKeyCode
YZKGAME_API int getPressedNormalKeyCode();
YZKGAME_API int getPressedSpecialKeyCode();
YZKGAME_API void asyncRun(void(*gameThread)(void *), void* argList);
YZKGAME_API void onNormalKeyUp(void(*func)(unsigned char key));//ֻ�ܵ���һ��
YZKGAME_API void onSpecialKeyUp(void(*func)(int key));//ֻ�ܵ���һ��


YZKGAME_API void rpInit(void(*gameMain)(void));

YZKGAME_API void createText(int txtNum, char* text);
YZKGAME_API void setText(int txtNum, char* text);
YZKGAME_API void setTextPosition(int txtNum, int x, int y);
YZKGAME_API void setTextColor(int txtNum, float r, float g, float b);
YZKGAME_API void setTextFontSize(int txtNum, int size);
YZKGAME_API void hideText(int num);
YZKGAME_API void showText(int num);
YZKGAME_API int getTextX(int num);
YZKGAME_API int getTextY(int num);
YZKGAME_API BOOL isTextVisible(int num);
YZKGAME_API BOOL isValidText(int num);

YZKGAME_API void setResourcesDir(char* dir);//�޸�Ĭ�ϵ���Դ·����Ĭ�Ϻ͵�ǰ����exeͬ��Ŀ¼�£���python��java�����԰�ʹ��

YZKGAME_API void createImage(int num, char* filePath);
YZKGAME_API void setImagePosition(int num, int x, int y);
YZKGAME_API void setImageSource(int num, char* imgName);
YZKGAME_API void showImage(int num);
YZKGAME_API void hideImage(int num);
YZKGAME_API int getImageX(int num);
YZKGAME_API int getImageY(int num);
YZKGAME_API int getImageWidth(int num);
YZKGAME_API int getImageHeight(int num);
YZKGAME_API BOOL isImageVisible(int num);
YZKGAME_API BOOL isValidImage(int num);

YZKGAME_API void createSprite(int num, char* spriteName);
YZKGAME_API void setSpritePosition(int num, int x, int y);
YZKGAME_API void playSpriteAnimate(int num, char* animateName);
YZKGAME_API void setSpriteRepeatPlay(int num, BOOL isRepeat);
YZKGAME_API void setSpriteFlipX(int num, BOOL isFlipX);
YZKGAME_API void setSpriteFlipY(int num, BOOL isFlipY);
YZKGAME_API void hideSprite(int num);
YZKGAME_API void showSprite(int num);
YZKGAME_API int getSpriteX(int num);//�״����ǵ���һ�ξͷ�תһ��
YZKGAME_API int getSpriteY(int num);
YZKGAME_API int getSpriteWidth(int num);
YZKGAME_API int getSpriteHeight(int num);
YZKGAME_API BOOL isSpriteVisible(int num);
YZKGAME_API BOOL isValidSprite(int num);

YZKGAME_API void alert(char* msg,...);
YZKGAME_API BOOL confirm(char* format, ...);

#endif /* YZKGAME_H */
