#include <stdio.h>
int m,n;
int out;

void devide(){
	if(n%m==0){
		out++;
	}
}


int main()
{
	int test;
	scanf("%d %d",&test,&m);
	
	for(int a=0;a<test;a++){
		scanf("%d",&n);
		devide();
	}printf("%d",out);
	
	return 0;
}
