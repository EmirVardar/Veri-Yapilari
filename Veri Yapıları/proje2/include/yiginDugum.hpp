/**
* @file yiginDugum.hpp
* @description yiginin düğüm yapısı ve başlıkları.
* @course 2. öğretim A Grubu
* @assignment 2. Ödev
* @date 16.12.2023
* @author Emir Vardar emir.vardar@ogr.sakarya.edu.tr
*/
#ifndef yiginDugum_hpp
#define yiginDugum_hpp


class yiginDugum
{
public:
    yiginDugum(int veri);
    int veri;
    yiginDugum* sonraki;
};
#endif