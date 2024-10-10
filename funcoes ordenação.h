

// Função Merge Sort
public void merge(int[] v, int left, int middle, int right) {

    // transfere os elementos entre left e right para um array auxiliar.
    int[] helper = new int[v.length];
    for (int i = left; i <= right; i++) {
        helper[i] = v[i];
    }


    int i = left;
    int j = middle + 1;
    int k = left;

    while (i <= middle && j <= right) {

        if (helper[i] <= helper[j]) {
            v[k] = helper[i];
            i++;
        } else {
            v[k] = helper[j];
            j++;
        }
        k++;    

    }

    // se a metade inicial não foi toda consumida, faz o append.
    while (i <= middle) {
        v[k] = helper[i];
        i++;
        k++;
    }

    // Não precisamos nos preocupar se a metade final foi 
    // toda consumida, já que, se esse foi o caso, ela já está
    // no array final.

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

void heapify(int arr[], int n, int i)
{
    int largest = i; // Inicializa largest como a raiz (root). Como estamos usando indexação baseada em 0.
    int l = 2 * i + 1; // esquerdo = 2*i + 1
    int r = 2 * i + 2; // direito = 2*i + 2

    // Se o filho da esquerda é maior que a raiz
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // Se o filho da direita é maior que o maior até agora
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // Se o maior não é a raiz
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Chama recursivamente o heapify no subárvore afetada
        heapify(arr, n, largest);
    }
}
