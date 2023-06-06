#include <vector>
#include "rainhas.hpp"
#include <algorithm>
#include <fstream>

bool posicao_segura(const std::vector<std::vector<int>>& tabuleiro, int linha, int coluna) {
    int n = tabuleiro.size();

    // Verifica se há uma rainha na mesma colunauna
    for (int i = 0; i < linha; i++) {
        if (tabuleiro[i][coluna] == 1)
            return false;
    }

    // Verifica se há uma rainha na diagonal superior esquerda
    for (int i = linha-1, j = coluna-1; i >= 0 && j >= 0; i--, j--) {
        if (tabuleiro[i][j] == 1)
            return false;
    }

    // Verifica se há uma rainha na diagonal superior direita
    for (int i = linha-1, j = coluna+1; i >= 0 && j < n; i--, j++) {
        if (tabuleiro[i][j] == 1)
            return false;
    }

    return true;
}

void ataques_rainhas(const std::vector<std::vector<int>>& tabuleiro) {
    std::ofstream outputFile("ataques_rainhas.txt");
    int n = tabuleiro.size();

    // Percorre todas as posições do tabuleiro
    for (int linha = 0; linha < n; linha++) {
        for (int coluna = 0; coluna < n; coluna++) {
            // Verifica se há uma rainha na posição (linha, coluna)
            if (tabuleiro[linha][coluna] == 1) {
                // Verifica se ela se ataca com outras rainhas
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (i != linha && j != coluna) {
                            if (tabuleiro[i][j] == 1 && !posicao_segura(tabuleiro, i, j)) {
                                // Escreve as posições das rainhas que se atacam no arquivo
                                outputFile << "(" << linha << "," << coluna << ") ataca (" << i << "," << j << ")\n";
                            }
                        }
                    }
                }
            }
        }
    }

    outputFile.close();
}

int checar_solucao(const std::vector<int>& tabuleiro) {
    int n = tabuleiro.size();
    if (n != 64) {
        return -1;
    }

    std::vector<std::vector<int>> xadrez(8, std::vector<int>(8, 0));

    // Preenche o tabuleiro com base no vetor tabuleiro
    for (int i = 0; i < n; i++) {
        int linha = i / 8;
        int coluna = i % 8;
        xadrez[linha][coluna] = tabuleiro[i];
    }

    // Verifica se há mais de 8 rainhas
    int numQueens = 0;
    for ( const auto& linha : xadrez) {
        numQueens += std::count(linha.begin(), linha.end(), 1);
        if (numQueens > 8) {
            return -1;
        }
    }

    // Verifica se as rainhas estão em posições seguras
    for (int linha = 0; linha < 8; linha++) {
        for (int coluna = 0; coluna < 8; coluna++) {
            if (xadrez[linha][coluna] == 1 && !posicao_segura(xadrez, linha, coluna)) {
                // Rainhas se atacam, escreve no arquivo de saída
                ataques_rainhas(xadrez);
                return 0;
            }
        }
    }

    return 1;
}

