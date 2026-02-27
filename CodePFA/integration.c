#define INTEGRATION_C
#include "integration.h"
#include <string.h>


double integrate_left(double (*f)(double), double a, double b, double dx){
    int nb_sub=(b-a)/dx;
    double res=0;
    double ai=a;
    double bi=a+dx;
    for(int i=0;i<nb_sub;i++){
        res+=(bi-ai)*f(ai);
        ai=bi;
        bi+=dx;
    }
    return res;
}

double integrate_right(double (*f)(double), double a, double b, double dx){
    int nb_sub=(b-a)/dx;
    double res=0;
    double ai=a;
    double bi=a+dx;
    for(int i=0;i<nb_sub;i++){
        res+=(bi-ai)*f(bi);
        ai=bi;
        bi+=dx;
    }
    return res;
}

double integrate_middle(double (*f)(double), double a, double b, double dx){
    int nb_sub=(b-a)/dx;
    double res=0;
    double ai=a;
    double bi=a+dx;
    for(int i=0;i<nb_sub;i++){
        double mid=(bi+ai)/2;
        res+=(bi-ai)*f(mid);
        ai=bi;
        bi+=dx;
    }
    return res;
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

bool setQuadFormula(QuadFormula* qf, char* name)
{
    if(!strcmp(name,"left")||!strcmp(name,"right")||!strcmp(name,"middle")||!strcmp(name,"trapezes")||!strcmp(name,"simpson")||!strcmp(name,"gauss2")||!strcmp(name,"gauss3")){
        strcpy(qf->name,name);
        return true;
    }
    else
        return false;
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

double integrate_dx(double (*f)(double), double a, double b, double dx, QuadFormula* qf)
{
	double mult=1;
	if (a==b) printf("Nani deska0.0");
	if (a>b) {double temp=a;a=b;b=temp;mult=-1;}
	if(!strcmp(qf->name,"left"))
		return mult*integrate_left(f,a,b,dx);
	else if(!strcmp(qf->name,"right"))
		return mult*integrate_right(f,a,b,dx);
	else if(!strcmp(qf->name,"middle"))
		return mult*integrate_middle(f,a,b,dx);
	else if(!strcmp(qf->name,"trapezes"))
		return mult*integrate_trap(f,a,b,dx);
	else if(!strcmp(qf->name,"simpson"))
		return mult*integrate_simp(f,a,b,dx);
	else if(!strcmp(qf->name,"gauss2"))
		return mult*integrate_inter2(f,a,b,dx);
	else if(!strcmp(qf->name,"gauss3"))
		return mult*integrate_inter3(f,a,b,dx);
	return 0.0;
}

double integrate(double (*f)(double), double a, double b, int N, QuadFormula* qf)
{
	double dx=(b-a)/N;
	return integrate_dx(f,a,b,dx,qf);
}
