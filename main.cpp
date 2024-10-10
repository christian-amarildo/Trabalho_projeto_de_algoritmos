#include "lista.h"
#include <iostream>
#include <string>
using namespace std;

int main() {

  TipoFila FilaHomem, FilaMulher;
  FFVazia(&FilaHomem);
  FFVazia(&FilaMulher);

  int op = 0;

  while (op != 4) {

    cout << "Bem-Vindo so sistema em c++ de formação de pares da Dacenteria "
            "UFPA\n";
    cout << "Deseja fazer o que?\n";
    cout << "1 - Cadastrar Homem\n";
    cout << "2 - Cadastrar Mulher\n";
    cout << "3 - Formar pares e imprimir\n";
    cout << "4 - Sair do programa\n";
    cout << "Sua opção? : ";
    cin >> op;

    cin.ignore();

    (void)system("clear");

    switch (op) {
    case 1: {
      string nome;
      cout << "Digite o nome do homem para adicionar na fila: ";
      getline(cin, nome);

      TipoItem item;

      item.nome = nome;

      Enfileria(item, &FilaHomem);
      cout << "\nHomem adicionado com sucesso!\n\n";
      break;
    }

    case 2: {

      string nome;
      cout << "Digite o nome do mulher para adicionar na fila: ";
      getline(cin, nome);

      TipoItem item;

      item.nome = nome;

      Enfileria(item, &FilaMulher);
      cout << "\nMulher adicionada com sucesso!\n\n";
      break;
    }

    case 3: {

      cout << "--------------------------------------\n";

      ImprimePares(FilaHomem, FilaMulher);

      cout << "--------------------------------------\n";

      break;
    }

    case 4: {
      cout << "Obrigado pela atenção!\nSaindo do programa\n";
      break;
    }
    }
  }
  return 0;
}