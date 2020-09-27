#include <stdio.h>


int main(){
	int n;
	int t;
	int hasil;
	
	scanf("%d",&n);
	hasil=0;
	
	for(int i=0;i<n;i++){
		scanf("%d",&t);
		if(t<0)
		hasil++;
	}
	
	printf("%d\n",hasil);
	
	return 0;
}
