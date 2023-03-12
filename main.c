#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    // Declara玢o de var韆veis
    int vet[18] = {186, 170, 193, 180, 192, 183, 177, 167, 176, 158, 174, 185, 154, 156, 170, 168, 176, 178};
    int kr, ks, xMin = 999, xMax, AA, sum, media, moda, mediana, tam = 18;
    int vetF[18] = {0}, maxF = 0, k, AI, aux, aux2, aux3, AC, trocou;
    kr = ks = xMax = sum = moda = aux2 = aux3 = 0;

    // Printando valores na tela
    printf("\n Valores: ");
    for (int i = 0 ; i < tam ; i++) {
        printf(" %d", vet[i]);
    }

    for (int i = 0 ; i < tam ; i++) {
        // Pega o valor de Xmax
        if (vet[i] > xMax) {
            xMax = vet[i];
        }
        // Pega o valor de Xmin
        if (vet[i] < xMin) {
            xMin = vet[i];
        }
        // Faz a soma dos valores
        sum += vet[i];
    }

    // Colocando em ordem crescente
    for (int i = 0 ; i < tam ; i++) {
        for (int y = i; y < tam; y++) {
            if (vet[i] > vet[y]) {
                aux = vet[i];
                vet[i] = vet[y];
                vet[y] = aux;
            }
        }
    }

    // Printando valores na tela
    printf("\n     Rol: ");
    for (int i = 0 ; i < tam ; i++) {
        printf(" %d", vet[i]);
    }

    // Determinando N鷐ero de Classes

    // Teste da Raiz
    kr = ceil(sqrt(tam));

    // Teste de Sturges
    ks = ceil(1 + (3,3 * log(tam)));

    printf("\n\n Deve ser dividido em ");

    if (tam > 100) {
        printf("%d classes - STURGES", ks);
        k = ks;
    } else {
        printf("%d classes - RAIZ", kr);
        k = kr;
    }

    // Amplitude Amostral
    AA = xMax - xMin + 1;

    // Media
    media = sum / tam;

    // Calcula a Mediana
   for (int i = 0 ; i < 1 ; i++) {
        if (tam % 2 == 0) {
            int r = tam / 2;
            int x = vet[r-1];
            int y = vet[r+1];

            mediana = (x + y) / 2;
        }
    }

    for (int i = 0; i < tam ; i++) {
        for (int y = i; y < tam; y++) {
            if (vet[i] == vet[y]) {
                vetF[i]++;
            }
        }
    }

    for (int i = 0; i < tam ; i++) {
        if (maxF < vetF[i]) {
            maxF = vetF[i];
        }
    }

    // Calcula a Amplitude de Intervalo
    AI = ceil(AA / k);

    // Frequ阯cia acumulada
    int F[k];
    // Frequ阯cia simples
    int ff[k];
    // Frequ阯cia relativa simples
    float frs[k];
    // Frequ阯cia relativa acumulada
    float fra[k];

    printf("\n\n\t Tabela: \n");
    printf("\n 创创创创创创创创创创创创创创创创创创创创创创创创创创创创");
    printf("\n | k |  Estaturas   | f  |  xi  |   fr   |  F  |   Fr   |");
    for (int i = 0 ; i < k ; i++) {
        // Pega o limite superior (Li) do intervalo de classe
        int temp = xMin + (AI * (i + 1));
        // Pega o limite inferior (li) do intervalo de classe
        int temp2 = xMin + (AI * i);

        for (int j = 0 ; j < tam ; j++) {
            // Verificar os valores que est鉶 dentro de cada intervalo de classe
            if (vet[j] >= temp2 && vet[j] < temp) {
                aux3++;
                aux2++;
                // Calcula Frequ阯cia acumulada
                F[i] = aux2;
                // Calcula Frequ阯cia simples
                ff[i] = aux3 - F[i-1];
                //Calcula Frequ阯cia relativa simples
                frs[i] = (float) ff[i] / tam;
                //Calcula Frequ阯cia relativa acumulada
                fra[i] = (float) F[i] / tam;
            }
        }

        // Calcula o ponto m閐io em cada estatura
        int xi = (temp + temp2) / 2;

        // Printa os valores na tela
        if (i < 2) {
            printf("\n | %d | %d |--> %d | %d  | %d  | %.1f%%  |  %d  | %.1f%%  |", i+1, temp2, temp, ff[i], xi, frs[i] * 100,F[i], fra[i] * 100);
        } else if (i < 4){
            printf("\n | %d | %d |--> %d | %d  | %d  | %.1f%%  | %d  | %.1f%%  |", i+1, temp2, temp, ff[i], xi, frs[i] * 100,F[i], fra[i] * 100);
        } else {
            printf("\n | %d | %d |--> %d | %d  | %d  | %.1f%%  | %d  | %.1f%% |", i+1, temp2, temp, ff[i], xi, frs[i] * 100,F[i], fra[i] * 100);
        }
    }
    printf("\n 创创创创创创创创创创创创创创创创创创创创创创创创创创创创");

    printf("\n\n\t Outros dados: ");
    printf("\n\n Media - %d", media);

    // Verifica tem moda
    if (maxF == 1) {
        printf("\n Amodal");
    } else {
        printf("\n Moda - ");
        for (int i = 0 ; i < tam ; i++) {
            if (maxF == vetF[i]) {
                printf("%d ", vet[i]);
            }
        }
    }

    printf("\n Mediana - %d", mediana);
    printf("\n X min - %d", xMin);
    printf("\n X max - %d", xMax);
    printf("\n Amplitude Amostral - %d", AA);
    printf("\n Amplitude de Intervalo - %d\n", AI);

    return 0;
}
