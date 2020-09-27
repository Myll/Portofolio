#include <stdio.h>
#include <string.h>


int main(){
	int jumlahCase;
	char kataSumber[100];
	char kataDicari[100];
	scanf("%d",&jumlahCase);
	
	for(int i=0;i<jumlahCase;i++){
		scanf("%s %s",kataSumber,kataDicari);
		printf("Case #%d:",i+1);
		
		strrev(kataSumber);
		strrev(kataDicari);
		
		if(strstr(kataSumber,kataDicari)){
			printf("%s",strrev(strstr(kataSumber,kataDicari)));
		}
		printf("\n");
	}
	getchar();
	
}
