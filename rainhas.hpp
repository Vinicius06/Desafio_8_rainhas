// Copyright[2023] <Vinicius de Camargo Bandeira>
#ifndef RAINHAS_HPP_
#define RAINHAS_HPP_

#include <vector>

/**

@file rainhas.hpp
@brief Este arquivo contém a declaração das funções relacionadas ao problema das rainhas.
O problema das rainhas envolve encontrar uma solução para posicionar N rainhas em um tabuleiro
de xadrez NxN, de forma que nenhuma rainha ameace outra. Este arquivo fornece uma função para
verificar a validade de uma solução.
*/

/**

@brief Verifica a validade de uma solução para o problema das rainhas em um tabuleiro de xadrez.
Esta função verifica se a solução fornecida é válida para posicionar as rainhas em um tabuleiro
de xadrez. Ela recebe um vetor que representa a solução, onde cada elemento representa a posição
da coluna da rainha na respectiva linha. A função verifica se nenhuma rainha está na mesma linha,
coluna ou diagonal, ameaçando-se mutuamente.

Assertiva de entrada:

@param tab O vetor que representa a solução, onde tab[i] representa a posição da coluna da rainha
css
Copy code na linha i.
Assertiva de saida:

@return 0 se a solução é válida, -1 caso contrário.
*/
int checar_solucao(const std::vector<int>& tab);


#endif  // RAINHAS_HPP_
