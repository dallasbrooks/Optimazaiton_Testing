#include <stdio.h>
#include <math.h>
#include <sys/time.h>

//(1 + sqrt(5)) / 2
#define PHI 1.6180339887498948482045
//50 proves what im trying to do, without adding too much time
#define Xn 50

struct timeval start;	

double fib_Equation(int n){
	return (pow(PHI, n) - pow(1-PHI, n)) / sqrt(5);
}

double fib_Recursion(double n){
	return n < 2 ? n : fib_Recursion(n-1) + fib_Recursion(n-2);
}

float getTime(){
	struct timeval now;
	gettimeofday(&now, NULL);
	return (now.tv_sec - start.tv_sec) + (now.tv_usec - start.tv_usec)/1000000.0f;
}

int main(){
	gettimeofday(&start, NULL);	
	for(int a = 0; a < Xn; a++){
		printf("%d\t%.0f\n", a, round(fib_Equation(a)));
	}
	double funct = getTime();
	gettimeofday(&start, NULL);
	for(int a = 0; a < Xn; a++){
		printf("%d\t%.0f\n", a, fib_Recursion(a));
	}
	double recurs = getTime();
	printf("Equation is: %f\n", funct);
	printf("Recursion is: %f\n", recurs);
	return 0;
}
