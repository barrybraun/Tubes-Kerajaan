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

/* Dibuat oleh Barry Arganeza*/
nbAddr nbCNode(nbAddr parent, nbType name, struct tm birthDate, bool gender);

/* Dibuat oleh Barry Arganeza*/
nbAddr nbSearch(nbAddr root, nbType src);

/* Dibuat oleh Barry Arganeza*/
pairAddr nbCPartnerNode(nbType name, struct tm birthDate, bool gender);

/* Dibuat oleh Barry Arganeza*/
void InsertVPartner(struct nbTree *pTree);

/* Dibuat oleh Barry Arganeza*/
void InsertPartner(nbAddr familyMember, pairAddr partner);

/* Dibuat oleh Aqila Ghifari Wandana*/
void nbCreate(struct nbTree *X);

/* Dibuat oleh Aqila Ghifari Wandana*/
void nbPrint(nbAddr node);

/* Dibuat oleh Arya Putra Kusumah */
bool isEmpty(struct nbTree X);

/* Dibuat oleh Aqila Ghifari Wandana*/
void InsertKing(struct nbTree *pTree);

/* Dibuat oleh Aqila Ghifari Wandana*/
void InsertNode(struct nbTree *tRoot, nbAddr newNode);

/* Dibuat oleh Barry Arganeza*/
void insertPartner(struct nbTree *pTree);

/* Dibuat oleh Arya Putra Kusumah */
void DeleteNode(struct nbTree *pTree);

/* Dibuat oleh Barry Arganeza*/
void PrintFromFile(const char* location);

/* Dibuat oleh Aqila Ghifari Wandana*/
void PrintDeletedNodes(const char* location);

/* Dibuat oleh Aqila Ghifari Wandana*/
void saveDeletedNode(const char* location, nbAddr deletedNode);

/* Dibuat oleh Aqila Ghifari Wandana*/
void saveToFile(const char* location, nbAddr node);


#endif
