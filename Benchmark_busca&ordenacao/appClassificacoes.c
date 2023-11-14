#include <stdio.h>
#include <time.h>

// Função para ordenar elementos usando o algoritmo Insertion Sort
void insertionSort(int numeros[], int tamanho) {
    clock_t inicio = clock();
    for (int i = 1; i < tamanho; i++) {
        int chave = numeros[i];
        int j = i - 1;
        while (j >= 0 && numeros[j] > chave) {
            numeros[j + 1] = numeros[j];
            j--;
        }
        numeros[j + 1] = chave;
    }
    clock_t fim = clock();
    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo de Insertion Sort: %.6f segundos\n", tempo);
}

// Função para ordenar elementos usando o algoritmo Bubble Sort
void bubbleSort(int numeros[], int tamanho) {
    clock_t inicio = clock();
    for (int i = 0; i < tamanho - 1; i++) {
        int trocado = 0;
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (numeros[j] > numeros[j + 1]) {
                int temp = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = temp;
                trocado = 1;
            }
        }
        if (trocado == 0) {
            break; // Se nenhum dos elementos for trocado, o vetor é dado como ordenado xD
        }
    }
    clock_t fim = clock();
    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo de Bubble Sort: %.6f segundos\n", tempo);
}

int partition(int numeros[], int baixo, int alto) {
    int pivo = numeros[alto];
    int i = (baixo - 1);

    for (int j = baixo; j <= alto - 1; j++) {
        if (numeros[j] < pivo) {
            i++;
            int temp = numeros[i];
            numeros[i] = numeros[j];
            numeros[j] = temp;
        }
    }

    int temp = numeros[i + 1];
    numeros[i + 1] = numeros[alto];
    numeros[alto] = temp;

    return (i + 1);
}

// Função para ordenar elementos usando o algoritmo Quick Sort
void quickSort(int numeros[], int baixo, int alto) {
    if (baixo < alto) {
        int pi = partition(numeros, baixo, alto);

        quickSort(numeros, baixo, pi - 1);
        quickSort(numeros, pi + 1, alto);
    }
}

void sortWithQuickSort(int numeros[], int tamanho) {
    clock_t inicio = clock();
    quickSort(numeros, 0, tamanho - 1);
    clock_t fim = clock();
    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo de Quick Sort: %.6f segundos\n", tempo);
}


// Função para ordenar elementos usando o algoritmo Merge Sort
void merge(int numeros[], int baixo, int meio, int alto) {
    int i, j, k;
    int n1 = meio - baixo + 1;
    int n2 = alto - meio;

    // São criados arrays temporários
    int temp1[n1], temp2[n2];

    // Copia-se os dados para os arrays temporários temp1[] e temp2[]
    for (i = 0; i < n1; i++)
        temp1[i] = numeros[baixo + i];
    for (j = 0; j < n2; j++)
        temp2[j] = numeros[meio + 1 + j];

    // Mescla os arrays temporários de volta em numeros
    i = 0;
    j = 0;
    k = baixo;
    while (i < n1 && j < n2) {
        if (temp1[i] <= temp2[j]) {
            numeros[k] = temp1[i];
            i++;
        } else {
            numeros[k] = temp2[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de temp1[], se tiverem
    while (i < n1) {
        numeros[k] = temp1[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de temp2[], se tiverem
    while (j < n2) {
        numeros[k] = temp2[j];
        j++;
        k++;
    }
}

// Função para ordenar elementos usando o algoritmo Merge Sort
void mergeSort(int numeros[], int baixo, int alto) {
    if (baixo < alto) {
        int meio = baixo + (alto - baixo) / 2;

        // Ordena a primeira e a segunda metade
        mergeSort(numeros, baixo, meio);
        mergeSort(numeros, meio + 1, alto);

        // Mescla as metades ordenadas
        merge(numeros, baixo, meio, alto);
    }
}

// Função para ordenar elementos usando o algoritmo Selection Sort
void selectionSort(int numeros[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < tamanho; j++) {
            if (numeros[j] < numeros[min_index]) {
                min_index = j;
            }
        }
        int temp = numeros[i];
        numeros[i] = numeros[min_index];
        numeros[min_index] = temp;
    }
}