#include <stdio.h>

void main()
{
    double attack = 57.88;          //伤害值
    double attackAdd = 4.5;         //伤害增加值
    int attackRange = 172;          //攻击距离
    double hujia = 27.536;          //护甲
    double hujiaAdd = 3.0;          //护甲加成
    double mokang = 32.1;           //魔抗
    double mokangAdd =1.25;       //魔抗加成
    double sm = 616.28;             //生命
    double smAdd = 84.25;           //生命加成
    double smhf = 7.84;             //生命回复
    double smhfAdd = 0.5;           //生命回复加成
    int fl = 0;                     //法力
    int flAdd= 0;                   //法力加成
    int flhf = 0;                   //法力回复
    int flhfAdd = 0;                //法力回复加成
    int ys = 340;                   //移动速度
    int dq = 450;                  //点券价格
    int jb = 1000;                  //金币数量
    printf("名称:德玛西亚之力`盖伦\n");
    printf("伤害：%.2lf(+%.2lf)\t攻击距离：%d\n",attack,attackAdd,attackRange);
    printf("护甲:%.2lf(+%.2lf)\t魔抗:%.2lf(+%.2lf)\n",hujia,hujiaAdd,mokang,mokangAdd);
    printf("生命:%.2lf(+%.2lf)\t生命回复:%.2lf(+%.2lf)\n",sm,smAdd,smhf,smhfAdd);
    printf("法力:%d(+%d)\t\t法力回复:%d(+%d)\n",fl,flAdd,flhf,flhfAdd);
    printf("移速:%d\t\t定位:上单 打野 辅助\n",ys);
    printf("金币:%d\t\t点券:%d\n",dq,jb);
}
