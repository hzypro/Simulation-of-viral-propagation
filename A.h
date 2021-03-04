#pragma once
#include "ȫ�ֱ���.h"

void InitP(int i) { //��ʼ��p
	if (i < 0.2 * MAX)
		p[i].age = YOUNG;//20%������
	else if (i < 0.7 * MAX)
		p[i].age = MIDDLE;//55%������
	else
		p[i].age = OLD;//������ֲ���������
	p[i].Ax = p[i].x = rand() % 700 + 50;
	p[i].Ay = p[i].y = rand() % 200 + 50;
	p[i].Bx = rand() % 150 + 200;
	p[i].By = rand() % 150 + 350;
	p[i].infect = NO;
	p[i].color = GREEN;
	p[i].quarantine = 0;
}


void StartP() {
	p[0].infect = YES;
	p[0].color = RED;//����������1������
	p[0].x = 300;
	p[0].y = 150;
	p[300].infect = YES;
	p[300].color = RED;//����������2��׳��
	p[300].x = 500;
	p[300].y = 150;

}

int MoveP(int i, int time) { //�ƶ���i������p[i]
	if (p[i].quarantine)
		return 0;
	int tx = 0, ty = 0, distance;
	double active = 1;//tx,tyΪ������ֵƫ�ã�activeΪ��Ծϵ��
	if (0 <= (time % MTime) && (time % MTime) < (MTime / 2)) {
		if (p[i].x < p[i].Bx)tx = 3;//�ƶ���ֵ
		if (p[i].x > p[i].Bx)tx = -3;
		if (p[i].y < p[i].By)ty = 2;
		if (p[i].y > p[i].By)ty = -2;
		distance = pow((p[i].x - p[i].Bx), 2) + pow((p[i].y - p[i].By), 2);
		//���������Ŀ��ľ���
	}
	if ((MTime / 2) <= (time % MTime) && (time % MTime) < (MTime)) {
		if (p[i].x < p[i].Ax)tx = 3;
		if (p[i].x > p[i].Ax)tx = -3;
		if (p[i].y < p[i].Ay)ty = 2;
		if (p[i].y > p[i].Ay)ty = -2;
		distance = pow((p[i].x - p[i].Ax), 2) + pow((p[i].y - p[i].Ay), 2);
	}
	if (distance < 2)//���ǳ��ӽ�����λ�ã���Ծϵ����0.5
		active = 0.5;
	p[i].x += active * ((rand() % 11 - 5) + tx);//����λ�ã�������λ���ƶ�
	if (p[i].x < 5)p[i].x += 5;//�߽���ײ��⣬��ֹԽ��
	if (p[i].x > 795)p[i].x -= 5;
	p[i].y += active * ((rand() % 11 - 5) + ty);
	if (p[i].y < 5)p[i].y += 5;
	if (p[i].y > 595)p[i].y -= 5;
	return 1;
}

