
#include <graphics.h>
#include <time.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include "ȫ�ֱ���.h"
#include "A.h"
#include "B.h"
#include "C.h"
#include "D.h"




/**************************/
/**************************/

int main() {
	int maski;
	printf("�Ƿ�������֣�����1���ǣ� ����0����\n");
	scanf_s("%d", &maski);
	if (maski)
		Mask = 0.7;
	printf("\n�趨�������߼��� ����0�������ø��룻 ����1����ʽ���룻 ����2����ʽ����\n");
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
	int c[2] = { 1 };//���������������ʱͳ������

	BackChart();
	for (int Time = 0; Time < MTime*5; ++Time) {//��ʼ������ʱ������
		for (int i = 0; i < 3; ++i)
			count[i] = 0;
		for (int i = 0; i < MAX; ++i) {
			Spread(i);
			DrawP(i,Time);
			if (p[i].infect == 1) {
				++count[p[i].age];//����Ⱦ����Ӧ����ε���������
			}
			QpLevel(i, Time, QL);
		}
		Sleep(1);
		DrawChart1(Time);
		if (Time % (MTime/48) == 0) {//ÿ����Сʱ����ͳ��һ��
			int d = (Time / (MTime/2)) % 2;//��ʾ�����ĸ�ʱ��Σ�0��0-12�� 1��12-24����
			int d_Last = ((Time - MTime / 24) / (MTime / 2)) % 2;//��һ�β��������ĸ�ʱ���
			if((d-d_Last))
				c[d] = count[0] + count[1] + count[2];//��ǡ�ÿ�����ʱ����������,��ֹ���ֳ�0
			Avg_R0[d] = double(count[0] + count[1] + count[2]) / double(c[d]);
			DrawChart2(Time,d);
			c[d] = count[0] + count[1] + count[2];//������ʱ��������

		}
		
	}
	system("pause");
	return 0;
}