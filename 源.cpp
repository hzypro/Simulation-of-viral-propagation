
#include <graphics.h>
#include <time.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include "全局变量.h"
#include "A.h"
#include "B.h"
#include "C.h"
#include "D.h"




/**************************/
/**************************/

int main() {
	int maski;
	printf("是否佩戴口罩？输入1：是； 输入0：否\n");
	scanf_s("%d", &maski);
	if (maski)
		Mask = 0.7;
	printf("\n设定隔离政策级别 输入0：不启用隔离； 输入1：美式隔离； 输入2：中式隔离\n");
	scanf_s("%d", &QL);

	srand((unsigned)time(NULL));
	initgraph(1000, 550,SHOWCONSOLE);
	setbkcolor(BackColor);
	cleardevice();
	Back();
	for (int i = 0; i < MAX; ++i) {
		InitP(i);
	}

	StartP();
	int c[2] = { 1 };//存放三个地区的临时统计数据

	BackChart();
	for (int Time = 0; Time < MTime*5; ++Time) {//开始传播，时限五天
		for (int i = 0; i < 3; ++i)
			count[i] = 0;
		for (int i = 0; i < MAX; ++i) {
			Spread(i);
			DrawP(i,Time);
			if (p[i].infect == 1) {
				++count[p[i].age];//若感染，相应年龄段的人数增加
			}
			QpLevel(i, Time, QL);
		}
		Sleep(1);
		DrawChart1(Time);
		if (Time % (MTime/48) == 0) {//每隔半小时采样统计一次
			int d = (Time / (MTime/2)) % 2;//表示处于哪个时间段（0：0-12； 1：12-24；）
			int d_Last = ((Time - MTime / 24) / (MTime / 2)) % 2;//上一次采样处于哪个时间段
			if((d-d_Last))
				c[d] = count[0] + count[1] + count[2];//当恰好跨区域时，更新数据,防止出现除0
			Avg_R0[d] = double(count[0] + count[1] + count[2]) / double(c[d]);
			DrawChart2(Time,d);
			c[d] = count[0] + count[1] + count[2];//更新临时地区数据

		}
		
	}
	system("pause");
	return 0;
}