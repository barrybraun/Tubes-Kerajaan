#ifndef header_H
#define header_H

#define MALE 1
#define FEMALE 0

#include <stdio.h>
#include <stdbool.h>
#include <time.h>

typedef char nbType[20];
typedef struct royalTree *nbAddr;

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
//	struct identity partner;
}nbTreeNode;

struct nbTree{
    nbAddr root;
};

void nbCreate(struct nbTree *X);

bool isEmpty(struct nbTree X);

void InsertKing(struct nbTree *pTree);

void InsertNode(struct nbTree *tRoot, nbAddr newNode);

#endif