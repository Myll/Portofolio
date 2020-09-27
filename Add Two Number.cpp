#include <stdio.h>


int main(){
	int test;
	int a,b;
	int c;
	scanf("%d",&test);
	
	for(int i=0;i<test;i++){
		scanf("%d %d",&a,&b);
		c=a+b;
		printf("%d\n",c);
	}
	
	return 0;
}
