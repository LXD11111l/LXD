#include "labelfactory.h"

LabelFactory::LabelFactory()
{

    for(int val = 1; val < 256; ++val){
        if(val>=201){ source[val] = ":/picture/Mota.png";}
        if(val>=1 && val<=4){ source[val] = ":/picture/Characters/men001.png";}
        if(val>=5 && val<=8){ source[val] = ":/picture/Characters/men002.png";}
        if(val>=9 && val<=12){ source[val] = ":/picture/Characters/men003.png";}
        if(val>=13 && val<=20){ source[val] = ":/picture/Characters/item01.png";}
        if(val>=21 && val<=24){ source[val] = ":/picture/Characters/item02.png";}
        if(val>=25 && val<=36){ source[val] = ":/picture/Characters/item03.png";}
        if(val>=37 && val<=40){ source[val] = ":/picture/Characters/item04.png";}
        if(val>=41 && val<=44){ source[val] = ":/picture/Characters/003-Monster01.png";}
        if(val>=45 && val<=48){ source[val] = ":/picture/Characters/004-Monster02.png";}
        if(val>=49 && val<=52){ source[val] = ":/picture/Characters/005-Monster03.png";}
        if(val>=53 && val<=56){ source[val] = ":/picture/Characters/006-Monster04.png";}
        if(val>=57 && val<=60){ source[val] = ":/picture/Characters/007-Monster05.png";}
        if(val>=61 && val<=64){ source[val] = ":/picture/Characters/008-Monster06.png";}
        if(val>=65 && val<=68){ source[val] = ":/picture/Characters/009-Monster07.png";}
        if(val>=69 && val<=72){ source[val] = ":/picture/Characters/010-Monster08.png";}
        if(val>=73 && val<=76){ source[val] = ":/picture/Characters/011-Monster091.png";}
        if(val>=77 && val<=80){ source[val] = ":/picture/Characters/014-Monster11.png";}
        if(val>=81 && val<=84){ source[val] = ":/picture/Characters/014-Monster12.png";}

        if(val>=101 && val<=104){ source[val] = ":/picture/Characters/001-npc01.png";}
        if(val>=105 && val<=108){ source[val] = ":/picture/Characters/001-npc01.png";}
    }

    rect[254] = QPoint(0, 992);//下楼
    rect[255] = QPoint(32, 992);//上楼
    rect[1] = QPoint(0, 0);//黄门
    rect[2] = QPoint(32, 0);//蓝门
    rect[3] = QPoint(64, 0);//红门
    rect[4] = QPoint(96, 0);//铁门
    rect[6] = QPoint(32, 0);//墙
    rect[10] = QPoint(32, 0);//岩浆
    rect[12] = QPoint(96, 0);//牢房
    rect[13] = QPoint(0, 0);//黄钥匙
    rect[14] = QPoint(32, 0);//蓝钥匙
    rect[15] = QPoint(64, 0);//红钥匙
    rect[16] = QPoint(96, 0);//绿钥匙
    rect[17] = QPoint(0, 96);//怪物手册
    rect[18] = QPoint(32, 96);//记事本
    rect[19] = QPoint(64, 96);//楼层跳跃器
    rect[20] = QPoint(96, 96);//金币
    rect[21] = QPoint(0, 0);//锄头
    rect[22] = QPoint(0, 32);//中心对称飞行器
    rect[23] = QPoint(0, 64);//炸药
    rect[25] = QPoint(0, 0);//红宝石
    rect[26] = QPoint(32, 0);//蓝宝石
    rect[27] = QPoint(64, 0);//绿宝石
    rect[28] = QPoint(96, 0);//黄宝石
    rect[29] = QPoint(0, 32);//红药水
    rect[30] = QPoint(32, 32);//蓝药水
    rect[31] = QPoint(64, 32);//绿药水
    rect[32] = QPoint(96, 32);//黄药水
    rect[37] = QPoint(0, 0);//铁剑
    rect[38] = QPoint(32, 0);//银剑
    rect[39] = QPoint(0, 64);//铁盾
    rect[40] = QPoint(32, 64);//银盾
    rect[41] = QPoint(0, 0);//绿色史莱姆
    rect[42] = QPoint(0, 32);//红色史莱姆
    rect[43] = QPoint(0, 64);//黑色史莱姆
    rect[44] = QPoint(0, 96);//大史莱姆
    rect[45] = QPoint(0, 0);//小蝙蝠
    rect[46] = QPoint(0, 32);//大蝙蝠
    rect[47] = QPoint(0, 64);//红蝙蝠
    rect[48] = QPoint(0, 96);//暗夜魔王
    rect[49] = QPoint(0, 0);//骷髅怪
    rect[50] = QPoint(0, 32);//骷髅士兵
    rect[51] = QPoint(0, 64);//骷髅队长
    rect[52] = QPoint(0, 96);//骷髅统领
    rect[53] = QPoint(0, 0);//兽人
    rect[54] = QPoint(0, 32);//兽人士兵
    rect[55] = QPoint(0, 64);//石头人
    rect[56] = QPoint(0, 96);//幽灵
    rect[57] = QPoint(0, 0);//初级法师
    rect[58] = QPoint(0, 32);//高级法师
    rect[59] = QPoint(0, 64);//褐衣法师
    rect[60] = QPoint(0, 96);//红衣法师
    rect[61] = QPoint(0, 0);//初级守卫
    rect[62] = QPoint(0, 32);//中级守卫
    rect[63] = QPoint(0, 64);//高级守卫
    rect[64] = QPoint(0, 96);//双剑杀手
    rect[65] = QPoint(0, 0);//甲胄武士
    rect[66] = QPoint(0, 32);//初级士兵
    rect[67] = QPoint(0, 64);//高级士兵
    rect[68] = QPoint(0, 96);//冥卫兵
    rect[69] = QPoint(0, 0);//红衣武士
    rect[70] = QPoint(0, 32);//青衣武士
    rect[71] = QPoint(0, 64);//灵法师
    rect[72] = QPoint(0, 96);//银色史莱姆
    rect[73] = QPoint(0, 0);//终极法师
    rect[76] = QPoint(0, 96);//变异兽人
    rect[77] = QPoint(0, 0);//黑衣魔王
    rect[101] = QPoint(0, 0);//老头
    rect[102] = QPoint(0, 32);//商人
    rect[103] = QPoint(0, 64);//小偷
    rect[104] = QPoint(0, 96);//仙子
    rect[107] = QPoint(0, 64);//商店
    rect[108] = QPoint(0, 96);//公主
    rect[201] = QPoint(96, 992);//商店左
    rect[202] = QPoint(160, 992);//商店右
    rect[220] = QPoint(0,0);//战斗
    for(int i = 0; i < 60; ++i){
        MON mon;
        monsterdata[i] = mon;
    }
}

RoleLable *LabelFactory::creatLabel(QWidget* parent, int id, QPoint p)
{
    if(id == 0) return nullptr;
    RoleLable * label = new RoleLable(parent, source[id], p);
    label->setPicture(rect[id]);
    label->setType(id);
    return label;
}
