#ifndef MORPHISMS_H
#define MORPHISMS_H

#include <functional>
#include <utility>
#include "product.h"

/*
Questões 1 e 4:
Define morfismos entre produtos e a tradução de um morfismo
nas projeções canônicas.
*/

template <typename A, typename B, typename C, typename D>
using PairMorphism =
    std::function<Product<C, D>(const Product<A, B>&)>;

template <typename A, typename B, typename C, typename D>
std::pair<
    std::function<C(const Product<A, B>&)>,
    std::function<D(const Product<A, B>&)>
>
translateToProjections(
    PairMorphism<A, B, C, D> f
) {
    auto toC = [f](const Product<A, B>& p) {
        return proj1(f(p));
    };

    auto toD = [f](const Product<A, B>& p) {
        return proj2(f(p));
    };

    return std::make_pair(toC, toD);
}

#endif
