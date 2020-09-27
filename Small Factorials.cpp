#include <stdio.h>


int fac(int n){
	if (n<=1){
		return n;
	}else return(n*fac(n-1));
}


int main(){
	int test;
	int n;
	int temp;
	int f[1000];
	scanf("%d",&test);
	
	for(int a=0;a<test;a++){
		scanf("%d",&n);
		fac(n);
		
		for(int b=0;b<test;b++){
			n=temp;
			temp=f[b];
		}
	}
	
	for(int c=0;c<test;c++){
		printf("%d\n",f[c]);
	}
	
	
	return 0;
}
