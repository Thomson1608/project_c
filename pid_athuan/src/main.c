/*
 * main.c
 *
 *  Created on: Dec 4, 2015
 *      Author: minht_000
 */

#include "main.h"
int main()
{
	while(1)
	{
		Pid(665);
	}
	return 0;
}

void Pid(int32_t des_speed)
{
	printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("nhap vao Sensor: \n");
	fflush(stdout);///bo dem de nhan biet scanf
	scanf("%d",&sensor);
	// tinh so xung trong thoi gian lay mau
	Process_Value= sensor-Old_Pulse;
	// luu lai gia tri Pulse(so xung) de tinh so xung lan sau
	Old_Pulse= sensor;
	// tinh sai so
	Err = des_speed - fabs(sensor);
	printf("sensor = %d\n",sensor);
	printf("des_speed = %d\n",des_speed);
	printf("Err = %d\n",Err);
	fflush(stdout);///bo dem de nhan biet scanf
	if (Err > 0)
	{
		pPart=(Kp*Err);
		printf("pPart = %f\n",pPart);
		printf("tat chan dao \n ");
	}
	else
	{
		pPart=(Kp*(-Err));
		printf("pPart = %f\n",pPart);
		printf("bat chan dao \n ");
	}
	//********* khau PID*****************//
	printf("************** khau PID**********************\n");
	dPart=Kd*(Err-Old_Err)*Inv_Sampling_Time;
	printf("Err-Old_Err= %d\n",Err-Old_Err);
	printf("dPart = %d\n",dPart);
	iPart+= Ki*Sampling_Time*Err/1000;
	printf("iPart = %f\n",iPart);
	Out_Put = pPart + dPart + iPart;
	printf("Out_Put = %d\n",Out_Put);
	fflush(stdout);///bo dem de nhan biet scanf
	//***********************************//
	if(Out_Put>=300)
	{
			Out_Put=300;
	}

	if (Out_Put < 0)
	{
			Out_Put=0;
	}
	printf("cap xung cho motor: %d \n ",Out_Put);
	fflush(stdout);///bo dem de nhan biet scanf
	// luu lai gia tri sai so
	Old_Err=Err;
	printf("Old_Err = %d\n",Old_Err);
}
