/**
* @file yigin.cpp
* @description yiginin fonksiyonları
* @course 2. öğretim A Grubu
* @assignment 2. Ödev
* @date 16.12.2023
* @author Emir Vardar emir.vardar@ogr.sakarya.edu.tr
*/
#include "yigin.hpp"
#include<exception>
#include<iostream>
#include <iomanip>
using namespace std;

yigin::yigin()
{
    tepe=0;
}
void yigin::ekle(int veri)
{
    yiginDugum* yeni = new yiginDugum(veri);
    if(tepe!=0)
        yeni->sonraki=tepe;
    tepe= yeni;
}
void yigin::cikar()
{
    if(tepe!=0)
    {
        yiginDugum* silinecek = tepe;
        tepe=tepe->sonraki;
        delete silinecek;
    }
    
}

int yigin::getir()
{
    if(tepe!=0)
        return tepe->veri;
    throw std::out_of_range("Yigin::Getir(): Yigin Bos");
}
bool yigin::bos() const {
    
    return (tepe == nullptr);
}
