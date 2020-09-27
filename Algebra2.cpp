#include <stdio.h>

int main()
{
	int T,z;
	float a1,b1,c1,a2,b2,c2;
	float x,y;
	
	scanf("%d",&T);
	for(z=1;z<=T;z++)
	{
	scanf("%f %f %f",&a1,&b1,&c1);
	scanf("%f %f %f",&a2,&b2,&c2);
	printf("Case #%d:\n",z);
	
		x=((c1*b2-c2*b1)/(a1*b2-a2*b1));
		y=((c1*a2-c2*a1)/(b1*a2-b2*a1));
		printf("x = %.4f\n",x);
		printf("y = %.4f\n",y);
	}
	return 0;
}
