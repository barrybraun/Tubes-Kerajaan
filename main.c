#include <stdio.h>
#include <conio.h>
#include "header.h"

int main(){
	struct nbTree pTree;
	char str[]="";
	int tombol;
	nbCreate(&pTree);
	nbAddr node, king;
	InsertKing(&pTree);
	do {	
		king = pTree.root;
		if((!isEmpty) && (king->info.birthDate.tm_year >= 80)){
        	deleteNode(&king, &pTree);
		}
		system("CLS");
		printf("\n\n\tKeadaan Pohon Keluarga:\n");
		if (isEmpty(pTree)){
			printf("\tTree kosong");
		} else {
			nbPrint(pTree.root);
		}
		printf("/n/n/n/t1. Insert Partner");
	} while (tombol != 0);
	return 0;
}	
