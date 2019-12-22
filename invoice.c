#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <process.h>
#include <time.h>

/*struct invoice {
	char invoiceID[12];
	float price;
	int day;
	char cname[20];
	char msname[20];
	char room[5];
};*/
struct customer{
	char name[20];
	char surname[20];
	char ID[12];
	char room[5];
	int day;
};
void main(){
	int staticprice=260,day,count,i;
	float netprice;
	time_t currentTime;
	time(&currentTime);
	struct tm *myTime=localtime(&currentTime);
	struct invoice *inv1=(struct invoice*)malloc(sizeof(struct invoice));
	struct customer *cst1=(struct customer*)malloc(sizeof(struct customer));
	FILE *fp1;
	FILE *fp2;
	fp1=fopen("customer.txt","r");
	while(!feof(fp1)){
		fread(cst1,sizeof(struct customer),1,fp1);
		count+=1;
	}
	count-=1;
	fclose(fp1);
	
	fp1=fopen("customer.txt","r");
	for(i=0;i<count;i++){
		fread(cst1,sizeof(struct customer),1,fp1);
		if(i==count-1){
			printf("Yeni Fatura icin Kayit;\n");
//		printf("\t\t\t%s\t%s\t%s\t%s\t%d\n",cst1->ID,cst1->name,cst1->surname,cst1->room,cst1->day);
	/*	strcpy(cst1->name,inv1->cname);
		strcpy(cst1->surname,inv1->msname);
		strcpy(cst1->room,inv1->room);
		strcpy(cst1->day,inv1->day);
		strcpy(cst1->ID,inv1->invoiceID);*/
		}
	}
	fclose(fp1);
	netprice=(cst1->day)*staticprice;// DAY x PRICE
	printf("\n\n\n\t\t\tCOLORFUL DREAMS HOTEL\n");
	printf("\t\t\t___________________________________________");
	printf("\n\t\t\t|INVOICE ID:\t %s%i%i%i%.2i%.2i%.2i|",cst1->ID,myTime->tm_mon+1,myTime->tm_mday,myTime->tm_year+1900,myTime->tm_hour,myTime->tm_min,myTime->tm_sec);
	printf("\n\n\n");
	printf("\t\t\tDAY\t|CUSTOMER\t\t    |PRICE\n");
	printf("\t\t\t--------|---------------------------|--------\n");
	printf("\t\t\t   %d    |%s %s Room:%s   |%dTL   \n",cst1->day,cst1->name,cst1->surname,cst1->room,staticprice);	
	printf("\t\t\t--------|---------------------------|--------\n");
	printf("\t\t\t        |        \t\tNET:|%2.2fTL  \n",netprice);
	printf("\n\n\t\t\tDATE:%i/%i/%i %.2i:%.2i\n\n",myTime->tm_mon+1,myTime->tm_mday,myTime->tm_year+1900,myTime->tm_hour,myTime->tm_min);
	FILE *fatura;
    char filename[sizeof "file100.txt"];
	//scanf("%s",filename);
	//strcpy(cst1->ID,filename);
    sprintf(filename, "%s%i%i%i%.2i%.2i%.2i.txt",cst1->ID,myTime->tm_mon+1,myTime->tm_mday,myTime->tm_year+1900,myTime->tm_hour,myTime->tm_min,myTime->tm_sec);
    fatura = fopen(filename,"w");
	fprintf(fatura,"\n\n\n\t\t\tCOLORFUL DREAMS HOTEL\n");
	fprintf(fatura,"\t\t\t___________________________________________");
	fprintf(fatura,"\n\t\t\t|INVOICE ID:\t %s%i%i%i%.2i%.2i%.2i|",cst1->ID,myTime->tm_mon+1,myTime->tm_mday,myTime->tm_year+1900,myTime->tm_hour,myTime->tm_min,myTime->tm_sec);
	fprintf(fatura,"\n\n\n");
	fprintf(fatura,"\t\t\tDAY\t|CUSTOMER\t\t    |PRICE\n");
	fprintf(fatura,"\t\t\t--------|---------------------------|--------\n");
	fprintf(fatura,"\t\t\t   %d    |%s %s Room:%s   |%dTL   \n",cst1->day,cst1->name,cst1->surname,cst1->room,staticprice);	
	fprintf(fatura,"\t\t\t--------|---------------------------|--------\n");
	fprintf(fatura,"\t\t\t        |        \t\tNET:|%2.2fTL  \n",netprice);
	fprintf(fatura,"\n\n\t\t\tDATE:%i/%i/%i %.2i:%.2i\n\n",myTime->tm_mon+1,myTime->tm_mday,myTime->tm_year+1900,myTime->tm_hour,myTime->tm_min);
    fclose(fatura);	
    printf("%s%i%i%i%.2i%.2i%.2i.txt",cst1->ID,myTime->tm_mon+1,myTime->tm_mday,myTime->tm_year+1900,myTime->tm_hour,myTime->tm_min,myTime->tm_sec);
	//system("notepad /P %s%i%i%i%.2i%.2i%.2i.txt",cst1->ID,myTime->tm_mon+1,myTime->tm_mday,myTime->tm_year+1900,myTime->tm_hour,myTime->tm_min,myTime->tm_sec);
//	printf("Listedeki Kisi Sayisi: %d\n",count);
	//printf("%i/%i/%i/%.2i/%.2i/%.2i\n",myTime->tm_mon+1,myTime->tm_mday,myTime->tm_year+1900,myTime->tm_hour,myTime->tm_min,myTime->tm_sec);
	//printf("%s\n",ctime(&currentTime));
/*	
	printf("Enter Day: ");
	scanf("%d",&day);
	netprice=day*staticprice;
	
	printf("\n\nNet Price: %2.2f\n\n",netprice);
	getch();*/

}
