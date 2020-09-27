#include <stdio.h>
#include <string.h>
int test,y,z;
char kalimat[1001];

int good()
{
	for(y=0;y<strlen(kalimat);y++){
		if(kalimat[y]=='g' || kalimat[y]=='G'){
			if(kalimat[y+1]=='O' || kalimat[y+1]=='o'){
				if(kalimat[y+2]=='o' || kalimat[y+2]=='O'){
					if(kalimat[y+3]=='D' || kalimat[y+3]=='d'){
						return true;
					}
				}
			}
		}
	}return false;
}
	

int main()
{
	scanf("%d",&test);
	getchar();
	for(z=1;z<=test;z++){
		scanf("%[^\n]",&kalimat);
		getchar();
		printf("Case #%d: ",z);
		if(good()==true){
			printf("yes\n",z);
		}else if(good()==false){
			printf("no\n",z);
		}
	}
	
	return 0;
}
