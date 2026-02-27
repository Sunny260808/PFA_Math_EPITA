/******************************************************/
/* Program to run and test the integration functions. */
/* Creation date: 31 July, 2025                       */
/******************************************************/

#include "integration.h"

/* Code here everything you need to test the integration methods and show your numericzal results */

double f(double x){
	return sin(x)*exp(2*x);
}

int main()
{	
	QuadFormula set;
	setQuadFormula(&set, "left");
	printf("Avec %s (dx=1): %f\n", set.name, integrate_dx(f, 0, 5, 1, &set));
	printf("Avec %s (dx=0.5): %f\n", set.name, integrate_dx(f, 0, 5, 0.5, &set));
	printf("Avec %s (dx=0.1): %f\n", set.name, integrate_dx(f, 0, 5, 0.1, &set));
	printf("Avec %s (dx=1): %f\n", set.name, integrate_dx(f, 5, 10, 1, &set));
	printf("Avec %s (dx=0.5): %f\n", set.name, integrate_dx(f, 5, 10, 0.5, &set));
	printf("Avec %s (dx=0.1): %f\n", set.name, integrate_dx(f, 5, 10, 0.1, &set));
	setQuadFormula(&set, "right");
	printf("Avec %s (dx=1): %f\n", set.name, integrate_dx(f, 0, 5, 1, &set));
	printf("Avec %s (dx=0.5): %f\n", set.name, integrate_dx(f, 0, 5, 0.5, &set));
	printf("Avec %s (dx=0.1): %f\n", set.name, integrate_dx(f, 0, 5, 0.1, &set));
	printf("Avec %s (dx=1): %f\n", set.name, integrate_dx(f, 5, 10, 1, &set));
	printf("Avec %s (dx=0.5): %f\n", set.name, integrate_dx(f, 5, 10, 0.5, &set));
	printf("Avec %s (dx=0.1): %f\n", set.name, integrate_dx(f, 5, 10, 0.1, &set));
	setQuadFormula(&set, "middle");
	printf("Avec %s (dx=1): %f\n", set.name, integrate_dx(f, 0, 5, 1, &set));
	printf("Avec %s (dx=0.5): %f\n", set.name, integrate_dx(f, 0, 5, 0.5, &set));
	printf("Avec %s (dx=0.1): %f\n", set.name, integrate_dx(f, 0, 5, 0.1, &set));
	printf("Avec %s (dx=1): %f\n", set.name, integrate_dx(f, 5, 10, 1, &set));
	printf("Avec %s (dx=0.5): %f\n", set.name, integrate_dx(f, 5, 10, 0.5, &set));
	printf("Avec %s (dx=0.1): %f\n", set.name, integrate_dx(f, 5, 10, 0.1, &set));
	setQuadFormula(&set, "trapezes");
	printf("Avec %s (dx=1): %f\n", set.name, integrate_dx(f, 0, 5, 1, &set));
	printf("Avec %s (dx=0.5): %f\n", set.name, integrate_dx(f, 0, 5, 0.5, &set));
	printf("Avec %s (dx=0.1): %f\n", set.name, integrate_dx(f, 0, 5, 0.1, &set));
	printf("Avec %s (dx=1): %f\n", set.name, integrate_dx(f, 5, 10, 1, &set));
	printf("Avec %s (dx=0.5): %f\n", set.name, integrate_dx(f, 5, 10, 0.5, &set));
	printf("Avec %s (dx=0.1): %f\n", set.name, integrate_dx(f, 5, 10, 0.1, &set));
	setQuadFormula(&set, "simpson");
	printf("Avec %s (dx=1): %f\n", set.name, integrate_dx(f, 0, 5, 1, &set));
	printf("Avec %s (dx=0.5): %f\n", set.name, integrate_dx(f, 0, 5, 0.5, &set));
	printf("Avec %s (dx=0.1): %f\n", set.name, integrate_dx(f, 0, 5, 0.1, &set));
	printf("Avec %s (dx=1): %f\n", set.name, integrate_dx(f, 5, 10, 1, &set));
	printf("Avec %s (dx=0.5): %f\n", set.name, integrate_dx(f, 5, 10, 0.5, &set));
	printf("Avec %s (dx=0.1): %f\n", set.name, integrate_dx(f, 5, 10, 0.1, &set));
	setQuadFormula(&set, "gauss2");
	printf("Avec %s (dx=1): %f\n", set.name, integrate_dx(f, 0, 5, 1, &set));
	printf("Avec %s (dx=0.5): %f\n", set.name, integrate_dx(f, 0, 5, 0.5, &set));
	printf("Avec %s (dx=0.1): %f\n", set.name, integrate_dx(f, 0, 5, 0.1, &set));
	printf("Avec %s (dx=1): %f\n", set.name, integrate_dx(f, 5, 10, 1, &set));
	printf("Avec %s (dx=0.5): %f\n", set.name, integrate_dx(f, 5, 10, 0.5, &set));
	printf("Avec %s (dx=0.1): %f\n", set.name, integrate_dx(f, 5, 10, 0.1, &set));
	setQuadFormula(&set, "gauss3");
	printf("Avec %s (dx=1): %f\n", set.name, integrate_dx(f, 0, 5, 1, &set));
	printf("Avec %s (dx=0.5): %f\n", set.name, integrate_dx(f, 0, 5, 0.5, &set));
	printf("Avec %s (dx=0.1): %f\n", set.name, integrate_dx(f, 0, 5, 0.1, &set));
	printf("Avec %s (dx=1): %f\n", set.name, integrate_dx(f, 5, 10, 1, &set));
	printf("Avec %s (dx=0.5): %f\n", set.name, integrate_dx(f, 5, 10, 0.5, &set));
	printf("Avec %s (dx=0.1): %f\n", set.name, integrate_dx(f, 5, 10, 0.1, &set));
	return 0;
}
