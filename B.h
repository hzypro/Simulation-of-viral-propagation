#include "全局变量.h"
#include "A.h"


double Sigmoid(int count) {//基本感染率函数，基本感染率与同一一时间点密切接触人数相关
	return 1.0 / (1 + pow(E, -count)) - 0.50;
}
int Spread(int i) { //病毒传播函数，用于判定p[i]是否感染
	if (p[i].infect == YES)return 0;//若自身已经感染，不考虑自己被传播。
	int distance, count = 0;//此count变量用于计算密切接触人数
	double rate;//综合感染率
	for (int j = 0; j < MAX; ++j) {
		int t1 = p[i].x - p[j].x, t2 = p[i].y - p[j].y;
		distance = pow(t1, 2) + pow(t2, 2);
		if (distance < 6 && p[j].infect == TRUE && !p[j].quarantine)//大致认为，距离在1像素点内，视为密切接触
			++count;
	}
	rate = Mask * Age_Rate[p[i].age] * 30.0 * Sigmoid(count);//综合感染率,*30将Sigomoid函数值域放大至[0,30]
	if ((rand() % 100) < rate) {
		p[i].infect = 1;//被感染
		p[i].color = RED;//对被感染者，改变粒子颜色
	}
	return 1;
}