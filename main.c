#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct customer{
	char name[20];
	char surname[20];
	char ID[12];
	char room[5];
	int day;
//	float cprice;
};
struct rooms{
	char roomID[5];
	int roomstd;
};
void main(){
	struct customer *cst1=(struct customer*)malloc(sizeof(struct customer));
	struct customer *cst2=(struct customer*)malloc(sizeof(struct customer));
	struct customer *temp=(struct customer*)malloc(sizeof(struct customer));
	struct rooms    *rms1=(struct rooms*)malloc(sizeof(struct rooms));
	float price=260;
	char uname1[15],uname2[15],pw1[15],pw2[15];
	int log1=0,menu,dng,maxp,i,j,k,attempt=0;
	FILE *ufp;
	FILE *fp1;
	FILE *rfp1;
	ufp=fopen("users.txt","r");
	fscanf(ufp,"%s %s",uname1,pw1);
	do{//LOGIN LOOP START
		printf("\t\t\t##############################\n\t\t\t#\t\t\t     #\n\t\t\t#   Welcome. Please Login    #\n\t\t\t#\t\t\t     #\n\t\t\t##############################\n ");
		printf("\n\t\t\tUsername: ");
		scanf("%s",uname2);
		printf("\n\t\t\tPassword: ");
		scanf("%s",pw2);
		if(attempt==3){
			exit(0);
		}
		else{
			if(strcmp(uname1,uname2)==0&&strcmp(pw1,pw2)==0){
				//system("cls");
				//printf("\tHosgeldiniz\n\n");
				log1=0;
				dng=1;
			}
			else{
				system("cls");
				attempt+=1;
				printf("\n\t\t\tWrong username or password\n\t\t\tAttempt: %d/3\n",attempt);
				log1=1;
				dng=0;
			}
		}
		fclose(ufp);
		while(dng){ //MENU LOOP
			system("cls");
			printf("\t\t\t###########################################\n\t\t\t#\t\t\t                  #\n\t\t\t#     Welcome to Colorful Dreams Hotel    #\n\t\t\t#\t\t\t                  #\n\t\t\t###########################################\n ");
			printf("\t\t\t\t\t     ");
			status(fp1,cst2);//REGISTERED STATUS FUNCTION
			printf("\n\n\t\t\t[1]New Customer Registration \n\t\t\t[2]Edit Registration \n\t\t\t[3]Delete Reservation \n\t\t\t[4]Customer List \n\t\t\t[5]LogOut \n\t\t\t[0]Exit\n");
			printf("\n\t\t\tValue: ");
			scanf("%d",&menu);
			switch(menu){
				case 1:
					dng=0;
					printf("\t\t\t\t------|Reservation Register Menu |------");
					printf("\n\t\tHow many Person: ");
					scanf("%d",&maxp);
					for(i=0;i<maxp;i++){
						printf("Person %d",i+1);
						printf("\n Name: ");
						scanf("%s",(cst1+i)->name);
						printf("\n Surname: ");
						scanf("%s",(cst1+i)->surname);
						printf("\n ID: ");
						scanf("%s",(cst1+i)->ID);
						printf("\n Room: ");
						scanf("%s",(cst1+i)->room);
						printf("\n Day: ");
						scanf("%d",&(cst1+i)->day);
						fp1=fopen("customer.txt","a");
						rfp1=fopen("rooms.txt","r+");
					/*	for(j=0;j<30;j++){
							if(strcmp((cst1+i)->room,(rms1+j)->roomID)==0){
								strcpy((rms1+i)->roomstd,"0");
								fseek(rfp1,-1*sizeof(struct rooms),SEEK_CUR);
				                fwrite(rms1,sizeof(struct rooms),1,rfp1);
							}
						}*/
						fwrite((cst1+i),sizeof(struct customer),1,fp1);
						fclose(fp1);
					}
				system("start invoice.exe");
					dng=1;
					break;
				case 2:
					reservationMenu(fp1,cst1);
					break;
					dng=1;
				case 3:
					printf("\t\t\t\t------|Reservation Delete Menu |------");
					FILE *fp2=fopen("customer.txt","r");
					FILE *tempfp=fopen("customer2.txt","w");
					char TID2[12]; 
						printf("\nSearch ID: ");
						scanf("%s",TID2);
						rewind(fp2);
					for(i=0;i<statusNum(fp1,cst2);i++){ 
					//while(!feof(fp2)){
						fread(cst2,sizeof(struct customer),1,fp2);
							if(strcmp(cst2->ID,TID2)!=0){
								fwrite(cst2,sizeof(struct customer),1,tempfp);
							}
	                    }
	                    fclose(tempfp);
						fclose(fp2);
						remove("customer.txt");
						rename("customer2.txt","customer.txt");
					
					break;
				case 4:
					printf("\t\t\t______|Customer List|______\n");
					printf("\t\t\tID\tNAME\tSURNAME\tROOM\tDAY\tPRICE\n\t\t\t-----------------------------------\n");
					fp1=fopen("customer.txt","r");
					for(i=0;i<statusNum(fp1,cst2);i++){
				//while(!feof(fp1)){
						fread(cst2,sizeof(struct customer),1,fp1);
						printf("\t\t\t%s\t%s\t%s\t%s\t%d\n",cst2->ID,cst2->name,cst2->surname,cst2->room,cst2->day);
					}
					//break;
					int count;
					printf("\n\t\t\tListede > %d < Kisi VAR\n",statusNum(fp1,cst2));
					dng=0;
					printf("\n\t\t\t [0]Turn Back\n");
					int turnback=1;
					printf("\t\t\tEnter Number: ");
					scanf("%d",&turnback);
					if(turnback==0){
						dng=1;
					}
					fclose(fp1);
					break;
				case 5:
					system("cls");
					dng=0;
					log1=1;
					break;
				case 0:
					printf("------|Exit|------");
					exit(1);
					break;
				default:
					//farklý sayý girince yeniden seçtiriyor.
					printf("Wrong Choose\n");
					dng=1;
					break;
			}//Switch menu SON
		}//while d1 SON
	}while(log1);//LOGIN RETURN
	
}
void reservationMenu(FILE *fp1,struct customer *cst1){
//	#include "statusnumber.h"
		printf("------|Reservation Edit Menu |------");
						fp1=fopen("customer.txt","r+");
						char TID[11];
						int nislemloop,i;
						printf("\nSearch ID: ");
						scanf("%s",TID);
						FILE *cst2;
						for(i=0;i<statusNum(fp1,cst2);i++){
		                    fread(cst1,sizeof(struct customer),1,fp1);
		                   	do{
							    printf("ID \t NAME \t SURNAME \t ROOM");
			                    printf("\n---------------------------------------------------");
			                    printf("\n%s\t",cst1->ID);
			                    printf("%s\t",cst1->name);
			                    printf("%s\t",cst1->surname);
			                    printf("%s\n",cst1->room);
			                    
			                    if(strcmp((cst1)->ID,TID)==0){
			                    	char newname[15];
			                    	char newsurname[15];
			                    	char newID[11];
			                    	char newroom[4];
			                    	
			                    	int nislem;
				                    	printf("Enter value.\n Change Name[1]   Change Surname[2]   Change newID[3]   Change Room[4]   Turn Back[0]\n");
				                    	scanf("%d",&nislem);
				                    	if(nislem==1){
				                    		printf("New Name: ");scanf("%s",newname);
				                    	strcpy(cst1->name,newname);
				                    	printf("Current New Name= %s",cst1->name);
				                    	fseek(fp1,-1*sizeof(struct customer),SEEK_CUR);
				                    	fwrite(cst1,sizeof(struct customer),1,fp1);
										}
										if(nislem==2){
											printf("New SurName: ");scanf("%s",newsurname);
				                    	strcpy(cst1->surname,newsurname);
				                    	printf("Current New SurName= %s",cst1->surname);
				                    	fseek(fp1,-1*sizeof(struct customer),SEEK_CUR);
				                    	fwrite(cst1,sizeof(struct customer),1,fp1);
										}
				                    	if(nislem==3){
				                    		printf("New newID: ");scanf("%s",newID);
				                    	strcpy(cst1->ID,newID);
				                    	printf("Current New ID= %s",cst1->ID);
				                    	fseek(fp1,-1*sizeof(struct customer),SEEK_CUR);
				                    	fwrite(cst1,sizeof(struct customer),1,fp1);
										}
										if(nislem==4){
											printf("New Room: ");scanf("%s",newroom);
				                    	strcpy(cst1->room,newroom);
				                    	printf("Current New Room= %s",cst1->room);
				                    	fseek(fp1,-1*sizeof(struct customer),SEEK_CUR);
				                    	fwrite(cst1,sizeof(struct customer),1,fp1);
										}
										
										if(nislem==0){
											nislemloop=0;
											break;
										}
									}
								}while(nislemloop);
							}
				   	fclose(fp1);
}
void status(FILE *fp1,struct customer *cst2){
	int count=0;
	fp1=fopen("customer.txt","r");
	while(!feof(fp1)){
		fread(cst2,sizeof(struct customer),1,fp1);
		count+=1;
	}
	count-=1;
	printf("Registered Customer: %d",count);
	fclose(fp1);
}
int statusNum(FILE *fp1,struct customer *cst2){
	int count=0;
	fp1=fopen("customer.txt","r");
	while(!feof(fp1)){
		fread(cst2,sizeof(struct customer),1,fp1);
		count+=1;
	}
	count-=1;
	//printf("Registered Customer: %d",count);
	fclose(fp1);
	return count;
}



