// buat header
#ifndef header_H
#define header_H

#define MALE 1
#define FEMALE 0

#include <stdio.h>
#include <stdbool.h>
#include <time.h>

typedef char nbType[20];
typedef struct royalTree *nbAddr;
typedef struct pair *pairAddr;

struct identity{
    nbType name;
    struct tm birthDate; // tipe data struct tm menyimpan tanggal lahir
    bool gender;
};

typedef struct royalTree{
	nbAddr fs;
	nbAddr nb;
	nbAddr parent;
	struct identity info;
	pairAddr partner;
}nbTreeNode;

struct nbTree{
    nbAddr root;
};

typedef struct pair{
	struct identity info;
}nbPairNode;
	
nbAddr nbCNode(nbAddr parent, nbType name, struct tm birthDate, bool gender);

nbAddr nbSearch(nbAddr root, nbType src);

pairAddr nbCPartnerNode(nbType name, struct tm birthDate, bool gender);

void InsertVPartner(struct nbTree *pTree);

void InsertPartner(nbAddr familyMember, pairAddr partner);

void nbCreate(struct nbTree *X);

void nbPrint(nbAddr node);

bool isEmpty(struct nbTree X);

void InsertKing(struct nbTree *pTree);

void InsertNode(struct nbTree *tRoot, nbAddr newNode);

void insertPartner(struct nbTree *pTree);

#endif
