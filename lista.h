#include <string>
using namespace std;

typedef struct {
  string nome;
}TipoItem;


typedef struct Celula* ApontadorCelula;

typedef struct Celula{
  TipoItem item;
  ApontadorCelula prox;
}Celula;

typedef struct{
  ApontadorCelula frente, tras;
}TipoFila;

void FFVazia(TipoFila *);

bool Vazia(TipoFila);

void Enfileria(TipoItem, TipoFila *);

TipoItem Desenfileria(TipoFila *);

int tamanhoFila(TipoFila);

void ImprimePares(TipoFila,TipoFila);

int TamanhoFila(TipoFila);