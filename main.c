#include <stdio.h>
#include <conio.h>
#include "header.h"

int main(){
	struct nbTree pTree;
	char str[]="";
	char tombol;
	nbCreate(&pTree);
	nbAddr node, king;
	PrintFromFile("assets/opening.txt");
	printf("\n\n");
	system("pause");
	system("cls");
	InsertKing(&pTree);
	do {	
		king = pTree.root;
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
		printf("\n\t4. Tampilkan Pendahulu");
		printf("\n\n\tPilihan %c ", 175);
		fflush(stdin);
		scanf("%c", &tombol);
		switch(tombol) {
			case '1' :
				system("cls");
				printf("\n\n");
				PrintFromFile("assets/king.txt");
				printf("\n\n");
				InsertVPartner(&pTree);
				break;
			case '2' :
				system("cls");
				printf("\n\n");
				PrintFromFile("assets/newmember.txt");
				InsertFamilyMember(&pTree);
				break;
			case '3' :
				system("cls");
				printf("\n\n")
				PrintFromFile("assets/crown.txt");
				DeleteNode(&pTree);
                break;
			case '4' :
				//PrintDeletedNodes("deleted_node.txt");
				system("cls");
				//PrintFromFile("deleted_node.txt");
				break;
		}
	} while (tombol != 0);
	return 0;
}	
