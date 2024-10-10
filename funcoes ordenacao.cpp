// Função Bubble Sort
void bubbleSort(std::vector<int>& vetor, int *trocas, int *comparacoes)
{
    int aux;
    for (int j = vetor.size() - 1; j >= 1; j--)
    {
        for (int i = 0; i < j; i++)
        {
            (*comparacoes)++;
            if (vetor[i] > vetor[i + 1])
            {
                (*trocas)++;
                aux = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = aux;
            }
        }
    }
}

// Função Merge Sort
void merge(std::vector<int>& arr, int esquerda, int meio, int direita, int *trocas, int *comparacoes)
{
    int i, j, k;
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;

    std::vector<int> L(n1), R(n2);

    for (i = 0; i < n1; i++)
    {
        L[i] = arr[esquerda + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[meio + 1 + j];
    }

    i = 0;
    j = 0;
    k = esquerda;
    while (i < n1 && j < n2)
    {
        (*comparacoes)++;
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        (*trocas)++;
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int>& arr, int esquerda, int direita, int *trocas, int *comparacoes)
{
    if (esquerda < direita)
    {
        int meio = esquerda + (direita - esquerda) / 2;
        mergeSort(arr, esquerda, meio, trocas, comparacoes);
        mergeSort(arr, meio + 1, direita, trocas, comparacoes);
        merge(arr, esquerda, meio, direita, trocas, comparacoes);
    }
}

// Função QuickSort
void quickSort(std::vector<int>& a, int esquerda, int direita, int *trocas, int *comparacoes)
{
    int i, j, x, y;
    i = esquerda;
    j = direita;
    x = a[(esquerda + direita) / 2];
    (*trocas) += 3;
    while (i <= j)
    {
        while (a[i] < x && i < direita)
        {
            i++;
            (*comparacoes)++;
            (*trocas)++;
        }
        while (a[j] > x && j > esquerda)
        {
            j--;
            (*comparacoes)++;
            (*trocas)++;
        }
        if (i <= j)
        {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            (*trocas) += 3;
            i++;
            j--;
        }
    }
    if (j > esquerda)
    {
        quickSort(a, esquerda, j, trocas, comparacoes);
    }
    if (i < direita)
    {
        quickSort(a, i, direita, trocas, comparacoes);
    }
}