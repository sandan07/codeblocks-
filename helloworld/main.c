#include <stdio.h>

void main()
{
    double attack = 57.88;          //�˺�ֵ
    double attackAdd = 4.5;         //�˺�����ֵ
    int attackRange = 172;          //��������
    double hujia = 27.536;          //����
    double hujiaAdd = 3.0;          //���׼ӳ�
    double mokang = 32.1;           //ħ��
    double mokangAdd =1.25;       //ħ���ӳ�
    double sm = 616.28;             //����
    double smAdd = 84.25;           //�����ӳ�
    double smhf = 7.84;             //�����ظ�
    double smhfAdd = 0.5;           //�����ظ��ӳ�
    int fl = 0;                     //����
    int flAdd= 0;                   //�����ӳ�
    int flhf = 0;                   //�����ظ�
    int flhfAdd = 0;                //�����ظ��ӳ�
    int ys = 340;                   //�ƶ��ٶ�
    int dq = 450;                  //��ȯ�۸�
    int jb = 1000;                  //�������
    printf("����:��������֮��`����\n");
    printf("�˺���%.2lf(+%.2lf)\t�������룺%d\n",attack,attackAdd,attackRange);
    printf("����:%.2lf(+%.2lf)\tħ��:%.2lf(+%.2lf)\n",hujia,hujiaAdd,mokang,mokangAdd);
    printf("����:%.2lf(+%.2lf)\t�����ظ�:%.2lf(+%.2lf)\n",sm,smAdd,smhf,smhfAdd);
    printf("����:%d(+%d)\t\t�����ظ�:%d(+%d)\n",fl,flAdd,flhf,flhfAdd);
    printf("����:%d\t\t��λ:�ϵ� ��Ұ ����\n",ys);
    printf("���:%d\t\t��ȯ:%d\n",dq,jb);
}
