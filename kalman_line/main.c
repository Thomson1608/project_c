/*
 * main.c
 *
 *  Created on: Dec 9, 2015
 *      Author: minht_000
 */

#include <stdio.h>

float Q = 0.100;
float R = 20;
float K;
float P;
float P_temp;
float x_temp_est;
float x_est;
float z_measured[20]={0,300,600,900,300,900,900,905,900,900,900,900,900,900,900,900,900,900,900,900}; //the 'noisy' value we measured
float z_real = 0; //the ideal value we wish to measure
float sum_error_kalman = 0;
float sum_error_measure = 0;
float x_est_last = 0;
float P_last = 0;
int main(void)
{
	int i=0;
	double LightValue=0;

	for(i=0;i<20;i++)
	{
		x_temp_est = x_est_last;
		P_temp = P_last + Q;
		//calculate the Kalman gain
		K = P_temp * ((float)(1.0/(P_temp + R)));
		//measure
//		z_measured = (float)((avg) / (sum));
		LightValue = x_temp_est + K * (z_measured[i] - x_temp_est);
		printf("kq :%f\n",LightValue);
		P = (1- K) * P_temp;
		P_last = P;

		//LightValue= (long) LightValue;
		x_est_last = LightValue;
	}

	return 0;
}

