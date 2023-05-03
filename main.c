#include <stdio.h>
#include <conio.h>
#include "header.h"

int main(){
	struct nbTree pTree;
	char str[]="";
	
	nbCreate(&pTree);
	nbAddr node, king;
	InsertKing(&pTree);
	king = pTree.root;
	if((!isEmpty) && (king->info.birthDate.tm_year >= 80)){
           deleteNode(&king, &pTree);
	}
	system("CLS");
	printf("\n\n\tKeadaan Pohon Keluarga:\n");
	if (isEmpty(pTree)){
		printf("\tTree kosong");
	}
	else{
		//nbPrint(pTree.root);
	}
	}
