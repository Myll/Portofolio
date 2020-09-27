#include <stdio.h>


int main(){
	int t;
	int n[100000];
	int temp;
	scanf("%d",&t);
	
	for(int a=0;a<t;a++){
		scanf("%d",&n[a]);
	}
	
	for(int i=0;i<t;i++){
		for(int j=i+1;j<t;j++){
			if(n[i]>n[j]){
				temp=n[i];
				n[i]=n[j];
				n[j]=temp;
			}
		}
	}
	
	for(int b=0;b<t;b++){
		printf("%d\n",n[b]);
	}
	
	return 0;
}
