#include <stdio.h>
#include <conio.h>
#include "header.h"

int main(){
	struct nbTree pTree;
	char str[]="";
	char tombol;
	nbCreate(&pTree);
	nbAddr node, king;
	InsertKing(&pTree);
	do {	
		king = pTree.root;
		if((!isEmpty) && (king->info.birthDate.tm_year >= 80)){
        	deleteNode(&pTree);
		}
		system("CLS");
		printf("\n\n\tKeadaan Pohon Keluarga:\n");
		if (isEmpty(pTree)){
			printf("\tTree kosong");
		} else {
			nbPrint(pTree.root);
		}
		printf("\n\n\n\t1. Insert Partner");
		printf("\n\t2. Insert Anggota Keluarga");
		printf("\n\t3. Hapus Anggota");
		printf("\n\n\tPilihan %c ", 175);
		fflush(stdin);
		scanf("%c", &tombol);
		switch(tombol) {
			case '1' :
				system("cls");
				InsertVPartner(&pTree);
				break;
			case '2' :
				system("cls");
				InsertFamilyMember(&pTree);
				break;
			case '3' :
				system("cls");
				DeleteNode(&pTree);
				break;
		}
	} while (tombol != 0);
	return 0;
}	
