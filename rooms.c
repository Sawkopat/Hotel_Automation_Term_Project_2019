#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct rooms{
	char roomID[4];
	char roomstd[2];
};
void main(){
	int i,j,menu;
	struct rooms *rms1=(struct rooms*)malloc(sizeof(struct rooms));
	struct rooms *rms2=(struct rooms*)malloc(sizeof(struct rooms));
	FILE *rfp1;
	FILE *rfp2;
	printf("\n\n[1]LISTELEME MENU\t\t[2]DUZENLEME MENU\n\n");
	printf("Secim: ");
	scanf("%d",&menu);
	switch(menu){
/*	rfp1=fopen("rooms.txt","w");
		for(i=0;i<30;i++){
			printf("ROOM  %d",i+1);
			printf("\n RoomID: ");
			scanf("%s",(rms1+i)->roomID);
			printf("\n Status: ");
			scanf("%s",(rms1+i)->roomstd);
			fwrite((rms1+i),sizeof(struct rooms),1,rfp1);
		}
		fclose(rfp1);
		rfp2=fopen("rooms.txt","r");
		//while(!feof(rfp2)){
		for(j=0;j<30;j++){
			fread((rms1+i),sizeof(struct rooms),1,rfp2);
			printf("%s %s\n",(rms1+j)->roomID,(rms1+j)->roomstd);
		//	printf("%s %s\n",rms2->roomID,rms2->roomstd);
		}
		fclose(rfp1);*/
		case 1:
			rfp1=fopen("rooms.txt","r");
			for(i=0;i<30;i++){
				fread((rms1+i),sizeof(struct rooms),1,rfp1);
				printf("%s - %s ||",(rms1+i)->roomID,(rms1+i)->roomstd);
			}
			fclose(rfp1);
			break;
		case 2:
			rfp1=fopen("rooms.txt","r+");
			char currID[4];
			printf("\nSearch roomID: ");
			scanf("%s",currID);
			for(i=0;i<30;i++){
				fread((rms1+i),sizeof(struct rooms),1,rfp1);
				printf("%s-%s || ",(rms1+i)->roomID,(rms1+i)->roomstd);
				if(strcmp((rms1)->roomID,currID)==0){
					char newRoomName[4];
					printf("\nNew Name: ");scanf("%s",newRoomName);
					strcpy(rms1->roomID,newRoomName);
					strcpy(rms1->roomstd,"1");
					printf("\nCurrent New Name= %s\n",rms1->roomID);
					fseek(rfp1,-1*sizeof(struct rooms),SEEK_CUR);
					fwrite(rms1,sizeof(struct rooms),1,rfp1);
					
				}
			}
			fclose(rfp1);
			
			break;
	}
}
