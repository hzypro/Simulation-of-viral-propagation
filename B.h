#include "ȫ�ֱ���.h"
#include "A.h"


double Sigmoid(int count) {//������Ⱦ�ʺ�����������Ⱦ����ͬһһʱ������нӴ��������
	return 1.0 / (1 + pow(E, -count)) - 0.50;
}
int Spread(int i) { //�������������������ж�p[i]�Ƿ��Ⱦ
	if (p[i].infect == YES)return 0;//�������Ѿ���Ⱦ���������Լ���������
	int distance, count = 0;//��count�������ڼ������нӴ�����
	double rate;//�ۺϸ�Ⱦ��
	for (int j = 0; j < MAX; ++j) {
		int t1 = p[i].x - p[j].x, t2 = p[i].y - p[j].y;
		distance = pow(t1, 2) + pow(t2, 2);
		if (distance < 6 && p[j].infect == TRUE && !p[j].quarantine)//������Ϊ��������1���ص��ڣ���Ϊ���нӴ�
			++count;
	}
	rate = Mask * Age_Rate[p[i].age] * 30.0 * Sigmoid(count);//�ۺϸ�Ⱦ��,*30��Sigomoid����ֵ��Ŵ���[0,30]
	if ((rand() % 100) < rate) {
		p[i].infect = 1;//����Ⱦ
		p[i].color = RED;//�Ա���Ⱦ�ߣ��ı�������ɫ
	}
	return 1;
}