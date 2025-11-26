#include<iostream>
#include "fonction.h"
#include<string>
using namespace std;
void bonjour() {
    cout<<"Entrez votre prenom :";
    string prenom;
    cin>>prenom;
    cout<<"Bonjour "<<prenom<<"\n";
}
int &operation(compte *tab,const string str){
    for(int i = 0;i < 4;i++) {
        if(tab[i].id == str)
            return tab[i].solde;
    }
}
void essai_comptes(){
    compte tab[4]={ {"courant", 0},{"codevi", 1500 },
    {"epargne", 200 }, { "cel", 300 } };
    operation(tab,"courant")=100;
    operation(tab,"codevi")+=100;
    operation(tab,"cel")-=50;
    for(int i=0; i<4; i++) cout<<tab[i].id<<" : "<<tab[i].solde<<"\n";
}
// void init(point* pt, int _x, int _y, int _z) {
//     pt->x=_x; pt->y=_y; pt->z=_z;
// }
// void init(point* pt, int _x, int _y) {
//     pt->x=_x; pt->y=_y; pt->z=0;
// }
// void init(point* pt, int _x) {
//     pt->x=_x; pt->y=0; pt->z=0;
// }
// void init(point* pt) {
//     pt->x=0; pt->y=0; pt->z=0;
// }
void init(point *pt,int x = 0,int y = 0,int z = 0) {
    pt->x = x;
    pt->y = y;
    pt->z = z;
}
void essai_init() {
    point p;
    init(&p);
    cout<<p.x<<" "<<p.y<<" "<<p.z<<endl;
    init(&p,1);
    cout<<p.x<<" "<<p.y<<" "<<p.z<<endl;
    init(&p,1,2);
    cout<<p.x<<" "<<p.y<<" "<<p.z<<endl;
    init(&p,1,2,3);
    cout<<p.x<<" "<<p.y<<" "<<p.z<<endl;
}
void essai_alloc(){
    int* pt_int;
    double* pt_double;
    pt_int = new int;//(int*)malloc(sizeof(int));
    pt_double = new double[100];//(double*)malloc(sizeof(double)*100);
    free(pt_int);
    free(pt_double);
}