typedef struct NO* ArvAVL;

int altura_no(struct NO* no);

int fatorBalanceamento_NO(struct NO* no);

int maior(int x, int y);

void RotacaoLL(ArvAVL* raiz);

void RotacaoRR(ArvAVL* raiz);

void RotacaoLR(ArvAVL* raiz);

void RotacaoRL(ArvAVL* raiz);

int insere_ArvAVL(ArvAVL* raiz, int valor);

int remove_ArvAVL(ArvAVL* raiz, int valor);

struct NO* procurarMenor(struct NO* atual);

void imprimir(NO *raiz);
