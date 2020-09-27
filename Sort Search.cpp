#include <stdio.h>
#include <string.h>
#include <windows.h>

struct Mahasiswa{
	char nama[100];
	char nim[100];
	float gpa;
	char major[100];
}data[100];

int count=0;

//bacafile & tulisfile

void bacaFile(){
	count=0;
	FILE*fp=fopen("data.txt","r");
	
	if(fp==NULL){
		printf("FILE tidak ditemukan!\n");
	}else{
		while(!feof(fp)){
			//feof=end of file
			fscanf(fp,"%[^#]#%[^#]#%f#%[^\n]\n",data[count].nim,data[count].nama,
			&data[count].gpa,data[count].major);
			//%[^#]=%s
			count++;
		}
	}
	fclose(fp);
}

void tulisFile(){
	FILE*fp=fopen("data.txt","w");
	for(int i=0;i<count;i++){
		fprintf(fp,"%s#%s#%2f#%s\n",data[count].nim,data[count].nama,
		data[count].gpa,data[count].major);
	}
	fclose(fp);
}

void view(){
	printf("Course net training center\n");
	if(count==0){
		printf("Belum ada data!\n");
	}else{
		printf("No.NIM - Nama - GPA - Major\n");
		for(int i=0;i<count;i++){
			printf("%d.%s - %s - %2f - %s\n",i+1,data[i].nim,data[i].nama,
			data[i].gpa,data[i].major);
		}
	}
}

int searchNama(char namatemp[100]){
	for(int i=0;i<count;i++){
		if(strcmp(namatemp,data[i].nama)==0){
			return i;
		}
	}
	return -1;
}

void case_2(){
	char namaedit[100];
	char namabaru[100];
	int flag=0;
	do{
		printf("Mau edit yang mana? masukkin namanya! :");
		gets(namaedit);
	}while(searchNama(namaedit)==-1);
	flag=searchNama(namaedit);
	do{
		printf("Masukan nama baru[5..20]:");
		gets(namabaru);
	}while(strlen(namabaru)<5 || strlen(namabaru)>20);
	strcpy(data[flag].nama,namabaru);
	printf("Sukses update!\n");
}

void case_5(){
	struct Mahasiswa temp;
	for(int i=0;i<count-1;i++){
		for(int j=0;j<count-i-1;j++){
			if(strcmp(data[j].nama,data[j+1].nama)>0){
				temp=data[j];
				data[j]=data[j+1];
				data[j+1]=temp;
			}
		}
	}
}

void menu(){
	printf("Menu\n");
	printf("1.Add\n");
	printf("2.Update\n");
	printf("3.Delete\n");
	printf("4.Sort GPA Ascending\n");
	printf("5.Sort Nama Ascending\n");
	printf("6. Save and Exit\n");
	printf("Choice:\n");
}

int main(){
	int pil;
	bacaFile();
	do{
		system("cls");
		view();
		printf("\n\n");
		menu();
		scanf("%d",&pil);fflush(stdin);
		switch(pil){
			case 1:
				break;
			case 2:case_2();
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:case_5();
				break;
		}
	}while(pil!=6);
	getchar();
}
