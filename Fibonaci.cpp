#include <stdio.h>
int t;
int angka,mulai;


int fib(int angka,int mulai){
	if(angka==1||angka==2){
		return mulai;
	}else{
		return fib(angka-1,mulai)+fib(angka-2,mulai);
	}
}


int main(){
	int t;
	scanf("%d",&t);
	
	for(int a=1;a<=t;a++){
		scanf("%d %d",&angka,&mulai);
		printf("Case #%d:",a);
		printf("%d\n",fib(angka,mulai));
	}
	
	return 0;
}
