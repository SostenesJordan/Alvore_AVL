#include <iostream>
#include<locale.h>
#include<math.h>
#include <stdio.h>
#include "Cabecalho.h"

using namespace std;

struct NO
{
	int informacao;
	int altura;
	struct NO* esquerda;
	struct NO* direita;
};


//Funções auxiliares

// Função auxiliar para calcula a altura de um nó
int altura_no(struct NO* no) {
	if (no == NULL) {
		return -1;
	}
	else{
		return no->altura;
	}
}


//calcula o fator de balanceamento de um nó.
int fatorBalanceamento_NO(struct NO* no) {
	return labs(altura_no(no->esquerda) - altura_no(no->direita));
}

//calcula o maior valor
int maior(int x, int y) {
	if (x > y) {
		return x;
	}
	else
	{
		return y;
	}
}


//Fim das funções auxiliares










//Funções de rotação

void RotacaoLL(ArvAVL* raiz) {

	struct NO* no;
	no = (*raiz)->esquerda;
	(*raiz)->esquerda = no->direita;
	no->direita = (*raiz);
	(*raiz)->altura = maior(altura_no((*raiz)->esquerda), altura_no((*raiz)->direita)+1);

	no->altura = maior(altura_no(no->esquerda), (*raiz)->altura +1);

	*raiz = no;
}

void RotacaoRR(ArvAVL* raiz) {

	struct NO* no;
	no = (*raiz)->direita;
	(*raiz)->direita = no->esquerda;
	no->esquerda = (*raiz);
	(*raiz)->altura = maior(altura_no((*raiz)->esquerda), altura_no((*raiz)->direita) + 1);

	no->altura = maior(altura_no(no->direita), (*raiz)->altura + 1);

	*raiz = no;

}

void RotacaoLR(ArvAVL* raiz) {

	RotacaoRR(&(*raiz)->esquerda);
	RotacaoLL(raiz);
}

void RotacaoRL(ArvAVL* raiz) {

	RotacaoLL(&(*raiz)->direita);
	RotacaoRR(raiz);
}

//Fim das funções de rotação





//Função de inserção

int insere_ArvAVL(ArvAVL* raiz, int valor) {

	int res;
	if (*raiz == NULL) {
		struct NO* novo;
		novo = (struct NO*)malloc(sizeof(struct NO));

		if (novo == NULL) {
			return 0;
		}

		novo->informacao = valor;
		novo->altura = 0;
		novo->esquerda = NULL;
		novo->direita = NULL;
		*raiz = novo;
		return 1;
	}

	struct NO* atual = *raiz;
	if (valor < atual->informacao) {
		if (res = insere_ArvAVL(&(atual->esquerda),valor) == 1){
			if (fatorBalanceamento_NO(atual) >= 2) {
				if (valor < (*raiz)->esquerda->informacao) {
					RotacaoLL(raiz);
				}
				else
				{
					RotacaoLR(raiz);
				}
			}
		}
	}
	else
	{
		if (valor > atual->informacao) {
			if (res = insere_ArvAVL(&(atual->direita), valor) == 1) {
				if (fatorBalanceamento_NO(atual) >= 2) {
					if ((*raiz)->direita->informacao < valor) {
						RotacaoRR(raiz);
					}
					else
					{
						RotacaoRL(raiz);
					}
				}
			}
		}
		else {
			cout << "Valor duplicado" << endl;
			return 0;
		}
	}
	atual->altura = maior(altura_no(atual->esquerda), altura_no(atual->direita)) + 1;
	return res;
}

//Fim da função de inserção




//Função de remover

int remove_ArvAVL(ArvAVL* raiz, int valor) {

	if (*raiz == NULL) {
		cout << "ERROR!" << endl << "Valor inexistente." << endl;
		return 0;
	}
	int res;
	if (valor < (*raiz)->informacao) {
		if ((res = remove_ArvAVL(&(*raiz)->esquerda, valor)) == 1) {
			if (fatorBalanceamento_NO(*raiz) >= 2) {
				if (altura_no((*raiz)->direita->esquerda) <= altura_no((*raiz)->direita->direita)) {
					RotacaoRR(raiz);
				}
				else
				{
					RotacaoRL(raiz);
				}
			}
		}
	}if ((*raiz)->informacao < valor) {
		if ((res = remove_ArvAVL(&(*raiz)->direita, valor)) == 1) {
			if (fatorBalanceamento_NO(*raiz) >= 2) {
				if (altura_no((*raiz)->esquerda->direita) <= altura_no((*raiz)->esquerda->esquerda)) {
					RotacaoLL(raiz);
				}
				else
				{
					RotacaoLR(raiz);
				}
			}
		}
	}if ((*raiz)->informacao == valor) {
		if (((*raiz)->esquerda == NULL || (*raiz)->direita == NULL)) {
			struct NO* oldNode = (*raiz);
			if ((*raiz)->esquerda != NULL) {
				*raiz = (*raiz)->esquerda;
			}
			else
			{
				*raiz = (*raiz)->direita;
			}
			free(oldNode);
		}
		else
		{
			struct NO* temp = procurarMenor((*raiz)->direita);
			(*raiz)->informacao = temp->informacao;
			remove_ArvAVL(&(*raiz)->direita, (*raiz)->informacao);
			if (fatorBalanceamento_NO(*raiz) >= 2) {
				if (altura_no((*raiz)->esquerda->direita) <= altura_no((*raiz)->esquerda->esquerda)) {
					RotacaoLL(raiz);
				}
				else
				{
					RotacaoLR(raiz);
				}
			}
		}
		return 1;
	}
	return res;
}

struct NO* procurarMenor(struct NO* atual) {

	struct NO* no1 = atual;
	struct NO* no2 = atual->esquerda;
	while (no2 != NULL)
	{
		no1 = no2;
		no2 = no2->esquerda;
	}
	return no1;
}

//Fim das funções de remover




void imprimir(NO* raiz) {

	//  Essa função imprime os elementos de forma recursiva

	
	
	if(raiz){ 
		
		cout << raiz->informacao;
		cout << endl;
		imprimir(raiz->esquerda);
		
		imprimir(raiz->direita);
		
	}
	;
	

	
}

