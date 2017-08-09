#include <malloc.h>
#include <stdio.h>
#define FALSE 0
#define TRUE 1

// -------------- LISTA DINAMICA (COM CHAVE) ----------------

typedef struct estrutura{
	int info;
	struct estrutura *prox;
} NO;

typedef struct {
	NO* inicio;
} LISTA;// DINAMICA


// Inicialização
void inicializar(LISTA *li){
	li->inicio = NULL;
}


NO* ultimoElem(LISTA li){
	NO* p = li.inicio;
	if(p)
		while(p->prox) p = p->prox;
	return p;
}


// Busca pela info na lista retornando p e ant
NO* buscaSeq(int info, LISTA li, NO* *ant) {
	NO* p = li.inicio;
	*ant = NULL;
	while(p){
        if (p->info == info)
            return p;
		*ant = p;
		p = p->prox;
	}
	return NULL;
}


// Anexar novo elemento ao final da lista
int inserirElem(int info, LISTA *li){
    NO* ant;
	NO* novoNo = buscaSeq(info,*li, &ant);
	if(novoNo)
        return FALSE;
	novoNo = (NO*) malloc(sizeof(NO));
	ant = ultimoElem(*li);
	novoNo->info = info;
	novoNo->prox = NULL;
	if(!ant) li->inicio = novoNo;
	else ant->prox = novoNo;
	return TRUE;
}


// Exclusão de info
int excluirElem(int info, LISTA *li){
	NO* ant;
	NO* elem;
	elem = buscaSeq(info, *li, &ant);
	if(!elem)
        return FALSE; // nada a excluir
	if(!ant)
        li->inicio = elem->prox; // exclui 1o. elemento da lista
	else
        ant->prox = elem->prox; // exclui elemento que possui ant
    elem->prox = NULL;
    printf("\nExcluido %i com sucesso.\n", info);
	free(elem);
	return TRUE;
}

