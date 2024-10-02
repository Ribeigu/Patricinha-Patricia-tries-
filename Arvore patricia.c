#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct no{
	int chave;
	int bit;
	struct no *esq, *dir;
}NO;

void inicializa(NO **arvore){
	*arvore =(NO*)malloc(siezeof(NO));
	(*arvore)->chave = UNIT_MAX;
	(*arvore)->esq = (*arvore)->dir = *arvore;
	(*arvore)->bit= -1;
}

int bit(unsigned x, int n){
	return(x>>n) & 1;
}

NO *buscaRec(NO *arvore, int x, int w){
	if(arvore->bit <= w)
		return arvore;
	if(bit(x,arvore->x)==0){
		return buscaRec(arvore->esq, x, arvore->bit);
	}else{
		return buscaRec(arvore->dir, x, arvore->bit);
	}
}

NO *busca(NO *arvore, int x){
	NO *t = buscaRec(arvore->esq, x, -1);
	return t->chave == x ? t : NULL;
}

NO *insereRec (NO *arvore, int chave, int w, NO *pai){
	NO *novo;
	if((arvore->bit=w) || arvore->bit<=pai->bit){
		novo = (NO*)malloc(sizeof(NO));
		novo->chave = chave;
		novo->bit=w;
		if(bit(chave, novo->bit) ==1){
			novo->esq=arvore;
			novo->dir=novo;
		}else{
			novo->esq=novo;
			novo->dir=arvore;
		}
		return novo;
	}
	if(bit(chave, arvore->bit) ==0){
		arvore->esq=insereRec(arvore->esq,chave, w, arvore);
	}else{
		arvore->dir=insereRec(arvore->dir,chave, w, arvore);
	}
	return arvore;
}

/* PONTEIRO DUPLO
 Ponteiro que aponta para um ponteiro
*/
void **insere(NO **arvore, int chave){
	int i;
	NO *t = buscaRec((*arvore)->esq, chave, -1);
	if(t->chave == chave) return NULL;
	for (i = 0; bit(chave, i) == bit(t->chave, i); i++){
		(*arvore)->esq= insere_rec((*arvore)->esq, chave, i, *arvore);
	}
}

void remove(NO *arvore, int x){
    NO *t= busca(arvore->esq, x, -1);
    if(t==NULL){
        printf("A chave %d não existe na arvore", x);
        return NULL;
    }
    if(t->chave==x){


    }
}