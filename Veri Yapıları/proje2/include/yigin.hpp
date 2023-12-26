/**
* @file yigin.hpp
* @description yigin classının fonksiyonlarının başlıklarını bulundurur
* @course 2. öğretim A Grubu
* @assignment 2. Ödev
* @date 16.12.2023
* @author Emir Vardar emir.vardar@ogr.sakarya.edu.tr
*/
#ifndef yigin_hpp
#define yigin_hpp
#include "yiginDugum.hpp"
#include<exception>
#include<iostream>
#include <iomanip>
using namespace std;

class yigin
{
public:
    yigin();
    void ekle(int veri);
    void cikar();
    int getir();//tepe değeri bulduğumuz fonksiyon
    bool bos() const;
private:
    yiginDugum* tepe;
};

#endif