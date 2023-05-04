#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
#include <time.h>

void nbCreate(struct nbTree *X){
    X->root=NULL;
}

bool isEmpty(struct nbTree X){
    return (X.root==NULL);
}

nbAddr nbSearch(nbAddr root, nbType src){
	nbAddr nSrc;
	if (root!=NULL){
		if (strcmp(root->info.name, src)==0){
			return root;
		}
		if(root->partner!=NULL){
			if(strcmp(root->partner->info.name, src)==0){
				return root;
			}
		}
		nSrc=nbSearch(root->fs,src);
		if (nSrc==NULL)
			return nbSearch(root->nb,src);
		else
			return nSrc;
	}
	return NULL;
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
        newNode->partner = 0;
    }
    return newNode;
}

pairAddr nbCPartnerNode(nbType name, struct tm birthDate, bool gender){
	pairAddr   newNode;
	//int age;
	newNode = (pairAddr) malloc(sizeof(nbPairNode));

	if (newNode != NULL){
		strcpy(newNode->info.name, name);
		newNode->info.birthDate = birthDate;
		newNode->info.gender = gender;
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
    scanf(" %[^\n]", &name);

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
    printf("\n\t  RANGE UMUR RAJA/RATU : 50 TAHUN-80 TAHUN (1943-1973)");
    printf("\n\t%c Tanggal lahir (dd-mm-yyyy): ", 175);
    scanf("%d-%d-%d", &birthDate.tm_mday, &birthDate.tm_mon, &birthDate.tm_year);
    
    /*Hitung umur dari birthdate*/
    birthDate.tm_year = 2023-birthDate.tm_year;
    if(birthDate.tm_year<50) {
    	printf("\n\t  Umur Raja/Ratu Tidak Memenuhi Kualifikasi Umur\n\n");
    	system("pause");
    	system("cls");
		InsertKing(pTree);
	}
	 if(birthDate.tm_year>80 ) {
    	printf("\n\t  Umur Raja/Ratu Tidak Memenuhi Kualifikasi Umur\n\n");
    	system("pause");
    	system("cls");
		InsertKing(pTree);
	}else{
    /*Alokasi node*/
    king = nbCNode(NULL, name, birthDate , gender);
    /*Insert ke tree*/
    InsertNode(pTree, king);
    printf("\n\t  Raja/ ratu berhasil ditambahkan");
    getch();
}
}

void InsertVPartner(struct nbTree *pTree){
	nbAddr srcNode;
	pairAddr partner;
	bool gender;
	nbType name, partnerName;
	int age;
	struct tm birthDate;

	/*Search node*/
	printf("\n\n\tMasukan 'q' untuk kembali\n");
	printf("\tUmur minimal untuk menikah adalah 18 tahun\n");
	do{
		printf("\n\t%c Nama anggota keluarga yang akan menikah: ", 175);
		scanf(" %[^\n]", &name);
		if(strcmp(name, "q")==0){
			return;
		}
		srcNode=nbSearch((*pTree).root, name);

		if(srcNode == NULL){
			printf("\t[x] Anggota keluarga tidak ditemukan\n");
		}else if(srcNode->partner != NULL){
			printf("\t[x] Anggota keluarga tersebut sudah memiliki pasangan\n");
		//}else if(srcNode->info.birthDate < 18){
		//	printf("\t[x] Anggota keluarga tersebut masih dibawah umur\n");
		}else{
			break;
		}
	}while(1);

	/*Get gender*/
	if(srcNode->info.gender == 1){
		gender = false;
	}else{
		gender = true;
	}

	/*Insert identitas partner*/
	do{
		printf("\n\t%c Masukan nama pasangan: ", 175);
		scanf(" %[^\n]", &partnerName);
		if(nbSearch((*pTree).root, partnerName)!=NULL){ /*Check jika ada node yg memiliki nama yg sama di tree*/
			printf("\t[x] Nama orang tersebut sudah ada pada pohon keluarga\n");
		}else{
			break;
		}
	}while(1);
	do{
		fflush(stdin);
		printf("\n\tUmur pasangan minimal 18 tahun\n");
		printf("\t%c Masukan usia pasangan: ", 175);
		scanf(" %d", &age);
		birthDate.tm_year = age;

		if(age < 18){
			printf("\t[x] Pasangan masih dibawah umur\n");
		}else{
			break;
		}
	}while(true);

	/*Alokasi partner*/
	partner = nbCPartnerNode(partnerName, birthDate, gender);

	/*Insert ke tree*/
	InsertPartner(srcNode, partner);
	printf("\n\t[o] Pasangan berhasil ditambahkan");
	getch();
}

void InsertPartner(nbAddr familyMember, pairAddr partner){
	familyMember->partner = partner;
}

void InsertNode(struct nbTree *tRoot, nbAddr newNode) {
    nbAddr temp;

    /* Jika belum ada root */
    if (newNode->parent == NULL) {
        tRoot->root = newNode;
        return;
    }
	
    temp = newNode->parent;

    /* Jika tidak memiliki first son */
    if (temp->fs == NULL) {
        temp->fs = newNode;
        return;
    }

    /* Bandingkan prioritas fs dengan newNode */
    temp = temp->fs;

    if (newNode->info.gender == MALE && temp->info.gender == FEMALE) {
        /* Jika newNode laki-laki dan fs perempuan, maka jadikan newNode sebagai first son */
        newNode->nb = temp->fs;
        temp->fs = newNode;
        return;
    }

    if (newNode->info.gender == temp->info.gender) {
        if (difftime(mktime(&newNode->info.birthDate), mktime(&temp->info.birthDate)) > 0) {
            /* Jika newNode dan fs memiliki jenis kelamin yang sama dan newNode lebih tua dari fs, maka jadikan newNode sebagai first son */
            newNode->nb = temp->fs;
            temp->fs = newNode;
            return;
        }

        /* Jika prioritas newNode lebih rendah daripada fs */
        /* Jika newNode laki-laki */
        if (newNode->info.gender == MALE) {
            /* Travers hingga ketemu next brother yang umurnya lebih muda atau yang jenis kelaminnya perempuan */
            while (temp->nb != NULL && temp->nb->info.gender == MALE && difftime(mktime(&newNode->info.birthDate), mktime(&temp->nb->info.birthDate)) <= 0) {
                temp = temp->nb;
            }
        }

        /* Jika newNode perempuan */
        if (newNode->info.gender == FEMALE) {
            /* Travers selama next brother jenis kelamin laki-laki, kemudian travers hingga menemukan next brother yang umurnya lebih muda */
            while (temp->nb != NULL && temp->nb->info.gender == MALE) {
                temp = temp->nb;
            }
            while (temp->nb != NULL && difftime(mktime(&newNode->info.birthDate), mktime(&temp->nb->info.birthDate)) <= 0) {
                temp = temp->nb;
            }
        }

        if (temp->nb != NULL) { /* Jika prioritas newNode berada di tengah */
            newNode->nb = temp->nb;
            temp->nb = newNode;
            return;
        }

        /* Jika prioritas newNode paling rendah */
        temp->nb = newNode;
    }
}
    

void InsertFamilyMember(struct nbTree *pTree){
	nbAddr parentNode, newMemberNode;
	nbType name, parentName;
	int temp;
	int age;
	bool gender;
	struct tm birthDate;

	/*Cari parent*/
	printf("\n\tMasukan 'q' untuk kembali\n");
	do{
		printf("\n\t%c Nama orang tua: ", 175);
		scanf(" %[^\n]", &parentName);
		if(strcmp(parentName, "q")==0){
			return;
		}
		parentNode = nbSearch((*pTree).root, parentName);
		if(parentNode == NULL){
			printf("\t[x] Nama orang tua tidak ditemukan\n");
		}else if(parentNode->partner == NULL){
			printf("\t[x] Orang tersebut tidak memiliki pasangan\n");
		}else{
			break;
		}
	}while(1);

	/*Insert nama*/
	do{
		printf("\n\t%c Masukan nama: ", 175);
		scanf(" %[^\n]", &name);
		if(nbSearch((*pTree).root, name)!=NULL){ /*Check jika ada node yg memiliki nama yg sama di tree*/
			printf("\t[x] Nama orang tersebut sudah ada pada pohon keluarga\n");
		}else{
			break;
		}
	}while(1);

	/*Insert tanggal lahir*/
	do{
    printf("\n\t%c Tanggal lahir (dd-mm-yyyy): ", 175);
    scanf("%d-%d-%d", &birthDate.tm_mday, &birthDate.tm_mon, &birthDate.tm_year);
    birthDate.tm_year = 2023-birthDate.tm_year;

	/*Insert jenis kelamin*/
	
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

	/*Alokasi node*/
	newMemberNode = nbCNode(parentNode, name, birthDate, gender);

	/*Insert ke tree*/
	InsertNode(pTree, newMemberNode);
	printf("\n\t[o] Anggota keluarga berhasil ditambahkan");
	getch();
}

void nbPrint(nbAddr node) {
    if (node == NULL) return;
    printf("\t%c Nama: %s\n", 175, node->info.name);
    printf("\t  Jenis kelamin: %s\n", node->info.gender == MALE ? "Pria" : "Wanita");
    printf("\t  Umur : %d\n", node->info.birthDate.tm_year);
    	if (node->partner == NULL){
    		printf("\t  Tidak Memiliki Pasangan\n");
    	}else{
    		printf("\t  Pasangan : %s\n",node->partner->info.name);	
		}
		
		if (node->parent == NULL){
			printf("\t  Merupakan Root\n");
		}else{
			printf("\t  Parent adalah : %s\n",node->parent->info.name);
		}

    /* Cek apakah node memiliki first son */
    if (node->fs != NULL) {
        printf("\t  Anak:\n");
        nbPrint(node->fs);
    }

    /* Cek apakah node memiliki next brother */
    else if (node->nb != NULL) {
        printf("\t  Saudara kandung:\n");
        nbPrint(node->nb);
    }
}

void DeleteNode(struct nbTree *pTree) {
    char name[30];
    printf("\n\tMasukkan nama orang yang ingin dihapus: ");
    scanf(" %[^\n]", name);
    nbAddr toDelete = nbSearch(pTree->root, name);

    if (toDelete == NULL) {
        printf("\t[x] Orang dengan nama tersebut tidak ditemukan.\n");
        return;
    }

    if (toDelete == pTree->root && toDelete->nb == NULL && toDelete->fs == NULL) {
        printf("\t[x] Tidak bisa menghapus raja/raja dari pohon keluarga.\n");
        return;
    }

    if (toDelete->nb == NULL && toDelete->fs == NULL) {
        nbAddr parent = toDelete->parent;
        if (parent->fs == toDelete) {
            parent->fs = NULL;
        } else {
            parent->nb = NULL;
        }
        free(toDelete);
        printf("\t[o] Orang dengan nama %s berhasil dihapus.\n", name);
        return;
    }

    printf("\t[x] Orang dengan nama tersebut tidak bisa dihapus karena masih memiliki anak/cucu.\n");
    return;
}
