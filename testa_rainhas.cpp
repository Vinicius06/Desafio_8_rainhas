#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <vector>
#include "rainhas.hpp"

TEST_CASE("Teste de solução válida das 8 damas") {
    std::vector<int> tabuleiro = {
        1, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 1, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 1,
        0, 0, 0, 0, 0, 1, 0, 0,
        0, 0, 1, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 1, 0,
        0, 1, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 1, 0, 0, 0, 0
    };

    REQUIRE(checar_solucao(tabuleiro) == 1);
}

TEST_CASE("Teste de solução válida das 8 damas v2") {
    std::vector<int> tabuleiro = {
        0, 0, 0, 1, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 1, 0,
        0, 0, 1, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 1,
        0, 1, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 1, 0, 0, 0,
        1, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 1, 0, 0
    };

    REQUIRE(checar_solucao(tabuleiro) == 1);
}

TEST_CASE("Teste de solução válida das 8 damas v3") {
    std::vector<int> tabuleiro = {
        0, 0, 0, 0, 1, 0, 0, 0,
        0, 1, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 1, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 1, 0,
        0, 0, 1, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 1,
        0, 0, 0, 0, 0, 1, 0, 0,
        1, 0, 0, 0, 0, 0, 0, 0
    };

    REQUIRE(checar_solucao(tabuleiro) == 1);
}

TEST_CASE("Teste de solução válida das 8 damas v4") {
    std::vector<int> tabuleiro = {
        0, 0, 0, 1, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 1, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 1,
        0, 0, 1, 0, 0, 0, 0, 0,
        1, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 1, 0,
        0, 0, 0, 0, 1, 0, 0, 0,
        0, 1, 0, 0, 0, 0, 0, 0
    };

    REQUIRE(checar_solucao(tabuleiro) == 1);
}

TEST_CASE("Teste de validação do tabuleiro inválido: solução inválida") {
    std::vector<int> tabuleiro = {
        1, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 1, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 1,
        0, 0, 0, 0, 0, 1, 0, 0,
        0, 0, 1, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 1, 0,
        0, 1, 0, 0, 0, 0, 0, 0,
        1, 0, 0, 0, 0, 0, 0, 0
    };

    REQUIRE(checar_solucao(tabuleiro) == 0);
}

TEST_CASE("Teste de validação do tabuleiro inválido: solução inválida v2") {
    std::vector<int> tabuleiro = {
        1, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 1, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 1,
        0, 0, 0, 0, 0, 1, 0, 0,
        0, 0, 1, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 1, 0,
        0, 1, 0, 0, 0, 0, 0, 0,
        0, 1, 0, 0, 0, 0, 0, 0
    };

    REQUIRE(checar_solucao(tabuleiro) == 0);
}

TEST_CASE("Teste de validação do tabuleiro inválido: solução inválida v3") {
    std::vector<int> tabuleiro = {
        1, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 1, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 1,
        0, 0, 0, 0, 0, 1, 0, 0,
        0, 0, 1, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 1, 0,
        0, 1, 0, 0, 0, 0, 0, 0,
        0, 0, 1, 0, 0, 0, 0, 0
    };

    REQUIRE(checar_solucao(tabuleiro) == 0);
}

TEST_CASE("Teste de solução inválida do tabuleiro ou rainhas") {
    std::vector<int> tabuleiro = {
        1, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 1, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 1,
        0, 0, 0, 0, 0, 1, 0, 0,
        0, 0, 1, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 1, 0,
        0, 1, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 1, 1, 0
    };

    REQUIRE(checar_solucao(tabuleiro) == -1);
}