#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
void gz(double a, double b, double dt, double& x1, double& x2)
{
	x1 = (-b + sqrt(dt)) / 2 * a;

	x2 = (-b - sqrt(dt)) / 2 * a;
	printf("x1=%.3lfx2=%.3lf", x1, x2);
}

void ez(double a, double b, double dt, double& x1, double& x2)
{
	x1 = (-b + sqrt(dt)) / 2 * a;

	x2 = (-b - sqrt(dt)) / 2 * a;
	printf("x1=%.3lfx2=%.3lf", x1, x2);
}

void sz(double a, double b, double dt, double& x1, double& x2)
{

	

	
	printf("x1=%.3lf+%.3lfi", -b/(2*a), (sqrt(-dt) / (2 * a)));
	printf("x2=%.3lf-%.3lfi", -b/(2*a), (sqrt(-dt) / (2 * a)));

	
}

int main()
{
	double a = 0;
    double b = 0;
	double c = 0;
	double x1 = 0;
	double x2 = 0;

	scanf("%lf%lf%lf", &a, &b, &c);
	double dt = pow(b, 2) - 4 * a * c;
	if (dt > 0)
	{
		gz(a,b,dt, x1, x2);
	}
	else if (dt == 0)
	{
		ez(a, b, dt, x1, x2);
	}
	else
	{
		sz(a, b, dt, x1, x2);
	}
 





	return 0;
}