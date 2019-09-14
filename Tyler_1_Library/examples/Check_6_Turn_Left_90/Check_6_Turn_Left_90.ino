/**********************************************************************
项目名称/Project          : 太乐1号 / Tyler-1
程序名称/Program name     : Check_6_Turn_Left_90
团队/Team                : 太极创客团队 / Taichi-Maker (www.taichi-maker.com)
作者/Author              : CYNO 朔 
日期/Date（YYYYMMDD）     : 20190721
程序目的/Purpose          : 
本程序用于找到太乐一号向左转动90度角度所需要的TURN_LEFT_90参数数值
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

#define TURN_LEFT_90   800

// 建立太乐1号对象。其中对象参数分别是：
// (车轮电机1运转方向, 车轮电机2运转方向, 车轮电机3运转方向, 车轮电机4运转方向,
// 车轮电机运转速度，测距传感器TRIG引脚， 测距传感器ECHO引脚，头部舵机信号引脚 )
Tyler_1 tyler_1(1, 1, 1, 1, 200, A0, A1, 10); 

void setup() {
  
}

void loop() {
  tyler_1.turnL();  
  delay(TURN_LEFT_90);
  tyler_1.stop();   
  delay(2000);         
}
