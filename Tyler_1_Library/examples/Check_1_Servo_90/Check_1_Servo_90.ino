/**********************************************************************
项目名称/Project           : 太乐1号 / Tyler-1
程序名称/Program name      : Check_1_Servo_90
团队/Team                 : 太极创客团队 / Taichi-Maker (www.taichi-maker.com)
作者/Author               : CYNO 朔 
日期/Date（YYYYMMDD）      : 20190716
程序目的/Purpose           : 
在太乐1号组装过程中，需要将舵机调整为90度位置。此程序用于将舵机调整为90度位置。
-----------------------------------------------------------------------
修订历史/Revision History  
日期/Date    作者/Author      参考号/Ref    修订说明/Revision Description
-----------------------------------------------------------------------
电路连接：
    舵机    -------   Arduino
    +5V    -------    +5VDC
    GND    -------     GND
    信号    -------     10    
***********************************************************************/
#include "Tyler_1.h"

Tyler_1 tyler_1(1, 1, 1, 1, 200, A0, A1, 10);      // 建立太乐1号对象

void setup() {
  tyler_1.headServoIni();  //头部舵机初始化       
}

void loop() {
       
	tyler_1.setHeadPos(90);
	delay(1000);
}
