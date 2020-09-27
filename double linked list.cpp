#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Data{
	
	char nama[25];
	int umur;
	
	struct Data *next,*prev;
}*head,*tail,*current;

void pushBelakang(char inputanNama[],int inputanUmur){
	current = (struct Data*) malloc(sizeof(struct Data));
	
	strcpy(current->nama,inputanNama);
	current->umur = inputanUmur;
	
	current->next = current->prev = NULL;
	
	if(head==NULL){
		head = tail = current;
	}else{
		tail->next = current;
		current->prev = tail;
		tail = current;
	}
			
}

void pushDepan(char inputanNama[],int inputanUmur){
	current = (struct Data*) malloc(sizeof(struct Data));
	
	strcpy(current->nama,inputanNama);
	current->umur = inputanUmur;
	
	current->next = current->prev = NULL;
	
	if(head==NULL){
		head = tail = current;
	}else{
		current->next = head;
		head->prev = current;
		head = current;
	}
			
}

void cetakData(){
	current = head;
	int nomor=1;
	printf("%-3s | %-20s | %s\n","NO","NAMA","UMUR");
	printf("---------------------------------\n");
	
	while(current !=NULL){
		printf("%03d | %-20s | %d\n",nomor,current->nama,current->umur);
		current = current->next;
		nomor++;
	}
}

void pushTengahSebelumNama(char inputanNama[],int inputanUmur, char inputanSebelumNama[]){
	current = (struct Data*) malloc(sizeof(struct Data));
	
	strcpy(current->nama,inputanNama);
	current->umur = inputanUmur;
	
	current->next = current->prev = NULL;
	
	if(strcmp(inputanSebelumNama, head->nama) == 0){
		pushDepan(inputanNama,inputanUmur);
	}else{
		struct Data *penampungNilai = head;
		
		while(penampungNilai != NULL){
			if(strcmp(penampungNilai->nama,inputanSebelumNama)==0){
				current->next = penampungNilai;
				current->prev = penampungNilai->prev;
				penampungNilai->prev->next = current;
				penampungNilai->prev = current;
				break;
			}
			penampungNilai = penampungNilai->next;
		}	
	}	
}

void popNama(char namaYangDidelete[]){
	
	if(head==NULL) {
	 	printf("Data belum dimasukkan\n");
		return;
	}
	
	current = head;
	
	while(current !=NULL){
		
		if(strcmp(namaYangDidelete,head->nama)==0){
			//pop Depan
			head = head->next;
			head->prev = NULL;
			free(current);
			break;
		}else if(strcmp(namaYangDidelete,tail->nama)==0){
			//pop belakang
			current = tail;
			tail = tail->prev;
			tail->next = NULL;
			free(current);
			break;
		}
		else if(strcmp(namaYangDidelete,current->nama)==0){
			//pop tengah
			current->prev->next = current->next;
			current->next->prev = current->prev;
			free(current);
			break;
		}
		current = current->next;
	}
	
}

int main(){
	//Fani Cani Andi Dini Eni Budi
	pushBelakang("Andi",23);
	pushBelakang("Dini",26);
	pushBelakang("Budi",20);
	pushDepan("Cani",18);
	pushTengahSebelumNama("Eni",19,"Budi");
	pushTengahSebelumNama("Fani",30,"Cani");
	cetakData();
	popNama("Fani");
	popNama("Budi");
	popNama("Andi");
	puts("");
	cetakData();
	return 0;
}
