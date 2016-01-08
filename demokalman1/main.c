/*
 * main.c
 *
 *  Created on: Dec 5, 2015
 *      Author: minht_000
 */
#include <complex.h>
double Q = 0.000001;
double R = 0.01;
double P = 1, X = 0, K;
double update(double input);
void measurementUpdate();
int main(){
	int i=0;
	double  input[20]={0,300,600,900,600,300,500,00,100,10,0,0,100,25,10,40,80,10,0,9};
	for(i=0 ; i<20 ; i++){
		printf("ketqua : %f\n", update(input[i]));
	}
	return 0;
}

//// update
double update(double input)
{
	measurementUpdate();
	double resul=X+(input-X)*K;
	X=resul;
	return resul;
}
///////////////tinh toan
void measurementUpdate()
 {
	 K = (P + Q) / (P + Q + R);
	 P = R * (P + Q) / (R + P + Q);
 }
