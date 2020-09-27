#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct data
{
	char nama[25];
	int umur;
	
	struct data *next, *prev;
}*head, *tail, *current;

void pushBelakang(char inputanNama[], int inputanUmur)
{
	current = (struct data*) malloc(sizeof(struct data));
	
	strcpy(current->nama, inputanNama);
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

void pushDepan(char inputanNama[], int inputanUmur){
	current = (struct data*) malloc(sizeof(struct data));
	
	strcpy(current->nama, inputanNama);
	current->umur = inputanUmur;
	
	current->next = current->prev = NULL;
	
	if(head==NULL){
		head = tail = current;
	}else{
		head->prev = current;
		current->next = head;
		head = current;
	}
}

void pushTengahBeforeNama(char inputanNama[], int inputanUmur, char inputanBeforeNama[])
{
	current = (struct data*) malloc(sizeof(struct data));
	
	strcpy(current->nama, inputanNama);
	current->umur = inputanUmur;
	
	current->next = current->prev = NULL;
	
	if(strcmp(inputanBeforeNama, head->nama)==0){
		pushDepan(inputanNama, inputanUmur);
	}else{
		struct data *penampungNilai = head;
		
		while(penampungNilai!=0){
			if(strcmp(penampungNilai->nama, inputanBeforeNama)==0){
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

void popNama(char namaDihapus[])
{
	if(head==NULL){
		printf("Data tidak ada.\n");
		return;
	}
	
	current = head;
	
	while(current!=NULL){
		if(strcmp(namaDihapus, head->nama)==0){
			//pop depan
			head = head->next;
			head->prev = NULL;
			free(current);
			break;
		}else if(strcmp(namaDihapus, tail->nama)==0){
			//pop belakang
			current = tail;
			tail = tail->prev;
			tail->next = NULL;
			free(current);
			break;
		}else if(strcmp(namaDihapus, current->nama)==0){
			//pop tengah
			current->prev->next = current->next;
			current->next->prev = current->prev;
			free(current);
			break;
		}
		current = current->next;
	}
}

void cetak()
{
	current = head;
	int num=1;
	
	printf("%-2s | %-20s | %s\n", "NO", "NAMA", "UMUR");
	printf("--------------------------------\n");
	while(current!=NULL){
		printf("%02d | %-20s | %d\n", num, current->nama, current->umur);
		current = current->next;
		num++;
	}
	printf("\n");
}

int main()
{
	pushBelakang("Andi", 23);
	pushDepan("Nana", 21);
	pushBelakang("Dini", 26);
	pushTengahBeforeNama("Nono", 25, "Dini");
	pushBelakang("Budi", 20);
	pushDepan("Ana", 22);
	cetak();
	popNama("Ana");
	cetak();
	popNama("Budi");
	cetak();
	popNama("Nono");
	cetak();
	
	return 0;
}
