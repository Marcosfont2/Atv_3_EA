#include <iostream>
#include "../include/product.h"
#include "../include/coproduct.h"
#include "../include/morphisms.h"
#include "../include/random_morphism.h"

int main() {

    // Questão 2 
    Product<int, char> p(10, 'A');
    std::cout << "Produto: (" << proj1(p) << ", " << proj2(p) << ")\n";

    // Questão 3 
    auto c1 = injectLeft<int, char>(42);
    auto c2 = injectRight<int, char>('Z');

    if (c1.fromLeft())
        std::cout << "Coproduct A: " << c1.getLeft() << "\n";

    if (c2.fromRight())
        std::cout << "Coproduct B: " << c2.getRight() << "\n";

    // Questão 4 
    PairMorphism<int, char, int, char> f =
        [](const Product<int, char>& x) {
            return Product<int, char>(x.first + 1, x.second);
        };

    auto translated = translateToProjections(f);
    std::cout << "πC ∘ f = " << translated.first(p) << "\n";
    std::cout << "πD ∘ f = " << translated.second(p) << "\n";

    // Questão 5
    auto r1 = pureRandomMorphism(p);
    auto r2 = pureRandomMorphism(p);

    std::cout << "Random puro 1: (" << r1.first << ", " << r1.second << ")\n";
    std::cout << "Random puro 2: (" << r2.first << ", " << r2.second << ")\n";

    return 0;
}
