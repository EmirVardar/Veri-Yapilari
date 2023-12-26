/**
* @file main.cpp
* @description main dosya okuma,ağaçları doldurma ve ağaç silme işlemleri
* @course 2. öğretim A Grubu
* @assignment 2. Ödev
* @date 16-17-18-19-20-23-24 .12.2023
* @author Emir Vardar emir.vardar@ogr.sakarya.edu.tr
*/

#include<iostream>
#include<iomanip>
#include <fstream>
#include <string>
#include "avlAgaci.hpp"
#include "yigin.hpp"
#include <sstream>
#include <climits>
#include <thread>
#include <chrono> // chrono başlık dosyasını ekledik
using namespace std;

#ifdef _WIN32
    #include <windows.h>  // Windows için Sleep fonksiyonu

#endif


int main()
{
  
    ifstream file("Veri.txt");

    
    if (!file.is_open()) {
        cerr << "Dosya açılamadı." << endl;
        return 1; 
    }

    
    avlAgaci* avlDizisi = nullptr;
    yigin* yaprakStackDizisi = nullptr;
    size_t numAgac = 0;
    string line;

    //not defterindeki verileri ağaçlara yazıyoruz ve ağaçları oluşturuyoruz
    while (getline(file, line)) {

        ++numAgac;
        
        
        avlAgaci* tempDizi = new avlAgaci[numAgac];
        yigin* tempStackDizisi = new yigin[numAgac];

        for (size_t i = 0; i < numAgac - 1; ++i) 
        {
            tempDizi[i] = avlDizisi[i];
            tempStackDizisi[i] = yaprakStackDizisi[i];
            
        }

        delete[] avlDizisi;         
        delete[] yaprakStackDizisi; 

        avlDizisi = tempDizi;         
        yaprakStackDizisi = tempStackDizisi; 

        istringstream iss(line);
        int number;

        while (iss >> number) 
        {
            avlDizisi[numAgac - 1].ekle(number); 
        }

        avlDizisi[numAgac - 1].yapraklariYiginaEkle(yaprakStackDizisi[numAgac - 1]);
        
    }

    //küçük büyük olacak sırada silme işlemleri
    while (true) {
        
        int enKucukDeger = INT_MAX;
        int enBuyukDeger = INT_MIN;
        int enKucukIndex = -1;
        int enBuyukIndex = -1;

        
        for (size_t i = 0; i < numAgac; ++i) 
        {   //tepe değerleri karşılaştırılıyor
            if (!yaprakStackDizisi[i].bos()) 
            {
                int tepeDeger = yaprakStackDizisi[i].getir();

                if (tepeDeger < enKucukDeger) 
                {
                    enKucukDeger = tepeDeger;
                    enKucukIndex = i;
                }

                if (tepeDeger > enBuyukDeger) 
                {
                    enBuyukDeger = tepeDeger;
                    enBuyukIndex = i;
                }
            }
        }
        //tepe değerini çıkarıyoruz
        if (enKucukIndex != -1) 
        {
            yaprakStackDizisi[enKucukIndex].cikar();
            
        } else 
        {
            cout << "En Kucuk Degeri Bulma Hatasi." << endl;
        }
        
        if (enBuyukIndex != -1) 
        {
            yaprakStackDizisi[enBuyukIndex].cikar();
            
        } else 
        {
            cout << "En Buyuk Degeri Bulma Hatasi." << endl;
        }
        int ascii ;
        //içi boşalırsa ağaç siliniyor
        for (size_t i = 0; i < numAgac; ++i) 
        {
            if (yaprakStackDizisi[i].bos()) 
            {
                
                for (size_t j = i; j < numAgac - 1; ++j) 
                {
                    
                    avlDizisi[j] = avlDizisi[j + 1];
                    yaprakStackDizisi[j] = yaprakStackDizisi[j + 1];
                }
                
                --numAgac;
    
                avlAgaci* tempDizi = new avlAgaci[numAgac];
                yigin* tempStackDizisi = new yigin[numAgac];

                for (size_t k = 0; k < numAgac; ++k) {
                    tempDizi[k] = avlDizisi[k];
                    tempStackDizisi[k] = yaprakStackDizisi[k];
                }

                delete[] avlDizisi;
                delete[] yaprakStackDizisi;

                avlDizisi = tempDizi;
                yaprakStackDizisi = tempStackDizisi;
                
                system("cls||clear");
                for (size_t k = 0; k < numAgac; ++k) 
                {
                    int toplamDeger = avlDizisi[k].toplamDugumDeger();
                     ascii = toplamDeger % (90 - 65 + 1) + 65;
                    cout << static_cast<char>(ascii) ;
                    
                }
                
                // cout << endl;
                #ifdef _WIN32
                    Sleep(10);  // Windows için Sleep fonksiyonu (0.5 saniye)
                #endif
                        
                break;  // Döngüyü sonlandır
            }

        }
        
        //eğer bir ağaç varsa döngüden çıkılır
        if (numAgac == 1) 
        {
            system("cls||clear");
            cout<<"Son Karakter : "  << static_cast<char>(ascii) ;
            
            break;
            
        }

    }
   
   
    
        



     
    file.close();

    // Dinamik dizileri temizle
    delete[] avlDizisi;
    delete[] yaprakStackDizisi;
    

    return 0;
  

    
    


    


}