#include <stdlib.h>
#include <stdio.h>
#include <yzkgame.h>
#include <string.h>


#pragma comment( linker, "/subsystem:\"console\" /entry:\"mainCRTStartup\"" )
#pragma comment(lib, "YZKGame.lib")
	void finish();
	int mapnum=0,mapnum1=0,Maxmap=1;//用于记录地图编号
	int i1=-1,j1=-1;//商店替换
	int music=0;
	char tempMsg[20]={0};
	char	shengguanghui=0,fengzhiluopan=0;
int bgImg=0,daguai=1000,guaiwutu=1001,SHENGGUANGHUI_PUSH=1002,FENGZHILUOPAN_PUSH=1003,wenbenkuang=1004,
	BAIFALAOREN=1005,HONGYILAOREN=1006,tujian1=1007,SHANGDIAN=1009,Kaishi=100;
int ii=0,iiy=30;
int bird=1;
int FLOOR[11][11]={0};
int LEVELNUM=0,YELLOWKEYNUM=1,BLUEKEYNUM=2,REDKEYNUM=3,ATACKNUM=5,HPNUM=4,DEFNUM=6,MONEYNUM=7,EXNUM=8;
int HP=9,ATACK=10,DEF=11,PEOPLEHP=12,PEOPLEATACK=13,PEOPLEDEF=14,wenbenkuang2=15,
	jieju[9]={16,17,18,19,20,21,22,23,24};
