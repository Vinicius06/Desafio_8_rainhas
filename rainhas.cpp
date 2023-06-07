// Copyright[2023] <Vinicius de Camargo Bandeira>
#include "/rainhas.hpp"
#include <vector>
#include <algorithm>
#include <fstream>

bool posicao(const std::vector<std::vector<int>>& tab, int li, int co) {
    int n = tab.size();

    // Verifica se há uma rainha na mesma couna
    for (int i = 0; i < li; i++) {
        if (tab[i][co] == 1)
            return false;
    }

    // Verifica se há uma rainha na diagonal superior esquerda
    for (int i = li-1, j = co-1; i >= 0 && j >= 0; i--, j--) {
        if (tab[i][j] == 1)
            return false;
    }

    // Verifica se há uma rainha na diagonal superior direita
    for (int i = li-1, j = co+1; i >= 0 && j < n; i--, j++) {
        if (tab[i][j] == 1)
            return false;
    }

    return true;
}

void ataques_rainhas(const std::vector<std::vector<int>>& tab) {
    std::ofstream outputFile("ataques_rainhas.txt");
    int n = tab.size();

    // Percorre todas as posições do tab
    for (int li = 0; li < n; li++) {
        for (int co = 0; co < n; co++) {
            // Verifica se há uma rainha na posição (li, co)
            if (tab[li][co] == 1) {
                // Verifica se ela se ataca com outras rainhas
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (i != li && j != co) {
                            if (tab[i][j] == 1 && !posicao(tab, i, j)) {
outputFile << "(" << li << "," << co << ")at(" << i << "," << j <<")\n";
                            }
                        }
                    }
                }
            }
        }
    }

    outputFile.close();
}

int checar_solucao(const std::vector<int>& tab) {
    int n = tab.size();
    if (n != 64) {
        return -1;
    }

    std::vector<std::vector<int>> xadrez(8, std::vector<int>(8, 0));

    // Preenche o tab com base no vetor tab
    for (int i = 0; i < n; i++) {
        int li = i / 8;
        int co = i % 8;
        xadrez[li][co] = tab[i];
    }

    // Verifica se há mais de 8 rainhas
    int numQueens = 0;
    for (const auto& li : xadrez) {
        numQueens += std::count(li.begin(), li.end(), 1);
        if (numQueens > 8) {
            return -1;
        }
    }

    // Verifica se as rainhas estão em posições seguras
    for (int li = 0; li < 8; li++) {
        for (int co = 0; co < 8; co++) {
            if (xadrez[li][co] == 1 && !posicao(xadrez, li, co)) {
                // Rainhas se atacam, escreve no arquivo de saída
                ataques_rainhas(xadrez);
                return 0;
            }
        }
    }

    return 1;
}

