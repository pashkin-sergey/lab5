#include <stdio.h>
#include <math.h>
#include <solve.h>
#include <discriminant.h>

const double eps = 1e-10;
const short ERROR = -1;
const short NO_ROOTS = 0;
const short ONE_ROOT = 1;
const short TWO_ROOTS = 2;

int equal(double a, double b, double eps) {
    return fabs(a - b) < eps;
}

short solve(double a, double b, double c, double *x1, double *x2) {
        double r = discriminant(a, b, c);
        if (r < 0)
		return NO_ROOTS;
        if (equal(r, 0, eps)) {
                *x1 = -b / (2 / a);
                return ONE_ROOT;
        }
	if (r > 0) {
		*x1 = (-b - sqrt(r)) / (2 * a);
		*x2 = (-b + sqrt(r)) / (2 * a);
		return TWO_ROOTS;
	}
	return ERROR;
}
