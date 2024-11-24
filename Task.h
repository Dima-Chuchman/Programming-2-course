#pragma once
#include <iostream>

class Polynom {
    size_t n;
    double* p;
public:
    Polynom() { n = 0; }
    Polynom(size_t n);
    Polynom(size_t, double* arr);
    ~Polynom();

    Polynom& operator = (const Polynom);
    Polynom(const Polynom& p);
    int set(size_t k, double a);
    double get(size_t k);
    void show();
    friend int saveFile(const char* fname, const Polynom& p);
    friend int readFile(const char* fname, Polynom& p);

};

#endif