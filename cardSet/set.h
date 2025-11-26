//
// Created by Ishmael on 2025-11-21.
//

#ifndef SET_H
#define SET_H
#include<iostream>
enum Couleur {
    rouge,violet,vert
};
enum Nombre {
    un,deux,trois
};
enum Forme {
    ovale,vague,losange
};
enum Remplissage {
plein,hachure,vide
};

    class Carte {
        Couleur couleur;
        Nombre nombre;
        Forme forme;
        Remplissage remplissage;
    public:
        Carte(Couleur c = vert,Nombre n = un, Forme f = ovale,Remplissage r = vide){
            couleur = c;
            nombre = n;
            forme = f;
            remplissage = r;
        }
        Carte(Carte &c) {
            couleur = c.getCouleur();
            nombre = c.getNombre();
            forme = c.getForme();
            remplissage = c.getRemplissage();
        }
        ~Carte() {
            std::cout <<couleur<<" "<<nombre<<" "<<forme<<" "<<remplissage<<std::endl;
        }
        Couleur getCouleur() {
            return couleur;
        }
        Nombre getNombre() {
            return nombre;
        }
        Forme getForme() {
            return forme;
        }
        Remplissage getRemplissage() {
            return remplissage;
        }
        void setCouleur(Couleur c) {
            couleur = c;
        }
        void setNombre(Nombre n) {
            nombre = n;
        }
        void setForme(Forme f) {
            forme = f;
        }
        void setRemplissage(Remplissage r) {
            remplissage = r;
        }

        Carte operator*();
    };
class Jeu{
    Carte *cartes[81];
public:
    Jeu(){
        int i = 0;
        for(int cou = 0;cou < 3;cou++){
            for(int nom = 0; nom < 3;nom++){
                for(int forme = 0;forme < 3;forme++) {
                    for(int rem = 0;rem < 3;rem++) {
                        Carte carte = Carte(static_cast<Couleur>(cou),static_cast<Nombre>(nom),static_cast<Forme>(forme),static_cast<Remplissage>(rem));
                        cartes[i] = &carte;
                        i++;
                    }
                }
            }
        }

    }
    ~Jeu() {
        delete[] cartes[81];
        std::cout<<"Jeu is deleted"<<std::endl;
    }
    Carte* getCartes() {
        return cartes[81];
    }
};
class Pioche{
    //Carte** cartes[];
    size_t nb;


};
class Plateau {

};
class Controleur {

};

#endif //SET_H
