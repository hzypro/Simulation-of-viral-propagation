#define MAX 500	// 总人数
#define MTime 336   //一天时长,设定为24的倍数
#define YES 1
#define NO 0
#define E 2.71 //自然对数
#define YOUNG 0 //年龄标志
#define MIDDLE 1
#define OLD 2
#define YOUNG_RATE 0.5 //年龄修正系数，对该年龄段的感染概率进行修正
#define MIDDLE_RATE 1.4
#define OLD_RATE 0.6
#define BackColor (RGB(20,20,20)) //背景颜色

struct PEOPLE {
	int x;
	int y;
	int infect;//是否感染
	int quarantine;//是否隔离
	int age;//年龄段
	unsigned long color;//颜色
	int Ax, Ay;//低密度区的期望位置
	int Bx, By;//高密度区的期望位置
};

PEOPLE p[MAX];
int count[3] = { 0 };              /***重要指标1！不考虑地区，各个年龄段感染人数***/
double Avg_R0[2] = { 1.0,1.0 };   /***重要指标2！不考虑年龄，各个地区的R0总均值***/
double Age_Rate[3] = { YOUNG_RATE ,MIDDLE_RATE,OLD_RATE };//存放年龄修正系数
double Mask = 1.0; //口罩修正系数
int QL;//设定的隔离政策强度
#pragma once
