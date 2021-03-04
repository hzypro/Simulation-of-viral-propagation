#include <graphics.h>
#include <time.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include "全局变量.h"


void Qp(int i) {//将感染者置于隔离区
	setfillcolor(BackColor);
	solidcircle(p[i].x, p[i].y, 1);//先覆盖原位置
	p[i].quarantine = YES;
	p[i].x = rand() % 99 + 555;
	p[i].y = rand() % 99 + 405;
}

int QpLevel(int i, int Time, int Level) {//隔离函数
	if (Level == 0            //当：1.未启用隔离
		|| Time < MTime / (Level + 1) //2.未到该级别对应的开始启用隔离时间（1级：24
		|| p[i].infect == NO      //3.未感染
		|| p[i].quarantine == YES //4.已隔离
		|| Time % 4)         //5. 间隔三个Time检测一次
		return 0;
	int t = 10 / Level + 85;//隔离“强制性”系数，级别越高越大
	if (rand() % 100 > t)
		Qp(i);
}
