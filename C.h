#include <graphics.h>
#include <time.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include "ȫ�ֱ���.h"


void Qp(int i) {//����Ⱦ�����ڸ�����
	setfillcolor(BackColor);
	solidcircle(p[i].x, p[i].y, 1);//�ȸ���ԭλ��
	p[i].quarantine = YES;
	p[i].x = rand() % 99 + 555;
	p[i].y = rand() % 99 + 405;
}

int QpLevel(int i, int Time, int Level) {//���뺯��
	if (Level == 0            //����1.δ���ø���
		|| Time < MTime / (Level + 1) //2.δ���ü����Ӧ�Ŀ�ʼ���ø���ʱ�䣨1����24
		|| p[i].infect == NO      //3.δ��Ⱦ
		|| p[i].quarantine == YES //4.�Ѹ���
		|| Time % 4)         //5. �������Time���һ��
		return 0;
	int t = 10 / Level + 85;//���롰ǿ���ԡ�ϵ��������Խ��Խ��
	if (rand() % 100 > t)
		Qp(i);
}
