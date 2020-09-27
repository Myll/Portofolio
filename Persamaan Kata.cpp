#include <stdio.h>
#include <string.h>
#include <ctype.h>


void sorting(char temp[]){
	for(int i=0;i<strlen(temp);i++){
		for(int j=i;j<strlen(temp);j++){
			if(toupper(temp[i])>toupper(temp[j])){
				char swap=temp[i];
				temp[i]=temp[j];
				temp[j]=swap;
			}
		}
	}
}


int main(){
	int jumlahCase,jumlahKata;
	char hasil[100];
	char kata[100][100];
	
	FILE*read=fopen("Data.txt","r");
	fscanf(read,"%d",&jumlahCase);
	
	for(int i=0;i<jumlahCase;i++){
		fscanf(read,"%d",&jumlahKata);
		strcpy(hasil,"Equal");
		
		for(int j=0;j<jumlahKata;j++){
			fscanf(read,"%s",kata[j]);
			sorting(kata[j]);
		}
		
		for(int j=0;j<jumlahKata-1;j++){
			if(strcmpi(kata[j],kata[j+1])!=0){
				strcpy(hasil,"Not equal");
				break;
			}
		}
		printf("Case #%d: %s\n",i+1,hasil);
	}
	fclose(read);
	getchar();
}
