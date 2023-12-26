/**
* @file avlAgaci.hpp
* @description  avl ağacının fonksiyonlarının başlıklarını bulundurur.
* @course 2. öğretim A Grubu
* @assignment 2. Ödev
* @date 16.12.2023
* @author Emir Vardar emir.vardar@ogr.sakarya.edu.tr
*/


#ifndef avlAgaci_hpp
#define avlAgaci_hpp
#include<iostream>
#include "avlDugum.hpp"
#include "yigin.hpp"


using namespace std;

class avlAgaci
{
public:
    
	avlAgaci();
	~avlAgaci();
	void ekle(int veri);
	void sil(int veri);
	int yukseklik();
    void postOrder();
	void yapraklariYiginaEkle(yigin& yigin) const;
	int toplamDugumDeger() const;
	// Yeni eklenen kısım
    
	
	

private:

	int dengesizlikYonu(avlDugum* aktif);
	avlDugum* solaDondur(avlDugum* dugum);
	avlDugum* sagaDondur(avlDugum* dugum);
	int minDeger(avlDugum* aktif);	
	int maxDeger(avlDugum* aktif);
	void postOrder(avlDugum* index);
	int yukseklik(avlDugum* aktifDugum);
	avlDugum* ekle(int veri,avlDugum* aktifDugum);
	avlDugum* sil(int veri,avlDugum* aktif);
	void postorderYapraklariYiginaEkle(avlDugum* node, yigin& yigin) const;
	int toplamDugumDegerRecursive(avlDugum* node) const;
	avlDugum* kok;
	
    
};

#endif