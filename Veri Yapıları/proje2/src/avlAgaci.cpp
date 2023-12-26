/**
* @file avlAgaci.cpp
* @description avl ağacının fonksiyonlarını tanımladık
* @course 2. öğretim A Grubu
* @assignment 2. Ödev
* @date 16.12.2023
* @author Emir Vardar emir.vardar@ogr.sakarya.edu.tr
*/

#include "avlAgaci.hpp"

#include <cmath>
#include <iomanip>
#include<iostream>
#include<queue>


using namespace std;
avlAgaci::avlAgaci()
{
    kok=0;
}
avlAgaci::~avlAgaci()
{

}

void avlAgaci::ekle(int eklenecek)
{
    kok = ekle(eklenecek,kok);
}
void avlAgaci::sil(int veri) 
{
	kok = sil(veri,kok);
}
int avlAgaci::yukseklik() 
{
	return yukseklik(kok);
}

void avlAgaci::postOrder() {
	postOrder(0);
}

void avlAgaci::postOrder(avlDugum* aktif) 
{
	if(aktif)
    {
        
        postOrder(aktif->sol);
        postOrder(aktif->sag);
        cout<<aktif->veri<<"  ";
    }	
}

int avlAgaci::yukseklik(avlDugum* aktifDugum) 
{
	if(aktifDugum)
    {
        return 1+max(   yukseklik(aktifDugum->sol),
                        yukseklik(aktifDugum->sag));
    }
    return -1;
}
avlDugum* avlAgaci::ekle(int veri,avlDugum* aktifDugum) 
{
    if(aktifDugum==0)
        return new avlDugum(veri);

	else if(aktifDugum->veri<veri)
    {
        aktifDugum->sag=ekle(veri,aktifDugum->sag);
        if(yukseklik(aktifDugum->sag)-yukseklik(aktifDugum->sol)>1)
        {   
            if(veri>aktifDugum->sag->veri)
                aktifDugum = solaDondur(aktifDugum);
                
            else
            {
                aktifDugum->sag = sagaDondur(aktifDugum->sag);
                aktifDugum =solaDondur(aktifDugum);
            }
        }
    }
    else if(aktifDugum->veri>veri)
    {
        aktifDugum->sol = ekle(veri,aktifDugum->sol);
        if(yukseklik(aktifDugum->sol)-yukseklik(aktifDugum->sag)>1)
        {

            if(veri<aktifDugum->sol->veri)
                aktifDugum = sagaDondur(aktifDugum);
            else
            {
                aktifDugum->sol = solaDondur(aktifDugum->sol);
                aktifDugum =sagaDondur(aktifDugum);
            }
        }

    }
    return aktifDugum;
}
avlDugum* avlAgaci::solaDondur(avlDugum* buyukEbeveyn) 
{
	avlDugum* sagCocuk = buyukEbeveyn->sag;
    buyukEbeveyn->sag = sagCocuk->sol;
    sagCocuk->sol = buyukEbeveyn;
    return sagCocuk;
}
avlDugum* avlAgaci::sagaDondur(avlDugum* buyukEbeveyn) 
{
	avlDugum* solCocuk = buyukEbeveyn->sol;
    buyukEbeveyn->sol = solCocuk->sag;
    solCocuk->sag = buyukEbeveyn;
    return solCocuk;
}
int avlAgaci::maxDeger(avlDugum* aktif) 
{
    if(aktif->sag)
        return maxDeger(aktif->sag);
    
    return aktif->veri;
}

avlDugum* avlAgaci::sil(int veri,avlDugum* aktif) 
{
	if(aktif==0)
        return 0;
    
    if(veri<aktif->veri)
    {
        aktif->sol = sil(veri,aktif->sol);
    }
    else if(veri>aktif->veri)
    {
        aktif->sag = sil(veri,aktif->sag);
    }
    else//aradığımız düğümü bulduk
    {
        if(aktif->sol==0&&aktif->sag==0)
        {
            delete aktif;
            aktif= 0;
        }
        else if(aktif->sol==0)
        {
            avlDugum* sil = aktif->sag;
            *aktif = *aktif->sag;
            delete sil;
        }
        else if(aktif->sag==0)
        {
            avlDugum* sil  = aktif->sol;
            *aktif=*aktif->sol;
            delete sil;
        }
        else 
        {
            aktif->veri = minDeger(aktif->sag);
            sil(aktif->veri,aktif->sag);
        }

        
    }
    
    
    int denge = dengesizlikYonu(aktif);

    if(denge>1) //sol tarafta dengesizlik
    {
        //sol sol dengesizliği
        if(dengesizlikYonu(aktif->sol)>=0)
        {
            return sagaDondur(aktif);
        }
        //sol sag durumu
        if(dengesizlikYonu(aktif->sol)<0)
        {
            aktif->sol=solaDondur(aktif->sol);
            return sagaDondur(aktif);
        }
    }
    else if(denge<-1)//sag tarafta dengesizlik
    {
        //sağ sağ durumu
        if(dengesizlikYonu(aktif->sag)<=0)
        {
            return solaDondur(aktif);
        }
        //sağ sol durumu
        if(dengesizlikYonu(aktif->sag)>0)
        {
            aktif->sag = sagaDondur(aktif->sag);
            return solaDondur(aktif);
        }
    }    
    return aktif;
}
int avlAgaci::minDeger(avlDugum* aktif) 
{
    if(aktif->sol)
        return maxDeger(aktif->sol);
    
    return aktif->veri;
}

int avlAgaci::dengesizlikYonu(avlDugum* aktif) 
{
    if(aktif==0)
        return 0;
    return yukseklik(aktif->sol)- yukseklik(aktif->sag);
}


//ÖNEMLİ FONKSİYON

void avlAgaci::yapraklariYiginaEkle(yigin& yigin) const 
{
        postorderYapraklariYiginaEkle(kok, yigin);
}

void avlAgaci::postorderYapraklariYiginaEkle(avlDugum* node, yigin& yigin) const 
{
        if (node != nullptr) 
        {
            postorderYapraklariYiginaEkle(node->sol, yigin);
            postorderYapraklariYiginaEkle(node->sag, yigin);

            // Yaprak düğümü kontrolü
            if (node->sol == nullptr && node->sag == nullptr) 
            {
                yigin.ekle(node->veri);
            }
        }
}

int avlAgaci::toplamDugumDeger() const 
{
    return toplamDugumDegerRecursive(kok);
}

int avlAgaci::toplamDugumDegerRecursive(avlDugum* node) const 
{
    if (node == nullptr) 
    {
        return 0;
    }

    // Yaprak düğümü kontrolü
    if (node->sol == nullptr && node->sag == nullptr) 
    {
        return 0;  // Yaprak düğümü ise 0 döndür
    }

    return node->veri + toplamDugumDegerRecursive(node->sol) + toplamDugumDegerRecursive(node->sag);
}

    
