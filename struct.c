#include <stdio.h>

struct point {
	int x;
	int y;
};

int main(void)
{
	struct point p;
		p.x = 20; 

		printf("%d\n", p.x);
	return(0);
}
