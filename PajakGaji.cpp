#include <stdio.h>
int main()
{
	int b,a,i;
	//b=gaji perbulan,a=jumlah anak,i=jumlah istri
	scanf("%d",&b);
	scanf("%d",&a);
	scanf("%d",&i);
	
	int gaji;
	gaji=b*12;
	
	int sabi;
	if(gaji<54000000){sabi=0;}
	if(gaji>54000000&& a==0&& i==0){sabi=gaji-54000000;}
	
	else
	
	if(gaji>54000000&& a==1&& i==1){sabi=gaji-54000000-4500000-4500000;}
	
	else
	
	if(gaji>54000000&& a==2&& i==1){sabi=gaji-54000000-4500000-4500000-4500000;}
	
	else
	
	if(gaji>54000000&& a>=3&& i==1){sabi=gaji-54000000-4500000-4500000-4500000-4500000;}
	
	
	int c,d;
	if(sabi<=50000000){c=sabi*0.05;d=0;}
	else
	if(sabi>=50000000){c=sabi*0.05;d=sabi-50000000;}
	
	
	int e,f;
	if(d=0){e=0;f=0;}
	if(d!=0){e=d*0.15;
		if(d>250000000){f=d-250000000;}
		else {d=0;}}
	
	
	
	int g,h;
	if(f=0){g=0;h=0;}
	else
	if(f!=0){g=f*0.25;
	if(f>500000000){h=f-500000000;}
	else {h=0;}}
	
	
	int j;
	if(h=0){j=0;}
	else
	if(h!=0){j=h*0.30;}
	
	int tp;
	// tp = total pajak
	tp=c+e+g+j;
	
	int gb;
	//gb = gaji bersih
	gb=(gaji-tp)/12;
	
	printf("pajak pertahun anda adalah %d\n",tp);
	printf("gaji bersih anda adalah %d",gb);
	
	
	
	return 0;
	
}
