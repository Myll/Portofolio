#include <stdio.h>
int z;
float y;
float draw;

void atm()
{
	if(z%5==0 && z+0.50<y){
		draw=y-z-0.50;
	}else
	draw=y;
}

int main()
{
	scanf("%d %f",&z,&y);
	atm();
	printf("%.2f\n",draw);
	
	return 0;
}
