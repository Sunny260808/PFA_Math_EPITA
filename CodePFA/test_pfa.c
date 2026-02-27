/******************************************************/
/* Program to run and test the integration functions. */
/* Creation date: 31 July, 2025                       */
/******************************************************/

#include "pfa.h"

/* Code here anything you want to test your pfa functions and to show your numerical results */
int main()
{
	printf("%d\n",init_integration("trapezes", 0.1));
	printf("%f\n", PHI(0));
	return 0;
}
