/**
* @file avlDugum.hpp
* @description avl ağacının düğümünün başlıklarını bulundurur
* @course 2. öğretim A Grubu
* @assignment 2. Ödev
* @date 16.12.2023
* @author Emir Vardar emir.vardar@ogr.sakarya.edu.tr
*/
#ifndef avlDugum_hpp
#define avlDugum_hpp

class avlDugum
{
public:
    avlDugum(int veri);
    int veri;
    avlDugum* sol;
    avlDugum* sag;
};

#endif