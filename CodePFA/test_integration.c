/******************************************************/
/* Program to run and test the integration functions. */
/* Creation date: 31 July, 2025                       */
/******************************************************/

#include "integration.h"

/* Code here everything you need to test the integration methods and show your numericzal results */

double f(double x){
	return sqrt(x);
}

int main()
{
	printf("Res : %f\n", integrate_inter2(f, 0, 14, 0.1));
	printf("Res : %f\n", integrate_inter3(f, 0, 14, 0.1));
	return 0;
}
