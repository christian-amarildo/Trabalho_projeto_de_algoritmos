#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <locale>

// Função para mostrar as estatísticas
void mostrarEstatisticas(int comparacoes, int trocas, float tempoExecucao)
{
    std::cout << "\nNúmero de comparações: " << comparacoes << "\n";
    std::cout << "Número de trocas de posição: " << trocas << "\n";
    std::cout << "Tempo (em segundos): " << tempoExecucao << "\n\n";
}

// Função para imprimir o array
void imprimirArray(const std::vector<int>& lista)
{
    std::cout << "\n[";
    for (size_t i = 0; i < lista.size(); i++)
    {
        std::cout << lista[i];
        if (i < lista.size() - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << "]\n";
}



// Função para gerar um relatório
void gerarRelatorio(std::ofstream& relatorio, const std::string& algoritmo, int comparacoes, int trocas, float tempo, const std::vector<int>& lista)
{
    relatorio << "Algoritmo: " << algoritmo << "\n";
    relatorio << "Número de comparações: " << comparacoes << "\n";
    relatorio << "Número de trocas de posição: " << trocas << "\n";
    relatorio << "Tempo (em segundos): " << tempo << "\n\n";

    relatorio << "Base de dados ordenada: [";
    for (size_t i = 0; i < lista.size(); i++)
    {
        relatorio << lista[i];
        if (i < lista.size() - 1)
        {
            relatorio << ", ";
        }
    }
    relatorio << "]\n\n";
}

// Função para abrir um arquivo e retornar o ponteiro para ele, com tratamento de erros
std::ifstream abrirArquivo(const std::string& caminho)
{
    std::ifstream arquivo(caminho);
    if (!arquivo)
    {
        std::cerr << "Erro ao abrir o arquivo: " << caminho << "\n";
        exit(EXIT_FAILURE);
    }
    return arquivo;
}

int main()
{
    int valor, tamanho;
    int trocas = 0, comparacoes = 0;
    int sairPrograma = 0; // Variável de controle para sair do programa

    std::setlocale(LC_ALL, "Portuguese");

    std::cout << "\n=== Programa de Análise de Algoritmos de Ordenação ===\n";
    std::cout << "Este programa permite analisar o desempenho de algoritmos de ordenação.\n";

    while (!sairPrograma)
    {
        std::string tamanhos[] = {"10", "50", "100", "500", "1k", "5k", "10k", "50k", "100k"};
        int tamanhosInteiros[] = {10, 50, 100, 500, 1000, 5000, 10000, 50000, 100000};
        std::string duplicidade[] = {"Com Duplicidade", "Sem Duplicidade"};
        std::string ordem[] = {"Aleatório", "Concavo-DecresceCresce", "Convexo-CresceDescresce", "Crescente", "Descrescente"};
        std::string abreviacoesOrdem[] = {"aleat", "concv", "convx", "cresc", "decre"};
        std::string duplicidadeOrdem[] = {"dup", "uni"};

        std::cout << "Selecione o tamanho da base de dados:\n\n";
        for (int i = 0; i < 9; i++)
        {
            std::cout << i + 1 << ". " << tamanhos[i] << "\n";
        }
        std::cout << "\nNúmero do tamanho (1-9): ";
        std::cin >> valor;

        if (valor < 1 || valor > 9)
        {
            std::cout << "\nOpção inválida!\n\n";
            continue; // Volta ao início do loop para escolher um tamanho válido
        }

        std::cout << "\nSelecione a duplicidade:\n\n";
        std::cout << "1. Com Duplicidade\n";
        std::cout << "2. Sem Duplicidade\n";
        std::cout << "\nNúmero da duplicidade (1-2): ";
        int duplicidadeValor;
        std::cin >> duplicidadeValor;

        if (duplicidadeValor < 1 || duplicidadeValor > 2)
        {
            std::cout << "Opção inválida!\n";
            return 1;
        }

        std::cout << "Selecione a ordem:\n\n";
        std::cout << "1. Aleatório\n";
        std::cout << "2. Concavo-DecresceCresce\n";
        std::cout << "3. Convexo-CresceDescresce\n";
        std::cout << "4. Crescente\n";
        std::cout << "5. Descrescente\n\n";
        std::cout << "Número da ordem (1-5): ";
        int ordemValor;
        std::cin >> ordemValor;

        if (ordemValor < 1 || ordemValor > 5)
        {
            std::cout << "Opção inválida!\n";
            return 1;
        }

        std::cout << "\nSelecione o sufixo do arquivo (0 a 9): ";
        int arquivoSufixo;
        std::cin >> arquivoSufixo;

        if (arquivoSufixo < 0 || arquivoSufixo > 9)
        {
            std::cout << "Sufixo inválido!\n";
            return 1;
        }

        tamanho = tamanhosInteiros[valor - 1];

        // Constrói o caminho do arquivo de dados com base nas seleções do usuário
        std::string caminhoArquivo = "dados\\" + tamanhos[valor - 1] + "\\" + duplicidade[duplicidadeValor - 1] + "\\" + ordem[ordemValor - 1] + "\\dt" + abreviacoesOrdem[ordemValor - 1] + tamanhos[valor - 1] + duplicidadeOrdem[duplicidadeValor - 1] + std::to_string(arquivoSufixo) + ".txt";

        std::cout << "\nBase de dados selecionada com tamanho " << tamanhos[valor - 1] << ", " << duplicidade[duplicidadeValor - 1] << " e " << ordem[ordemValor - 1] << ".\n\n";

        // Abre o arquivo
        std::ifstream arqNome = abrirArquivo(caminhoArquivo);

        std::vector<int> lista(tamanho);

        // Variáveis para armazenar tempo
        float tempoBubble, tempoMerge, tempoQuick;

        // Verificação se o arquivo foi devidamente selecionado
        if (!arqNome)
        {
            std::cout << "Erro ao abrir o arquivo. Certifique-se de que o caminho e o nome do arquivo estão corretos.\n";
            return 1; // Encerra o programa com um código de erro
        }

        // O arquivo foi aberto com sucesso, podemos continuar a leitura
        int i = 0;
        int numeroLido;

        while (i < tamanho && arqNome >> numeroLido)
        {
            if (numeroLido != 0)
            {
                lista[i] = numeroLido;
                i++;
            }
        }

        tamanho = i;

        std::string nomeDoArquivo = caminhoArquivo.substr(caminhoArquivo.find_last_of('\\') + 1);

        // Imprime a base de dados selecionada
        std::cout << "Dados da base de dados: [";
        for (int i = 0; i < tamanho; i++)
        {
            std::cout << lista[i];
            if (i < tamanho - 1)
            {
                std::cout << ", ";
            }
        }
        std::cout << "]\n\n";

        // Adicionar a extensão ".txt" ao nome do arquivo
        std::string nomeDoRelatorio = "relatorios\\relatorio_" + nomeDoArquivo + ".txt";

        std::ofstream relatorio(nomeDoRelatorio);
        relatorio << "Relatório de Análise de Algoritmos de Ordenação\n\n";
        relatorio << "Base de dados selecionada com tamanho " << tamanhos[valor - 1] << ", " << duplicidade[duplicidadeValor - 1] << " e " << ordem[ordemValor - 1] << ".\n\n";
        relatorio << "Caminho do arquivo: " << caminhoArquivo << "\n\n";
        relatorio << "Base de dados original: [";
        for (int i = 0; i < tamanho; i++)
        {
            relatorio << lista[i];
            if (i < tamanho - 1)
            {
                relatorio << ", ";
            }
        }
        relatorio << "]\n\n";
        relatorio.close();

        int sairBaseDados = 0;

        while (!sairBaseDados)
        {
            std::cout << "Selecione o algoritmo de organização:\n";
            std::cout << "1. Bubble Sort;\n";
            std::cout << "2. Merge Sort;\n";
            std::cout << "3. Quick Sort;\n";
            std::cout << "\nNúmero do algoritmo (ou 0 para sair da base de dados atual): ";

            if (!(std::cin >> valor))
            {
                std::cout << "\nEntrada inválida! Insira um número correspondente à opção desejada.\n\n";
                std::cin.clear(); // Limpa o estado de erro
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpa o buffer de entrada
                continue;
            }

            // Extrair o nome do arquivo do caminho
            std::string nomeDoArquivo = caminhoArquivo.substr(caminhoArquivo.find_last_of('\\') + 1);

            // Adicionar a extensão ".txt" ao nome do arquivo
            std::string nomeDoRelatorio = "relatorios\\relatorio_" + nomeDoArquivo + ".txt";

            std::ofstream relatorio(nomeDoRelatorio, std::ios::app); // Abra o arquivo de relatório em modo de anexação
            relatorio << "Algoritmo: ";                                          // Indique qual algoritmo está sendo registrado
            switch (valor)
            {
            case 1:
                // Chama Bubble Sort e inicia timer
                auto beginBubble = std::chrono::high_resolution_clock::now();
                bubbleSort(lista, &trocas, &comparacoes);
                imprimirArray(lista);
                auto endBubble = std::chrono::high_resolution_clock::now();
                tempoBubble = std::chrono::duration<float>(endBubble - beginBubble).count();

                gerarRelatorio(relatorio, "Bubble Sort", comparacoes, trocas, tempoBubble, lista);
                mostrarEstatisticas(comparacoes, trocas, tempoBubble);

                break;

            case 2:
                // Chama o Merge Sort e inicia o timer
                auto beginMerge = std::chrono::high_resolution_clock::now();
                mergeSort(lista, 0, tamanho - 1, &trocas, &comparacoes);
                imprimirArray(lista);
                auto endMerge = std::chrono::high_resolution_clock::now();
                tempoMerge = std::chrono::duration<float>(endMerge - beginMerge).count();

                gerarRelatorio(relatorio, "Merge Sort", comparacoes, trocas, tempoMerge, lista);
                mostrarEstatisticas(comparacoes, trocas, tempoMerge);
                break;

            case 3:
                // Chama o Quick Sort e inicia o timer
                auto beginQuick = std::chrono::high_resolution_clock::now();
                quickSort(lista, 0, tamanho - 1, &trocas, &comparacoes);
                imprimirArray(lista);
                auto endQuick = std::chrono::high_resolution_clock::now();
                tempoQuick = std::chrono::duration<float>(endQuick - beginQuick).count();

                gerarRelatorio(relatorio, "Quick Sort", comparacoes, trocas, tempoQuick, lista);
                mostrarEstatisticas(comparacoes, trocas, tempoQuick);

                break;

            case 0:
                sairBaseDados = 1; // Define a variável "sair" como 1 para sair do loop
                break;

            default:
                std::cout << "\nOpção inválida! Escolha as opções listadas (apenas o número).\n\n";
                break;
            }

            relatorio.close();

            // Pergunta ao usuário se deseja selecionar outra base de dados
            std::cout << "Deseja selecionar outra base de dados? (0 para sair ou qualquer outro número para continuar): ";
            int resposta;
            std::cin >> resposta;
            if (resposta == 0)
            {
                sairBaseDados = 1; // Define a variável "sairBaseDados" como 1 para sair do loop
            }
        }

        // Fecha o arquivo utilizado
        arqNome.close();

        // Reinicie as variáveis de controle para selecionar uma nova base de dados
        trocas = 0;
        comparacoes = 0;

        // Libera a memória alocada dinamicamente quando não for mais necessária
        lista.clear();

        std::cout << "\nDeseja sair do programa? (0 para sair ou qualquer outro número para continuar): ";
        int resposta;
        std::cin >> resposta;
        if (resposta == 0)
        {
            sairPrograma = 1;
        }
    }

    std::cout << "\nObrigado por usar o nosso programa! Esperamos que tenha sido útil.\n";

    return 0; // Encerra o programa
}