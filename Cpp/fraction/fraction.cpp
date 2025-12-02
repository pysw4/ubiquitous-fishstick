//
// Created by Ishmael on 2025-11-21.
//
#include "fraction.h"
// à ajouter en tant méthode privée de la classe Fraction
namespace MATH{
    Fraction::Fraction(int n,int d){
        numerateur = n;
        denominateur = d;
        simplification();
    }
    Fraction::Fraction(const Fraction &f) {
        numerateur = f.getNumerateur();
        denominateur = f.getDenomiteur();
    }
    Fraction Fraction::operator+(const Fraction &f){
        return addFraction(f);
    }
    // Fraction operator+(const Fraction &f1,const Fraction &f2) {
    //     return f1.addFraction(f2);
    // }
    Fraction Fraction::operator+(int n) {
        return addFraction(Fraction(n,1));
    }
    Fraction operator+(int n,Fraction &f) {
        return Fraction(n,1).addFraction(f);
    }
    Fraction & Fraction::operator++() {
       numerateur += denominateur;
        return *this;
    }
    Fraction Fraction::operator++(int) {
        Fraction temp = Fraction(numerateur,denominateur);
        Fraction f = temp;
        ++f;
        return temp;
    }
    std::ostream &operator<<(std::ostream &os,const Fraction &f){
        os<<f.getNumerateur()<<"/"<<f.getDenomiteur();
        return os;
    }
    Fraction Fraction::addFraction(const Fraction &f) const {
        return {numerateur*f.getDenomiteur()+denominateur*f.getNumerateur(),denominateur*f.getDenomiteur()};
    }
    Fraction::~Fraction() {
        std::cout<<"析构"<<this<<"=>"<<numerateur<<" "<<denominateur<<std::endl;
    }

}
inline int MATH::Fraction::getNumerateur() const {
    return numerateur;
}
int MATH::Fraction::getDenomiteur() const {
    return denominateur;
}
void MATH::Fraction::simplification(){
    // si le numerateur est 0, le denominateur prend la valeur 1
    if (numerateur==0) { denominateur=1; return; }
    /* un denominateur ne devrait pas être 0;
    si c’est le cas, on sort de la méthode */
    if (denominateur==0)
        throw FractionException("Denominateur nul!");
    /* utilisation de l’algorithme d’Euclide pour trouver le Plus Grand Commun
    Denominateur (PGCD) entre le numerateur et le denominateur */
    int a=numerateur, b=denominateur;
    // on ne travaille qu’avec des valeurs positives...
    if (a<0) a=-a;
    if (b<0) b=-b;
    if (denominateur==1) return;
    while(a!=b){ if (a>b) a=a-b; else b=b-a; }//求分子分母的最大公约数
    // on divise le numerateur et le denominateur par le PGCD=a
    numerateur/=a; denominateur/=a;
    // si le denominateur est négatif, on fait passer le signe - au numérateur
    if (denominateur<0) {
        denominateur=-denominateur; numerateur=-numerateur;
    }
}
void MATH::Fraction::setFraction(int n,int d) {
    numerateur = n;
    denominateur = d;
    simplification();
}




