#define MAX 500	// ������
#define MTime 336   //һ��ʱ��,�趨Ϊ24�ı���
#define YES 1
#define NO 0
#define E 2.71 //��Ȼ����
#define YOUNG 0 //�����־
#define MIDDLE 1
#define OLD 2
#define YOUNG_RATE 0.5 //��������ϵ�����Ը�����εĸ�Ⱦ���ʽ�������
#define MIDDLE_RATE 1.4
#define OLD_RATE 0.6
#define BackColor (RGB(20,20,20)) //������ɫ

struct PEOPLE {
	int x;
	int y;
	int infect;//�Ƿ��Ⱦ
	int quarantine;//�Ƿ����
	int age;//�����
	unsigned long color;//��ɫ
	int Ax, Ay;//���ܶ���������λ��
	int Bx, By;//���ܶ���������λ��
};

PEOPLE p[MAX];
int count[3] = { 0 };              /***��Ҫָ��1�������ǵ�������������θ�Ⱦ����***/
double Avg_R0[2] = { 1.0,1.0 };   /***��Ҫָ��2�����������䣬����������R0�ܾ�ֵ***/
double Age_Rate[3] = { YOUNG_RATE ,MIDDLE_RATE,OLD_RATE };//�����������ϵ��
double Mask = 1.0; //��������ϵ��
int QL;//�趨�ĸ�������ǿ��
#pragma once
