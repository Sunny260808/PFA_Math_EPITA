#define INTEGRATION_C
#include "integration.h"

bool setQuadFormula(QuadFormula* qf, char* name)
{
  return true;
}

/* This function is not required ,but it may useful to debug */
void printQuadFormula(QuadFormula* qf)
{
  printf("Quadratic formula: %s\n", qf->name);
  /* Print everything else that may be useful */
}


/* Approximate the integral of function f from a to b.
   - f is a pointer to a function pointer
   - a and b are the integration bounds
   - Interval [a,b] is split in N subdivisions [ai,bi]
   - Integral of f on each subdivision [ai,bi] is approximated by the quadrature formula qf.
*/
double integrate(double (*f)(double), double a, double b, int N, QuadFormula* qf)
{
  return 0.0;
}

double integrate_dx(double (*f)(double), double a, double b, double dx, QuadFormula* qf)
{
  return 0.0;
}

double integrate_trap(double (*f)(double), double a, double b, double dx){
	double n;
	double ai=a;
	for (double bi=a+dx;bi<=b;bi=bi+dx){
		n=n+dx*(f(ai)+f(bi))/2;
		ai=ai+dx;
	}
	return n;
}

double integrate_simp(double (*f)(double), double a, double b, double dx){
	double n;
	double ai=a;
	for (double bi=a+dx;bi<=b;bi=bi+dx){
		n=n+dx*(f(ai)+4*f((ai+bi)/2)+f(bi))/6;
		ai=ai+dx;
	}
	return n;
}

double integrate_inter2(double (*f)(double), double a, double b, double dx){
	double n;
	double ai=a;
	for (double bi=a+dx;bi<=b;bi=bi+dx){
		n=n+dx*(f(ai+(dx-1/sqrt(3))/2)+f(ai+(dx+1/sqrt(3))/2))/2;
		ai=ai+dx;
	}
	return n;
}

double integrate_inter3(double (*f)(double), double a, double b, double dx){
	double n;
	double ai=a;
	for (double bi=a+dx;bi<=b;bi=bi+dx){
		n=n+dx*(5*f(ai+(dx-sqrt(1/5))/2)+8*f((ai+bi)/2)+5*f(ai+(dx+sqrt(3/5))/2))/18;
		ai=ai+dx;
	}
	return n;
}
