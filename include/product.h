#ifndef PRODUCT_H
#define PRODUCT_H

/*
Questão 2:
Implementa o produto categórico A×B na categoria Set, junto com
suas projeções canônicas π1 e π2.
*/

template <typename A, typename B>
struct Product {
    A first;
    B second;

    Product(const A& a, const B& b) : first(a), second(b) {}
};

template <typename A, typename B>
A proj1(const Product<A, B>& p) {
    return p.first;
}

template <typename A, typename B>
B proj2(const Product<A, B>& p) {
    return p.second;
}

#endif
