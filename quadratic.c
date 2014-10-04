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

	float vX = -b/2*a;
	float vY = a*(vX*vX) + b*vX + c;

	printf("Vertex: (%g, %g)\n", vX, vY);

	float d = b*b - 4*a*c;

	int coef = 1;

	for (int i=1; i<=sqrt(d); i++) {
		if ((int)d%(i*i)==0) {
			coef = coef*i;
			d = d/(i*i);
			i = 1;
		}
	}

	if (d==0) {
		printf("root: %g", vX);
	} else {
		float p1 = -b/(2*a);
		float p2 = coef/(2*a);
		
		int co = 1;
		if (d<0) {
			co = -1;
		}
		
		char* sign[2] = {"+", "-"};
		
		for (int i=0; i<=1; i++) {
			printf("root: %g%s%g", p1, sign[i], p2);
			if (d<0) {
				printf("i");
			}
			if (d*d!=1) {
				printf("\u221A(%g)", co*d);
			}
			printf("\n");
		}
	}

	return 0;
}
