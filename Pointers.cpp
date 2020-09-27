#include<stdio.h>
int main()
{
	int b=5;
	int*c;
	c=&b;
	
	printf("%d\n",&c);
	printf("%d\n",*c);
	
	return 0;
}
