/**
* @file avlDugum.cpp
* @description avl ağacının düğüm yapısı
* @course 2. öğretim A Grubu
* @assignment 2. Ödev
* @date 16.12.2023
* @author Emir Vardar emir.vardar@ogr.sakarya.edu.tr
*/
#include "avlDugum.hpp"

avlDugum::avlDugum(int veri)
{
    this->veri = veri;
    sol=sag=0;
}