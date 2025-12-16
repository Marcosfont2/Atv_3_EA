#ifndef RANDOM_MORPHISM_H
#define RANDOM_MORPHISM_H

#include <random>
#include "product.h"

/*
Questão 5:
Implementa um morfismo puro usando pseudo-random com seed local,
evitando efeitos colaterais e garantindo determinismo.
*/

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

