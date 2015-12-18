/*
 * main.c
 *
 *  Created on: Dec 4, 2015
 *      Author: minht_000
 */


#include "main.h"

int main()
{


	while (1){
		printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		printf("nhap vao gia tri can set \n ");
		fflush(stdout);///bo dem de nhan biet scanf
		scanf("%d",&LightValue);
		Error = (float) ((float)ref - (float)LightValue);        //! calculate the error by subtracting the offset
		integral = integral + Error;        //! calculate the integral
		if(integral>40000)
			integral=40000;

		if(integral<(-40000))
		integral=(-40000);
		derivative = (float) (Error - lastError);     //! calculate the derivative
		Turn = Kp*Error + Kd*derivative + Ki*integral;;  //! the "P term" the "I term" and the "D term"
		printf("\nTurn = %f\n",Turn);
		   //Turn = Turn/100; //! REMEMBER to undo the affect of the factor of 100 in Kp, Ki and Kd!
		donus = (long) Turn;
		printf("\ndonus = %d\n",donus);
		if(donus >= Tp)
		{donus = Tp;}
		else if (donus <= (-Tp) )
		{donus = ( -Tp);}

		if(duzgit==1)
		{
			printf("xuat ra solmotor: %d\n",solmotor);
			printf("xuat ra sagmotor: %d\n",sagmotor);
			return 0;
		}

		if(donus < 0)
		{
			solmotor=Tp + donus;
			sagmotor=Tp;
			printf("xuat ra solmotor: %d\n",solmotor);
			printf("xuat ra sagmotor: %d\n",sagmotor);
		}
		else
		{
			solmotor=Tp;
			sagmotor=Tp - donus;
			printf("xuat ra solmotor: %d\n",solmotor);
			printf("xuat ra sagmotor: %d\n",sagmotor);
		}
		//  bitis:
		lastError = Error;                  //! save the current error so it can be the lastError next time around
	}
	system("pause");
}
