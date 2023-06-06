#include <vector>
#include "rainhas.hpp"
#include <algorithm>

bool verificar_posicao(const std::vector<std::vector<int>>& tabuleiro, int linha, int col) {
    int n = tabuleiro.size();

    // Verifica se há uma rainha na mesma coluna
    for (int i = 0; i < linha; i++) {
        if (tabuleiro[i][col] == 1)
            return false;
    }

    // Verifica se há uma rainha na diagonal superior esquerda
    for (int i = linha-1, j = col-1; i >= 0 && j >= 0; i--, j--) {
        if (tabuleiro[i][j] == 1)
            return false;
    }

    // Verifica se há uma rainha na diagonal superior direita
    for (int i = linha-1, j = col+1; i >= 0 && j < n; i--, j++) {
        if (tabuleiro[i][j] == 1)
            return false;
    }

    return true;
}

int checar_solucao(const std::vector<int>& tabuleiro) {
    int n = tabuleiro.size();
    if (n != 64) {
        return -1;
    }

    std::vector<std::vector<int>> chessboard(8, std::vector<int>(8, 0));

    // Preenche o tabuleiro com base no vetor board
    for (int i = 0; i < n; i++) {
        int linha = i / 8;
        int col = i % 8;
        chessboard[linha][col] = tabuleiro[i];
    }

    // Verifica se há mais de 8 rainhas
    int numRainhas = 0;
    for (const auto& linha : chessboard) {
        numRainhas += std::count(linha.begin(), linha.end(), 1);
        if (numRainhas > 8) {
            return -1;
        }
    }

    // Verifica se as rainhas estão em posições seguras
    for (int linha = 0; linha < 8; linha++) {
        for (int col = 0; col < 8; col++) {
            if (chessboard[linha][col] == 1 && !verificar_posicao(chessboard, linha, col)) {
                return 0;
            }
        }
    }

    return 1;
}