typedef struct{
   char name[20];
   int hp;
   int ATACK;
   int DEF;
   int money;
   int ex;
   long int lost;
} THINGS;
THINGS QINGTOUGUAI={"青头怪",200,35,10,5,5},HONGTOUGUAI={"红头怪",70,15,2,5,5},KULOUREN={"骷髅人",110,25,5,5,5},
CHUJIFASHI={"初级法师",125,50,25,25,10},LVTOUGUAI={"绿头怪",50,20,1,1,1},XIAOBIANFU={"小蝙蝠",100,20,5,3,3},
SHOUMIANREN={"兽面人",300,75,45,13,10},KULOUSHIBING={"骷髅士兵",150,40,20,8,6},DABIANFU={"大蝙蝠",150,65,40,10,8},
CHUJIWEIBING={"初级卫兵",450,150,90,22,19},JINGDUIZHANG={"金队长",900,750,650,77,70},JINGWEISHI={"金卫士",850,350,200,45,40},
KULOUDUIZHANG={"骷髅队长",400,90,50,15,12},GUAIWANG={"怪王",700,250,125,32,30},SHITOUGUAIREN={"石头怪人",500,115,65,15,15},
HONGBIANFU={"红蝙蝠",550,160,90,25,20},HONGYIFASHI={"红衣法师",500,400,260,47,45},GAOJIFASHI={"高级法师",100,200,110,40,35},
BAIYIWUSHI={"白衣武士",1300,300,150,40,35},MAYIFASHI={"麻衣法师",250,120,70,20,17},SHOUMIANWUSHI={"兽面武士",900,450,330,50,50},
SHUANGSHOUJIANSHI={"双手剑士",1200,620,520,65,75},GAOJIWEIBING={"高级卫兵",1500,560,460,60,60},MINGWEIBING={"冥卫兵",1250,500,400,55,55},
LINGWUSHI={"灵武士",1200,980,900,99,75},MINGZHANSHI={"冥战士",200,680,590,70,65},LINGFASHI={"灵法师",1500,830,730,80,70},
MINGDUIZHANG={"冥队长",2500,900,850,84,75},YINGZIZHANSHI={"影子战士",3100,1150,1050,92,80},
HONGYIMOWANG={"红衣魔王",15000,1000,1050,100,100},MINGLINGMOWANG={"冥灵魔王",30000,2550,2250,250,220};
typedef struct
{
	int level;
	int hp;
	int ATACK;
	int DEF;
	int money;
	int ex;
	int x;
	int y;
	int YELLOWKEY;
	int REDKEY;
	int BLUEKEY;
} THING;
THING PEOPLE={1,1000,10,10,0,0,5,1,1,1,1};
typedef struct
{
   int Map[11][11];
} MAPDEFINE;
MAPDEFINE M[12];
int Ma[][11][11]={
	{	{16, 8,12, 2, 0, 0, 0, 2, 2, 2, 2},
		{17,37, 2, 2,13, 0, 0, 2, 6,32, 2},
		{ 2,35, 7, 2, 2, 3, 2, 7,32,16, 2},
		{ 2, 2,37, 7, 2, 0, 2,32,17,37, 2},
		{13, 2,12, 2, 2, 0, 2, 2, 2, 4, 2},
		{36, 5,32, 2, 0, 0, 0, 0, 0, 0, 0},
		{14, 2, 4, 2, 0, 2, 2, 4, 2, 2, 2},
		{ 2, 2, 0, 0,34, 5,35,33,34, 2, 2},
		{14,33,12,31, 2, 2,38,30,38, 2, 2},
		{ 2, 4, 2,34, 2,17, 6, 2, 6,16, 2},
		{12,12, 2, 0,10, 2, 2, 2, 2, 2, 2}
	},
	{	{ 6, 6, 2,24, 2,16, 2,17, 2, 0,12},
		{ 6, 6, 2, 0, 2,16, 2,17, 2,39,10},
		{ 7, 7, 4,41, 2,16,40,17, 2,34,12},
		{ 7, 7, 2, 0, 2,41, 5,41, 2, 0,31},
		{ 2, 2, 2, 3, 2, 4, 2, 4, 2, 4, 2},
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 4, 2, 4, 2, 0, 2, 2, 2, 4, 2, 2},
		{12, 2,12, 2, 0, 2,12,52,53,52,14},
		{38, 2,38, 2, 0, 2,12, 2,52, 2,14},
		{14, 2,14, 2, 0, 2,12, 2,13, 2,14},
		{36,38,36, 2,11, 2,97, 2,13, 2,29}
	},
	{
		{ 6,17, 2, 2, 2, 2, 2, 2, 2, 2, 2},
		{21,32, 4,34, 0, 0, 0,31, 2, 0,11},
		{ 6,16, 2, 0, 2, 0, 2, 0, 2, 0, 2},
		{ 2, 2, 0, 0, 2,32, 2, 0,35, 0, 2},
		{35, 0, 0, 2, 2, 4, 2, 2, 2, 2, 2},//临时
		{ 4, 2, 0, 2, 0, 0, 0, 2, 0, 0,10},
		{12, 2,31, 2,22,22,22, 2, 0, 2, 2},
		{12, 2, 0, 2, 2, 2, 2, 2,35, 2, 6},
		{12, 2, 0, 0, 6, 6,31, 0, 0, 5, 6},
		{14, 2, 4, 2, 2, 2, 2, 0, 4,32,12},
		{31,16,35,17,12, 7, 2, 0, 2,12,35}	},
	{
		{45, 6,12, 2, 7, 7, 7,36, 3, 3,38},
		{ 6, 2, 2, 2,12,12,12, 2, 2, 2, 0},
		{ 6, 2,16,17,14,14,14,17,16, 2, 0},
		{30, 2,17,16,13,13,13,16,17, 2, 0},
		{ 0, 2, 2, 2, 2,20, 2, 2, 2, 0, 0},
		{ 0, 0,32, 6, 6,30, 6, 6, 0, 0,11},
		{12, 0,30, 2, 2, 3, 2, 2,30, 0, 0},
		{12, 2, 5, 2,12,36,12, 2, 5, 2,30},
		{12, 2,16,45,38,39,38,45,17, 2, 6},
		{32, 2,16, 2, 2,99, 2, 2,17, 2, 6},
		{10, 2,16, 2, 0,23, 0, 2,17, 2,32}	},//4
	{
		{36, 0, 0,30,12,12, 6, 0, 0, 0,10},
		{ 0, 5, 2, 4, 2, 2, 2, 4, 2, 0, 0},
		{ 0, 2, 2,12,38, 2,33, 7, 2, 2, 0},
		{ 0, 4,38,16,38, 5, 0,35, 7, 4, 0},
		{ 0, 2,12,38,18, 2,35,33,33, 2, 6},
		{30, 2, 2, 2, 2, 2, 2, 2, 2, 2,14},
		{ 0, 2,37, 6,37, 2,30,12,17, 2,14},
		{ 0, 4, 6,37, 0, 5,25,30,30, 4,35},
		{ 0, 2, 2,31,37, 2,30,12, 2, 2, 0},
		{ 0, 0, 2, 4, 2, 2, 2, 4, 2, 5, 0},
		{11, 0, 0, 0, 0,30, 0, 0, 0, 0,39}	},//第五层
	{
		{ 0, 0, 0, 2,10, 0, 4, 4, 0, 0,11},
		{ 0, 2,38, 2, 0, 0, 2, 2, 0, 0, 2},
		{ 0, 2, 4, 2, 4, 2, 2, 2, 2, 5, 2},
		{ 0, 2,38, 4,38, 0, 0, 0, 0, 0, 2},
		{ 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
		{ 0, 0,47, 0,12,12,12, 0,47, 0,19},
		{ 2, 2, 2, 3, 2, 2, 2, 2, 2, 4, 2},
		{ 0, 0, 2,39, 2, 0, 0, 0, 2,46, 0},
		{12,45, 5, 0, 5,45, 0,12, 2, 0,44},
		{42,12, 2,16, 2, 0,12,43, 2,44, 7},
		{26,42, 2,17, 2,12,43,27, 2, 7, 7}	},//第六层
	{
		{ 2, 0, 0, 4,11, 0, 0, 4, 0, 0, 2},
		{ 0, 0, 2, 2, 2, 3, 2, 2, 2, 0, 0},
		{ 0, 2, 2,14,14, 7,14,14, 2, 2, 0},
		{ 0, 2,12, 6, 2, 5, 2, 6,12, 2, 0},
		{ 0, 2, 6,16, 2,48, 2,17, 6, 2, 0},
		{ 0, 2, 2, 2, 2,98, 2, 2, 2, 2, 0},
		{ 0, 0, 5,48,99,28,98,48, 5, 0, 0},
		{ 0, 0, 2, 2, 2,98, 2, 2, 2, 0, 0},
		{ 2, 0,45,17, 2,48, 2,16,42, 0, 2},
		{ 2, 2, 0,45, 2, 5, 2,42, 0, 2, 2},
		{10, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2}	},//第七层
	{
		{ 0, 0,49, 0, 0, 2, 0,43,48,43, 0},
		{ 0, 2, 2, 2, 4, 2, 0, 2, 2, 2, 0},
		{ 0, 2, 0,42, 0, 2,42, 2, 0, 0, 0},
		{ 0, 2,30, 2, 2, 2,39, 2, 4, 2, 2},
		{38, 2,30, 2, 0, 0, 0, 2, 0,45, 0},
		{45, 2,17, 2, 6, 2, 2, 2, 2, 2, 0},
		{38, 2, 0, 2, 6, 2,10, 0, 0, 2,30},
		{ 0, 2, 0, 2,49, 2, 2, 2,38, 2,30},
		{ 0, 2, 0, 2, 0, 0, 5, 0, 0, 2,16},
		{ 0, 2, 0, 2, 2, 4, 2, 4, 2, 2, 0},
		{11, 2, 0, 0, 0, 0, 2, 0,12,42, 0}	},//第八层
	{
		{97,14,42, 4, 7,44, 7, 2, 0, 2, 0},
		{14,42, 6, 2,44,49,44, 2, 0, 4,42},
		{42, 6,42, 2, 2, 5, 2, 2, 0, 2,12},
		{ 2, 4, 2, 2, 0, 0, 0, 4, 0, 2,12},
		{17,46,16, 2,49, 2,10, 2, 0, 2, 6},
		{ 2, 5, 2, 2, 0, 2, 2, 2, 0, 2, 2},
		{ 0, 0, 0, 3, 0, 2,11, 2, 0, 2, 6},
		{ 0, 0, 0, 2, 0, 2, 0, 0, 0, 2,12},
		{ 2, 4, 2, 2, 0, 2, 2, 2, 0, 2,12},
		{12, 0,50, 4, 0, 0, 0, 2, 0, 4,42},
		{ 9,12, 0, 2, 2, 2, 0, 0, 0, 2, 0}	},//第九层
	{
		{10, 2, 6,17,16, 2,14, 2,14, 2, 6},
		{ 0, 2, 6,17,16, 3,49, 2,49, 2,12},
		{ 0, 2, 6,17,16, 2, 0,45, 0, 2,12},
		{ 0, 2, 2, 2, 2, 2, 2, 4, 2, 2, 0},
		{38, 2, 0, 0, 0,11, 2, 0, 4,45, 0},
		{45, 2, 0, 2, 2, 2, 2, 4, 2, 2,12},
		{38, 2, 0, 0,12,12,12, 0, 0, 2,12},
		{ 0, 2, 0, 2, 2, 2, 2, 2, 0, 2, 2},
		{ 0, 0, 0, 0, 0, 2, 0, 0, 0,46, 7},
		{ 0, 0, 2, 2, 4, 2, 4, 2, 2, 0,46},
		{ 0, 2, 2,17,50, 2,50,16, 2, 2, 0}	},//第十层
	{
		{11, 0, 0, 0, 0, 0, 0, 0, 0, 0,10},
		{ 2, 2, 3, 2, 6, 0, 6, 2, 3, 2, 2},
		{17, 2,53, 2,22,22,22, 2,53, 2,16},
		{51, 2,53, 2, 2, 2, 2, 2,53, 2,51},
		{53, 2, 0,53,52,51,52,53, 0, 2,52},
		{ 4, 2, 2, 5, 2, 2, 2, 5, 2, 2, 4},
		{ 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0},
		{ 4, 2, 4, 2, 4, 2, 4, 2, 2, 5, 2},
		{ 6, 2,12, 2,14, 2,13, 2, 7, 0, 7},
		{ 6, 2,12, 2,14, 2,13, 2, 7, 0, 7},
		{ 6, 2,12, 2,14, 2,13, 2, 7,29, 7}	},//第十一层
	{
		{10, 0, 0, 0, 0, 0, 0, 0, 0, 0,11},
		{ 2, 2 ,2,52, 2, 5, 2,52, 2, 2, 2},
		{17, 4,51,53,53,52,53,53,51, 4,16},
		{ 2, 2, 2, 0, 2, 2, 2, 0, 2, 2, 2},
		{ 0, 0, 0, 0, 2, 6, 2, 0, 0, 0, 0},
		{ 2, 5, 2, 0, 2, 6, 2, 0, 2, 5, 2},
		{51,55, 2, 0, 2,12, 2, 0, 2,56,54},
		{ 0,51, 2, 0, 2,12, 2, 0, 2,54, 0},
		{ 0, 0, 2, 0, 2,40, 2, 0, 2, 0, 0},
		{16, 0, 2, 0, 2, 4, 2, 0, 2, 0, 7},
		{19,17, 2, 0,41,40,41, 0, 2, 7,26}	},//12
{
		{11, 0, 0, 0, 0,10, 2,91,57, 4, 0},
		{ 2,41, 2, 0, 0, 0, 2, 2, 2, 2, 0},
		{ 2,40, 2, 5, 2, 0, 0, 0, 2,17, 0},
		{ 2,16, 2, 0, 2,55,55, 2, 2,17, 2},
		{ 2,16, 2,41, 7, 0,41, 0, 2,17, 2},
		{ 2,16, 2, 0,53,52,53, 0, 2, 0, 2},
		{ 2,41, 2, 2, 2, 5, 2, 0, 4,55, 2},
		{ 2, 2, 2, 0, 7,57, 7, 2, 2, 2, 2},
		{ 2,98, 0,54,57,98,57,54, 0,98, 2},
		{ 2,98,55,55,99,18,98,55,55,98, 2},
		{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}	},//13
{
		{ 2, 2, 2, 2, 2,11, 2, 2, 2, 2, 2},
		{ 2,53,52,53, 5, 0, 5,53,52,53, 2},
		{ 2, 0,66,66, 2, 5, 2,66,66, 0, 2},
		{ 2, 0,66,66, 2,55, 2,66,66, 0, 2},
		{ 2, 0, 0, 6, 2,57, 2,16, 0, 0, 2},
		{ 2, 0, 6, 2, 2,55, 2, 2, 7, 0, 2},
		{ 2, 0, 2, 2, 2,99, 2, 2, 2, 0, 2},
		{ 2, 0, 2, 2, 2,92, 2, 2, 2, 0, 2},
		{ 2, 0, 2, 2, 2, 2, 2, 2, 2, 0, 2},
		{ 2, 0, 7, 2, 2, 2, 2, 2, 6, 0, 2},
		{ 2, 0,54,24,17,10, 0,53, 0, 0, 2}	},//14
{
		{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
		{66, 2, 2, 2, 2, 2, 2, 2, 2, 2,66},
		{66,66, 2, 2, 2, 2, 2, 2, 2,66,66},
		{66,66,66, 2,94, 2,95, 2,66,66,66},
		{66,66, 2,17,16, 2,16,17, 2,66,66},
		{66, 2, 2, 0, 0, 2, 0, 0, 2, 2,66},
		{66,66, 2, 2, 4, 2, 4, 2, 2,66,66},
		{66,66,66, 2, 0, 0, 0, 2,66,66,66},
		{66,66, 2, 2, 2, 3, 2, 2, 2,66,66},
		{66, 2, 2,12, 0, 0, 0,12, 2, 2,66},
		{ 2, 0, 0, 0, 0,11, 0, 0, 0,10, 2}	},//15
{
		{66,66,66,66,66,66,66,66,66,66,66},
		{66,66,66,66,66,66,66,66,66,66,66},
		{66,66, 2, 2, 2, 2, 2, 2, 2,66,66},
		{66, 2, 2, 2,98,10,98, 2, 2, 2,66},
		{66, 2, 2, 6, 6,59, 6, 6, 2, 2,66},
		{66, 2,17,16, 0, 0, 0,16,17, 2,66},
		{ 2, 2,16,17,55,55,55,17,16, 2, 2},
		{66, 2, 2, 2, 0, 0, 0, 2, 2, 2,66},
		{66,66,66, 2, 2, 3, 2, 2,66,66,66},
		{66, 2, 2, 2, 0, 0, 0, 2, 2, 2,66},
		{ 2, 0, 0, 0, 0, 0, 0, 0, 0,11, 2}	},//16
{
		{10, 0,58, 0, 0,57, 0, 0, 0,54, 7},
		{66,66,66,66,66,66,66,66,66, 0,66},
		{66,40,16,16,66,66,66,54, 0,54,66},
		{66,17,66,66,66,11,66, 0,66,66,66},
		{66,17,66,57, 0, 0,66, 0,66,27,66},
		{66,59,66, 0,66,66,66,54, 0,58,66},
		{66, 0,57,54,66, 7, 0,57,66,66,66},
		{66, 0, 0,66,66,54, 0,66,66,66,66},
		{66, 0,66,66,40, 0,66,66,16,17,66},
		{66,57,66, 0, 0,40, 0, 0,59,16,17},
		{66,54,57, 0,66,66,66,66,66,66,66}	},//17
{
		{58,16,48, 6,57,13,57, 6,48,16,58},
		{ 7,66,12,66,14,66,14,66,12,66, 7},
		{66,17,48, 0,54, 0,54, 0,48,17,66},
		{ 6,66,12,66, 0,10, 0,66,12,66, 6},
		{57,14,54, 0, 0, 0, 0, 0,54,14,57},
		{13,66, 0,66, 0,66, 0,66, 0,66,13},
		{57,14,54, 0, 0, 0, 0, 0,54,14,57},
		{ 6,66,12,66, 0,11, 0,66,12,66, 6},
		{66,17,48, 0,54, 0,54, 0,48,17,66},
		{ 7,66,12,66,14,66,14,66,12,66, 7},
		{58,16,48, 6,57,13,57, 6,48,16,58}	},//18
{
		{66,66,66,66,66,66,66,66,66,66,66},
		{66, 2, 2, 2, 2, 2, 2, 2, 2, 2,66},
		{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
		{ 0, 0, 0, 2,99,11,98, 2, 0, 0, 0},
		{ 0,66, 0, 0, 0, 0, 0, 0, 0,66, 0},
		{ 0,66,66,66,98, 0,98,66,66,66, 0},
		{ 0,66,94,66,66,60,66,66,95,66, 0},
		{ 0,66,99,66,98,10,98,66,99,66, 0},
		{ 0,66,59,66,66,66,66,66,59,66, 0},
		{ 0,66, 0,66, 0, 0, 0,66, 0,66, 0},
		{ 0, 0, 0, 0, 0,66, 0, 0, 0, 0, 0},	},//19
{
		{11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{66,66,66,66,66, 0,66,66,66,66,66},
		{66,66,66,66, 2, 0, 2,66,66,66,66},
		{66,66,66, 2, 2, 0, 2, 2,66,66,66},
		{66,66, 2, 2, 2, 3, 2, 2, 2,66,66},
		{66, 2, 2, 2, 2,96, 2, 2, 2, 2,66},
		{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
		{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
		{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
		{ 2, 2, 2, 2,66,66,66, 2, 2, 2, 2},
		{66, 2, 2,66,66,66,66,66, 2, 2,66}	}//20

};

int map[11][11] =
{	{16, 8,12, 2, 0, 0, 0, 2, 2, 2, 2},
	{17,37, 2, 2,13, 0, 0, 2, 6,32, 2},
	{ 2,35, 7, 2, 2, 3, 2, 7,32,16, 2},
	{ 2, 2,37, 7, 2, 0, 2,32,17,37, 2},
	{13, 2,12, 2, 2, 0, 2, 2, 2, 4, 2},
	{36, 5,32, 2, 0, 0, 0, 0, 0, 0, 0},
	{14, 2, 4, 2, 0, 2, 2, 4, 2, 2, 2},
	{ 2, 2, 0, 0,34, 5,35,33,34, 2, 2},
	{14,33,12,31, 2, 2,38,30,38, 2, 2},
	{ 2, 4, 2,34, 2,17, 6, 2, 6,16, 2},
	{12,12, 2, 0,10, 2, 2, 2, 2, 2, 2}
};//第一层


void showmap(void* d){
	int i,j,k=1;
	char temp[10];
   //memcpy(map,map1,sizeof(map));
   map[PEOPLE.y][PEOPLE.x] = 15;
   for(i = 0 ; i < 11; i++)
	   for(j = 0 ; j < 11 ; j++)
			FLOOR[i][j]=k++;
	for(i = 0 ; i < 11; i++)
		for(j = 0 ; j < 11 ; j++){
		   if(map[i][j]==0){
			   createImage(FLOOR[i][j],"FLOOR.png");
			   setImagePosition(FLOOR[i][j],60*j+365,60*i+57);
		   }
		   else if(map[i][j]==2){
				createImage(FLOOR[i][j],"QIANG.png");
				setImagePosition(FLOOR[i][j],60*j+365,60*i+57);
		   }
		   else if(map[i][j]==3){
				createImage(FLOOR[i][j],"HONGMEN.png");
				setImagePosition(FLOOR[i][j],60*j+365,60*i+57);
		   }
		   else if(map[i][j]==4){
				createImage(FLOOR[i][j],"HUANGMEN.png");
				setImagePosition(FLOOR[i][j],60*j+365,60*i+57);
		   }
		   else if(map[i][j]==5){
				createImage(FLOOR[i][j],"LANMEN.png");
				setImagePosition(FLOOR[i][j],60*j+365,60*i+57);
		   }
		   else if(map[i][j]==6){
				createImage(FLOOR[i][j],"HONGPING.png");
				setImagePosition(FLOOR[i][j],60*j+365,60*i+57);
		   }
		   else if(map[i][j]==7){
				createImage(FLOOR[i][j],"LANPING.png");
				setImagePosition(FLOOR[i][j],60*j+365,60*i+57);
		   }
		   else if(map[i][j]==8){
				createImage(FLOOR[i][j],"SHENGGUANGHUI.png");
				setImagePosition(FLOOR[i][j],60*j+365,60*i+57);
		   }
		   else if(map[i][j]==9){
				createImage(FLOOR[i][j],"FENGZHILUOPAN.png");
				setImagePosition(FLOOR[i][j],60*j+365,60*i+57);
		   }
		   else if(map[i][j]==10){
				createImage(FLOOR[i][j],"LOUTIS.png");
				setImagePosition(FLOOR[i][j],60*j+365,60*i+57);
		   }
		   else if(map[i][j]==11){
				createImage(FLOOR[i][j],"LOUTIX.png");
				setImagePosition(FLOOR[i][j],60*j+365,60*i+57);
		   }
		   else if(map[i][j]==12){
				createImage(FLOOR[i][j],"HUANGYAOSHI.png");
				setImagePosition(FLOOR[i][j],60*j+365,60*i+57);
		   }
		   else if(map[i][j]==13){
				createImage(FLOOR[i][j],"HONGYAOSHI.png");
				setImagePosition(FLOOR[i][j],60*j+365,60*i+57);
		   }
		   else if(map[i][j]==14){
				createImage(FLOOR[i][j],"LANYAOSHI.png");
				setImagePosition(FLOOR[i][j],60*j+365,60*i+57);
		   }
		   else if(map[i][j]==15){
			   createImage(FLOOR[i][j],"PEOPLE1.png");
			   setImagePosition(FLOOR[i][j],60*j+365,60*i+57);
		   }
		   else if(map[i][j]==16){
			   createImage(FLOOR[i][j],"HONGBAOSHI.png");
			   setImagePosition(FLOOR[i][j],60*j+365,60*i+57);
		   }
		   else if(map[i][j]==17){
			   createImage(FLOOR[i][j],"LANBAOSHI.png");
			   setImagePosition(FLOOR[i][j],60*j+365,60*i+57);
		   }
		   else if(map[i][j]==18){
			   createImage(FLOOR[i][j],"BAIFALAOREN.png");
			   setImagePosition(FLOOR[i][j],60*j+365,60*i+57);
		   }
		   else if(map[i][j]==19){
			   createImage(FLOOR[i][j],"HONGYILAOREN.png");
			   setImagePosition(FLOOR[i][j],60*j+365,60*i+57);
		   }
		   else if(map[i][j]==20){
			   createImage(FLOOR[i][j],"QINGMEN.png");
			   setImagePosition(FLOOR[i][j],60*j+365,60*i+57);
		   }
		   else if(map[i][j]==21){
			   createImage(FLOOR[i][j],"BAOJIAN.png");
			   setImagePosition(FLOOR[i][j],60*j+365,60*i+57);
		   }
		   else if(map[i][j]==22){
			   createImage(FLOOR[i][j],"SHANGDIAN.png");
			   setImagePosition(FLOOR[i][j],60*j+365,60*i+57);
			   j+=2;
		   }
		   else if(map[i][j]==24){
			   createImage(FLOOR[i][j],"JINYAOSHI.png");
			   setImagePosition(FLOOR[i][j],60*j+365,60*i+57);
			   j+=2;
		   }
		   else if(map[i][j]==28){
			   createImage(FLOOR[i][j],"SHIZIJIA.png");
			   setImagePosition(FLOOR[i][j],60*j+365,60*i+57);
			   j+=2;
		   }
		   else if(map[i][j]==29){
			   createImage(FLOOR[i][j],"TENGMUDUN.png");
			   setImagePosition(FLOOR[i][j],60*j+365,60*i+57);
			   j+=2;
		   }
		   else if(map[i][j]==30){
				createImage(FLOOR[i][j],"QINGTOUGUAI.png");
				setImagePosition(FLOOR[i][j],60*j+365,60*i+57);
		   }
		   else if(map[i][j]==31){
				createImage(FLOOR[i][j],"HONGTOUGUAI.png");
				setImagePosition(FLOOR[i][j],60*j+365,60*i+57);
		   }
		   else if(map[i][j]==32){
				createImage(FLOOR[i][j],"KULOUREN.png");
				setImagePosition(FLOOR[i][j],60*j+365,60*i+57);
		   }
		   else if(map[i][j]==33){
				createImage(FLOOR[i][j],"CHUJIFASHI.png");
				setImagePosition(FLOOR[i][j],60*j+365,60*i+57);
		   }
		   else if(map[i][j]==34){
				createImage(FLOOR[i][j],"LVTOUGUAI.png");
				setImagePosition(FLOOR[i][j],60*j+365,60*i+57);
		   }
		   else if(map[i][j]==35){
				createImage(FLOOR[i][j],"XIAOBIANFU.png");
				setImagePosition(FLOOR[i][j],60*j+365,60*i+57);
		   }
		   else if(map[i][j]==36){
				createImage(FLOOR[i][j],"SHOUMIANREN.png");
				setImagePosition(FLOOR[i][j],60*j+365,60*i+57);
		   }
		   else if(map[i][j]==37){
				createImage(FLOOR[i][j],"KULOUSHIBING.png");
				setImagePosition(FLOOR[i][j],60*j+365,60*i+57);
		   }
		   else if(map[i][j]==38){
				createImage(FLOOR[i][j],"DABIANFU.png");
				setImagePosition(FLOOR[i][j],60*j+365,60*i+57);
		   }
		   else if(map[i][j]==39){
				createImage(FLOOR[i][j],"CHUJIWEIBING.png");
				setImagePosition(FLOOR[i][j],60*j+365,60*i+57);
		   }
		   else if(map[i][j]==40){
				createImage(FLOOR[i][j],"JINDUIZHANG.png");
				setImagePosition(FLOOR[i][j],60*j+365,60*i+57);
		   }
		   else if(map[i][j]==41){
				createImage(FLOOR[i][j],"JINGWEISHI.png");
				setImagePosition(FLOOR[i][j],60*j+365,60*i+57);
		   }
		   else if(map[i][j]==42){
				createImage(FLOOR[i][j],"KULOUDUIZHANG.png");
				setImagePosition(FLOOR[i][j],60*j+365,60*i+57);
		   }
		   else if(map[i][j]==43){
				createImage(FLOOR[i][j],"GUAIWANG.png");
				setImagePosition(FLOOR[i][j],60*j+365,60*i+57);
		   }
		   else if(map[i][j]==44){
				createImage(FLOOR[i][j],"SHITOUGUAIREN.png");
				setImagePosition(FLOOR[i][j],60*j+365,60*i+57);
		   }
		   else if(map[i][j]==45){
				createImage(FLOOR[i][j],"HONGBIANFU.png");
				setImagePosition(FLOOR[i][j],60*j+365,60*i+57);
		   }
		   else if(map[i][j]==46){
				createImage(FLOOR[i][j],"HONGYIFASHI.png");
				setImagePosition(FLOOR[i][j],60*j+365,60*i+57);
		   }
		   else if(map[i][j]==47){
				createImage(FLOOR[i][j],"GAOJIFASHI.png");
				setImagePosition(FLOOR[i][j],60*j+365,60*i+57);
		   }
		   else if(map[i][j]==48){
				createImage(FLOOR[i][j],"BAIYIWUSHI.png");
				setImagePosition(FLOOR[i][j],60*j+365,60*i+57);
		   }
		   else if(map[i][j]==49){
				createImage(FLOOR[i][j],"MAYIFASHI.png");
				setImagePosition(FLOOR[i][j],60*j+365,60*i+57);
		   }
		   else if(map[i][j]==50){
				createImage(FLOOR[i][j],"SHOUMIANWUSHI.png");
				setImagePosition(FLOOR[i][j],60*j+365,60*i+57);
		   }
		   else if(map[i][j]==51){
				createImage(FLOOR[i][j],"SHUANGSHOUJIANSHI.png");
				setImagePosition(FLOOR[i][j],60*j+365,60*i+57);
		   }
		   else if(map[i][j]==52){
				createImage(FLOOR[i][j],"GAOJIWEIBING.png");
				setImagePosition(FLOOR[i][j],60*j+365,60*i+57);
		   }
		   else if(map[i][j]==53){
				createImage(FLOOR[i][j],"MINGWEIBING.png");
				setImagePosition(FLOOR[i][j],60*j+365,60*i+57);
		   }
		   else if(map[i][j]==54){
				createImage(FLOOR[i][j],"LINGWUSHI.png");
				setImagePosition(FLOOR[i][j],60*j+365,60*i+57);
		   }
		   else if(map[i][j]==55){
				createImage(FLOOR[i][j],"MINGZHANSHI.png");
				setImagePosition(FLOOR[i][j],60*j+365,60*i+57);
		   }
		   else if(map[i][j]==56){
				createImage(FLOOR[i][j],"LINGFASHI.png");
				setImagePosition(FLOOR[i][j],60*j+365,60*i+57);
		   }
		   else if(map[i][j]==57){
				createImage(FLOOR[i][j],"MINGDUIZHANG.png");
				setImagePosition(FLOOR[i][j],60*j+365,60*i+57);
		   }
		   else if(map[i][j]==99||map[i][j]==98){
				createImage(FLOOR[i][j],"TIELAN.png");
				setImagePosition(FLOOR[i][j],60*j+365,60*i+57);
		   }
		   else{
			   	createImage(FLOOR[i][j],"XINGXING.png");
				setImagePosition(FLOOR[i][j],60*j+365,60*i+57);
		   }
		}
	sprintf(temp,"%d",PEOPLE.level);
	createText(LEVELNUM,temp);
	setTextFontSize(LEVELNUM,50);
	setTextPosition(LEVELNUM,170,645);
	setTextColor(LEVELNUM,1,1,1);//等级值
	sprintf(temp,"%d",PEOPLE.hp);
	createText(HPNUM,temp);
	setTextFontSize(HPNUM,30);
	setTextPosition(HPNUM,150,585);
	setTextColor(HPNUM,1,1,1);//生命值//Y轴间距为每项45左右
	sprintf(temp,"%d",PEOPLE.ATACK);
	createText(ATACKNUM,temp);
	setTextFontSize(ATACKNUM,30);
	setTextPosition(ATACKNUM,150,543);
	setTextColor(ATACKNUM,1,1,1);//攻击数
	sprintf(temp,"%d",PEOPLE.DEF);
	createText(DEFNUM,temp);
	setTextFontSize(DEFNUM,30);
	setTextPosition(DEFNUM,150,500);
	setTextColor(DEFNUM,1,1,1);//防御数
	sprintf(temp,"%d",PEOPLE.money);
	createText(MONEYNUM,temp);
	setTextFontSize(MONEYNUM,30);
	setTextPosition(MONEYNUM,150,458);
	setTextColor(MONEYNUM,1,1,1);//金钱数
	sprintf(temp,"%d",PEOPLE.ex);
	createText(EXNUM,temp);
	setTextFontSize(EXNUM,30);
	setTextPosition(EXNUM,150,413);
	setTextColor(EXNUM,1,1,1);//经验数
	sprintf(temp,"%d",PEOPLE.YELLOWKEY);
	createText(YELLOWKEYNUM,temp);
	setTextFontSize(YELLOWKEYNUM,40);
	setTextPosition(YELLOWKEYNUM,200,328);
	setTextColor(YELLOWKEYNUM,1,1,1);//黄钥匙数打印//Y轴间距每项60左右
	sprintf(temp,"%d",PEOPLE.BLUEKEY);
	createText(BLUEKEYNUM,temp);
	setTextFontSize(BLUEKEYNUM,40);
	setTextPosition(BLUEKEYNUM,200,265);
	setTextColor(BLUEKEYNUM,1,1,1);//蓝钥匙数
	sprintf(temp,"%d",PEOPLE.REDKEY);
	createText(REDKEYNUM,temp);
	setTextFontSize(REDKEYNUM,40);
	setTextPosition(REDKEYNUM,200,205);
	setTextColor(REDKEYNUM,1,1,1);//红钥匙数


	createSprite(guaiwutu,"guaiwutu");//打怪界面的怪物
	playSpriteAnimate(guaiwutu,"guaiwutu");
	setSpritePosition(guaiwutu,403,424);
	hideSprite(guaiwutu);
	createSprite(daguai,"DAGUAI");
	playSpriteAnimate(daguai,"DAGUAI");
	setSpritePosition(daguai,390,300);
	hideSprite(daguai);
	sprintf(temp,"%d",HP);
	createText(HP,temp);//打怪生命
	setTextFontSize(HP,25);
	setTextPosition(HP,538,485);
	setTextColor(HP,1,1,1);
	hideText(HP);
	sprintf(temp,"%d",ATACK);
	createText(ATACK,temp);//打怪攻击
	setTextFontSize(ATACK,25);
	setTextPosition(ATACK,538,422);//间距60左右
	setTextColor(ATACK,1,1,1);
	hideText(ATACK);
	sprintf(temp,"%d",DEF);
	createText(DEF,temp);//打怪防御
	setTextFontSize(DEF,25);
	setTextPosition(DEF,538,361);
	setTextColor(DEF,1,1,1);
	hideText(DEF);
	sprintf(temp,"%d",PEOPLEHP);
	createText(PEOPLEHP,temp);//打怪勇士生命
	setTextFontSize(PEOPLEHP,25);
	setTextPosition(PEOPLEHP,778,485);
	setTextColor(PEOPLEHP,1,1,1);
	hideText(PEOPLEHP);
	sprintf(temp,"%d",PEOPLEATACK);
	createText(PEOPLEATACK,temp);//打怪勇士攻击
	setTextFontSize(PEOPLEATACK,25);
	setTextPosition(PEOPLEATACK,778,422);
	setTextColor(PEOPLEATACK,1,1,1);
	hideText(PEOPLEATACK);
	sprintf(temp,"%d",PEOPLEDEF);
	createText(PEOPLEDEF,temp);//打怪勇士防御
	setTextFontSize(PEOPLEDEF,25);
	setTextPosition(PEOPLEDEF,778,361);
	setTextColor(PEOPLEDEF,1,1,1);
	hideText(PEOPLEDEF);

	createSprite(wenbenkuang,"WENBENKUANG");//获得一般物品的界面
	playSpriteAnimate(wenbenkuang,"1");
	setSpritePosition(wenbenkuang,370,350);
	hideSprite(wenbenkuang);
	createText(wenbenkuang2,temp);//获得一般物品的文本框
	setTextFontSize(wenbenkuang2,50);
	setTextPosition(wenbenkuang2,450,387);
	setTextColor(wenbenkuang2,(float)0.85,(float)0.85,(float)0.85);
	hideText(wenbenkuang2);

	createSprite(BAIFALAOREN,"BAIFALAOREN");//初始化白发老人
	playSpriteAnimate(BAIFALAOREN,"1");
	setSpritePosition(BAIFALAOREN,500,200);
	hideSprite(BAIFALAOREN);
	createSprite(HONGYILAOREN,"HONGYILAOREN");//初始化红衣老人
	playSpriteAnimate(HONGYILAOREN,"1");
	setSpritePosition(HONGYILAOREN,500,200);
	hideSprite(HONGYILAOREN);
	createSprite(SHANGDIAN,"SHANGDIAN");//初始商店
	playSpriteAnimate(SHANGDIAN,"1");
	setSpritePosition(SHANGDIAN,500,200);
	hideSprite(SHANGDIAN);
	createSprite(tujian1,"tujian1");//初始化怪物图鉴1
	playSpriteAnimate(tujian1,"1");
	setSpritePosition(tujian1,250,20);
	hideSprite(tujian1);
}

void refreshmap(){
	int i,j;
	map[PEOPLE.y][PEOPLE.x] = 15;
	if(i1!=-1&&j1!=-1){
		showImage(FLOOR[i1][j1+1]);
		showImage(FLOOR[i1][j1+2]);
		i1=-1,j1=-1;
	}
	for(i = 0 ; i < 11; i++)
		for(j = 0 ; j < 11 ; j++){
			if(map[i][j]==0){
			   setImageSource(FLOOR[i][j],"FLOOR.png");
		   }
		   else if(map[i][j]==2){
				setImageSource(FLOOR[i][j],"QIANG.png");
		   }
		   else if(map[i][j]==3){
				setImageSource(FLOOR[i][j],"HONGMEN.png");
		   }
		   else if(map[i][j]==4){
				setImageSource(FLOOR[i][j],"HUANGMEN.png");
		   }
		   else if(map[i][j]==5){
				setImageSource(FLOOR[i][j],"LANMEN.png");
		   }
		   else if(map[i][j]==6){
				setImageSource(FLOOR[i][j],"HONGPING.png");
		   }
		   else if(map[i][j]==7){
				setImageSource(FLOOR[i][j],"LANPING.png");
		   }
		   else if(map[i][j]==8){
				setImageSource(FLOOR[i][j],"SHENGGUANGHUI.png");
		   }
		   else if(map[i][j]==9){
				setImageSource(FLOOR[i][j],"FENGZHILUOPAN.png");
		   }
		   else if(map[i][j]==10){
				setImageSource(FLOOR[i][j],"LOUTIS.png");
		   }
		   else if(map[i][j]==11){
				setImageSource(FLOOR[i][j],"LOUTIX.png");
		   }
		   else if(map[i][j]==12){
				setImageSource(FLOOR[i][j],"HUANGYAOSHI.png");
		   }
		   else if(map[i][j]==13){
				setImageSource(FLOOR[i][j],"HONGYAOSHI.png");
		   }
		   else if(map[i][j]==14){
				setImageSource(FLOOR[i][j],"LANYAOSHI.png");
		   }
		   else if(map[i][j]==15){
			   setImageSource(FLOOR[i][j],"PEOPLE1.png");
		   }
		   else if(map[i][j]==16){
			   setImageSource(FLOOR[i][j],"HONGBAOSHI.png");
		   }
		   else if(map[i][j]==17){
			   setImageSource(FLOOR[i][j],"LANBAOSHI.png");
		   }
		   else if(map[i][j]==18){
			   setImageSource(FLOOR[i][j],"BAIFALAOREN.png");
		   }
		   else if(map[i][j]==19){
			   setImageSource(FLOOR[i][j],"HONGYILAOREN.png");
		   }
		   else if(map[i][j]==20){
			   setImageSource(FLOOR[i][j],"QINGMEN.png");
		   }
		   else if(map[i][j]==21){
			   setImageSource(FLOOR[i][j],"BAOJIAN.png");
		   }
		   else if(map[i][j]==22){
			   setImageSource(FLOOR[i][j],"SHANGDIAN.png");
			   hideImage(FLOOR[i][j+1]);
			   hideImage(FLOOR[i][j+2]);
			   i1=i,j1=j;
			   j+=2;
		   }
		   else if(map[i][j]==23){
			   setImageSource(FLOOR[i][j],"YONGSHI.png");
		   }
		   else if(map[i][j]==24){
			   setImageSource(FLOOR[i][j],"JINYAOSHI.png");
		   }
		   else if(map[i][j]==25){
			   setImageSource(FLOOR[i][j],"DUNPAI.png");
		   }
		   else if(map[i][j]==26||map[i][j]==91){
			   setImageSource(FLOOR[i][j],"DENGJICHIBANG.png");
		   }
		   else if(map[i][j]==27){
			   setImageSource(FLOOR[i][j],"KAIXINJINBI.png");
		   }
		   else if(map[i][j]==28){
			   setImageSource(FLOOR[i][j],"SHIZIJIA.png");
		   }
		   else if(map[i][j]==29){
			   setImageSource(FLOOR[i][j],"TENGMUDUN.png");
		   }
		   else if(map[i][j]==30){
				setImageSource(FLOOR[i][j],"QINGTOUGUAI.png");
		   }
		   else if(map[i][j]==31){
				setImageSource(FLOOR[i][j],"HONGTOUGUAI.png");
		   }
		   else if(map[i][j]==32){
				setImageSource(FLOOR[i][j],"KULOUREN.png");
		   }
		   else if(map[i][j]==33){
				setImageSource(FLOOR[i][j],"CHUJIFASHI.png");
		   }
		   else if(map[i][j]==34){
				setImageSource(FLOOR[i][j],"LVTOUGUAI.png");
		   }
		   else if(map[i][j]==35){
				setImageSource(FLOOR[i][j],"XIAOBIANFU.png");
		   }
		   else if(map[i][j]==36){
				setImageSource(FLOOR[i][j],"SHOUMIANREN.png");
		   }
		   else if(map[i][j]==37){
				setImageSource(FLOOR[i][j],"KULOUSHIBING.png");
		   }
		   else if(map[i][j]==38){
				setImageSource(FLOOR[i][j],"DABIANFU.png");
		   }
		   else if(map[i][j]==39){
				setImageSource(FLOOR[i][j],"CHUJIWEIBING.png");
		   }
		   else if(map[i][j]==40){
				setImageSource(FLOOR[i][j],"JINGDUIZHANG.png");
		   }
		   else if(map[i][j]==41){
				setImageSource(FLOOR[i][j],"JINGWEISHI.png");
		   }
		   else if(map[i][j]==42){
				setImageSource(FLOOR[i][j],"KULOUDUIZHANG.png");
		   }
		   else if(map[i][j]==43){
				setImageSource(FLOOR[i][j],"GUAIWANG.png");
		   }
		   else if(map[i][j]==44){
				setImageSource(FLOOR[i][j],"SHITOUGUAIREN.png");
		   }
		   else if(map[i][j]==45){
				setImageSource(FLOOR[i][j],"HONGBIANFU.png");
		   }
		   else if(map[i][j]==46){
				setImageSource(FLOOR[i][j],"HONGYIFASHI.png");
		   }
		   else if(map[i][j]==47){
				setImageSource(FLOOR[i][j],"GAOJIFASHI.png");
		   }
		   else if(map[i][j]==48){
				setImageSource(FLOOR[i][j],"BAIYIWUSHI.png");
		   }
		   else if(map[i][j]==49){
				setImageSource(FLOOR[i][j],"MAYIFASHI.png");
		   }
		   else if(map[i][j]==50){
				setImageSource(FLOOR[i][j],"SHOUMIANWUSHI.png");
		   }
		   else if(map[i][j]==51){
				setImageSource(FLOOR[i][j],"SHUANGSHOUJIANSHI.png");
		   }
		   else if(map[i][j]==52){
				setImageSource(FLOOR[i][j],"GAOJIWEIBING.png");
		   }
		   else if(map[i][j]==53){
				setImageSource(FLOOR[i][j],"MINGWEIBING.png");
		   }
		   else if(map[i][j]==54){
				setImageSource(FLOOR[i][j],"LINGWUSHI.png");
		   }
		   else if(map[i][j]==55){
				setImageSource(FLOOR[i][j],"MINGZHANSHI.png");
		   }
		   else if(map[i][j]==56){
				setImageSource(FLOOR[i][j],"LINGFASHI.png");
		   }
		   else if(map[i][j]==57){
				setImageSource(FLOOR[i][j],"MINGDUIZHANG.png");
		   }
		   else if(map[i][j]==58){
				setImageSource(FLOOR[i][j],"YINGZIZHANSHI.png");
		   }
		   else if(map[i][j]==59){
				setImageSource(FLOOR[i][j],"HONGYIMOWANG.png");
		   }
		   else if(map[i][j]==60){
				setImageSource(FLOOR[i][j],"DAMOWANG.png");
		   }
			else if(map[i][j]==92){
				setImageSource(FLOOR[i][j],"SHENGMINGSHUI.png");
		   }
		   else if(map[i][j]==94){
				setImageSource(FLOOR[i][j],"SHENGJIAN.png");
		   }
		   else if(map[i][j]==95){
				setImageSource(FLOOR[i][j],"SHENGDUN.png");
		   }
		   else if(map[i][j]==96){
				setImageSource(FLOOR[i][j],"GONGZHU.png");
		   }
		   else if(map[i][j]==97){
				setImageSource(FLOOR[i][j],"QINGFENGJIAN.png");
		   }
		   else if(map[i][j]==99||map[i][j]==98){
				setImageSource(FLOOR[i][j],"TIELAN.png");
		   }
		   else{
			   	setImageSource(FLOOR[i][j],"XINGXING.png");
		   }
		}
}

void change_peoplexy()///改变每层人物位置
{
   if(mapnum>=mapnum1)///上楼情况
      switch(mapnum+1)
      {
      case 1:///上楼到1楼(或初始化开局)
         PEOPLE.x = 10;
         PEOPLE.y = 6;
         break;
      case 2:///上楼到2楼
         PEOPLE.x = 4;
         PEOPLE.y = 9;
         break;
      case 3:
         PEOPLE.x = 9;
         PEOPLE.y = 1;
         break;
      case 4:
         PEOPLE.x = 9;
         PEOPLE.y = 5;
         break;
      case 5:
         PEOPLE.x = 0;
         PEOPLE.y = 9;
         break;
      case 6:
         PEOPLE.x = 9;
         PEOPLE.y = 0;
         break;
      case 7:
         PEOPLE.x = 5;
         PEOPLE.y = 0;
         break;
      case 8:
         PEOPLE.x = 0;
         PEOPLE.y = 9;
         break;
      case 9:
         PEOPLE.x = 6;
         PEOPLE.y = 7;
         break;
      case 10:
         PEOPLE.x = 4;
         PEOPLE.y = 4;
         break;
      case 11:
         PEOPLE.x = 1;
         PEOPLE.y = 0;
         break;
	  case 12:
         PEOPLE.x = 9;
         PEOPLE.y = 0;
         break;
      case 13:
         PEOPLE.x = 1;
         PEOPLE.y = 0;
         break;
      case 14:
         PEOPLE.x = 5;
         PEOPLE.y = 1;
         break;
      case 15:
         PEOPLE.x = 5;
         PEOPLE.y = 9;
         break;
      case 16:
         PEOPLE.x = 8;
         PEOPLE.y = 10;
         break;
      case 17:
         PEOPLE.x = 5;
         PEOPLE.y = 4;
         break;
	  case 18:
         PEOPLE.x = 5;
         PEOPLE.y = 6;
         break;
	  case 19:
         PEOPLE.x = 5;
         PEOPLE.y = 4;
         break;
	  case 20:
         PEOPLE.x = 9;
         PEOPLE.y = 0;
         break;
      }
   else ///下楼情况
      switch(mapnum+1)
      {
      case 1:///下楼到1楼
         PEOPLE.x = 3;
         PEOPLE.y = 10;
         break;
      case 2:///下楼到2楼
         PEOPLE.x = 10;
         PEOPLE.y = 2;
         break;
      case 3:
         PEOPLE.x = 9;
         PEOPLE.y = 5;
         break;
      case 4:
         PEOPLE.x = 0;
         PEOPLE.y = 9;
         break;
      case 5:
         PEOPLE.x = 9;
         PEOPLE.y = 0;
         break;
      case 6:
         PEOPLE.x = 4;
         PEOPLE.y = 1;
         break;
      case 7:
         PEOPLE.x = 1;
         PEOPLE.y = 10;
         break;
      case 8:
         PEOPLE.x = 7;
         PEOPLE.y = 6;
         break;
      case 9:
         PEOPLE.x = 6;
         PEOPLE.y = 3;
         break;
      case 10:
         PEOPLE.x = 0;
         PEOPLE.y = 1;
         break;
      case 11:
         PEOPLE.x = 9;
         PEOPLE.y = 0;
         break;
	  case 12:
         PEOPLE.x = 1;
         PEOPLE.y = 0;
         break;
      case 13:
         PEOPLE.x = 5;
         PEOPLE.y = 1;
         break;
      case 14:
         PEOPLE.x = 6;
         PEOPLE.y = 10;
         break;
      case 15:
         PEOPLE.x = 8;
         PEOPLE.y = 10;
         break;
      case 16:
         PEOPLE.x = 5;
         PEOPLE.y = 4;
         break;
      case 17:
         PEOPLE.x = 1;
         PEOPLE.y = 0;
         break;
	  case 18:
         PEOPLE.x = 5;
         PEOPLE.y = 4;
         break;
	  case 19:
         PEOPLE.x = 5;
         PEOPLE.y = 4;
         break;
      }
   pauseGame(200);///去除上下楼无限换图BUG
   mapnum1 = mapnum;
   refreshmap();
   if(mapnum+1<10)
	   sprintf(tempMsg,"   第 %2d  层",mapnum+1);//显示楼层数
   else
	   sprintf(tempMsg,"   第 %2d 层",mapnum+1);
   setText(wenbenkuang2,tempMsg);
   showSprite(wenbenkuang);
   showText(wenbenkuang2);
   if(mapnum>6){
	   if(!music){
		   music=1;
		   closeSound("sndBGM.MP3");
		   playSound("MUSIC.MP3",1);
	   }
    }
	else{
		if(music){
			music=0;
			closeSound("MUSIC.MP3");
			playSound("sndBGM.MP3",1);
		}
	}
   pauseGame(250);
   hideSprite(wenbenkuang);
   hideText(wenbenkuang2);
}

void iiMove(void* a){
	int iix=getSpriteX(ii);
	int iiwidth=40;
	int bgwidth=getGameWidth();
	printf("%d",iix);
	while(1){
		if(iix<=20){
			setSpriteFlipX(ii,0);
			while(iix<bgwidth-iiwidth){
				setSpritePosition(ii,++iix,iiy);
				pauseGame(10);

			}
		}
		if(iix>=bgwidth-iiwidth){
			setSpriteFlipX(ii,1);
			while(iix>=10){
				setSpritePosition(ii,--iix,iiy);
				pauseGame(10);
			}
		}
	}

};

void iiJump(void* c){
	int i;
	for(i=0;i<50;i++,iiy++)
		pauseGame(10);
	for(i=0;i<50;i++,iiy--)
		pauseGame(10);
}

void Fengzhiluopan(){
	int pan=1;
	char ch;
	//printf("%d\n",Maxmap);
	while(1){
		pauseGame(100);
		ch=getPressedKeyCode();
		if(ch==RP_KEY_UP&&pan>1){
			pan--;
			//printf("%d\n",pan);
			sprintf(tempMsg,"%d",pan);
			playSpriteAnimate(FENGZHILUOPAN_PUSH,tempMsg);
		}
		else if(ch==RP_KEY_DOWN&&pan<Maxmap){
			pan++;
			//printf("%d\n",pan);
			sprintf(tempMsg,"%d",pan);
			playSpriteAnimate(FENGZHILUOPAN_PUSH,tempMsg);
		}
		else if(ch==' '){
			hideSprite(FENGZHILUOPAN_PUSH);
			playSpriteAnimate(FENGZHILUOPAN_PUSH,"1");
			if(pan!=mapnum+1){
				map[PEOPLE.y][PEOPLE.x] = 0;
				memcpy(Ma[mapnum],map,sizeof(int)*11*11);
				mapnum=pan-1;
				memcpy(map,Ma[mapnum],sizeof(int)*11*11);
				playSound("sndStair.MP3",0);
				change_peoplexy();
			}
			break;
		}
		else if(ch=='k'||ch=='K'){
			hideSprite(FENGZHILUOPAN_PUSH);
			playSpriteAnimate(FENGZHILUOPAN_PUSH,"1");
			break;}

	}

}//使用风之罗盘

void nku(unsigned char key){

	if(key=='l'||key=='L'){
		if(shengguanghui==' '){
			if(isSpriteVisible(tujian1)){
				hideSprite(tujian1);
			}
			else{
				showSprite(tujian1);
			}
		}
	}
	/*else if(key==' '){
		asyncRun(iiJump,0);
	}*/
}

void atack_monster_hp(int EXCLE,int x,int y,int temhp)///修复人物HP可以为负数的BUG
{
   map[x][y] = EXCLE;
   PEOPLE.hp+=temhp;
}

void show_DAGUAI(int hp,int atack,int def){
	//showImage(daguai);
	showSprite(guaiwutu);
	showSprite(daguai);
	showText(HP);
	showText(ATACK);
	showText(DEF);
	showText(PEOPLEHP);
	showText(PEOPLEATACK);
	showText(PEOPLEDEF);

}///显示打怪界面

void DAGUAI(int hp,int atack,int def){
	sprintf(tempMsg,"%d",hp);
	setText(HP,tempMsg);
	sprintf(tempMsg,"%d",atack);
	setText(ATACK,tempMsg);
	sprintf(tempMsg,"%d",def);
	setText(DEF,tempMsg);
	sprintf(tempMsg,"%d",PEOPLE.hp);
	setText(PEOPLEHP,tempMsg);
	sprintf(tempMsg,"%d",PEOPLE.ATACK);
	setText(PEOPLEATACK,tempMsg);
	sprintf(tempMsg,"%d",PEOPLE.DEF);
	setText(PEOPLEDEF,tempMsg);
}//显示打怪中数值变化

void hide_DAGUAI(int hp,int atack,int def){
	hideText(HP);
	hideText(ATACK);
	hideText(DEF);
	hideText(PEOPLEHP);
	hideText(PEOPLEATACK);
	hideText(PEOPLEDEF);
	//hideImage(daguai);
	hideSprite(daguai);
	hideSprite(guaiwutu);
}//打完后再次隐藏打怪界面

void atack_monster(int EXCLE,int x,int y)
{
	int i;
	///打怪函数
   switch(EXCLE){
	case 30://青头怪
		  if(PEOPLE.ATACK>QINGTOUGUAI.DEF)
		  {
			  if((PEOPLE.hp-((QINGTOUGUAI.hp/(PEOPLE.ATACK-QINGTOUGUAI.DEF))*(QINGTOUGUAI.ATACK-PEOPLE.DEF)))>0){
				  int hp = QINGTOUGUAI.hp;
				  int temhp = 0;
				  show_DAGUAI(hp,QINGTOUGUAI.ATACK,QINGTOUGUAI.DEF);
				  playSound("ATACK.MP3",1);
				  for(i = 0 ; i < 20000 ; i++){
					  if(QINGTOUGUAI.ATACK-PEOPLE.DEF>0)
							PEOPLE.hp-=QINGTOUGUAI.ATACK-PEOPLE.DEF;
						hp-=PEOPLE.ATACK-QINGTOUGUAI.DEF;
						temhp+=QINGTOUGUAI.ATACK-PEOPLE.DEF;
						if(hp<0)
							hp = 0;
						DAGUAI(hp,QINGTOUGUAI.ATACK,QINGTOUGUAI.DEF);
						pauseGame(200);
						if(hp==0)
						break;
				  }
				  hide_DAGUAI(hp,QINGTOUGUAI.ATACK,QINGTOUGUAI.DEF);
				  closeSound("ATACK.MP3");
				  if(PEOPLE.hp<=0)
					  atack_monster_hp(EXCLE,x,y,temhp);
				  else{
						PEOPLE.money+=QINGTOUGUAI.money;
						PEOPLE.ex+=QINGTOUGUAI.ex;
						map[x][y] = 0;
						setImageSource(FLOOR[x][y],"FLOOR.png");
						sprintf(tempMsg,"获得%2d金币,%2d经验",QINGTOUGUAI.money,QINGTOUGUAI.ex);
						setText(wenbenkuang2,tempMsg);
						showSprite(wenbenkuang);
						showText(wenbenkuang2);
						sprintf(tempMsg,"%d",PEOPLE.hp);
						setText(HPNUM,tempMsg);
						sprintf(tempMsg,"%d",PEOPLE.money);
						setText(MONEYNUM,tempMsg);
						sprintf(tempMsg,"%d",PEOPLE.ex);
						setText(EXNUM,tempMsg);
						playSound("sndStair.MP3",0);
				  }
				  map[PEOPLE.y][PEOPLE.x] = 0;
				}
			  else
				  playSound("f_gun.mp3",0);
		  }
		  else
			  playSound("f_gun.mp3",0);	break;
	case 31://红头怪
		  if(PEOPLE.ATACK>HONGTOUGUAI.DEF)
		  {
			  if((PEOPLE.hp-((HONGTOUGUAI.hp/(PEOPLE.ATACK-HONGTOUGUAI.DEF))*(HONGTOUGUAI.ATACK-PEOPLE.DEF)))>0){
				  int hp = HONGTOUGUAI.hp;
				  int temhp = 0;
				  show_DAGUAI(hp,HONGTOUGUAI.ATACK,HONGTOUGUAI.DEF);
				  playSound("ATACK.MP3",1);
				  for(i = 0 ; i < 20000 ; i++){
					  if(HONGTOUGUAI.ATACK-PEOPLE.DEF>0)
							PEOPLE.hp-=HONGTOUGUAI.ATACK-PEOPLE.DEF;
						hp-=PEOPLE.ATACK-HONGTOUGUAI.DEF;
						temhp+=HONGTOUGUAI.ATACK-PEOPLE.DEF;
						if(hp<0)
							hp = 0;
						DAGUAI(hp,HONGTOUGUAI.ATACK,HONGTOUGUAI.DEF);
						pauseGame(200);
						if(hp==0)
						break;
				  }
				  hide_DAGUAI(hp,HONGTOUGUAI.ATACK,HONGTOUGUAI.DEF);
				  closeSound("ATACK.MP3");
				  if(PEOPLE.hp<=0)
					  atack_monster_hp(EXCLE,x,y,temhp);
				  else{
						PEOPLE.money+=HONGTOUGUAI.money;
						PEOPLE.ex+=HONGTOUGUAI.ex;
						map[x][y] = 0;
						setImageSource(FLOOR[x][y],"FLOOR.png");
						sprintf(tempMsg,"获得%2d金币,%2d经验",HONGTOUGUAI.money,HONGTOUGUAI.ex);
						setText(wenbenkuang2,tempMsg);
						showSprite(wenbenkuang);
						showText(wenbenkuang2);
						sprintf(tempMsg,"%d",PEOPLE.hp);
						setText(HPNUM,tempMsg);
						sprintf(tempMsg,"%d",PEOPLE.money);
						setText(MONEYNUM,tempMsg);
						sprintf(tempMsg,"%d",PEOPLE.ex);
						setText(EXNUM,tempMsg);
						playSound("sndStair.MP3",0);
				  }
				  map[PEOPLE.y][PEOPLE.x] = 0;
				}
			  else
				  playSound("f_gun.mp3",0);
		  }
		  else
			  playSound("f_gun.mp3",0);	break;
	case 32://骷髅人
		  if(PEOPLE.ATACK>KULOUREN.DEF)
		  {
			  if((PEOPLE.hp-((KULOUREN.hp/(PEOPLE.ATACK-KULOUREN.DEF))*(KULOUREN.ATACK-PEOPLE.DEF)))>0){
				  int hp = KULOUREN.hp;
				  int temhp = 0;
				  show_DAGUAI(hp,KULOUREN.ATACK,KULOUREN.DEF);
				  playSound("ATACK.MP3",1);
				  for(i = 0 ; i < 20000 ; i++){
					  if(KULOUREN.ATACK-PEOPLE.DEF>0)
							PEOPLE.hp-=KULOUREN.ATACK-PEOPLE.DEF;
						hp-=PEOPLE.ATACK-KULOUREN.DEF;
						temhp+=KULOUREN.ATACK-PEOPLE.DEF;

						if(hp<0)
							hp = 0;
						DAGUAI(hp,KULOUREN.ATACK,KULOUREN.DEF);
						pauseGame(200);
						if(hp==0)
						break;
				  }
				  hide_DAGUAI(hp,KULOUREN.ATACK,KULOUREN.DEF);
				  closeSound("ATACK.MP3");
				  if(PEOPLE.hp<=0)
					  atack_monster_hp(EXCLE,x,y,temhp);
				  else{
						PEOPLE.money+=KULOUREN.money;
						PEOPLE.ex+=KULOUREN.ex;
						map[x][y] = 0;
						setImageSource(FLOOR[x][y],"FLOOR.png");
						sprintf(tempMsg,"获得%2d金币,%2d经验",KULOUREN.money,KULOUREN.ex);
						setText(wenbenkuang2,tempMsg);
						showSprite(wenbenkuang);
						showText(wenbenkuang2);
						sprintf(tempMsg,"%d",PEOPLE.hp);
						setText(HPNUM,tempMsg);
						sprintf(tempMsg,"%d",PEOPLE.money);
						setText(MONEYNUM,tempMsg);
						sprintf(tempMsg,"%d",PEOPLE.ex);
						setText(EXNUM,tempMsg);
						playSound("sndStair.MP3",0);
				  }
				  map[PEOPLE.y][PEOPLE.x] = 0;
				}
			  else
				  playSound("f_gun.mp3",0);

		  }
		  else
			  playSound("f_gun.mp3",0);	break;
	case 33://初级法师
		  if(PEOPLE.ATACK>CHUJIFASHI.DEF)
		  {
			  if((PEOPLE.hp-((CHUJIFASHI.hp/(PEOPLE.ATACK-CHUJIFASHI.DEF))*(CHUJIFASHI.ATACK-PEOPLE.DEF)))>0){
				  int hp = CHUJIFASHI.hp;
				  int temhp = 0;
				  show_DAGUAI(hp,CHUJIFASHI.ATACK,CHUJIFASHI.DEF);
				  playSound("ATACK.MP3",1);
				  for(i = 0 ; i < 20000 ; i++){
					  if(CHUJIFASHI.ATACK-PEOPLE.DEF>0)
							PEOPLE.hp-=CHUJIFASHI.ATACK-PEOPLE.DEF;
						hp-=PEOPLE.ATACK-CHUJIFASHI.DEF;
						temhp+=CHUJIFASHI.ATACK-PEOPLE.DEF;

						if(hp<0)
							hp = 0;
						DAGUAI(hp,CHUJIFASHI.ATACK,CHUJIFASHI.DEF);
						pauseGame(200);
						if(hp==0)
						break;
				  }
				  hide_DAGUAI(hp,CHUJIFASHI.ATACK,CHUJIFASHI.DEF);
				  closeSound("ATACK.MP3");
				  if(PEOPLE.hp<=0)
					  atack_monster_hp(EXCLE,x,y,temhp);
				  else{
						PEOPLE.money+=CHUJIFASHI.money;
						PEOPLE.ex+=CHUJIFASHI.ex;
						map[x][y] = 0;
						setImageSource(FLOOR[x][y],"FLOOR.png");
						sprintf(tempMsg,"获得%2d金币,%2d经验",CHUJIFASHI.money,CHUJIFASHI.ex);
						setText(wenbenkuang2,tempMsg);
						showSprite(wenbenkuang);
						showText(wenbenkuang2);
						sprintf(tempMsg,"%d",PEOPLE.hp);
						setText(HPNUM,tempMsg);
						sprintf(tempMsg,"%d",PEOPLE.money);
						setText(MONEYNUM,tempMsg);
						sprintf(tempMsg,"%d",PEOPLE.ex);
						setText(EXNUM,tempMsg);
				  }
				  map[PEOPLE.y][PEOPLE.x] = 0;
				  playSound("sndStair.MP3",0);
				}
			  else
				  playSound("f_gun.mp3",0);

		  }
		  else
			  playSound("f_gun.mp3",0);	break;
	case 34://绿头怪
		  if(PEOPLE.ATACK>LVTOUGUAI.DEF)
		  {
			  if((PEOPLE.hp-((LVTOUGUAI.hp/(PEOPLE.ATACK-LVTOUGUAI.DEF))*(LVTOUGUAI.ATACK-PEOPLE.DEF)))>0){
				  int hp = LVTOUGUAI.hp;
				  int temhp = 0;
				  show_DAGUAI(hp,LVTOUGUAI.ATACK,LVTOUGUAI.DEF);
				  playSound("ATACK.MP3",1);
				  for(i = 0 ; i < 20000 ; i++){
						if(LVTOUGUAI.ATACK-PEOPLE.DEF>0)
							PEOPLE.hp-=LVTOUGUAI.ATACK-PEOPLE.DEF;
						hp-=PEOPLE.ATACK-LVTOUGUAI.DEF;
						temhp+=LVTOUGUAI.ATACK-PEOPLE.DEF;

						if(hp<0)
							hp = 0;
						DAGUAI(hp,LVTOUGUAI.ATACK,LVTOUGUAI.DEF);
						pauseGame(200);
						if(hp==0)
						break;
				  }
				  hide_DAGUAI(hp,LVTOUGUAI.ATACK,LVTOUGUAI.DEF);
				  closeSound("ATACK.MP3");
				  if(PEOPLE.hp<=0)
					  atack_monster_hp(EXCLE,x,y,temhp);
				  else{
						PEOPLE.money+=LVTOUGUAI.money;
						PEOPLE.ex+=LVTOUGUAI.ex;
						map[x][y] = 0;
						setImageSource(FLOOR[x][y],"FLOOR.png");
						sprintf(tempMsg,"获得%2d金币,%2d经验",LVTOUGUAI.money,LVTOUGUAI.ex);
						setText(wenbenkuang2,tempMsg);
						showSprite(wenbenkuang);
						showText(wenbenkuang2);
						sprintf(tempMsg,"%d",PEOPLE.hp);
						setText(HPNUM,tempMsg);
						sprintf(tempMsg,"%d",PEOPLE.money);
						setText(MONEYNUM,tempMsg);
						sprintf(tempMsg,"%d",PEOPLE.ex);
						setText(EXNUM,tempMsg);
				  }
				  map[PEOPLE.y][PEOPLE.x] = 0;
				  playSound("sndStair.MP3",0);
				}
			  else
				  playSound("f_gun.mp3",0);

		  }
		  else
			  playSound("f_gun.mp3",0);	break;
	case 35://小蝙蝠
		  if(PEOPLE.ATACK>XIAOBIANFU.DEF)
		  {
			  if((PEOPLE.hp-((XIAOBIANFU.hp/(PEOPLE.ATACK-XIAOBIANFU.DEF))*(XIAOBIANFU.ATACK-PEOPLE.DEF)))>0){
				  int hp = XIAOBIANFU.hp;
				  int temhp = 0;
				  show_DAGUAI(hp,XIAOBIANFU.ATACK,XIAOBIANFU.DEF);
				  playSound("ATACK.MP3",1);
				  for(i = 0 ; i < 20000 ; i++){
						if(XIAOBIANFU.ATACK-PEOPLE.DEF>0)
							PEOPLE.hp-=XIAOBIANFU.ATACK-PEOPLE.DEF;
						hp-=PEOPLE.ATACK-XIAOBIANFU.DEF;
						temhp+=XIAOBIANFU.ATACK-PEOPLE.DEF;

						if(hp<0)
							hp = 0;
						DAGUAI(hp,XIAOBIANFU.ATACK,XIAOBIANFU.DEF);
						pauseGame(200);
						if(hp==0)
						break;
				  }
				  hide_DAGUAI(hp,XIAOBIANFU.ATACK,XIAOBIANFU.DEF);
				  closeSound("ATACK.MP3");
				  if(PEOPLE.hp<=0)
					  atack_monster_hp(EXCLE,x,y,temhp);
				  else{
						PEOPLE.money+=XIAOBIANFU.money;
						PEOPLE.ex+=XIAOBIANFU.ex;
						map[x][y] = 0;
						setImageSource(FLOOR[x][y],"FLOOR.png");
						sprintf(tempMsg,"获得%2d金币,%2d经验",XIAOBIANFU.money,XIAOBIANFU.ex);
						setText(wenbenkuang2,tempMsg);
						showSprite(wenbenkuang);
						showText(wenbenkuang2);
						sprintf(tempMsg,"%d",PEOPLE.hp);
						setText(HPNUM,tempMsg);
						sprintf(tempMsg,"%d",PEOPLE.money);
						setText(MONEYNUM,tempMsg);
						sprintf(tempMsg,"%d",PEOPLE.ex);
						setText(EXNUM,tempMsg);
				  }
				  map[PEOPLE.y][PEOPLE.x] = 0;
				  playSound("sndStair.MP3",0);
				}
			  else
				  playSound("f_gun.mp3",0);

		  }
		  else
			  playSound("f_gun.mp3",0);	break;
	case 36://兽面人
		  if(PEOPLE.ATACK>SHOUMIANREN.DEF)
		  {
			  if((PEOPLE.hp-((SHOUMIANREN.hp/(PEOPLE.ATACK-SHOUMIANREN.DEF))*(SHOUMIANREN.ATACK-PEOPLE.DEF)))>0){
				  int hp = SHOUMIANREN.hp;
				  int temhp = 0;
				  show_DAGUAI(hp,SHOUMIANREN.ATACK,SHOUMIANREN.DEF);
				  playSound("ATACK.MP3",1);
				  for(i = 0 ; i < 20000 ; i++){
						if(SHOUMIANREN.ATACK-PEOPLE.DEF>0)
							PEOPLE.hp-=SHOUMIANREN.ATACK-PEOPLE.DEF;
						hp-=PEOPLE.ATACK-SHOUMIANREN.DEF;
						temhp+=SHOUMIANREN.ATACK-PEOPLE.DEF;

						if(hp<0)
							hp = 0;
						DAGUAI(hp,SHOUMIANREN.ATACK,SHOUMIANREN.DEF);
						pauseGame(200);
						if(hp==0)
						break;
				  }
				  hide_DAGUAI(hp,SHOUMIANREN.ATACK,SHOUMIANREN.DEF);
				  closeSound("ATACK.MP3");
				  if(PEOPLE.hp<=0)
					  atack_monster_hp(EXCLE,x,y,temhp);
				  else{
						PEOPLE.money+=SHOUMIANREN.money;
						PEOPLE.ex+=SHOUMIANREN.ex;
						map[x][y] = 0;
						setImageSource(FLOOR[x][y],"FLOOR.png");
						sprintf(tempMsg,"获得%2d金币,%2d经验",SHOUMIANREN.money,SHOUMIANREN.ex);
						setText(wenbenkuang2,tempMsg);
						showSprite(wenbenkuang);
						showText(wenbenkuang2);
						sprintf(tempMsg,"%d",PEOPLE.hp);
						setText(HPNUM,tempMsg);
						sprintf(tempMsg,"%d",PEOPLE.money);
						setText(MONEYNUM,tempMsg);
						sprintf(tempMsg,"%d",PEOPLE.ex);
						setText(EXNUM,tempMsg);
						playSound("sndStair.MP3",0);
				  }
				  map[PEOPLE.y][PEOPLE.x] = 0;
				}
			  else
				  playSound("f_gun.mp3",0);

		  }
		  else
			  playSound("f_gun.mp3",0);	break;
	case 37:
		  if(PEOPLE.ATACK>KULOUSHIBING.DEF)
		  {
			  if((PEOPLE.hp-((KULOUSHIBING.hp/(PEOPLE.ATACK-KULOUSHIBING.DEF))*(KULOUSHIBING.ATACK-PEOPLE.DEF)))>0){
				  int hp = KULOUSHIBING.hp;
				  int temhp = 0;
				  show_DAGUAI(hp,KULOUSHIBING.ATACK,KULOUSHIBING.DEF);
				  playSound("ATACK.MP3",1);
				  for(i = 0 ; i < 20000 ; i++){
						if(KULOUSHIBING.ATACK-PEOPLE.DEF>0)
							PEOPLE.hp-=KULOUSHIBING.ATACK-PEOPLE.DEF;
						hp-=PEOPLE.ATACK-KULOUSHIBING.DEF;
						temhp+=KULOUSHIBING.ATACK-PEOPLE.DEF;

						if(hp<0)
							hp = 0;
						DAGUAI(hp,KULOUSHIBING.ATACK,KULOUSHIBING.DEF);
						pauseGame(200);
						if(hp==0)
						break;
				  }
				  hide_DAGUAI(hp,KULOUSHIBING.ATACK,KULOUSHIBING.DEF);
				  closeSound("ATACK.MP3");
				  if(PEOPLE.hp<=0)
					  atack_monster_hp(EXCLE,x,y,temhp);
				  else{
						PEOPLE.money+=KULOUSHIBING.money;
						PEOPLE.ex+=KULOUSHIBING.ex;
						map[x][y] = 0;
						setImageSource(FLOOR[x][y],"FLOOR.png");
						sprintf(tempMsg,"获得%2d金币,%2d经验",KULOUSHIBING.money,KULOUSHIBING.ex);
						setText(wenbenkuang2,tempMsg);
						showSprite(wenbenkuang);
						showText(wenbenkuang2);
						sprintf(tempMsg,"%d",PEOPLE.hp);
						setText(HPNUM,tempMsg);
						sprintf(tempMsg,"%d",PEOPLE.money);
						setText(MONEYNUM,tempMsg);
						sprintf(tempMsg,"%d",PEOPLE.ex);
						setText(EXNUM,tempMsg);
						playSound("sndStair.MP3",0);
				  }
				  map[PEOPLE.y][PEOPLE.x] = 0;
				}
			  else
				  playSound("f_gun.mp3",0);

		  }
		  else
			  playSound("f_gun.mp3",0);	break;
	case 38://
		  if(PEOPLE.ATACK>DABIANFU.DEF)
		  {
			  if((PEOPLE.hp-((DABIANFU.hp/(PEOPLE.ATACK-DABIANFU.DEF))*(DABIANFU.ATACK-PEOPLE.DEF)))>0){
				  int hp = DABIANFU.hp;
				  int temhp = 0;
				  show_DAGUAI(hp,DABIANFU.ATACK,DABIANFU.DEF);
				  playSound("ATACK.MP3",1);
				  for(i = 0 ; i < 20000 ; i++){
						if(DABIANFU.ATACK-PEOPLE.DEF>0)
							PEOPLE.hp-=DABIANFU.ATACK-PEOPLE.DEF;
						hp-=PEOPLE.ATACK-DABIANFU.DEF;
						temhp+=DABIANFU.ATACK-PEOPLE.DEF;

						if(hp<0)
							hp = 0;
						DAGUAI(hp,DABIANFU.ATACK,DABIANFU.DEF);
						pauseGame(200);
						if(hp==0)
						break;
				  }
				  hide_DAGUAI(hp,DABIANFU.ATACK,DABIANFU.DEF);
				  closeSound("ATACK.MP3");
				  if(PEOPLE.hp<=0)
					  atack_monster_hp(EXCLE,x,y,temhp);
				  else{
						PEOPLE.money+=DABIANFU.money;
						PEOPLE.ex+=DABIANFU.ex;
						map[x][y] = 0;
						setImageSource(FLOOR[x][y],"FLOOR.png");
						sprintf(tempMsg,"获得%2d金币,%2d经验",DABIANFU.money,DABIANFU.ex);
						setText(wenbenkuang2,tempMsg);
						showSprite(wenbenkuang);
						showText(wenbenkuang2);
						sprintf(tempMsg,"%d",PEOPLE.hp);
						setText(HPNUM,tempMsg);
						sprintf(tempMsg,"%d",PEOPLE.money);
						setText(MONEYNUM,tempMsg);
						sprintf(tempMsg,"%d",PEOPLE.ex);
						setText(EXNUM,tempMsg);
						playSound("sndStair.MP3",0);
				  }
				  map[PEOPLE.y][PEOPLE.x] = 0;
				}
			  else
				  playSound("f_gun.mp3",0);

		  }
		  else
			  playSound("f_gun.mp3",0);	break;
	case 39:
		  if(PEOPLE.ATACK>CHUJIWEIBING.DEF)
		  {
			  if((PEOPLE.hp-((CHUJIWEIBING.hp/(PEOPLE.ATACK-CHUJIWEIBING.DEF))*(CHUJIWEIBING.ATACK-PEOPLE.DEF)))>0){
				  int hp = CHUJIWEIBING.hp;
				  int temhp = 0;
				  show_DAGUAI(hp,CHUJIWEIBING.ATACK,CHUJIWEIBING.DEF);
				  playSound("ATACK.MP3",1);
				  for(i = 0 ; i < 20000 ; i++){
					  if(CHUJIWEIBING.ATACK-PEOPLE.DEF>0)
							PEOPLE.hp-=CHUJIWEIBING.ATACK-PEOPLE.DEF;
						hp-=PEOPLE.ATACK-CHUJIWEIBING.DEF;
						temhp+=CHUJIWEIBING.ATACK-PEOPLE.DEF;

						if(hp<0)
							hp = 0;
						DAGUAI(hp,CHUJIWEIBING.ATACK,CHUJIWEIBING.DEF);
						pauseGame(200);
						if(hp==0)
						break;
				  }
				  hide_DAGUAI(hp,CHUJIWEIBING.ATACK,CHUJIWEIBING.DEF);
				  closeSound("ATACK.MP3");
				  if(PEOPLE.hp<=0)
					  atack_monster_hp(EXCLE,x,y,temhp);
				  else{
						PEOPLE.money+=CHUJIWEIBING.money;
						PEOPLE.ex+=CHUJIWEIBING.ex;
						map[x][y] = 0;
						setImageSource(FLOOR[x][y],"FLOOR.png");
						sprintf(tempMsg,"获得%2d金币,%2d经验",CHUJIWEIBING.money,CHUJIWEIBING.ex);
						setText(wenbenkuang2,tempMsg);
						showSprite(wenbenkuang);
						showText(wenbenkuang2);
						sprintf(tempMsg,"%d",PEOPLE.hp);
						setText(HPNUM,tempMsg);
						sprintf(tempMsg,"%d",PEOPLE.money);
						setText(MONEYNUM,tempMsg);
						sprintf(tempMsg,"%d",PEOPLE.ex);
						setText(EXNUM,tempMsg);
						playSound("sndStair.MP3",0);
				  }
				  map[PEOPLE.y][PEOPLE.x] = 0;
				}
			  else
				  playSound("f_gun.mp3",0);

		  }
		  else
			  playSound("f_gun.mp3",0);	break;
	case 40:
		  if(PEOPLE.ATACK>JINGDUIZHANG.DEF)
		  {
			  if((PEOPLE.hp-((JINGDUIZHANG.hp/(PEOPLE.ATACK-JINGDUIZHANG.DEF))*(JINGDUIZHANG.ATACK-PEOPLE.DEF)))>0){
				  int hp = JINGDUIZHANG.hp;
				  int temhp = 0;
				  show_DAGUAI(hp,JINGDUIZHANG.ATACK,JINGDUIZHANG.DEF);
				  playSound("ATACK.MP3",1);
				  for(i = 0 ; i < 20000 ; i++){
					  if(JINGDUIZHANG.ATACK-PEOPLE.DEF>0)
							PEOPLE.hp-=JINGDUIZHANG.ATACK-PEOPLE.DEF;
						hp-=PEOPLE.ATACK-JINGDUIZHANG.DEF;
						temhp+=JINGDUIZHANG.ATACK-PEOPLE.DEF;

						if(hp<0)
							hp = 0;
						DAGUAI(hp,JINGDUIZHANG.ATACK,JINGDUIZHANG.DEF);
						pauseGame(200);
						if(hp==0)
						break;
				  }
				  hide_DAGUAI(hp,JINGDUIZHANG.ATACK,JINGDUIZHANG.DEF);
				  closeSound("ATACK.MP3");
				  if(PEOPLE.hp<=0)
					  atack_monster_hp(EXCLE,x,y,temhp);
				  else{
						PEOPLE.money+=JINGDUIZHANG.money;
						PEOPLE.ex+=JINGDUIZHANG.ex;
						map[x][y] = 0;
						setImageSource(FLOOR[x][y],"FLOOR.png");
						sprintf(tempMsg,"获得%2d金币,%2d经验",JINGDUIZHANG.money,JINGDUIZHANG.ex);
						setText(wenbenkuang2,tempMsg);
						showSprite(wenbenkuang);
						showText(wenbenkuang2);
						sprintf(tempMsg,"%d",PEOPLE.hp);
						setText(HPNUM,tempMsg);
						sprintf(tempMsg,"%d",PEOPLE.money);
						setText(MONEYNUM,tempMsg);
						sprintf(tempMsg,"%d",PEOPLE.ex);
						setText(EXNUM,tempMsg);
						playSound("sndStair.MP3",0);
				  }
				  map[PEOPLE.y][PEOPLE.x] = 0;
				}
			  else
				  playSound("f_gun.mp3",0);

		  }
		  else
			  playSound("f_gun.mp3",0);	break;
	case 41:
		  if(PEOPLE.ATACK>JINGWEISHI.DEF)
		  {
			  if((PEOPLE.hp-((JINGWEISHI.hp/(PEOPLE.ATACK-JINGWEISHI.DEF))*(JINGWEISHI.ATACK-PEOPLE.DEF)))>0){
				  int hp = JINGWEISHI.hp;
				  int temhp = 0;
				  show_DAGUAI(hp,JINGWEISHI.ATACK,JINGWEISHI.DEF);
				  playSound("ATACK.MP3",1);
				  for(i = 0 ; i < 20000 ; i++){
					  if(JINGWEISHI.ATACK-PEOPLE.DEF>0)
							PEOPLE.hp-=JINGWEISHI.ATACK-PEOPLE.DEF;
						hp-=PEOPLE.ATACK-JINGWEISHI.DEF;
						temhp+=JINGWEISHI.ATACK-PEOPLE.DEF;

						if(hp<0)
							hp = 0;
						DAGUAI(hp,JINGWEISHI.ATACK,JINGWEISHI.DEF);
						pauseGame(200);
						if(hp==0)
						break;
				  }
				  hide_DAGUAI(hp,JINGWEISHI.ATACK,JINGWEISHI.DEF);
				  closeSound("ATACK.MP3");
				  if(PEOPLE.hp<=0)
					  atack_monster_hp(EXCLE,x,y,temhp);
				  else{
						PEOPLE.money+=JINGWEISHI.money;
						PEOPLE.ex+=JINGWEISHI.ex;
						map[x][y] = 0;
						setImageSource(FLOOR[x][y],"FLOOR.png");
						sprintf(tempMsg,"获得%2d金币,%2d经验",JINGWEISHI.money,JINGWEISHI.ex);
						setText(wenbenkuang2,tempMsg);
						showSprite(wenbenkuang);
						showText(wenbenkuang2);
						sprintf(tempMsg,"%d",PEOPLE.hp);
						setText(HPNUM,tempMsg);
						sprintf(tempMsg,"%d",PEOPLE.money);
						setText(MONEYNUM,tempMsg);
						sprintf(tempMsg,"%d",PEOPLE.ex);
						setText(EXNUM,tempMsg);
						playSound("sndStair.MP3",0);
				  }
				  map[PEOPLE.y][PEOPLE.x] = 0;
				}
			  else
				  playSound("f_gun.mp3",0);

		  }
		  else
			  playSound("f_gun.mp3",0);	break;
	case 42:
		  if(PEOPLE.ATACK>KULOUDUIZHANG.DEF)
		  {
			  if((PEOPLE.hp-((KULOUDUIZHANG.hp/(PEOPLE.ATACK-KULOUDUIZHANG.DEF))*(KULOUDUIZHANG.ATACK-PEOPLE.DEF)))>0){
				  int hp = KULOUDUIZHANG.hp;
				  int temhp = 0;
				  show_DAGUAI(hp,KULOUDUIZHANG.ATACK,KULOUDUIZHANG.DEF);
				  playSound("ATACK.MP3",1);
				  for(i = 0 ; i < 20000 ; i++){
					  if(KULOUDUIZHANG.ATACK-PEOPLE.DEF>0)
							PEOPLE.hp-=KULOUDUIZHANG.ATACK-PEOPLE.DEF;
						hp-=PEOPLE.ATACK-KULOUDUIZHANG.DEF;
						temhp+=KULOUDUIZHANG.ATACK-PEOPLE.DEF;

						if(hp<0)
							hp = 0;
						DAGUAI(hp,KULOUDUIZHANG.ATACK,KULOUDUIZHANG.DEF);
						pauseGame(200);
						if(hp==0)
						break;
				  }
				  hide_DAGUAI(hp,KULOUDUIZHANG.ATACK,KULOUDUIZHANG.DEF);
				  closeSound("ATACK.MP3");
				  if(PEOPLE.hp<=0)
					  atack_monster_hp(EXCLE,x,y,temhp);
				  else{
						PEOPLE.money+=KULOUDUIZHANG.money;
						PEOPLE.ex+=KULOUDUIZHANG.ex;
						map[x][y] = 0;
						setImageSource(FLOOR[x][y],"FLOOR.png");
						sprintf(tempMsg,"获得%2d金币,%2d经验",KULOUDUIZHANG.money,KULOUDUIZHANG.ex);
						setText(wenbenkuang2,tempMsg);
						showSprite(wenbenkuang);
						showText(wenbenkuang2);
						sprintf(tempMsg,"%d",PEOPLE.hp);
						setText(HPNUM,tempMsg);
						sprintf(tempMsg,"%d",PEOPLE.money);
						setText(MONEYNUM,tempMsg);
						sprintf(tempMsg,"%d",PEOPLE.ex);
						setText(EXNUM,tempMsg);
						playSound("sndStair.MP3",0);
				  }
				  map[PEOPLE.y][PEOPLE.x] = 0;
				}
			  else
				  playSound("f_gun.mp3",0);

		  }
		  else
			  playSound("f_gun.mp3",0);	break;
	case 43:
		  if(PEOPLE.ATACK>GUAIWANG.DEF)
		  {
			  if((PEOPLE.hp-((GUAIWANG.hp/(PEOPLE.ATACK-GUAIWANG.DEF))*(GUAIWANG.ATACK-PEOPLE.DEF)))>0){
				  int hp = GUAIWANG.hp;
				  int temhp = 0;
				  show_DAGUAI(hp,GUAIWANG.ATACK,GUAIWANG.DEF);
				  playSound("ATACK.MP3",1);
				  for(i = 0 ; i < 20000 ; i++){
					  if(GUAIWANG.ATACK-PEOPLE.DEF>0)
							PEOPLE.hp-=GUAIWANG.ATACK-PEOPLE.DEF;
						hp-=PEOPLE.ATACK-GUAIWANG.DEF;
						temhp+=GUAIWANG.ATACK-PEOPLE.DEF;

						if(hp<0)
							hp = 0;
						DAGUAI(hp,GUAIWANG.ATACK,GUAIWANG.DEF);
						pauseGame(200);
						if(hp==0)
						break;
				  }
				  hide_DAGUAI(hp,GUAIWANG.ATACK,GUAIWANG.DEF);
				  closeSound("ATACK.MP3");
				  if(PEOPLE.hp<=0)
					  atack_monster_hp(EXCLE,x,y,temhp);
				  else{
						PEOPLE.money+=GUAIWANG.money;
						PEOPLE.ex+=GUAIWANG.ex;
						map[x][y] = 0;
						setImageSource(FLOOR[x][y],"FLOOR.png");
						sprintf(tempMsg,"获得%2d金币,%2d经验",GUAIWANG.money,GUAIWANG.ex);
						setText(wenbenkuang2,tempMsg);
						showSprite(wenbenkuang);
						showText(wenbenkuang2);
						sprintf(tempMsg,"%d",PEOPLE.hp);
						setText(HPNUM,tempMsg);
						sprintf(tempMsg,"%d",PEOPLE.money);
						setText(MONEYNUM,tempMsg);
						sprintf(tempMsg,"%d",PEOPLE.ex);
						setText(EXNUM,tempMsg);
						playSound("sndStair.MP3",0);
				  }
				  map[PEOPLE.y][PEOPLE.x] = 0;
				}
			  else
				  playSound("f_gun.mp3",0);

		  }
		  else
			  playSound("f_gun.mp3",0);	break;
	case 44:
		  if(PEOPLE.ATACK>SHITOUGUAIREN.DEF)
		  {
			  if((PEOPLE.hp-((SHITOUGUAIREN.hp/(PEOPLE.ATACK-SHITOUGUAIREN.DEF))*(SHITOUGUAIREN.ATACK-PEOPLE.DEF)))>0){
				  int hp = SHITOUGUAIREN.hp;
				  int temhp = 0;
				  show_DAGUAI(hp,SHITOUGUAIREN.ATACK,SHITOUGUAIREN.DEF);
				  playSound("ATACK.MP3",1);
				  for(i = 0 ; i < 20000 ; i++){
					  if(SHITOUGUAIREN.ATACK-PEOPLE.DEF>0)
							PEOPLE.hp-=SHITOUGUAIREN.ATACK-PEOPLE.DEF;
						hp-=PEOPLE.ATACK-SHITOUGUAIREN.DEF;
						temhp+=SHITOUGUAIREN.ATACK-PEOPLE.DEF;

						if(hp<0)
							hp = 0;
						DAGUAI(hp,SHITOUGUAIREN.ATACK,SHITOUGUAIREN.DEF);
						pauseGame(200);
						if(hp==0)
						break;
				  }
				  hide_DAGUAI(hp,SHITOUGUAIREN.ATACK,SHITOUGUAIREN.DEF);
				  closeSound("ATACK.MP3");
				  if(PEOPLE.hp<=0)
					  atack_monster_hp(EXCLE,x,y,temhp);
				  else{
						PEOPLE.money+=SHITOUGUAIREN.money;
						PEOPLE.ex+=SHITOUGUAIREN.ex;
						map[x][y] = 0;
						setImageSource(FLOOR[x][y],"FLOOR.png");
						sprintf(tempMsg,"获得%2d金币,%2d经验",SHITOUGUAIREN.money,SHITOUGUAIREN.ex);
						setText(wenbenkuang2,tempMsg);
						showSprite(wenbenkuang);
						showText(wenbenkuang2);
						sprintf(tempMsg,"%d",PEOPLE.hp);
						setText(HPNUM,tempMsg);
						sprintf(tempMsg,"%d",PEOPLE.money);
						setText(MONEYNUM,tempMsg);
						sprintf(tempMsg,"%d",PEOPLE.ex);
						setText(EXNUM,tempMsg);
						playSound("sndStair.MP3",0);
				  }
				  map[PEOPLE.y][PEOPLE.x] = 0;
				}
			  else
				  playSound("f_gun.mp3",0);

		  }
		  else
			  playSound("f_gun.mp3",0);	break;
	case 45:
		  if(PEOPLE.ATACK>HONGBIANFU.DEF)
		  {
			  if((PEOPLE.hp-((HONGBIANFU.hp/(PEOPLE.ATACK-HONGBIANFU.DEF))*(HONGBIANFU.ATACK-PEOPLE.DEF)))>0){
				  int hp = HONGBIANFU.hp;
				  int temhp = 0;
				  show_DAGUAI(hp,HONGBIANFU.ATACK,HONGBIANFU.DEF);
				  playSound("ATACK.MP3",1);
				  for(i = 0 ; i < 20000 ; i++){
					  if(HONGBIANFU.ATACK-PEOPLE.DEF>0)
							PEOPLE.hp-=HONGBIANFU.ATACK-PEOPLE.DEF;
						hp-=PEOPLE.ATACK-HONGBIANFU.DEF;
						temhp+=HONGBIANFU.ATACK-PEOPLE.DEF;

						if(hp<0)
							hp = 0;
						DAGUAI(hp,HONGBIANFU.ATACK,HONGBIANFU.DEF);
						pauseGame(200);
						if(hp==0)
						break;
				  }
				  hide_DAGUAI(hp,HONGBIANFU.ATACK,HONGBIANFU.DEF);
				  closeSound("ATACK.MP3");
				  if(PEOPLE.hp<=0)
					  atack_monster_hp(EXCLE,x,y,temhp);
				  else{
						PEOPLE.money+=HONGBIANFU.money;
						PEOPLE.ex+=HONGBIANFU.ex;
						map[x][y] = 0;
						setImageSource(FLOOR[x][y],"FLOOR.png");
						sprintf(tempMsg,"获得%2d金币,%2d经验",HONGBIANFU.money,HONGBIANFU.ex);
						setText(wenbenkuang2,tempMsg);
						showSprite(wenbenkuang);
						showText(wenbenkuang2);
						sprintf(tempMsg,"%d",PEOPLE.hp);
						setText(HPNUM,tempMsg);
						sprintf(tempMsg,"%d",PEOPLE.money);
						setText(MONEYNUM,tempMsg);
						sprintf(tempMsg,"%d",PEOPLE.ex);
						setText(EXNUM,tempMsg);
						playSound("sndStair.MP3",0);
				  }
				  map[PEOPLE.y][PEOPLE.x] = 0;
				}
			  else
				  playSound("f_gun.mp3",0);

		  }
		  else
			  playSound("f_gun.mp3",0);	break;
	case 46:
		  if(PEOPLE.ATACK>HONGYIFASHI.DEF)
		  {
			  if((PEOPLE.hp-((HONGYIFASHI.hp/(PEOPLE.ATACK-HONGYIFASHI.DEF))*(HONGYIFASHI.ATACK-PEOPLE.DEF)))>0){
				  int hp = HONGYIFASHI.hp;
				  int temhp = 0;
				  show_DAGUAI(hp,HONGYIFASHI.ATACK,HONGYIFASHI.DEF);
				  playSound("ATACK.MP3",1);
				  for(i = 0 ; i < 20000 ; i++){
					  if(HONGYIFASHI.ATACK-PEOPLE.DEF>0)
							PEOPLE.hp-=HONGYIFASHI.ATACK-PEOPLE.DEF;
						hp-=PEOPLE.ATACK-HONGYIFASHI.DEF;
						temhp+=HONGYIFASHI.ATACK-PEOPLE.DEF;

						if(hp<0)
							hp = 0;
						DAGUAI(hp,HONGYIFASHI.ATACK,HONGYIFASHI.DEF);
						pauseGame(200);
						if(hp==0)
						break;
				  }
				  hide_DAGUAI(hp,HONGYIFASHI.ATACK,HONGYIFASHI.DEF);
				  closeSound("ATACK.MP3");
				  if(PEOPLE.hp<=0)
					  atack_monster_hp(EXCLE,x,y,temhp);
				  else{
						PEOPLE.money+=HONGYIFASHI.money;
						PEOPLE.ex+=HONGYIFASHI.ex;
						map[x][y] = 0;
						setImageSource(FLOOR[x][y],"FLOOR.png");
						sprintf(tempMsg,"获得%2d金币,%2d经验",HONGYIFASHI.money,HONGYIFASHI.ex);
						setText(wenbenkuang2,tempMsg);
						showSprite(wenbenkuang);
						showText(wenbenkuang2);
						sprintf(tempMsg,"%d",PEOPLE.hp);
						setText(HPNUM,tempMsg);
						sprintf(tempMsg,"%d",PEOPLE.money);
						setText(MONEYNUM,tempMsg);
						sprintf(tempMsg,"%d",PEOPLE.ex);
						setText(EXNUM,tempMsg);
						playSound("sndStair.MP3",0);
				  }
				  map[PEOPLE.y][PEOPLE.x] = 0;
				}
			  else
				  playSound("f_gun.mp3",0);

		  }
		  else
			  playSound("f_gun.mp3",0);	break;
	case 47:
		  if(PEOPLE.ATACK>GAOJIFASHI.DEF)
		  {
			  if((PEOPLE.hp-((GAOJIFASHI.hp/(PEOPLE.ATACK-GAOJIFASHI.DEF))*(GAOJIFASHI.ATACK-PEOPLE.DEF)))>0){
				  int hp = GAOJIFASHI.hp;
				  int temhp = 0;
				  show_DAGUAI(hp,GAOJIFASHI.ATACK,GAOJIFASHI.DEF);
				  playSound("ATACK.MP3",1);
				  for(i = 0 ; i < 20000 ; i++){
					  if(GAOJIFASHI.ATACK-PEOPLE.DEF>0)
							PEOPLE.hp-=GAOJIFASHI.ATACK-PEOPLE.DEF;
						hp-=PEOPLE.ATACK-GAOJIFASHI.DEF;
						temhp+=GAOJIFASHI.ATACK-PEOPLE.DEF;

						if(hp<0)
							hp = 0;
						DAGUAI(hp,GAOJIFASHI.ATACK,GAOJIFASHI.DEF);
						pauseGame(200);
						if(hp==0)
						break;
				  }
				  hide_DAGUAI(hp,GAOJIFASHI.ATACK,GAOJIFASHI.DEF);
				  closeSound("ATACK.MP3");
				  if(PEOPLE.hp<=0)
					  atack_monster_hp(EXCLE,x,y,temhp);
				  else{
						PEOPLE.money+=GAOJIFASHI.money;
						PEOPLE.ex+=GAOJIFASHI.ex;
						map[x][y] = 0;
						setImageSource(FLOOR[x][y],"FLOOR.png");
						sprintf(tempMsg,"获得%2d金币,%2d经验",GAOJIFASHI.money,GAOJIFASHI.ex);
						setText(wenbenkuang2,tempMsg);
						showSprite(wenbenkuang);
						showText(wenbenkuang2);
						sprintf(tempMsg,"%d",PEOPLE.hp);
						setText(HPNUM,tempMsg);
						sprintf(tempMsg,"%d",PEOPLE.money);
						setText(MONEYNUM,tempMsg);
						sprintf(tempMsg,"%d",PEOPLE.ex);
						setText(EXNUM,tempMsg);
						playSound("sndStair.MP3",0);
				  }
				  map[PEOPLE.y][PEOPLE.x] = 0;
				}
			  else
				  playSound("f_gun.mp3",0);

		  }
		  else
			  playSound("f_gun.mp3",0);	break;
	case 48:
		  if(PEOPLE.ATACK>BAIYIWUSHI.DEF)
		  {
			  if((PEOPLE.hp-((BAIYIWUSHI.hp/(PEOPLE.ATACK-BAIYIWUSHI.DEF))*(BAIYIWUSHI.ATACK-PEOPLE.DEF)))>0){
				  int hp = BAIYIWUSHI.hp;
				  int temhp = 0;
				  show_DAGUAI(hp,BAIYIWUSHI.ATACK,BAIYIWUSHI.DEF);
				  playSound("ATACK.MP3",1);
				  for(i = 0 ; i < 20000 ; i++){
					  if(BAIYIWUSHI.ATACK-PEOPLE.DEF>0)
							PEOPLE.hp-=BAIYIWUSHI.ATACK-PEOPLE.DEF;
						hp-=PEOPLE.ATACK-BAIYIWUSHI.DEF;
						temhp+=BAIYIWUSHI.ATACK-PEOPLE.DEF;

						if(hp<0)
							hp = 0;
						DAGUAI(hp,BAIYIWUSHI.ATACK,BAIYIWUSHI.DEF);
						pauseGame(200);
						if(hp==0)
						break;
				  }
				  hide_DAGUAI(hp,BAIYIWUSHI.ATACK,BAIYIWUSHI.DEF);
				  closeSound("ATACK.MP3");
				  if(PEOPLE.hp<=0)
					  atack_monster_hp(EXCLE,x,y,temhp);
				  else{
						PEOPLE.money+=BAIYIWUSHI.money;
						PEOPLE.ex+=BAIYIWUSHI.ex;
						map[x][y] = 0;
						setImageSource(FLOOR[x][y],"FLOOR.png");
						sprintf(tempMsg,"获得%2d金币,%2d经验",BAIYIWUSHI.money,BAIYIWUSHI.ex);
						setText(wenbenkuang2,tempMsg);
						showSprite(wenbenkuang);
						showText(wenbenkuang2);
						sprintf(tempMsg,"%d",PEOPLE.hp);
						setText(HPNUM,tempMsg);
						sprintf(tempMsg,"%d",PEOPLE.money);
						setText(MONEYNUM,tempMsg);
						sprintf(tempMsg,"%d",PEOPLE.ex);
						setText(EXNUM,tempMsg);
						playSound("sndStair.MP3",0);
				  }
				  map[PEOPLE.y][PEOPLE.x] = 0;
				}
			  else
				  playSound("f_gun.mp3",0);

		  }
		  else
			  playSound("f_gun.mp3",0);	break;
	case 49:
		  if(PEOPLE.ATACK>MAYIFASHI.DEF)
		  {
			  if((PEOPLE.hp-((MAYIFASHI.hp/(PEOPLE.ATACK-MAYIFASHI.DEF))*(MAYIFASHI.ATACK-PEOPLE.DEF)))>0){
				  int hp = MAYIFASHI.hp;
				  int temhp = 0;
				  show_DAGUAI(hp,MAYIFASHI.ATACK,MAYIFASHI.DEF);
				  playSound("ATACK.MP3",1);
				  for(i = 0 ; i < 20000 ; i++){
					  if(MAYIFASHI.ATACK-PEOPLE.DEF>0)
							PEOPLE.hp-=MAYIFASHI.ATACK-PEOPLE.DEF;
						hp-=PEOPLE.ATACK-MAYIFASHI.DEF;
						temhp+=MAYIFASHI.ATACK-PEOPLE.DEF;

						if(hp<0)
							hp = 0;
						DAGUAI(hp,MAYIFASHI.ATACK,MAYIFASHI.DEF);
						pauseGame(200);
						if(hp==0)
						break;
				  }
				  hide_DAGUAI(hp,MAYIFASHI.ATACK,MAYIFASHI.DEF);
				  closeSound("ATACK.MP3");
				  if(PEOPLE.hp<=0)
					  atack_monster_hp(EXCLE,x,y,temhp);
				  else{
						PEOPLE.money+=MAYIFASHI.money;
						PEOPLE.ex+=MAYIFASHI.ex;
						map[x][y] = 0;
						setImageSource(FLOOR[x][y],"FLOOR.png");
						sprintf(tempMsg,"获得%2d金币,%2d经验",MAYIFASHI.money,MAYIFASHI.ex);
						setText(wenbenkuang2,tempMsg);
						showSprite(wenbenkuang);
						showText(wenbenkuang2);
						sprintf(tempMsg,"%d",PEOPLE.hp);
						setText(HPNUM,tempMsg);
						sprintf(tempMsg,"%d",PEOPLE.money);
						setText(MONEYNUM,tempMsg);
						sprintf(tempMsg,"%d",PEOPLE.ex);
						setText(EXNUM,tempMsg);
						playSound("sndStair.MP3",0);
				  }
				  map[PEOPLE.y][PEOPLE.x] = 0;
				}
			  else
				  playSound("f_gun.mp3",0);

		  }
		  else
			  playSound("f_gun.mp3",0);	break;
	case 50:
		  if(PEOPLE.ATACK>SHOUMIANWUSHI.DEF)
		  {
			  if((PEOPLE.hp-((SHOUMIANWUSHI.hp/(PEOPLE.ATACK-SHOUMIANWUSHI.DEF))*(SHOUMIANWUSHI.ATACK-PEOPLE.DEF)))>0){
				  int hp = SHOUMIANWUSHI.hp;
				  int temhp = 0;
				  show_DAGUAI(hp,SHOUMIANWUSHI.ATACK,SHOUMIANWUSHI.DEF);
				  playSound("ATACK.MP3",1);
				  for(i = 0 ; i < 20000 ; i++){
					  if(SHOUMIANWUSHI.ATACK-PEOPLE.DEF>0)
							PEOPLE.hp-=SHOUMIANWUSHI.ATACK-PEOPLE.DEF;
						hp-=PEOPLE.ATACK-SHOUMIANWUSHI.DEF;
						temhp+=SHOUMIANWUSHI.ATACK-PEOPLE.DEF;

						if(hp<0)
							hp = 0;
						DAGUAI(hp,SHOUMIANWUSHI.ATACK,SHOUMIANWUSHI.DEF);
						pauseGame(200);
						if(hp==0)
						break;
				  }
				  hide_DAGUAI(hp,SHOUMIANWUSHI.ATACK,SHOUMIANWUSHI.DEF);
				  closeSound("ATACK.MP3");
				  if(PEOPLE.hp<=0)
					  atack_monster_hp(EXCLE,x,y,temhp);
				  else{
						PEOPLE.money+=SHOUMIANWUSHI.money;
						PEOPLE.ex+=SHOUMIANWUSHI.ex;
						map[x][y] = 0;
						setImageSource(FLOOR[x][y],"FLOOR.png");
						sprintf(tempMsg,"获得%2d金币,%2d经验",SHOUMIANWUSHI.money,SHOUMIANWUSHI.ex);
						setText(wenbenkuang2,tempMsg);
						showSprite(wenbenkuang);
						showText(wenbenkuang2);
						sprintf(tempMsg,"%d",PEOPLE.hp);
						setText(HPNUM,tempMsg);
						sprintf(tempMsg,"%d",PEOPLE.money);
						setText(MONEYNUM,tempMsg);
						sprintf(tempMsg,"%d",PEOPLE.ex);
						setText(EXNUM,tempMsg);
						playSound("sndStair.MP3",0);
				  }
				  map[PEOPLE.y][PEOPLE.x] = 0;
				}
			  else
				  playSound("f_gun.mp3",0);

		  }
		  else
			  playSound("f_gun.mp3",0);	break;
	case 51:
		  if(PEOPLE.ATACK>SHUANGSHOUJIANSHI.DEF)
		  {
			  if((PEOPLE.hp-((SHUANGSHOUJIANSHI.hp/(PEOPLE.ATACK-SHUANGSHOUJIANSHI.DEF))*(SHUANGSHOUJIANSHI.ATACK-PEOPLE.DEF)))>0){
				  int hp = SHUANGSHOUJIANSHI.hp;
				  int temhp = 0;
				  show_DAGUAI(hp,SHUANGSHOUJIANSHI.ATACK,SHUANGSHOUJIANSHI.DEF);
				  playSound("ATACK.MP3",1);
				  for(i = 0 ; i < 20000 ; i++){
					  if(SHUANGSHOUJIANSHI.ATACK-PEOPLE.DEF>0)
							PEOPLE.hp-=SHUANGSHOUJIANSHI.ATACK-PEOPLE.DEF;
						hp-=PEOPLE.ATACK-SHUANGSHOUJIANSHI.DEF;
						temhp+=SHUANGSHOUJIANSHI.ATACK-PEOPLE.DEF;

						if(hp<0)
							hp = 0;
						DAGUAI(hp,SHUANGSHOUJIANSHI.ATACK,SHUANGSHOUJIANSHI.DEF);
						pauseGame(200);
						if(hp==0)
						break;
				  }
				  hide_DAGUAI(hp,SHUANGSHOUJIANSHI.ATACK,SHUANGSHOUJIANSHI.DEF);
				  closeSound("ATACK.MP3");
				  if(PEOPLE.hp<=0)
					  atack_monster_hp(EXCLE,x,y,temhp);
				  else{
						PEOPLE.money+=SHUANGSHOUJIANSHI.money;
						PEOPLE.ex+=SHUANGSHOUJIANSHI.ex;
						map[x][y] = 0;
						setImageSource(FLOOR[x][y],"FLOOR.png");
						sprintf(tempMsg,"获得%2d金币,%2d经验",SHUANGSHOUJIANSHI.money,SHUANGSHOUJIANSHI.ex);
						setText(wenbenkuang2,tempMsg);
						showSprite(wenbenkuang);
						showText(wenbenkuang2);
						sprintf(tempMsg,"%d",PEOPLE.hp);
						setText(HPNUM,tempMsg);
						sprintf(tempMsg,"%d",PEOPLE.money);
						setText(MONEYNUM,tempMsg);
						sprintf(tempMsg,"%d",PEOPLE.ex);
						setText(EXNUM,tempMsg);
						playSound("sndStair.MP3",0);
				  }
				  map[PEOPLE.y][PEOPLE.x] = 0;
				}
			  else
				  playSound("f_gun.mp3",0);

		  }
		  else
			  playSound("f_gun.mp3",0);	break;
	case 52:
		  if(PEOPLE.ATACK>GAOJIWEIBING.DEF)
		  {
			  if((PEOPLE.hp-((GAOJIWEIBING.hp/(PEOPLE.ATACK-GAOJIWEIBING.DEF))*(GAOJIWEIBING.ATACK-PEOPLE.DEF)))>0){
				  int hp = GAOJIWEIBING.hp;
				  int temhp = 0;
				  show_DAGUAI(hp,GAOJIWEIBING.ATACK,GAOJIWEIBING.DEF);
				  playSound("ATACK.MP3",1);
				  for(i = 0 ; i < 20000 ; i++){
					  if(GAOJIWEIBING.ATACK-PEOPLE.DEF>0)
							PEOPLE.hp-=GAOJIWEIBING.ATACK-PEOPLE.DEF;
						hp-=PEOPLE.ATACK-GAOJIWEIBING.DEF;
						temhp+=GAOJIWEIBING.ATACK-PEOPLE.DEF;

						if(hp<0)
							hp = 0;
						DAGUAI(hp,GAOJIWEIBING.ATACK,GAOJIWEIBING.DEF);
						pauseGame(200);
						if(hp==0)
						break;
				  }
				  hide_DAGUAI(hp,GAOJIWEIBING.ATACK,GAOJIWEIBING.DEF);
				  closeSound("ATACK.MP3");
				  if(PEOPLE.hp<=0)
					  atack_monster_hp(EXCLE,x,y,temhp);
				  else{
						PEOPLE.money+=GAOJIWEIBING.money;
						PEOPLE.ex+=GAOJIWEIBING.ex;
						map[x][y] = 0;
						setImageSource(FLOOR[x][y],"FLOOR.png");
						sprintf(tempMsg,"获得%2d金币,%2d经验",GAOJIWEIBING.money,GAOJIWEIBING.ex);
						setText(wenbenkuang2,tempMsg);
						showSprite(wenbenkuang);
						showText(wenbenkuang2);
						sprintf(tempMsg,"%d",PEOPLE.hp);
						setText(HPNUM,tempMsg);
						sprintf(tempMsg,"%d",PEOPLE.money);
						setText(MONEYNUM,tempMsg);
						sprintf(tempMsg,"%d",PEOPLE.ex);
						setText(EXNUM,tempMsg);
						playSound("sndStair.MP3",0);
				  }
				  map[PEOPLE.y][PEOPLE.x] = 0;
				}
			  else
				  playSound("f_gun.mp3",0);

		  }
		  else
			  playSound("f_gun.mp3",0);	break;
	case 53:
		  if(PEOPLE.ATACK>MINGWEIBING.DEF)
		  {
			  if((PEOPLE.hp-((MINGWEIBING.hp/(PEOPLE.ATACK-MINGWEIBING.DEF))*(MINGWEIBING.ATACK-PEOPLE.DEF)))>0){
				  int hp = MINGWEIBING.hp;
				  int temhp = 0;
				  show_DAGUAI(hp,MINGWEIBING.ATACK,MINGWEIBING.DEF);
				  playSound("ATACK.MP3",1);
				  for(i = 0 ; i < 20000 ; i++){
					  if(MINGWEIBING.ATACK-PEOPLE.DEF>0)
							PEOPLE.hp-=MINGWEIBING.ATACK-PEOPLE.DEF;
						hp-=PEOPLE.ATACK-MINGWEIBING.DEF;
						temhp+=MINGWEIBING.ATACK-PEOPLE.DEF;

						if(hp<0)
							hp = 0;
						DAGUAI(hp,MINGWEIBING.ATACK,MINGWEIBING.DEF);
						pauseGame(200);
						if(hp==0)
						break;
				  }
				  hide_DAGUAI(hp,MINGWEIBING.ATACK,MINGWEIBING.DEF);
				  closeSound("ATACK.MP3");
				  if(PEOPLE.hp<=0)
					  atack_monster_hp(EXCLE,x,y,temhp);
				  else{
						PEOPLE.money+=MINGWEIBING.money;
						PEOPLE.ex+=MINGWEIBING.ex;
						map[x][y] = 0;
						setImageSource(FLOOR[x][y],"FLOOR.png");
						sprintf(tempMsg,"获得%2d金币,%2d经验",MINGWEIBING.money,MINGWEIBING.ex);
						setText(wenbenkuang2,tempMsg);
						showSprite(wenbenkuang);
						showText(wenbenkuang2);
						sprintf(tempMsg,"%d",PEOPLE.hp);
						setText(HPNUM,tempMsg);
						sprintf(tempMsg,"%d",PEOPLE.money);
						setText(MONEYNUM,tempMsg);
						sprintf(tempMsg,"%d",PEOPLE.ex);
						setText(EXNUM,tempMsg);
						playSound("sndStair.MP3",0);
				  }
				  map[PEOPLE.y][PEOPLE.x] = 0;
				}
			  else
				  playSound("f_gun.mp3",0);

		  }
		  else
			  playSound("f_gun.mp3",0);	break;
	case 54:
		  if(PEOPLE.ATACK>LINGWUSHI.DEF)
		  {
			  if((PEOPLE.hp-((LINGWUSHI.hp/(PEOPLE.ATACK-LINGWUSHI.DEF))*(LINGWUSHI.ATACK-PEOPLE.DEF)))>0){
				  int hp = LINGWUSHI.hp;
				  int temhp = 0;
				  show_DAGUAI(hp,LINGWUSHI.ATACK,LINGWUSHI.DEF);
				  playSound("ATACK.MP3",1);
				  for(i = 0 ; i < 20000 ; i++){
					  if(LINGWUSHI.ATACK-PEOPLE.DEF>0)
							PEOPLE.hp-=LINGWUSHI.ATACK-PEOPLE.DEF;
						hp-=PEOPLE.ATACK-LINGWUSHI.DEF;
						temhp+=LINGWUSHI.ATACK-PEOPLE.DEF;

						if(hp<0)
							hp = 0;
						DAGUAI(hp,LINGWUSHI.ATACK,LINGWUSHI.DEF);
						pauseGame(200);
						if(hp==0)
						break;
				  }
				  hide_DAGUAI(hp,LINGWUSHI.ATACK,LINGWUSHI.DEF);
				  closeSound("ATACK.MP3");
				  if(PEOPLE.hp<=0)
					  atack_monster_hp(EXCLE,x,y,temhp);
				  else{
						PEOPLE.money+=LINGWUSHI.money;
						PEOPLE.ex+=LINGWUSHI.ex;
						map[x][y] = 0;
						setImageSource(FLOOR[x][y],"FLOOR.png");
						sprintf(tempMsg,"获得%2d金币,%2d经验",LINGWUSHI.money,LINGWUSHI.ex);
						setText(wenbenkuang2,tempMsg);
						showSprite(wenbenkuang);
						showText(wenbenkuang2);
						sprintf(tempMsg,"%d",PEOPLE.hp);
						setText(HPNUM,tempMsg);
						sprintf(tempMsg,"%d",PEOPLE.money);
						setText(MONEYNUM,tempMsg);
						sprintf(tempMsg,"%d",PEOPLE.ex);
						setText(EXNUM,tempMsg);
						playSound("sndStair.MP3",0);
				  }
				  map[PEOPLE.y][PEOPLE.x] = 0;
				}
			  else
				  playSound("f_gun.mp3",0);

		  }
		  else
			  playSound("f_gun.mp3",0);	break;
	case 55:
		  if(PEOPLE.ATACK>MINGZHANSHI.DEF)
		  {
			  if((PEOPLE.hp-((MINGZHANSHI.hp/(PEOPLE.ATACK-MINGZHANSHI.DEF))*(MINGZHANSHI.ATACK-PEOPLE.DEF)))>0){
				  int hp = MINGZHANSHI.hp;
				  int temhp = 0;
				  show_DAGUAI(hp,MINGZHANSHI.ATACK,MINGZHANSHI.DEF);
				  playSound("ATACK.MP3",1);
				  for(i = 0 ; i < 20000 ; i++){
					  if(MINGZHANSHI.ATACK-PEOPLE.DEF>0)
							PEOPLE.hp-=MINGZHANSHI.ATACK-PEOPLE.DEF;
						hp-=PEOPLE.ATACK-MINGZHANSHI.DEF;
						temhp+=MINGZHANSHI.ATACK-PEOPLE.DEF;

						if(hp<0)
							hp = 0;
						DAGUAI(hp,MINGZHANSHI.ATACK,MINGZHANSHI.DEF);
						pauseGame(200);
						if(hp==0)
						break;
				  }
				  hide_DAGUAI(hp,MINGZHANSHI.ATACK,MINGZHANSHI.DEF);
				  closeSound("ATACK.MP3");
				  if(PEOPLE.hp<=0)
					  atack_monster_hp(EXCLE,x,y,temhp);
				  else{
						PEOPLE.money+=MINGZHANSHI.money;
						PEOPLE.ex+=MINGZHANSHI.ex;
						map[x][y] = 0;
						setImageSource(FLOOR[x][y],"FLOOR.png");
						sprintf(tempMsg,"获得%2d金币,%2d经验",MINGZHANSHI.money,MINGZHANSHI.ex);
						setText(wenbenkuang2,tempMsg);
						showSprite(wenbenkuang);
						showText(wenbenkuang2);
						sprintf(tempMsg,"%d",PEOPLE.hp);
						setText(HPNUM,tempMsg);
						sprintf(tempMsg,"%d",PEOPLE.money);
						setText(MONEYNUM,tempMsg);
						sprintf(tempMsg,"%d",PEOPLE.ex);
						setText(EXNUM,tempMsg);
						playSound("sndStair.MP3",0);
				  }
				  map[PEOPLE.y][PEOPLE.x] = 0;
				}
			  else
				  playSound("f_gun.mp3",0);

		  }
		  else
			  playSound("f_gun.mp3",0);	break;
	case 56:
		  if(PEOPLE.ATACK>LINGFASHI.DEF)
		  {
			  if((PEOPLE.hp-((LINGFASHI.hp/(PEOPLE.ATACK-LINGFASHI.DEF))*(LINGFASHI.ATACK-PEOPLE.DEF)))>0){
				  int hp = LINGFASHI.hp;
				  int temhp = 0;
				  show_DAGUAI(hp,LINGFASHI.ATACK,LINGFASHI.DEF);
				  playSound("ATACK.MP3",1);
				  for(i = 0 ; i < 20000 ; i++){
					  if(LINGFASHI.ATACK-PEOPLE.DEF>0)
							PEOPLE.hp-=LINGFASHI.ATACK-PEOPLE.DEF;
						hp-=PEOPLE.ATACK-LINGFASHI.DEF;
						temhp+=LINGFASHI.ATACK-PEOPLE.DEF;

						if(hp<0)
							hp = 0;
						DAGUAI(hp,LINGFASHI.ATACK,LINGFASHI.DEF);
						pauseGame(200);
						if(hp==0)
						break;
				  }
				  hide_DAGUAI(hp,LINGFASHI.ATACK,LINGFASHI.DEF);
				  closeSound("ATACK.MP3");
				  if(PEOPLE.hp<=0)
					  atack_monster_hp(EXCLE,x,y,temhp);
				  else{
						PEOPLE.money+=LINGFASHI.money;
						PEOPLE.ex+=LINGFASHI.ex;
						map[x][y] = 0;
						setImageSource(FLOOR[x][y],"FLOOR.png");
						sprintf(tempMsg,"获得%2d金币,%2d经验",LINGFASHI.money,LINGFASHI.ex);
						setText(wenbenkuang2,tempMsg);
						showSprite(wenbenkuang);
						showText(wenbenkuang2);
						sprintf(tempMsg,"%d",PEOPLE.hp);
						setText(HPNUM,tempMsg);
						sprintf(tempMsg,"%d",PEOPLE.money);
						setText(MONEYNUM,tempMsg);
						sprintf(tempMsg,"%d",PEOPLE.ex);
						setText(EXNUM,tempMsg);
						playSound("sndStair.MP3",0);
				  }
				  map[PEOPLE.y][PEOPLE.x] = 0;
				}
			  else
				  playSound("f_gun.mp3",0);

		  }
		  else
			  playSound("f_gun.mp3",0);	break;
	case 57:
		  if(PEOPLE.ATACK>MINGDUIZHANG.DEF)
		  {
			  if((PEOPLE.hp-((MINGDUIZHANG.hp/(PEOPLE.ATACK-MINGDUIZHANG.DEF))*(MINGDUIZHANG.ATACK-PEOPLE.DEF)))>0){
				  int hp = MINGDUIZHANG.hp;
				  int temhp = 0;
				  show_DAGUAI(hp,MINGDUIZHANG.ATACK,MINGDUIZHANG.DEF);
				  playSound("ATACK.MP3",1);
				  for(i = 0 ; i < 20000 ; i++){
					  if(MINGDUIZHANG.ATACK-PEOPLE.DEF>0)
							PEOPLE.hp-=MINGDUIZHANG.ATACK-PEOPLE.DEF;
						hp-=PEOPLE.ATACK-MINGDUIZHANG.DEF;
						temhp+=MINGDUIZHANG.ATACK-PEOPLE.DEF;

						if(hp<0)
							hp = 0;
						DAGUAI(hp,MINGDUIZHANG.ATACK,MINGDUIZHANG.DEF);
						pauseGame(200);
						if(hp==0)
						break;
				  }
				  hide_DAGUAI(hp,MINGDUIZHANG.ATACK,MINGDUIZHANG.DEF);
				  closeSound("ATACK.MP3");
				  if(PEOPLE.hp<=0)
					  atack_monster_hp(EXCLE,x,y,temhp);
				  else{
						PEOPLE.money+=MINGDUIZHANG.money;
						PEOPLE.ex+=MINGDUIZHANG.ex;
						map[x][y] = 0;
						setImageSource(FLOOR[x][y],"FLOOR.png");
						sprintf(tempMsg,"获得%2d金币,%2d经验",MINGDUIZHANG.money,MINGDUIZHANG.ex);
						setText(wenbenkuang2,tempMsg);
						showSprite(wenbenkuang);
						showText(wenbenkuang2);
						sprintf(tempMsg,"%d",PEOPLE.hp);
						setText(HPNUM,tempMsg);
						sprintf(tempMsg,"%d",PEOPLE.money);
						setText(MONEYNUM,tempMsg);
						sprintf(tempMsg,"%d",PEOPLE.ex);
						setText(EXNUM,tempMsg);
						playSound("sndStair.MP3",0);
				  }
				  map[PEOPLE.y][PEOPLE.x] = 0;
				}
			  else
				  playSound("f_gun.mp3",0);

		  }
		  else
			  playSound("f_gun.mp3",0);	break;
	case 58:
		  if(PEOPLE.ATACK>YINGZIZHANSHI.DEF)
		  {
			  if((PEOPLE.hp-((YINGZIZHANSHI.hp/(PEOPLE.ATACK-YINGZIZHANSHI.DEF))*(YINGZIZHANSHI.ATACK-PEOPLE.DEF)))>0){
				  int hp = YINGZIZHANSHI.hp;
				  int temhp = 0;
				  show_DAGUAI(hp,YINGZIZHANSHI.ATACK,YINGZIZHANSHI.DEF);
				  playSound("ATACK.MP3",1);
				  for(i = 0 ; i < 20000 ; i++){
					  if(YINGZIZHANSHI.ATACK-PEOPLE.DEF>0)
							PEOPLE.hp-=YINGZIZHANSHI.ATACK-PEOPLE.DEF;
						hp-=PEOPLE.ATACK-YINGZIZHANSHI.DEF;
						temhp+=YINGZIZHANSHI.ATACK-PEOPLE.DEF;

						if(hp<0)
							hp = 0;
						DAGUAI(hp,YINGZIZHANSHI.ATACK,YINGZIZHANSHI.DEF);
						pauseGame(200);
						if(hp==0)
						break;
				  }
				  hide_DAGUAI(hp,YINGZIZHANSHI.ATACK,YINGZIZHANSHI.DEF);
				  closeSound("ATACK.MP3");
				  if(PEOPLE.hp<=0)
					  atack_monster_hp(EXCLE,x,y,temhp);
				  else{
						PEOPLE.money+=YINGZIZHANSHI.money;
						PEOPLE.ex+=YINGZIZHANSHI.ex;
						map[x][y] = 0;
						setImageSource(FLOOR[x][y],"FLOOR.png");
						sprintf(tempMsg,"获得%2d金币,%2d经验",YINGZIZHANSHI.money,YINGZIZHANSHI.ex);
						setText(wenbenkuang2,tempMsg);
						showSprite(wenbenkuang);
						showText(wenbenkuang2);
						sprintf(tempMsg,"%d",PEOPLE.hp);
						setText(HPNUM,tempMsg);
						sprintf(tempMsg,"%d",PEOPLE.money);
						setText(MONEYNUM,tempMsg);
						sprintf(tempMsg,"%d",PEOPLE.ex);
						setText(EXNUM,tempMsg);
						playSound("sndStair.MP3",0);
				  }
				  map[PEOPLE.y][PEOPLE.x] = 0;
				}
			  else
				  playSound("f_gun.mp3",0);

		  }
		  else
			  playSound("f_gun.mp3",0);	break;
	case 59:
		  if(PEOPLE.ATACK>HONGYIMOWANG.DEF)
		  {
			  if((PEOPLE.hp-((HONGYIMOWANG.hp/(PEOPLE.ATACK-HONGYIMOWANG.DEF))*(HONGYIMOWANG.ATACK-PEOPLE.DEF)))>0){
				  int hp = HONGYIMOWANG.hp;
				  int temhp = 0;
				  show_DAGUAI(hp,HONGYIMOWANG.ATACK,HONGYIMOWANG.DEF);
				  playSound("ATACK.MP3",1);
				  for(i = 0 ; i < 20000 ; i++){
					  if(HONGYIMOWANG.ATACK-PEOPLE.DEF>0)
							PEOPLE.hp-=HONGYIMOWANG.ATACK-PEOPLE.DEF;
						hp-=PEOPLE.ATACK-HONGYIMOWANG.DEF;
						temhp+=HONGYIMOWANG.ATACK-PEOPLE.DEF;

						if(hp<0)
							hp = 0;
						DAGUAI(hp,HONGYIMOWANG.ATACK,HONGYIMOWANG.DEF);
						pauseGame(200);
						if(hp==0)
						break;
				  }
				  hide_DAGUAI(hp,HONGYIMOWANG.ATACK,HONGYIMOWANG.DEF);
				  closeSound("ATACK.MP3");
				  if(PEOPLE.hp<=0)
					  atack_monster_hp(EXCLE,x,y,temhp);
				  else{
						PEOPLE.money+=HONGYIMOWANG.money;
						PEOPLE.ex+=HONGYIMOWANG.ex;
						map[x][y] = 0;
						setImageSource(FLOOR[x][y],"FLOOR.png");
						sprintf(tempMsg,"获得%2d金币,%2d经验",HONGYIMOWANG.money,HONGYIMOWANG.ex);
						setText(wenbenkuang2,tempMsg);
						showSprite(wenbenkuang);
						showText(wenbenkuang2);
						sprintf(tempMsg,"%d",PEOPLE.hp);
						setText(HPNUM,tempMsg);
						sprintf(tempMsg,"%d",PEOPLE.money);
						setText(MONEYNUM,tempMsg);
						sprintf(tempMsg,"%d",PEOPLE.ex);
						setText(EXNUM,tempMsg);
						playSound("sndStair.MP3",0);
				  }
				  map[PEOPLE.y][PEOPLE.x] = 0;
				}
			  else
				  playSound("f_gun.mp3",0);

		  }
		  else
			  playSound("f_gun.mp3",0);	break;
	case 60:
		  if(PEOPLE.ATACK>MINGLINGMOWANG.DEF)
		  {
			  if((PEOPLE.hp-((MINGLINGMOWANG.hp/(PEOPLE.ATACK-MINGLINGMOWANG.DEF))*(MINGLINGMOWANG.ATACK-PEOPLE.DEF)))>0){
				  int hp = MINGLINGMOWANG.hp;
				  int temhp = 0;
				  show_DAGUAI(hp,MINGLINGMOWANG.ATACK,MINGLINGMOWANG.DEF);
				  playSound("ATACK.MP3",1);
				  for(i = 0 ; i < 20000 ; i++){
					  if(MINGLINGMOWANG.ATACK-PEOPLE.DEF>0)
							PEOPLE.hp-=MINGLINGMOWANG.ATACK-PEOPLE.DEF;
						hp-=PEOPLE.ATACK-MINGLINGMOWANG.DEF;
						temhp+=MINGLINGMOWANG.ATACK-PEOPLE.DEF;

						if(hp<0)
							hp = 0;
						DAGUAI(hp,MINGLINGMOWANG.ATACK,MINGLINGMOWANG.DEF);
						pauseGame(200);
						if(hp==0)
						break;
				  }
				  hide_DAGUAI(hp,MINGLINGMOWANG.ATACK,MINGLINGMOWANG.DEF);
				  closeSound("ATACK.MP3");
				  if(PEOPLE.hp<=0)
					  atack_monster_hp(EXCLE,x,y,temhp);
				  else{
						PEOPLE.money+=MINGLINGMOWANG.money;
						PEOPLE.ex+=MINGLINGMOWANG.ex;
						map[x][y] = 0;
						setImageSource(FLOOR[x][y],"FLOOR.png");
						sprintf(tempMsg,"获得%2d金币,%2d经验",MINGLINGMOWANG.money,MINGLINGMOWANG.ex);
						setText(wenbenkuang2,tempMsg);
						showSprite(wenbenkuang);
						showText(wenbenkuang2);
						sprintf(tempMsg,"%d",PEOPLE.hp);
						setText(HPNUM,tempMsg);
						sprintf(tempMsg,"%d",PEOPLE.money);
						setText(MONEYNUM,tempMsg);
						sprintf(tempMsg,"%d",PEOPLE.ex);
						setText(EXNUM,tempMsg);
						playSound("sndStair.MP3",0);
				  }
				  map[PEOPLE.y][PEOPLE.x] = 0;
				}
			  else
				  playSound("f_gun.mp3",0);

		  }
		  else
			  playSound("f_gun.mp3",0);	break;
	default:break;
   }
   pauseGame(200);
   hideSprite(wenbenkuang);
   hideText(wenbenkuang2);
}

void push_BAIFALAOREN()
{
	char ch;
	int a = 1;///记录选择的选项
	playSpriteAnimate(BAIFALAOREN,"1");
	showSprite(BAIFALAOREN);
	while(1){
	   ch=getPressedKeyCode();
	   if(ch==' '){
		   if(a==1){
               if(PEOPLE.ex>99)
               {
                  playSound("sndBuy.MP3",0);
                  PEOPLE.ex-=100;
                  PEOPLE.hp+=1000;
                  PEOPLE.ATACK+=7;
                  PEOPLE.DEF+=7;
                  PEOPLE.level++;
				  sprintf(tempMsg,"%d",PEOPLE.level);
				  setText(LEVELNUM,tempMsg);
				  sprintf(tempMsg,"%d",PEOPLE.hp);
				  setText(HPNUM,tempMsg);
				  sprintf(tempMsg,"%d",PEOPLE.ATACK);
				  setText(ATACKNUM,tempMsg);
				  sprintf(tempMsg,"%d",PEOPLE.DEF);
				  setText(DEFNUM,tempMsg);
				  sprintf(tempMsg,"%d",PEOPLE.ex);
				  setText(EXNUM,tempMsg);
               }
               else
               {
                  playSound("sndCancel.MP3",0);
               }
		   }
		   else if(a==2){
               if(PEOPLE.ex>29)
               {
                  playSound("sndBuy.MP3",0);
                  PEOPLE.ex-=30;
                  PEOPLE.ATACK+=5;
				  sprintf(tempMsg,"%d",PEOPLE.ATACK);
				  setText(ATACKNUM,tempMsg);
				  sprintf(tempMsg,"%d",PEOPLE.ex);
				  setText(EXNUM,tempMsg);
               }
               else
               {
                  playSound("sndCancel.MP3",0);
               }
           }
           else if(a==3){
               if(PEOPLE.ex>29)
               {
                  playSound("sndBuy.MP3",0);
                  PEOPLE.ex-=30;
                  PEOPLE.DEF+=5;
				  sprintf(tempMsg,"%d",PEOPLE.DEF);
				  setText(DEFNUM,tempMsg);
				  sprintf(tempMsg,"%d",PEOPLE.ex);
				  setText(EXNUM,tempMsg);
               }
               else
               {
                  playSound("sndCancel.MP3",0);
               }
           }
           else{
               playSound("sndStair.MP3",0);
			   hideSprite(BAIFALAOREN);
				//此处添加更新文本
               break;
		   }
		   pauseGame(60);
	   }
	   else{
		   if(ch==RP_KEY_UP){
			   if(a>1){
				   a--;
				   playSound("sndSelect.MP3",0);
			   }
		   }
		   else if(ch==RP_KEY_DOWN){
			   if(a<4){
				   a++;
				   playSound("sndSelect.MP3",0);
			   }
		   }
		   switch(a){
				case 1:playSpriteAnimate(BAIFALAOREN,"1");break;
				case 2:playSpriteAnimate(BAIFALAOREN,"2");break;
				case 3:playSpriteAnimate(BAIFALAOREN,"3");break;
				case 4:playSpriteAnimate(BAIFALAOREN,"4");break;
		   }
		}
		pauseGame(100);
	}
}

void push_BAIFALAOREN2()
{
	char ch;
	int a = 1;///记录选择的选项
	playSpriteAnimate(BAIFALAOREN,"5");
	showSprite(BAIFALAOREN);
	while(1){
	   ch=getPressedKeyCode();
	   if(ch==' '){
		   if(a==1){
               if(PEOPLE.ex>269)
               {
                  playSound("sndBuy.MP3",0);
                  PEOPLE.ex-=270;
                  PEOPLE.hp+=3000;
                  PEOPLE.ATACK+=21;
                  PEOPLE.DEF+=21;
                  PEOPLE.level+=3;
				  sprintf(tempMsg,"%d",PEOPLE.level);
				  setText(LEVELNUM,tempMsg);
				  sprintf(tempMsg,"%d",PEOPLE.hp);
				  setText(HPNUM,tempMsg);
				  sprintf(tempMsg,"%d",PEOPLE.ATACK);
				  setText(ATACKNUM,tempMsg);
				  sprintf(tempMsg,"%d",PEOPLE.DEF);
				  setText(DEFNUM,tempMsg);
				  sprintf(tempMsg,"%d",PEOPLE.ex);
				  setText(EXNUM,tempMsg);
               }
               else
               {
                  playSound("sndCancel.MP3",0);
               }
		   }
		   else if(a==2){
               if(PEOPLE.ex>94)
               {
                  playSound("sndBuy.MP3",0);
                  PEOPLE.ex-=95;
                  PEOPLE.ATACK+=17;
				  sprintf(tempMsg,"%d",PEOPLE.ATACK);
				  setText(ATACKNUM,tempMsg);
				  sprintf(tempMsg,"%d",PEOPLE.ex);
				  setText(EXNUM,tempMsg);
               }
               else
               {
                  playSound("sndCancel.MP3",0);
               }
           }
           else if(a==3){
               if(PEOPLE.ex>94)
               {
                  playSound("sndBuy.MP3",0);
                  PEOPLE.ex-=95;
                  PEOPLE.DEF+=17;
				  sprintf(tempMsg,"%d",PEOPLE.DEF);
				  setText(DEFNUM,tempMsg);
				  sprintf(tempMsg,"%d",PEOPLE.ex);
				  setText(EXNUM,tempMsg);
               }
               else
               {
                  playSound("sndCancel.MP3",0);
               }
           }
           else{
               playSound("sndStair.MP3",0);
			   hideSprite(BAIFALAOREN);
				//此处添加更新文本
               break;
		   }
		   pauseGame(60);
	   }
	   else{
		   if(ch==RP_KEY_UP){
			   if(a>1){
				   a--;
				   playSound("sndSelect.MP3",0);
			   }
		   }
		   else if(ch==RP_KEY_DOWN){
			   if(a<4){
				   a++;
				   playSound("sndSelect.MP3",0);
			   }
		   }
		   switch(a){
				case 1:playSpriteAnimate(BAIFALAOREN,"5");break;
				case 2:playSpriteAnimate(BAIFALAOREN,"6");break;
				case 3:playSpriteAnimate(BAIFALAOREN,"7");break;
				case 4:playSpriteAnimate(BAIFALAOREN,"8");break;
		   }
		}
		pauseGame(100);
	}
}

void push_HONGYILAOREN()
{
	char ch;
	int a = 1;///记录选择的选项
	playSpriteAnimate(HONGYILAOREN,"1");
	showSprite(HONGYILAOREN);
	while(1){
	   ch=getPressedKeyCode();
	   if(ch==' '){
		   if(a==3){
               if(PEOPLE.money>99)
               {
                  playSound("sndBuy.MP3",0);
                  PEOPLE.money-=100;
                  PEOPLE.REDKEY++;
				  sprintf(tempMsg,"%d",PEOPLE.REDKEY);
				  setText(REDKEYNUM,tempMsg);
				  sprintf(tempMsg,"%d",PEOPLE.money);
				  setText(MONEYNUM,tempMsg);
               }
               else
               {
                  playSound("sndCancel.MP3",0);
               }
		   }
		   else if(a==2){
               if(PEOPLE.money>49)
               {
                  playSound("sndBuy.MP3",0);
                  PEOPLE.money-=50;
                  PEOPLE.BLUEKEY++;
				  sprintf(tempMsg,"%d",PEOPLE.BLUEKEY);
				  setText(BLUEKEYNUM,tempMsg);
				  sprintf(tempMsg,"%d",PEOPLE.money);
				  setText(MONEYNUM,tempMsg);
               }
               else
               {
                  playSound("sndCancel.MP3",0);
               }
           }
           else if(a==1){
               if(PEOPLE.money>9)
               {
                  playSound("sndBuy.MP3",0);
                  PEOPLE.money-=10;
                  PEOPLE.YELLOWKEY++;
				  sprintf(tempMsg,"%d",PEOPLE.YELLOWKEY);
				  setText(YELLOWKEYNUM,tempMsg);
				  sprintf(tempMsg,"%d",PEOPLE.money);
				  setText(MONEYNUM,tempMsg);
               }
               else
               {
                  playSound("sndCancel.MP3",0);
               }
           }
           else{
               playSound("sndStair.MP3",0);
			   hideSprite(HONGYILAOREN);
				//此处添加更新文本
               break;
		   }
		   pauseGame(60);
	   }
	   else{
		   if(ch==RP_KEY_UP){
			   if(a>1){
				   a--;
				   playSound("sndSelect.MP3",0);
			   }
		   }
		   else if(ch==RP_KEY_DOWN){
			   if(a<4){
				   a++;
				   playSound("sndSelect.MP3",0);
			   }
		   }
		   switch(a){
				case 1:playSpriteAnimate(HONGYILAOREN,"1");break;
				case 2:playSpriteAnimate(HONGYILAOREN,"2");break;
				case 3:playSpriteAnimate(HONGYILAOREN,"3");break;
				case 4:playSpriteAnimate(HONGYILAOREN,"4");break;
		   }
		}
		pauseGame(100);
	}
}

void push_HONGYILAOREN2()
{
	char ch;
	int a = 1;///记录选择的选项
	playSpriteAnimate(HONGYILAOREN,"5");
	showSprite(HONGYILAOREN);
	while(1){
	   ch=getPressedKeyCode();
	   if(ch==' '){
		   if(a==3){
               if(PEOPLE.REDKEY>1)
               {
                  playSound("sndBuy.MP3",0);
                  PEOPLE.money+=70;
                  PEOPLE.REDKEY--;
				  sprintf(tempMsg,"%d",PEOPLE.REDKEY);
				  setText(REDKEYNUM,tempMsg);
				  sprintf(tempMsg,"%d",PEOPLE.money);
				  setText(MONEYNUM,tempMsg);
               }
               else
               {
                  playSound("sndCancel.MP3",0);
               }
		   }
		   else if(a==2){
               if(PEOPLE.BLUEKEY>1)
               {
                  playSound("sndBuy.MP3",0);
                  PEOPLE.money+=35;
                  PEOPLE.BLUEKEY--;
				  sprintf(tempMsg,"%d",PEOPLE.BLUEKEY);
				  setText(BLUEKEYNUM,tempMsg);
				  sprintf(tempMsg,"%d",PEOPLE.money);
				  setText(MONEYNUM,tempMsg);
               }
               else
               {
                  playSound("sndCancel.MP3",0);
               }
           }
           else if(a==1){
               if(PEOPLE.YELLOWKEY>1)
               {
                  playSound("sndBuy.MP3",0);
                  PEOPLE.money+=7;
                  PEOPLE.YELLOWKEY--;
				  sprintf(tempMsg,"%d",PEOPLE.YELLOWKEY);
				  setText(YELLOWKEYNUM,tempMsg);
				  sprintf(tempMsg,"%d",PEOPLE.money);
				  setText(MONEYNUM,tempMsg);
               }
               else
               {
                  playSound("sndCancel.MP3",0);
               }
           }
           else{
               playSound("sndStair.MP3",0);
			   hideSprite(HONGYILAOREN);
				//此处添加更新文本
               break;
		   }
		   pauseGame(60);
	   }
	   else{
		   if(ch==RP_KEY_UP){
			   if(a>1){
				   a--;
				   playSound("sndSelect.MP3",0);
			   }
		   }
		   else if(ch==RP_KEY_DOWN){
			   if(a<4){
				   a++;
				   playSound("sndSelect.MP3",0);
			   }
		   }
		   switch(a){
				case 1:playSpriteAnimate(HONGYILAOREN,"5");break;
				case 2:playSpriteAnimate(HONGYILAOREN,"6");break;
				case 3:playSpriteAnimate(HONGYILAOREN,"7");break;
				case 4:playSpriteAnimate(HONGYILAOREN,"8");break;
		   }
		}
		pauseGame(100);
	}
}

void push_SHANGDIAN()///第三层商店
{
   char ch;
	int a = 1;///记录选择的选项
	playSpriteAnimate(SHANGDIAN,"1");
	showSprite(SHANGDIAN);
	while(1){
	   ch=getPressedKeyCode();
	   if(ch==' '){
		   if(a<4)
			   if(PEOPLE.money>24){
				   if(a==1){
					  playSound("sndBuy.MP3",0);
					  PEOPLE.money-=25;
					  PEOPLE.hp+=800;
					  sprintf(tempMsg,"%d",PEOPLE.hp);
					  setText(HPNUM,tempMsg);
					  sprintf(tempMsg,"%d",PEOPLE.money);
					  setText(MONEYNUM,tempMsg);
					}
					else if(a==2){
					  playSound("sndBuy.MP3",0);
					  PEOPLE.money-=25;
					  PEOPLE.ATACK+=4;
					  sprintf(tempMsg,"%d",PEOPLE.ATACK);
					  setText(ATACKNUM,tempMsg);
					  sprintf(tempMsg,"%d",PEOPLE.money);
					  setText(MONEYNUM,tempMsg);
					 }
					else if(a==3){
					  playSound("sndBuy.MP3",0);
					  PEOPLE.money-=25;
					  PEOPLE.DEF+=4;
					  sprintf(tempMsg,"%d",PEOPLE.DEF);
					  setText(DEFNUM,tempMsg);
					  sprintf(tempMsg,"%d",PEOPLE.money);
					  setText(MONEYNUM,tempMsg);
					}

					pauseGame(60);
			   }
			   else
				   {
					  playSound("sndCancel.MP3",0);
				   }
			else{
					playSound("sndStair.MP3",0);
					hideSprite(SHANGDIAN);
					//此处添加更新文本
					break;
				}
	   }
	   else{
		   if(ch==RP_KEY_UP){
			   if(a>1){
				   a--;
				   playSound("sndSelect.MP3",0);
			   }
		   }
		   else if(ch==RP_KEY_DOWN){
			   if(a<4){
				   a++;
				   playSound("sndSelect.MP3",0);
			   }
		   }
		   switch(a){
				case 1:playSpriteAnimate(SHANGDIAN,"1");break;
				case 2:playSpriteAnimate(SHANGDIAN,"2");break;
				case 3:playSpriteAnimate(SHANGDIAN,"3");break;
				case 4:playSpriteAnimate(SHANGDIAN,"4");break;
		   }
		}
		pauseGame(100);
	}
}

void push_SHANGDIAN2()///第十一层商店
{
   char ch;
	int a = 1;///记录选择的选项
	playSpriteAnimate(SHANGDIAN,"5");
	showSprite(SHANGDIAN);
	while(1){
	   ch=getPressedKeyCode();
	   if(ch==' '){
		   if(a<4)
			   if(PEOPLE.money>99){
				   if(a==1){
					  playSound("sndBuy.MP3",0);
					  PEOPLE.money-=100;
					  PEOPLE.hp+=4000;
					  sprintf(tempMsg,"%d",PEOPLE.hp);
					  setText(HPNUM,tempMsg);
					  sprintf(tempMsg,"%d",PEOPLE.money);
					  setText(MONEYNUM,tempMsg);
					}
					else if(a==2){
					  playSound("sndBuy.MP3",0);
					  PEOPLE.money-=100;
					  PEOPLE.ATACK+=20;
					  sprintf(tempMsg,"%d",PEOPLE.ATACK);
					  setText(ATACKNUM,tempMsg);
					  sprintf(tempMsg,"%d",PEOPLE.money);
					  setText(MONEYNUM,tempMsg);
					 }
					else if(a==3){
					  playSound("sndBuy.MP3",0);
					  PEOPLE.money-=100;
					  PEOPLE.DEF+=20;
					  sprintf(tempMsg,"%d",PEOPLE.DEF);
					  setText(DEFNUM,tempMsg);
					  sprintf(tempMsg,"%d",PEOPLE.money);
					  setText(MONEYNUM,tempMsg);
					}

					pauseGame(60);
			   }
			   else
				   {
					  playSound("sndCancel.MP3",0);
				   }
			else{
					playSound("sndStair.MP3",0);
					hideSprite(SHANGDIAN);
					//此处添加更新文本
					break;
				}
	   }
	   else{
		   if(ch==RP_KEY_UP){
			   if(a>1){
				   a--;
				   playSound("sndSelect.MP3",0);
			   }
		   }
		   else if(ch==RP_KEY_DOWN){
			   if(a<4){
				   a++;
				   playSound("sndSelect.MP3",0);
			   }
		   }
		   switch(a){
				case 1:playSpriteAnimate(SHANGDIAN,"5");break;
				case 2:playSpriteAnimate(SHANGDIAN,"6");break;
				case 3:playSpriteAnimate(SHANGDIAN,"7");break;
				case 4:playSpriteAnimate(SHANGDIAN,"8");break;
		   }
		}
		pauseGame(100);
	}
}

void change_state(int EXCLE,int x,int y)///EXCLE代表标号值这个函数用于改变(x,y)的状态
{
	//printf("%d %d %d\n",x,y,map[x][y]);
	if(EXCLE==2);
	else if(map[x][y] == 3 && PEOPLE.REDKEY>0){
      playSound("OPENTHEDOOR.MP3",0);
	  setImageSource(FLOOR[x][y],"FLOOR.png");
	  pauseGame(100);
      map[x][y] = 0;
      map[PEOPLE.y][PEOPLE.x] = 0;
      PEOPLE.REDKEY--;
	  sprintf(tempMsg,"%d",PEOPLE.REDKEY);
	  setText(REDKEYNUM,tempMsg);
   }
   else if(map[x][y] == 4 && PEOPLE.YELLOWKEY>0){
      playSound("OPENTHEDOOR.MP3",0);
	  setImageSource(FLOOR[x][y],"FLOOR.png");
	  pauseGame(100);
      map[x][y] = 0;
      map[PEOPLE.y][PEOPLE.x] = 0;
      PEOPLE.YELLOWKEY--;
	  sprintf(tempMsg,"%d",PEOPLE.YELLOWKEY);
	  setText(YELLOWKEYNUM,tempMsg);
   }
   else if(map[x][y] == 5 && PEOPLE.BLUEKEY>0){
      playSound("OPENTHEDOOR.MP3",0);
	  setImageSource(FLOOR[x][y],"FLOOR.png");
	  pauseGame(100);
      map[x][y] = 0;
      map[PEOPLE.y][PEOPLE.x] = 0;
      PEOPLE.BLUEKEY--;
	  sprintf(tempMsg,"%d",PEOPLE.BLUEKEY);
	  setText(BLUEKEYNUM,tempMsg);
   }
   else if(map[x][y] == 6)
   {
	   	showSprite(wenbenkuang);
		showText(wenbenkuang2);
		setText(wenbenkuang2,"获得血瓶，生命值+200");
	   setImageSource(FLOOR[x][y],"FLOOR.png");
	   playSound("PICK.MP3",0);
	   map[x][y] = 0;
	   map[PEOPLE.y][PEOPLE.x] = 0;
	   PEOPLE.hp+=200;
	   sprintf(tempMsg,"%d",PEOPLE.hp);
	   setText(HPNUM,tempMsg);
   }
   else if(map[x][y] == 7)
   {
	   	showSprite(wenbenkuang);
		showText(wenbenkuang2);
		setText(wenbenkuang2,"获得血瓶，生命值+500");
	   playSound("PICK.MP3",0);
	   setImageSource(FLOOR[x][y],"FLOOR.png");
	   map[x][y] = 0;
	   map[PEOPLE.y][PEOPLE.x] = 0;
	   PEOPLE.hp+=500;
	   sprintf(tempMsg,"%d",PEOPLE.hp);
	   setText(HPNUM,tempMsg);
   }
   else if(map[x][y] == 8)
   {
      map[x][y] = 0;   ///打印圣光徽图片
	  setImageSource(FLOOR[x][y],"FLOOR.png");
	  createSprite(SHENGGUANGHUI_PUSH,"SHENGGUANGHUI_PUSH");
	  playSpriteAnimate(SHENGGUANGHUI_PUSH,"1");
      setSpritePosition(SHENGGUANGHUI_PUSH,250,350);
      playSound("sndItem2.MP3",0);
	  shengguanghui=0;
      pauseGame(100);
      while(shengguanghui!=' '){
		  shengguanghui=getPressedKeyCode();
	  };
      map[PEOPLE.y][PEOPLE.x] = 0;
	  hideSprite(SHENGGUANGHUI_PUSH);
   }
   else if(map[x][y] == 9)
   {
      map[x][y] = 0;   ///打印风之罗盘图片
	  setImageSource(FLOOR[x][y],"FLOOR.png");
	  createSprite(FENGZHILUOPAN_PUSH,"FENGZHILUOPAN_PUSH");
	  playSpriteAnimate(FENGZHILUOPAN_PUSH,"0");
      setSpritePosition(FENGZHILUOPAN_PUSH,250,200);
      playSound("sndItem2.MP3",0);
	  fengzhiluopan=0;
      pauseGame(100);
      while(fengzhiluopan!=' '){
		  fengzhiluopan=getPressedKeyCode();
	  };
      map[PEOPLE.y][PEOPLE.x] = 0;
	  playSpriteAnimate(FENGZHILUOPAN_PUSH,"1");
	  setSpritePosition(FENGZHILUOPAN_PUSH,250,150);
	  hideSprite(FENGZHILUOPAN_PUSH);
   }
   else if(map[x][y] == 10)///上楼梯
   {
	  playSound("sndStair.MP3",0);
	  map[PEOPLE.y][PEOPLE.x] = 0;
	  memcpy(Ma[mapnum],map,sizeof(int)*11*11);
      mapnum++;
	  if(mapnum>=Maxmap) Maxmap++;
	  memcpy(map,Ma[mapnum],sizeof(int)*11*11);
      change_peoplexy();

   }
   else if(map[x][y] == 11)///下楼梯
   {
         playSound("sndStair.MP3",0);
		 map[PEOPLE.y][PEOPLE.x] = 0;
         memcpy(Ma[mapnum],map,sizeof(int)*11*11);
		 mapnum--;
		 memcpy(map,Ma[mapnum],sizeof(int)*11*11);
         change_peoplexy();
   }
   else if(map[x][y] == 12)
   {
	   	showSprite(wenbenkuang);
		showText(wenbenkuang2);
		setText(wenbenkuang2,"  获得 1 把黄钥匙");
      map[x][y] = 0;
      map[PEOPLE.y][PEOPLE.x] = 0;
      PEOPLE.YELLOWKEY++;
	  setImageSource(FLOOR[x][y],"FLOOR.png");
      playSound("PICK.MP3",0);
	  sprintf(tempMsg,"%d",PEOPLE.YELLOWKEY);
	  setText(YELLOWKEYNUM,tempMsg);
   }
   else if(map[x][y] == 13)
   {
	   	showSprite(wenbenkuang);
		showText(wenbenkuang2);
		setText(wenbenkuang2,"  获得 1 把红钥匙");
      map[x][y] = 0;
      map[PEOPLE.y][PEOPLE.x] = 0;
      PEOPLE.REDKEY++;
	  setImageSource(FLOOR[x][y],"FLOOR.png");
      playSound("PICK.MP3",0);
	  sprintf(tempMsg,"%d",PEOPLE.REDKEY);
	  setText(REDKEYNUM,tempMsg);
   }
   else if(map[x][y] == 14)
   {
	   	showSprite(wenbenkuang);
		showText(wenbenkuang2);
		setText(wenbenkuang2,"  获得 1 把蓝钥匙");
      map[x][y] = 0;
      map[PEOPLE.y][PEOPLE.x] = 0;
      PEOPLE.BLUEKEY++;
	  setImageSource(FLOOR[x][y],"FLOOR.png");
      playSound("PICK.MP3",0);
	  sprintf(tempMsg,"%d",PEOPLE.BLUEKEY);
	  setText(BLUEKEYNUM,tempMsg);
   }
   else if(map[x][y] == 16)
   {
		showSprite(wenbenkuang);
		showText(wenbenkuang2);
		setText(wenbenkuang2,"获得红宝石,攻击力+3");
      map[x][y] = 0;
      map[PEOPLE.y][PEOPLE.x] = 0;
      PEOPLE.ATACK+=3;
	  setImageSource(FLOOR[x][y],"FLOOR.png");
      playSound("PICK.MP3",0);
	  sprintf(tempMsg,"%d",PEOPLE.ATACK);
	  setText(ATACKNUM,tempMsg);
   }
   else if(map[x][y] == 17)
   {
		showSprite(wenbenkuang);
		showText(wenbenkuang2);
		setText(wenbenkuang2,"获得蓝宝石,防御力+3");
      map[x][y] = 0;
      map[PEOPLE.y][PEOPLE.x] = 0;
      PEOPLE.DEF+=3;
	  setImageSource(FLOOR[x][y],"FLOOR.png");
      playSound("PICK.MP3",0);
	  sprintf(tempMsg,"%d",PEOPLE.DEF);
	  setText(DEFNUM,tempMsg);
   }
   else if(map[x][y] == 18){	//(当楼层为5时)弹出白发老人购买菜单
      playSound("sndSelect.MP3",0);
	  if(mapnum+1==5)
		push_BAIFALAOREN();
	  else
		push_BAIFALAOREN2();
   }
   else if(map[x][y] == 19){	//(当楼层为5时)弹出红衣老人购买菜单
      playSound("sndSelect.MP3",0);
	  if(mapnum+1==6)
		push_HONGYILAOREN();
	  else
		push_HONGYILAOREN2();
   }
   else if(map[x][y] == 21){	//第三层的宝剑
		showSprite(wenbenkuang);
		showText(wenbenkuang2);
		setText(wenbenkuang2,"取得宝剑，攻击力+10");
      map[x][y] = 0;
      map[PEOPLE.y][PEOPLE.x] = 0;
      PEOPLE.ATACK+=10;
	  setImageSource(FLOOR[x][y],"FLOOR.png");
      playSound("PICK.MP3",0);
	  sprintf(tempMsg,"%d",PEOPLE.ATACK);
	  setText(ATACKNUM,tempMsg);
   }
   else if(map[x][y] == 22){	//弹出商店购买菜单
      playSound("sndSelect.MP3",0);
	  if(mapnum+1==3)//3楼
		push_SHANGDIAN();
	  else
		push_SHANGDIAN2();
   }
   else if(map[x][y] == 23)///勇士
   {
      playSound("sndStair.MP3",0);
	  setImageSource(FLOOR[x][y],"FLOOR.png");
      showSprite(wenbenkuang);
	  showText(wenbenkuang2);
	  setText(wenbenkuang2,"勇士报恩，开启暗门");
	  map[x][y] = 0;
	  map[PEOPLE.y][PEOPLE.x] = 0;
	  map[4][5]=0;
	  setImageSource(FLOOR[4][5],"FLOOR.png");
   }
   else if(map[x][y] == 24)
   {
	   	showSprite(wenbenkuang);
		showText(wenbenkuang2);
		setText(wenbenkuang2,"取得金钥匙,全钥匙+1");
      map[x][y] = 0;
      map[PEOPLE.y][PEOPLE.x] = 0;
      PEOPLE.BLUEKEY++;
	  PEOPLE.REDKEY++;
	  PEOPLE.YELLOWKEY++;
	  setImageSource(FLOOR[x][y],"FLOOR.png");
      playSound("PICK.MP3",0);
	  sprintf(tempMsg,"%d",PEOPLE.BLUEKEY);
	  setText(BLUEKEYNUM,tempMsg);
	  sprintf(tempMsg,"%d",PEOPLE.YELLOWKEY);
	  setText(YELLOWKEYNUM,tempMsg);
	  sprintf(tempMsg,"%d",PEOPLE.REDKEY);
	  setText(REDKEYNUM,tempMsg);
	  pauseGame(50);
   }
   else if(map[x][y] == 25)//小盾牌
   {
		showSprite(wenbenkuang);
		showText(wenbenkuang2);
		setText(wenbenkuang2,"获得盾牌,防御力+10");
      map[x][y] = 0;
      map[PEOPLE.y][PEOPLE.x] = 0;
      PEOPLE.DEF+=10;
	  setImageSource(FLOOR[x][y],"FLOOR.png");
      playSound("PICK.MP3",0);
	  sprintf(tempMsg,"%d",PEOPLE.DEF);
	  setText(DEFNUM,tempMsg);
   }
   else if(map[x][y] == 26)//等级翅膀
   {
		showSprite(wenbenkuang);
		showText(wenbenkuang2);
		setText(wenbenkuang2,"获得跃升翅,等级+1");
      map[x][y] = 0;
      map[PEOPLE.y][PEOPLE.x] = 0;
	  PEOPLE.level++;
	  PEOPLE.hp+=1000;
      PEOPLE.DEF+=7;
	  PEOPLE.ATACK+=7;
	  setImageSource(FLOOR[x][y],"FLOOR.png");
      playSound("PICK.MP3",0);
	  sprintf(tempMsg,"%d",PEOPLE.DEF);
	  setText(DEFNUM,tempMsg);
	  sprintf(tempMsg,"%d",PEOPLE.ATACK);
	  setText(ATACKNUM,tempMsg);
	  sprintf(tempMsg,"%d",PEOPLE.hp);
	  setText(HPNUM,tempMsg);
	  sprintf(tempMsg,"%d",PEOPLE.level);
	  setText(LEVELNUM,tempMsg);
	  pauseGame(50);
   }
   else if(map[x][y] == 27)//盾牌2
   {
		showSprite(wenbenkuang);
		showText(wenbenkuang2);
		setText(wenbenkuang2,"获得开心币,金币+300");
      map[x][y] = 0;
      map[PEOPLE.y][PEOPLE.x] = 0;
      PEOPLE.money+=300;
	  setImageSource(FLOOR[x][y],"FLOOR.png");
      playSound("PICK.MP3",0);
	  sprintf(tempMsg,"%d",PEOPLE.money);
	  setText(MONEYNUM,tempMsg);
	  pauseGame(50);
   }
   else if(map[x][y] == 28)
   {
		showSprite(wenbenkuang);
		showText(wenbenkuang2);
		setText(wenbenkuang2,"取得十字架,攻防加半");
      map[x][y] = 0;
      map[PEOPLE.y][PEOPLE.x] = 0;
      PEOPLE.ATACK+=PEOPLE.ATACK/2;
	  PEOPLE.DEF+=PEOPLE.DEF/2;
	  setImageSource(FLOOR[x][y],"FLOOR.png");
      playSound("sndItem2.MP3",0);
	  sprintf(tempMsg,"%d",PEOPLE.ATACK);
	  setText(ATACKNUM,tempMsg);
	  sprintf(tempMsg,"%d",PEOPLE.DEF);
	  setText(DEFNUM,tempMsg);
	  pauseGame(100);
   }
   else if(map[x][y] == 29)//盾牌2
   {
		showSprite(wenbenkuang);
		showText(wenbenkuang2);
		setText(wenbenkuang2,"取得藤木盾,防御力+45");
      map[x][y] = 0;
      map[PEOPLE.y][PEOPLE.x] = 0;
      PEOPLE.DEF+=45;
	  setImageSource(FLOOR[x][y],"FLOOR.png");
      playSound("PICK.MP3",0);
	  sprintf(tempMsg,"%d",PEOPLE.DEF);
	  setText(DEFNUM,tempMsg);
	  pauseGame(50);
   }
   else if(map[x][y] == 91)//等级翅膀2
   {
		showSprite(wenbenkuang);
		showText(wenbenkuang2);
		setText(wenbenkuang2,"获得飞升翅,等级+3");
      map[x][y] = 0;
      map[PEOPLE.y][PEOPLE.x] = 0;
	  PEOPLE.level+=3;
	  PEOPLE.hp+=3000;
      PEOPLE.DEF+=21;
	  PEOPLE.ATACK+=21;
	  setImageSource(FLOOR[x][y],"FLOOR.png");
      playSound("sndItem2.MP3",0);
	  sprintf(tempMsg,"%d",PEOPLE.DEF);
	  setText(DEFNUM,tempMsg);
	  sprintf(tempMsg,"%d",PEOPLE.ATACK);
	  setText(ATACKNUM,tempMsg);
	  sprintf(tempMsg,"%d",PEOPLE.hp);
	  setText(HPNUM,tempMsg);
	  sprintf(tempMsg,"%d",PEOPLE.level);
	  setText(LEVELNUM,tempMsg);
	  pauseGame(100);
   }
   else if(map[x][y] == 92)
   {
	   	showSprite(wenbenkuang);
		showText(wenbenkuang2);
		setText(wenbenkuang2,"生命之水,生命值加一倍");
	   setImageSource(FLOOR[x][y],"FLOOR.png");
	   playSound("sndItem2.MP3",0);
	   map[x][y] = 0;
	   map[PEOPLE.y][PEOPLE.x] = 0;
	   PEOPLE.hp+=PEOPLE.hp;
	   sprintf(tempMsg,"%d",PEOPLE.hp);
	   setText(HPNUM,tempMsg);
	   pauseGame(100);
   }
   else if(map[x][y] == 95)//圣盾
   {
		showSprite(wenbenkuang);
		showText(wenbenkuang2);
		setText(wenbenkuang2,"取得圣盾，防御力+120");
      map[x][y] = 0;
      map[PEOPLE.y][PEOPLE.x] = 0;
      PEOPLE.DEF+=120;
	  setImageSource(FLOOR[x][y],"FLOOR.png");
      playSound("PICK.MP3",0);
	  sprintf(tempMsg,"%d",PEOPLE.DEF);
	  setText(DEFNUM,tempMsg);
	  pauseGame(50);
   }
   else if(map[x][y] == 94)//圣剑
   {
		showSprite(wenbenkuang);
		showText(wenbenkuang2);
		setText(wenbenkuang2,"取得圣剑,攻击力+120");
      map[x][y] = 0;
      map[PEOPLE.y][PEOPLE.x] = 0;
      PEOPLE.ATACK+=120;
	  setImageSource(FLOOR[x][y],"FLOOR.png");
      playSound("PICK.MP3",0);
	  sprintf(tempMsg,"%d",PEOPLE.ATACK);
	  setText(ATACKNUM,tempMsg);
	  pauseGame(50);
   }
   else if(map[x][y] == 96){
	   playSound("sndStair.MP3",0);
		 map[PEOPLE.y][PEOPLE.x] = 0;
         map[x][y]=0;
		 pauseGame(100);
		 closeSound("MUSIC.MP3");
		 finish();
   }

   else if(map[x][y] == 97)//宝剑2
   {
		showSprite(wenbenkuang);
		showText(wenbenkuang2);
		setText(wenbenkuang2,"取得青锋剑,攻击力+70");
      map[x][y] = 0;
      map[PEOPLE.y][PEOPLE.x] = 0;
      PEOPLE.ATACK+=70;
	  setImageSource(FLOOR[x][y],"FLOOR.png");
      playSound("PICK.MP3",0);
	  sprintf(tempMsg,"%d",PEOPLE.ATACK);
	  setText(ATACKNUM,tempMsg);
	  pauseGame(50);
   }
   else if(map[x][y] == 99)///开牢笼
   {
         playSound("sndStair.MP3",0);
		 map[PEOPLE.y][PEOPLE.x] = 0;
         map[x][y]=0;
		 setImageSource(FLOOR[x][y],"FLOOR.png");
   }
   else{
	   atack_monster(EXCLE,x,y);
   }
   pauseGame(250);
   hideSprite(wenbenkuang);
   hideText(wenbenkuang2);
}

int decide(int y,int x)//判断(x,y)是什么东西返回它的EXCLE标号值用作碰到调用属性前的判断
{
   return map[y][x];
}

void GetPressedKeyCode(void* a){
	//int i,j;
	onNormalKeyUp(nku);
	while(1){
		int ch=getPressedKeyCode();
		if(ch==RP_KEY_LEFT){
			if(PEOPLE.x>0)
				if(map[PEOPLE.y][PEOPLE.x-1] == 0)
				{
					setImageSource(FLOOR[PEOPLE.y][PEOPLE.x-1],"PEOPLE4.png");
					map[PEOPLE.y][PEOPLE.x] = 0;
					setImageSource(FLOOR[PEOPLE.y][PEOPLE.x],"FLOOR.png");
					PEOPLE.x-= 1;
					playSound("WALK.MP3",0);
					map[PEOPLE.y][PEOPLE.x] = 15;

				}
				else{
					change_state(map[PEOPLE.y][PEOPLE.x-1],PEOPLE.y,PEOPLE.x-1);}
			}
		else if(ch==RP_KEY_RIGHT){
			if(PEOPLE.x<10)
				if(map[PEOPLE.y][PEOPLE.x+1] == 0)
				{
					setImageSource(FLOOR[PEOPLE.y][PEOPLE.x+1],"PEOPLE2.png");
					map[PEOPLE.y][PEOPLE.x] = 0;
					setImageSource(FLOOR[PEOPLE.y][PEOPLE.x],"FLOOR.png");
					PEOPLE.x+= 1;
					playSound("WALK.MP3",0);
					map[PEOPLE.y][PEOPLE.x] = 15;
				}
				else{
					change_state(decide(PEOPLE.y,PEOPLE.x+1),PEOPLE.y,PEOPLE.x+1);}
		}
		else if(ch==RP_KEY_UP){
			if(PEOPLE.y<10)
				if(map[PEOPLE.y+1][PEOPLE.x] == 0)
				{
					setImageSource(FLOOR[PEOPLE.y+1][PEOPLE.x],"PEOPLE3.png");
					map[PEOPLE.y][PEOPLE.x] = 0;
					setImageSource(FLOOR[PEOPLE.y][PEOPLE.x],"FLOOR.png");
					PEOPLE.y+= 1;
					playSound("WALK.MP3",0);
					map[PEOPLE.y][PEOPLE.x] = 15;
				}
				else
					change_state(decide(PEOPLE.y+1,PEOPLE.x),PEOPLE.y+1,PEOPLE.x);
		}
		else if(ch==RP_KEY_DOWN){
			if(PEOPLE.y>0)
				if(map[PEOPLE.y-1][PEOPLE.x] == 0)
				{
					setImageSource(FLOOR[PEOPLE.y-1][PEOPLE.x],"PEOPLE1.png");
					map[PEOPLE.y][PEOPLE.x] = 0;
					setImageSource(FLOOR[PEOPLE.y][PEOPLE.x],"FLOOR.png");
					PEOPLE.y-= 1;
					playSound("WALK.MP3",0);
					map[PEOPLE.y][PEOPLE.x] = 15;
				}
				else
					change_state(decide(PEOPLE.y-1,PEOPLE.x),PEOPLE.y-1,PEOPLE.x);
		}
		else if(ch==' '){
			/*for(i = 0 ; i < 11; i++){
					for(j = 0 ; j < 11 ; j++)
						printf("%2d ",map[i][j]);
					printf("\n");
			}*/

		}
		else if(ch=='k'||ch=='K'){
			if(fengzhiluopan==' '){
				if(isSpriteVisible(FENGZHILUOPAN_PUSH)){
					hideSprite(FENGZHILUOPAN_PUSH);
				}
				else{
					showSprite(FENGZHILUOPAN_PUSH);
					pauseGame(50);
					Fengzhiluopan();

				}
			}
		}
		else if(ch==27){
			exit(0);
		}
		else if(ch=='1'){//作弊部分（供开发及演示使用）
			PEOPLE.ATACK+=50;
			PEOPLE.DEF+=20;
			PEOPLE.money+=1000;
			PEOPLE.ex+=1000;
			sprintf(tempMsg,"%d",PEOPLE.ATACK);
			setText(ATACKNUM,tempMsg);
			sprintf(tempMsg,"%d",PEOPLE.DEF);
			setText(DEFNUM,tempMsg);
			sprintf(tempMsg,"%d",PEOPLE.money);
			setText(MONEYNUM,tempMsg);
			sprintf(tempMsg,"%d",PEOPLE.ex);
			setText(EXNUM,tempMsg);
		}
		else if(ch=='2'){
			Maxmap=20;
		}
		pauseGame(100);
	}

}

void MouseOperate(){
	int x,y,b;
	int Shuoming=101;
	char ch;
	createSprite(Shuoming,"Shuoming");
	playSpriteAnimate(Shuoming,"1");
	setSpritePosition(Shuoming,50,100);
	hideSprite(Shuoming);
	while(1){
		x=getMousePositionX();
		y=getMousePositionY();
		b=isMouseLeftButtonDown();
		if(b){
			if(x>=420&&x<=660){
				if(y>=140&&y<=190){
					exit(0);
				}
				else if(y>=210&&y<=255){
					ch=0;
					showSprite(Shuoming);
					pauseGame(200);
					while(!ch){
						ch=getPressedKeyCode();
					}
					hideSprite(Shuoming);
				}
				else if(y>=275&&y<=320){
					hideSprite(Kaishi);
					break;
				}
			}
		}
	}

}

void finish()
{
	int Y[]={0,-50,-100,-150,-200,-250,-300,-350};
	int i=0,j,bg=800;
	float a;char ch=0;
	setImageSource(bgImg,"QQ截图20190520230356.png");
		hideText(LEVELNUM);
		hideText(HPNUM);
		hideText(ATACKNUM);
		hideText(DEFNUM);
		hideText(MONEYNUM);
		hideText(EXNUM);
		hideText(YELLOWKEYNUM);
		hideText(BLUEKEYNUM);
		hideText(REDKEYNUM);
	createText(jieju[0],"  大魔王被打败了，公主也被救出了塔。");
	createText(jieju[1],"  当勇士和公主一起走出塔来的时候，国王也");
	createText(jieju[2],"带着军队来到了岛外。");
	createText(jieju[3],"  一切都是这么正常。");
	createText(jieju[4],"  回国后，国王为勇士和公主举行了隆重而且");
	createText(jieju[5],"盛大的婚礼，并且宣布由勇士来继承国王的位");
	createText(jieju[6],"置。从此以后，勇士和公主就幸福的生活在一");
	createText(jieju[7],"起了。");
	createText(jieju[8],"制作：物联1801摹塔工作室\t2019年5月");
	setTextFontSize(jieju[8],50);
	setTextColor(jieju[8],1.0f,1.0f,1.0f);
	hideText(jieju[8]);
	for(i=0;i<8;i++)
		{
			setTextFontSize(jieju[i],45);
			setTextColor(jieju[i],1.0f,1.0f,1.0f);
		}
	while(Y[7]<410){
		for(i=0;i<8;i++)
		{
			Y[i]+=1;
			if(Y[i]<400)
			{
				setTextPosition(jieju[i],100,Y[i]);
				showText(jieju[i]);
			}
			else
			{
				hideText(jieju[i]);
			}		
		}
		pauseGame(1);
	}
	setTextPosition(jieju[8],100,400);
	setTextPosition(jieju[7],400,280);
	setText(jieju[7]," 感 谢 欣 赏 ");
	pauseGame(500);
	showText(jieju[8]);
	showText(jieju[7]);
	for(a=0;a<1;a+=(float)0.01){
		setTextColor(jieju[7],a,a,a);
		setTextColor(jieju[8],a,a,a);
		pauseGame(10);
	}
	pauseGame(600);
	for(a=2;a>0;a-=(float)0.01){
		setTextColor(jieju[7],a,a,a);
		setTextColor(jieju[8],a,a,a);
		pauseGame(10);
	}
	for(i=0;i<11;i++)
		for(j=0;j<11;j++)
			hideImage(FLOOR[i][j]);
	hideText(jieju[8]);
	hideText(jieju[7]);
	setImageSource(bgImg,"QQ图片20190520234941.png");
	pauseGame(800);
	showText(jieju[0]);
	setTextFontSize(jieju[0],30);
	setTextPosition(jieju[0],440,200);
	setTextColor(jieju[0],0.9f,0.9f,0.9f);
	setText(jieju[0],"请按任意键退出\n");
	while(!ch){
		ch=getPressedKeyCode();
	}
	exit(0);

}

void gameMain(void)
{

	setGameTitle(" 魔 塔(Made by Mota Studio of JNU)");
	setGameSize(1080, 780);
	createImage(bgImg,"BEIJING.png");
	createSprite(Kaishi,"Kaishi");
	playSpriteAnimate(Kaishi,"1");
	MouseOperate();
	//finish();
	asyncRun(showmap,0);
	playSound("sndBGM.MP3",1);
	createSprite(ii,"ll");
	//createSprite(bird,"bird");
	playSpriteAnimate(ii,"attack3");
	//playSpriteAnimate(bird,"fly");
	setSpritePosition(ii,15,30);
	//setSpritePosition(bird,20,100);
	asyncRun(iiMove,0);
	asyncRun(GetPressedKeyCode,0);
	while(1);
	pauseGame(150000);
}

int main(void)
{
	rpInit(gameMain);
	return 0;
}


