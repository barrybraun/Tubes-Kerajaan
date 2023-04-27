#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void nbCreate(struct nbTree *X){
    X->root=NULL; // use -> to access struct members since X is a pointer
}

bool isEmpty(struct nbTree X){
    return (X.root==NULL);
}

nbAddr nbCNode(nbAddr parent, nbType name, struct tm birthDate, bool gender){
    nbAddr newNode;
    newNode=(nbAddr) malloc(sizeof(nbTreeNode));

    if (newNode != NULL){
        newNode->fs=NULL;
        newNode->nb=NULL;
        newNode->parent=parent;
        strcpy(newNode->info.name, name);
        newNode->info.birthDate=birthDate;
        newNode->info.gender=gender;
        struct identity id;
    	//newNode->partner=NULL; // initialize partner to NULL
    }
    return newNode;
}

void InsertKing(struct nbTree *pTree){
    nbAddr king;
    nbType name;
    int temp;
    struct tm birthDate;
    bool gender;

    /*Insert nama*/
    printf("\n\tMasukan Identitas Raja/ Ratu:\n");
    printf("\n\t%c Nama: ", 175);
    scanf(" %[^\n]", name); // no need to use & since name is already an array

    /*Insert jenis kelamin*/
    do{
        printf("\n\t%c Pilih jenis kelamin\n", 175);
        printf("\t  0. Wanita\n");
        printf("\t  1. Pria\n");
        printf("\t  Pilihan: ");
        scanf(" %d", &temp);
        if(temp != 0 && temp != 1){
            printf("\t[x] Input tidak valid\n");
        }else{
            gender = temp;
            break;
        }
    }while(1);

    /*Insert tanggal lahir*/
    printf("\n\t%c Tanggal lahir (dd-mm-yyyy): ", 175);
    scanf("%d-%d-%d", &birthDate.tm_mday, &birthDate.tm_mon, &birthDate.tm_year);
    birthDate.tm_mon -= 1; // tm_mon dimulai dari 0 (Januari)
    birthDate.tm_year -= 1900; // tm_year dimulai dari 1900

    /*Insert umur raja atau ratu*/
    printf("\n\t%c Umur: ", 175);
    scanf("%d", &temp);
    if(temp < 0){
        printf("\t[x] Input tidak valid\n");
    }else{
        birthDate.tm_year += temp; // tambahkan umur ke tahun lahir
    }

    /*Alokasi node*/
    king = nbCNode(NULL, name, birthDate , gender);

    /*Insert ke tree*/
    InsertNode(pTree, king);
    printf("\n\t[o] Raja/ ratu berhasil ditambahkan");
    getch();
}

void InsertNode(struct nbTree *tRoot, nbAddr newNode){
	nbAddr temp;
	/*Jika belum ada root*/
	if(newNode->parent==NULL){
		tRoot->root=newNode;
		return;
	}
	
	temp=newNode->parent;
	/*Jika tidak memiliki first son*/
	if(temp->fs==NULL){
		temp->fs=newNode;
		return;
	}
	
	/*Bandingkan prioritas fs dengan newNode*/
	temp=temp->fs;
	if(newNode->info.gender==MALE && temp->info.gender==FEMALE){
		newNode->nb = temp->fs;
		temp->fs = newNode;
		return;
	}
	
	if(newNode->info.gender == temp->info.gender){
		if(newNode->info.birthDate > temp->info.birthDate){
			newNode->nb = temp->fs;
			temp->fs = newNode;
			return;
		}
	}
	
	/*Jika prioritas newNode lebih rendah daripada fs*/
	/*Jika newNode male*/
	if(newNode->info.gender==MALE){
		/*Travers hingga ketemu next brother yang umurnya lebih muda atau yang gendernya female*/
		while(temp->nb!=NULL && temp->nb->info.gender == MALE && newNode->info.birthDate <= temp->nb->info.birthDate){
			temp = temp->nb;
		}
	}
	
	/*Jika newNode female*/
	if(newNode->info.gender==FEMALE){
		/*Travers selama next brother male, kemudian travers hingga menemukan next brother yang umurnya lebih muda*/
		while(temp->nb!=NULL && temp->nb->info.gender == MALE){
			temp=temp->nb;
		}
		while(temp->nb!=NULL && newNode->info.birthDate <= temp->nb->info.birthDate){
			temp=temp->nb;
		}
	}
	
	if(temp->nb!=NULL){ /*Jika prioritas newNode berada di tengah*/
		newNode->nb = temp->nb;
	    temp->nb = newNode;
	    return;
	} 
	
	/*Jika prioritas newNode paling rendah*/
	temp->nb=newNode;
}