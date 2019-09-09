/**********************************************************************
项目名称/Project          : 太乐1号 / TaiLe-1
程序名称/Program name     : TaiLe-1.cpp
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
#include <AFMotor.h>
#include "Tyler_1.h"

// 只提供车轮电机方向设置参数的构造函数
Tyler_1::Tyler_1(bool dir1, bool dir2, bool dir3, bool dir4){

  dcMotor1->setSpeed(DEFAULT_SPEED);
  dcMotor2->setSpeed(DEFAULT_SPEED);
  dcMotor3->setSpeed(DEFAULT_SPEED);
  dcMotor4->setSpeed(DEFAULT_SPEED);

  dcMotorIni( dir1,  dir2,  dir3,  dir4);
}

// 提供车轮电机方向设置参数，车轮电机速度参数的构造函数
Tyler_1::Tyler_1(bool dir1, bool dir2, bool dir3, bool dir4, byte motorSpeed){

  dcMotor1->setSpeed(motorSpeed);
  dcMotor2->setSpeed(motorSpeed);
  dcMotor3->setSpeed(motorSpeed);
  dcMotor4->setSpeed(motorSpeed);

  dcMotorIni( dir1,  dir2,  dir3,  dir4);
  
  
}

// 提供车轮电机方向设置参数，车轮电机速度参数， 测距传感器引脚参数的构造函数
Tyler_1::Tyler_1(bool dir1, bool dir2, bool dir3, bool dir4, byte motorSpeed, int trigPin, int echoPin){
  
  hcTrig = trigPin;
  hcEcho = echoPin;
 
  dcMotor1->setSpeed(motorSpeed);
  dcMotor2->setSpeed(motorSpeed);
  dcMotor3->setSpeed(motorSpeed);
  dcMotor4->setSpeed(motorSpeed);

  dcMotorIni( dir1,  dir2,  dir3,  dir4);


  pinMode(hcTrig, OUTPUT);
  pinMode(hcEcho, INPUT);  
}

// 提供车轮电机方向设置参数，车轮电机速度参数， 测距传感器引脚参数以及舵机控制引脚参数的构造函数
Tyler_1::Tyler_1(bool dir1, bool dir2, bool dir3, bool dir4, byte motorSpeed, int trigPin, int echoPin, int servoPin){
  
  headServoPin = servoPin;
  hcTrig = trigPin;
  hcEcho = echoPin;
  
  dcMotor1->setSpeed(motorSpeed);
  dcMotor2->setSpeed(motorSpeed);
  dcMotor3->setSpeed(motorSpeed);
  dcMotor4->setSpeed(motorSpeed);

  dcMotorIni( dir1,  dir2,  dir3,  dir4);

  pinMode(hcTrig, OUTPUT);
  pinMode(hcEcho, INPUT);  
}

// 初始化舵机
void Tyler_1::headServoIni(){
  headServo.attach(headServoPin);               
}

// 设置舵机位置
void Tyler_1::setHeadPos(int pos){
    headServo.write(pos);               
}

// 获取舵机位置
int Tyler_1::getHeadPos(){
    return headServo.read();               
}

// 读取传感器距离读数（单位为厘米）
int Tyler_1::getDistance(){
   
  digitalWrite(hcTrig, LOW);
  delayMicroseconds(5);
  digitalWrite(hcTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(hcTrig, LOW);

  duration = pulseIn(hcEcho, HIGH);
  cm = (duration/2) / 29.1;
  
  return cm;
}

// 车轮电机初始化(设置各个车轮转动方向，使其符合程序控制需要)
void Tyler_1::dcMotorIni(bool dir1, bool dir2, bool dir3, bool dir4){
  
  if (dir1 == 1){
    dcMotor1Forward = FORWARD;
    dcMotor1Backward = BACKWARD;
  } else {
    dcMotor1Forward = BACKWARD;
    dcMotor1Backward = FORWARD;
  }
  
  if (dir2 == 1){
    dcMotor2Forward = FORWARD;
    dcMotor2Backward = BACKWARD;
  } else {
    dcMotor2Forward = BACKWARD;
    dcMotor2Backward = FORWARD;
  }  

  if (dir3 == 1){
    dcMotor3Forward = FORWARD;
    dcMotor3Backward = BACKWARD;
  } else {
    dcMotor3Forward = BACKWARD;
    dcMotor3Backward = FORWARD;
  }

  if (dir4 == 1){
    dcMotor4Forward = FORWARD;
    dcMotor4Backward = BACKWARD;
  } else {
    dcMotor4Forward = BACKWARD;
    dcMotor4Backward = FORWARD;
  }    
}

// 前进
void Tyler_1::forward(){  
  dcMotor1->run(dcMotor1Forward);
  dcMotor2->run(dcMotor2Forward);  
  dcMotor3->run(dcMotor3Forward);
  dcMotor4->run(dcMotor4Forward);   
}

// 后退
void Tyler_1::backward(){
  dcMotor1->run(dcMotor1Backward);
  dcMotor2->run(dcMotor2Backward);
  dcMotor3->run(dcMotor3Backward);
  dcMotor4->run(dcMotor4Backward);  
}

// 左转
void Tyler_1::turnL(){
  dcMotor1->run(dcMotor1Forward);
  dcMotor2->run(dcMotor2Forward);
  dcMotor3->run(dcMotor3Backward);
  dcMotor4->run(dcMotor4Backward);    
}

// 右转
void Tyler_1::turnR(){
  dcMotor1->run(dcMotor1Backward);
  dcMotor2->run(dcMotor2Backward);
  dcMotor3->run(dcMotor3Forward);
  dcMotor4->run(dcMotor4Forward);       
}

// 左前
void Tyler_1::forwardL(){
  dcMotor1->run(dcMotor1Forward);   
  dcMotor2->run(dcMotor2Forward);   
  dcMotor3->run(RELEASE);
  dcMotor4->run(RELEASE);    
  
}

// 右前
void Tyler_1::forwardR(){
  dcMotor1->run(RELEASE);   
  dcMotor2->run(RELEASE);   
  dcMotor3->run(dcMotor3Forward);
  dcMotor4->run(dcMotor4Forward);  
}

// 左后
void Tyler_1::backwardL(){
  dcMotor1->run(RELEASE);   
  dcMotor2->run(RELEASE);   
  dcMotor3->run(dcMotor3Backward);
  dcMotor4->run(dcMotor4Backward);  
}

// 右后
void Tyler_1::backwardR(){
  dcMotor1->run(dcMotor1Backward);   
  dcMotor2->run(dcMotor2Backward);   
  dcMotor3->run(RELEASE);
  dcMotor4->run(RELEASE);    
}

// 停止
void Tyler_1::stop(){
  dcMotor1->run(RELEASE);
  dcMotor2->run(RELEASE);
  dcMotor3->run(RELEASE);
  dcMotor4->run(RELEASE);   
}
