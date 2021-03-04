#include <graphics.h>
#include <time.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include "ȫ�ֱ���.h"
#include "A.h"

void Back() { //���Ʊ���1���ⲿ�ֱ�����Ҫ��֡�ػ�
	setlinecolor(RGB(100, 100, 100));
	setlinestyle(PS_DASH | PS_ENDCAP_FLAT, 2);
	POINT pts1[] = { {50,50},{750, 50},{750,250} ,{50, 250} };
	polygon(pts1, 4);
	POINT pts2[] = { {200,350},{350, 350},{350,500} ,{200, 500} };
	polygon(pts2, 4);
	POINT pts3[] = { {550,400},{650, 400},{650,500} ,{550, 500} };
	polygon(pts3, 4);
	settextstyle(16, 0, _T("Consolas"));
	RECT r1 = { 300, 100, 500, 200 };//���α߽磨���ϣ��ң��£�
	settextstyle(22, 0, _T("����"));
	drawtext(_T("�� �� �� ��"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	RECT r2 = { 200, 350, 350, 500 };
	drawtext(_T("�� �� �� ��"), &r2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	RECT r3 = { 550, 400, 650, 500 };
	drawtext(_T("�� �� ��"), &r3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}

void DrawP(int i, int time) { //���Ƶ�p
	setfillcolor(BackColor);
	solidcircle(p[i].x, p[i].y, 1);//����ԭλ��
	Back();
	MoveP(i, time);
	setfillcolor(p[i].color);
	solidcircle(p[i].x, p[i].y, 1);//������λ��

}

void BackChart() {//����ͼ��������̬
	//Chart1
	setfillcolor(RGB(200, 150, 0));
	solidrectangle(780, 200, 790, 210);//ͼ��1
	setfillcolor(RGB(200, 100, 0));
	solidrectangle(780, 218, 790, 228);//ͼ��2
	setfillcolor(RGB(200, 50, 0));
	solidrectangle(780, 236, 790, 246);//ͼ��3
	settextstyle(16, 0, _T("����"));
	outtextxy(780, 180, _T("������׶θ�Ⱦ������"));
	outtextxy(800, 197, _T("����"));
	outtextxy(800, 215, _T("׳��"));
	outtextxy(800, 233, _T("����"));

	outtextxy(100, 10, _T("ʱ�䣺"));
	outtextxy(170, 10, _T("Сʱ"));
	outtextxy(220, 10, _T("�ܸ�Ⱦ������"));
	outtextxy(460, 10, _T("�������ߣ�"));
	if (Mask < 1)
		outtextxy(550, 10, _T("�������"));
	else
		outtextxy(550, 10, _T("��������"));
	if (QL == 0)
		outtextxy(630, 10, _T("�����и���"));
	else if (QL == 1)
		outtextxy(630, 10, _T("��ʽ����"));
	else
		outtextxy(630, 10, _T("��ʽ����"));
	setlinecolor(WHITE);
	setlinestyle(PS_SOLID, 2);
	line(800, 501, 950, 501);
	line(800, 501, 800, 280);
	line(765, 20, 765, 530);//������
	line(765, 170, 950, 170);//������
	settextstyle(14, 0, _T("Consolas"));
	outtextxy(790, 495, _T("0"));
	outtextxy(782, 445, _T("50"));
	outtextxy(775, 395, _T("100"));
	outtextxy(775, 345, _T("150"));
	outtextxy(775, 295, _T("200"));


	//Chart2
	settextstyle(16, 0, _T("����"));
	outtextxy(780, 50, _T("��������R0ֵ�仯�����"));
	setfillcolor(RGB(20, 20, 250));
	solidrectangle(780, 85, 790, 95);//ͼ��1
	settextstyle(15, 0, _T("����"));
	outtextxy(800, 84, _T("R0ֵ1"));
	setfillcolor(RGB(10, 10, 180));
	solidrectangle(780, 135, 790, 145);//ͼ��2
	outtextxy(800, 134, _T("R0ֵ2"));


}
void DrawChart1(int Time) {//����ͳ��ͼ1
	setfillcolor(RGB(200, 150, 0));
	solidrectangle(810, 500 - count[0], 835, 500);

	setfillcolor(RGB(200, 100, 0));
	solidrectangle(860, 500 - count[1], 885, 500);

	setfillcolor(RGB(200, 50, 0));
	solidrectangle(910, 500 - count[2], 935, 500);
	settextstyle(16, 0, _T("Consolas"));
	TCHAR s[5];
	swprintf_s(s, _T("%d"), count[0]);
	outtextxy(850, 197, s);//�����Ⱦ����
	swprintf_s(s, _T("%d"), count[1]);
	outtextxy(850, 215, s);//׳���Ⱦ����
	swprintf_s(s, _T("%d"), count[2]);
	outtextxy(850, 233, s);//�����Ⱦ����
	swprintf_s(s, _T("%02d"), Time / 14);
	settextstyle(18, 0, _T("Consolas"));
	outtextxy(148, 11, s);//��ʾʱ��
	swprintf_s(s, _T("%03d"), count[0] + count[1] + count[2]);
	settextcolor(LIGHTRED);
	outtextxy(323, 11, s);
	settextcolor(WHITE);
}

int DrawChart2(int Time, int d) {//����ͳ��ͼ2
	if (Time == 0)
		return 0;
	static int Location1 = 860;//����1��ʼ������
	static int Location2 = 860;//����2��ʼ������
	outtextxy(460, 10, _T("R0"));
	outtextxy(460, 10, _T("�������ߣ�"));
	if (d == 0) {
		setlinecolor(RGB(20, 20, 250));
		setlinestyle(PS_SOLID, 2);
		Location1 += 2;
		line(Location1, 100, Location1, 80 - 20 * (Avg_R0[d] - 1));
	}
	if (d == 1) {
		setlinecolor(RGB(10, 10, 180));
		setlinestyle(PS_SOLID, 2);
		Location2 += 2;
		line(Location2, 150, Location2, 130 - 20 * (Avg_R0[d] - 1));
	}

}
