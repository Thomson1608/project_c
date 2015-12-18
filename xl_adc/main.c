/*
 * main.c
 *
 *  Created on: Dec 3, 2015
 *      Author: minht_000
 */
#include <stdio.h>

int main()
{
	int i=0;
	int valuse=0;
	int secson[8]={200,200,100,100,100,100,100,100};

	for(i=0 ; i<8 ; i++)
	{
		if(secson[i]>150)//// bat 1
		{
			if(i==0)
				valuse |= 2;
			else
			{
				valuse <<=1;
				valuse |= 2;
			}
		}
		else
				valuse <<=1;
	}
	printf("%d",valuse);
	return 0;
}

