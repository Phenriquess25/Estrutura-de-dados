#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* ====== Estrutura da Lista ====== */
typedef struct no_lista {
    int valor;
    struct no_lista *prox;
} NoLista;

/* ====== Estrutura da Árvore ====== */
typedef struct no_arvore {
    int valor;
    struct no_arvore *esq, *dir;
} NoArv;

void insere_numeros_lista(NoLista **lista, int v) {
    NoLista *novo = (NoLista*) malloc(sizeof(NoLista));
    novo->valor = v;
    novo->prox = *lista;
    *lista = novo;
}

int busca_numeros_lista(NoLista *lista, int chave) {
    int comp = 0;
    while (lista != NULL) {
        comp++;
        if (lista->valor == chave){
            return comp; // achou
        } 
        lista = lista->prox;
    }
    return comp; // não achou
}

NoArv* insere_numeros_arv(NoArv *raiz, int v) {
    if (raiz == NULL) {
        NoArv *novo = (NoArv*) malloc(sizeof(NoArv));
        novo->valor = v;
        novo->esq = novo->dir = NULL;
        return novo;
    }
    if (v < raiz->valor)
        raiz->esq = insere_numeros_arv(raiz->esq, v);
    else if (v > raiz->valor)
        raiz->dir = insere_numeros_arv(raiz->dir, v);
    return raiz;
}

int busca_numeros_arv(NoArv *raiz, int chave) {
    int comp = 0;
    while (raiz != NULL) {
        comp++;
        if (chave == raiz->valor){
            return comp; // achou
        }else if(chave < raiz->valor){
            raiz = raiz->esq;
        }else{
            raiz = raiz->dir;
        } 
    }
    return comp; // não achou
}

/* ====== Embaralhamento ====== */
void embaralha_numeros(int *v, int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int tmp = v[i];
        v[i] = v[j];
        v[j] = tmp;
    }
}

/* ====== Programa Principal ====== */
int main() {
    //Cria a lista e a árvore que será usada ao longo do código.
    NoLista *lista = NULL; 
    NoArv *arvore = NULL;

    int total = 10000;  // universo de valores de 0 a 9999
    int n = 1000;      // quantidade de números a inserir e buscar

    srand(time(NULL)); //Inicializa o gerador de numeros aleatórios. Precisa ser usado com o rand().

    // cria vetor com números de 0 a 9999
    int *vetor = malloc(total * sizeof(int));
    int i;
    for (i = 0; i < total; i++){
        vetor[i] = i;
    }
        

    // embaralha o vetor
    embaralha_numeros(vetor, total);

    // insere os 10.000 primeiros na lista e na árvore
    int j;
    for (j = 0; j < n; j++) {
        insere_numeros_lista(&lista, vetor[j]);
        arvore = insere_numeros_arv(arvore, vetor[j]);
    }

    // abre CSV
    FILE *f = fopen("dados.csv", "w"); //Cria um arquivo do tipo .csv para escrita, por isso o W.
    if (f == NULL) { //Verifica se a abertura do aquivo deu certo.
        printf("Erro ao abrir arquivo.\n");
        free(vetor);
        return 1;
    }

    fprintf(f, "numero,comparacoes_lista,comparacoes_arvore\n"); /*  Essa função é parecida com o printf, mas, ao invés de escrever na tela, escreve no arquivo 'f'.
       Os parâmetros são: fprintf(ponteiro_arquivo, "texto com formato", valores).  */ 

    embaralha_numeros(vetor, n);

    // faz as buscas para os 10.000 números sorteados
    for (int i = 0; i < n; i++) {
        int chave = vetor[i];
        int comp_lista = busca_numeros_lista(lista, chave);
        int comp_arv = busca_numeros_arv(arvore, chave);
        fprintf(f, "%d,%d,%d\n", chave, comp_lista, comp_arv); // Escreve no arquivo 'dados.csv' esses três valores, um em cada coluna (número, comparaçoes_lista, comparações_árvore).
    }

    fclose(f); // Fecha e salva os valores no arquivo.
    free(vetor); //Libera o vetor com os valores iniciais.
    printf("Arquivo 'dados.csv' gerado com sucesso!\n");

    return 0;
}
