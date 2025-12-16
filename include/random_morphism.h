#ifndef RANDOM_MORPHISM_H
#define RANDOM_MORPHISM_H

#include <random>
#include "product.h"

/*
Questão 5:
Implementa um morfismo puro usando pseudo-random com seed local,
evitando efeitos colaterais e garantindo determinismo.
*/

// a explicação detalhada do efeito da função random está comentado no final do arquivo.

inline Product<int, char> pureRandomMorphism(
    const Product<int, char>& p
) {
    std::mt19937 gen(p.first); // seed depende apenas da entrada
    std::uniform_int_distribution<int> dist(0, 100);

    return Product<int, char>(
        dist(gen),
        p.second  // identidade
    );
}

#endif

/*
Na implementação do morfismo Int×Char → Int×Char, o efeito colateral da função
random é evitado ao instanciar o gerador pseudoaleatório localmente dentro do
morfismo, utilizando como seed um valor derivado exclusivamente da entrada.
Dessa forma, não há uso de estado global nem dependência externa, garantindo
que entradas iguais produzam saídas iguais. Com isso, a função torna-se
determinística e, portanto, um morfismo válido na categoria considerada,
preservando a identidade na segunda coordenada.
*/
