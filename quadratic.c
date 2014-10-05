#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]) {
	float a;
	float b;
	float c;

	printf("ax^2 + bx + c\n");

	if (argv[1]==NULL) {
		printf("a=");
		scanf("%f", &a);
		printf("b=");
		scanf("%f", &b);
		printf("c=");
		scanf("%f", &c);
		} else {
		if (sscanf (argv[1], "%f", &a)!=1) {
			printf ("error - not a number\n");
		}
		if (sscanf (argv[2], "%f", &b)!=1) {
			printf ("error - not a number\n");
		}
		if (sscanf (argv[3], "%f", &c)!=1) {
			printf ("error - not a number\n");
		}
	}

	float vX = -b/(2*a);
	float vY = a*(vX*vX) + b*vX + c;
	
	if (vX == -0) {
		vX = 0;
	}
	if (vY == -0) {
		vY = 0;
	}

	printf("vertex: (%g, %g)\n", vX, vY);

	float d = b*b - 4*a*c;

	int coef = 1;

	for (int i=1; i<=sqrt(d); i++) {
		if ((int)d%(i*i)==0) {
			coef = coef*i;
			d = d/(i*i);
			i = 1;
		}
	}
	
	char p1[32];
	
	if (d==0) {
		if ((int)b == 0) {
			snprintf(p1, sizeof(p1), "");
		} else if((int)a == a && (int)b == b) {
			for (int i=1; i<=(int)((2*a)+b); i++) {
				if ((int)(2*a/i) == (2*a/i) && (int)(b/i) == (b/i)) {
					a = a / i;
					b = b / i;
					i = 1;
				}
			}
			if (2*a == 1) {
				snprintf(p1, sizeof(p1), "%d\u2245", -(int)b);
			} else {
				snprintf(p1, sizeof(p1), "(%d/%d)\u2245", -(int)b, (int)(2*a));
			}
		} else {
			snprintf(p1, sizeof(p1), "%g\u2245", -b/(2*a));
		}
		printf("%s", p1);
		float r = (-b/(2*a));
		if (r == -0) {
			printf("%g", -r);
		} else {
			printf("%g", r);
		}
		printf("\n");
	} else {
		char p2[32];
		
		int down = 1;
		
		if ((int)b == 0) {
			snprintf(p1, sizeof(p1), "");
		} else if((int)a == a && (int)b == b) {
			for (int i=1; i<=(int)((2*a)+b); i++) {
				if ((int)(2*a/i) == (2*a/i) && (int)(b/i) == (b/i)) {
					a = a / i;
					b = b / i;
					down = down*i;
					i = 1;
				}
			}
			if (2*a == 1) {
				snprintf(p1, sizeof(p1), "%d", -(int)b);
			} else {
				snprintf(p1, sizeof(p1), "(%d/%d)", -(int)b, (int)(2*a));
			}
		} else {
			snprintf(p1, sizeof(p1), "%g", -b/(2*a));
		}
		
		a = a * down;
		b = b * down;
		
		// Add code for cases where p1 and p2 can be reduced, and reduce them
		
		printf("coef: %d\n", (int)coef);
		printf("2a: %d\n", (int)(2*a));
		
		down = 1;

		if ((int)a == a && (int)coef == coef) {
			for (int i=1; i<=(int)((2*a)+coef); i++) {
				if ((int)(2*a)%i == 0 && (int)(coef) % i == 0) {
					a = a / i;
					coef = coef / i;
					down = down * i;
					i = 1;
				}
			}
			if (2*a == 1) {
				if (coef == 1) {
					snprintf(p2, sizeof(p2), "");
				} else {
					snprintf(p2, sizeof(p2), "%d", (int)coef);
				}
			} else {
				snprintf(p2, sizeof(p2), "(%d/%d)", (int)coef, (int)(2*a));
			}
		} else {
			snprintf(p2, sizeof(p2), "%g", coef/(2*a));
		}
		
		a = a * down;
		coef = coef * down; 
			
		int co = 1;
		if (d<0) {
			co = -1;
		}
		
		char* sign[2] = {"+", "-"};
		
		for (int i=0; i<=1; i++) {
			printf("root: %s%s%s", p1, sign[i], p2);
			if (d<0) {
				printf("i");
			}
			if (d*d!=1) {
				printf("\u221A(%g)", co*d);
			}
			printf("\u2245");
			if (d>0) {
				if (i==0) {
					printf("%g", (-b+sqrt(d))/(2*a));
				} else {
					printf("%g", (-b-sqrt(d))/(2*a));
				}
			} else {
				printf("%g%s%gi", (-b)/(2*a), sign[i], sqrt(-d)/(2*a));
			}
			printf("\n");
		}
	}

	return 0;
}
