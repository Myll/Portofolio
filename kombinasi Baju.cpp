#include <stdio.h>
#include <string.h>

int main(){
	int jumlahCase;
	int beli;
	int warna;
	int kombinasi;
	char ukuran;
	
	scanf("%d",&jumlahCase);
	for(int i=0;i<jumlahCase;i++){
		int sizeS[100]={0};
		int sizeM[100]={0};
		int sizeL[100]={0};
		
		scanf("%d",&beli);
		getchar();
		kombinasi=0;
		
		for(int j=0;j<beli;j++){
			scanf("%c %d",&ukuran,&warna);
			getchar();
			
			if(ukuran=='S'){
				if(sizeS[warna]==0){
					kombinasi++;
				}
				sizeS[warna]++;
			}
			if(ukuran=='M'){
				if(sizeM[warna]==0){
					kombinasi++;
				}
				sizeM[warna]++;
			}
			if(ukuran=='L'){
				if(sizeL[warna]==0){
					kombinasi++;
				}
				sizeL[warna]++;
			}
		}
		printf("Case #%d: %d\n",i+1,kombinasi);
	}
}
