#include "Rational.h"
#include <iostream>

Rational maxRational(Rational* arr, int n) {
    Rational minRat;
    minRat = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i].less(minRat)) {
            minRat = arr[i];
        }
    }
    return minRat;
}

Rational Hregory(double eps) {
    Rational S;
    int sign = -1;
    for (int i = 2; eps * i * i < 1; i++) {
        Rational tmp;
        tmp.setNom(sign);
        sign = -sign;
        tmp.setDenom(i * i);
        S = S.add(tmp);
    }
    return S;
}