/**********************************************************************
项目名称/Project          : 太乐1号 / Tyler-1
程序名称/Program name     : Tyler-1.h
团队/Team                 : 太极创客团队 / Taichi-Maker (www.taichi-maker.com)
作者/Author               : CYNO 朔 
日期/Date（YYYYMMDD）     : 20190719
程序目的/Purpose          : 
太乐1号是基于Arduino与乐高积木的创客智能模型车。该智能模型车旨在帮助创客朋友学习熟悉Arduino编程，
尤其是通过面向对象的方式开发Arduino。 
-----------------------------------------------------------------------
修订历史/Revision History  
日期/Date    作者/Author      参考号/Ref    修订说明/Revision Description
20190821	   CYNO朔			0.1			增加左后右后控制	

***********************************************************************/

#ifndef TYLER_1_H_
#define TYLER_1_H_

#include "Arduino.h"
#include <AFMotor.h>
#include <Servo.h>

#define DEFAULT_SPEED 255  //默认太乐1号行动速度

// 太乐1号类
class Tyler_1{
  public:
    // 只提供车轮电机方向设置参数的构造函数
    Tyler_1(bool dir1, bool dir2, bool dir3, bool dir4);
	
	// 提供车轮电机方向设置参数，车轮电机速度参数的构造函数
	Tyler_1(bool dir1, bool dir2, bool dir3, bool dir4, byte motorSpeed);
	
	// 提供车轮电机方向设置参数，车轮电机速度参数， 测距传感器引脚参数的构造函数
    Tyler_1(bool dir1, bool dir2, bool dir3, bool dir4, byte motorSpeed, int trigPin, int echoPin);
	
	// 提供车轮电机方向设置参数，车轮电机速度参数， 测距传感器引脚参数以及舵机控制引脚参数的构造函数
    Tyler_1(bool dir1, bool dir2, bool dir3, bool dir4, byte motorSpeed, int trigPin, int echoPin, int servoPin);
    
    void forward();				// 前进
    void backward();			// 后退
    void turnL();				// 左转
    void turnR();   			// 右转
    void forwardL();			// 左前
    void forwardR();			// 右前
    void backwardL();			// 左后
    void backwardR();			// 右后	
    void stop();                // 停车
    int getDistance();          // 获取距离传感器读数

    void setHeadPos(int pos);   // 设定舵机角度
    int getHeadPos();           // 获取舵机角度

    void headServoIni();  		// 舵机初始化
      
  private:
    void dcMotorIni(bool dir1, bool dir2, bool dir3, bool dir4);  // 车轮电机初始化设置
	
    AF_DCMotor* dcMotor1 = new AF_DCMotor(1);					  // 车轮电机1
    AF_DCMotor* dcMotor2 = new AF_DCMotor(2);					  // 车轮电机2
    AF_DCMotor* dcMotor3 = new AF_DCMotor(3);					  // 车轮电机3
    AF_DCMotor* dcMotor4 = new AF_DCMotor(4);					  // 车轮电机4

    Servo headServo;     	// 建立头部舵机对象
    int headServoPin;     	// 舵机控制引脚
    
    byte dcMotor1Forward;		// 车轮电机1正转参数
    byte dcMotor1Backward;		// 车轮电机1反转参数
    byte dcMotor2Forward;		// 车轮电机2正转参数
    byte dcMotor2Backward;		// 车轮电机2反转参数
    byte dcMotor3Forward;		// 车轮电机3正转参数
    byte dcMotor3Backward;		// 车轮电机3反转参数
    byte dcMotor4Forward;		// 车轮电机4正转参数
    byte dcMotor4Backward; 		// 车轮电机4反转参数   

    int hcTrig;  // 超声测距传感器Trig引脚
    int hcEcho;  // 超声测距传感器Echo引脚
    long duration, cm;   // 超声测距传感器用变量
};
#endif  
