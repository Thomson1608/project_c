/*
 * main.h
 *
 *  Created on: Dec 4, 2015
 *      Author: minht_000
 */

#ifndef MAIN_H_
#define MAIN_H_
#include <stdio.h>
#include <math.h>

#define sampling_time 10
#define inv_sampling_time 100
#define pwm_period 665
#define KP 3
#define KI 0.5
#define KD 0.05
#define _dt_ 0.5
 int pulse;
 int previous_pulse=0;
 int previous_error = 0;
 int error=0;
 int speed=0;
 int ctrl_speed=0;
 float p=0.0;
 float i=0.0;
 float d=0.0;
 int output=0;

//	extern void EncodersRead(void);
 int Old_Pulse=0;
 int Err=0;
 float Old_Err=0;
 float Kp=2;
 float Kd=0.01;
 float Ki=0.01;
 float pPart=0;
 int dPart=0;
 float iPart=0;
 long Out_Put=0;
 int Sampling_Time=10;			   	//ms
 int Inv_Sampling_Time=10;	  	// 	1/ms
 int Set_Point =0;
 int Process_Value=0;
 volatile long fwdTotal;
 volatile uint sensor;

	void Pid(int32_t des_speed);

#endif /* MAIN_H_ */
