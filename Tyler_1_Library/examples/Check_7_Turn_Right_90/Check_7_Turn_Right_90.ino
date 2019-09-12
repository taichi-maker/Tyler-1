/**********************************************************************
项目名称/Project          : 太乐1号 / Tyler-1
程序名称/Program name     : Check_7_Turn_Right_90
团队/Team                : 太极创客团队 / Taichi-Maker (www.taichi-maker.com)
作者/Author              : CYNO 朔 
日期/Date（YYYYMMDD）     : 20190721
程序目的/Purpose          : 
本程序用于找到太乐一号向右转动90度角度所需要的TURN_RIGHT_90参数数值
-----------------------------------------------------------------------
修订历史/Revision History  
日期/Date    作者/Author      参考号/Ref    修订说明/Revision Description
-----------------------------------------------------------------------
电路连接：
  Arduino AFMOTOR SERVO2引脚（Arduino引脚9）连接 HC06-TX
  Arduino A0引脚 连接 HCSR04的 trig 引脚
  Arduino A1引脚 连接 HCSR04的 echo 引脚
***********************************************************************/
#include "Tyler_1.h"

#define TURN_RIGHT_90   1000

Tyler_1 tyler_1(1, 1, 1, 1, 255);        // 通过改变此处参数调整电机旋转方向 以及电机速度控制
                                         // 调整最终目的是让车前进运行，（M1,M2 顺时针，M3,M4,逆时针）
                                         // 此处建立对象的前四个参数分别控制四个电机的旋转方向。
                                         // 最后一个参数用于控制电机速度。用户可用该参数找到喜欢的太乐1号速度数值。
void setup() {
  
}

void loop() {
  tyler_1.turnR();  
  delay(TURN_RIGHT_90);
  tyler_1.stop();   
  delay(2000);         
}
