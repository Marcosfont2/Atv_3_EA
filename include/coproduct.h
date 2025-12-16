#ifndef COPRODUCT_H
#define COPRODUCT_H

/*
Questão 3:
Implementa o coproduto categórico A ⊔ B como união disjunta,
com suas injeções canônicas.
*/

template <typename A, typename B>
class Coproduct {
private:
    bool isLeft;
    A leftValue;
    B rightValue;

public:
    Coproduct(const A& a) : isLeft(true), leftValue(a) {}
    Coproduct(const B& b) : isLeft(false), rightValue(b) {}

    bool fromLeft() const { return isLeft; }
    bool fromRight() const { return !isLeft; }

    A getLeft() const { return leftValue; }
    B getRight() const { return rightValue; }
};

template <typename A, typename B>
Coproduct<A, B> injectLeft(const A& a) {
    return Coproduct<A, B>(a);
}

template <typename A, typename B>
Coproduct<A, B> injectRight(const B& b) {
    return Coproduct<A, B>(b);
}

#endif
