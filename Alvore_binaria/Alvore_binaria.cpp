#include <iostream>
#include<locale.h>
#include<math.h>
#include <stdio.h>
#include "Cabecalho.h"


using namespace std;
int main()
{
	


	NO* arvore = NULL;
	NO* q;
	int op, x, y;

    int aux = 0;
    int i = 1;
    int opcao;

	//int op, x, y;




    while (i != 0)
    {
		system("cls");
		printf("\n           Arvore AVL      ");
		printf("\n------------------------------------------------");
		printf("\n");
		printf("\n");
		printf("\n  [1] - Inserir\n   ");
		printf("\n  [2] - Remover\n ");
		printf("\n  [3] - Imprimir\n ");
		printf("\n	[0] = PARA SAIR\n ");
		printf("\n------------------------------------------------");
		printf("\n\n ");
		printf("\n");
		printf("\n\n\n>> "); cin >> opcao;

		switch (opcao)
		{
			case 1:
				cout << "Qual numero voce quer inserir na arvore?" << endl;
				cin >> x;
				insere_ArvAVL(&arvore, x);
				system("pause");
				break;

			case 2:
				cout << "Qual elemento voce quer retirar?" << endl;
				cin >> y;
				remove_ArvAVL(&arvore, y);
				system("pause");
				break;

			case 3:

				imprimir(arvore);
				system("pause");
				break;

			case 0:
				cout << "Programa finalizado" << endl;
				i = 0;
				break;


		}
    }


    
    


    return 0;
}

