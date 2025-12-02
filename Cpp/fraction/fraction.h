//
// Created by Ishmael on 2025-11-21.
//

#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
#include <cstring>
namespace MATH {
    class FractionException {
        char info[256];
    public:
        const char* getinfo() {
            return info;
        };
        FractionException(const char* msg) {
            strncpy(info,msg, 255);
            info[255] = '\0'; // 确保字符串以 null 结尾
        }
    };

    class Fraction {
        int numerateur = 0;
        int denominateur = 0;
        void simplification();
    public:
        Fraction(int n = 0,int d = 1);
        Fraction(const Fraction &f);
        ~Fraction();
        Fraction operator+(const Fraction &f);
        Fraction operator+(int n);
        friend Fraction operator+(int n,Fraction &f);
        Fraction &operator++();
        Fraction operator++(int);
        int getNumerateur() const;
        int getDenomiteur() const;
        void setFraction(int numerateur,int denomiteur);
        Fraction addFraction(const Fraction &f) const;
        friend std::ostream &operator<<(std::ostream &os,const Fraction &f);
    };
}
#endif //FRACTION_H
