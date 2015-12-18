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

float Kp=0.343; //1
float Kd=400; //17.3
float Ki=0.0000; //0.0015;
int LightValue=0;
//pid degiskenleri
int solmotor=0;
int sagmotor=0;
volatile float integral=0,lastError=0,derivative=0,Turn=0;
volatile float Error=0;
volatile float ref=3500;
volatile int16_t Tp=0;
int donus=0;
int duzgit=0;

#endif /* MAIN_H_ */
