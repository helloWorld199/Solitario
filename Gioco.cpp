#include "Gioco.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <chrono>

using namespace std::chrono;

void creaMazzo(std::vector<Carta*>&);
void mescola(std::vector<Carta*>&);
void scambia(std::vector<Carta*>&, int, int);
bool seUguali(std::vector<Carta*>&, int, int);


//Creazione del mazzo e del campo da gioco
Gioco :: Gioco(){
    int v = 0, p = 0, t = 0;
    while(t < 1000000){
        creaMazzo(mazzo);
        carteCampo = 0;
        carteMazzo = 40;
        controllaCorrispondenze(v, p);
        campo.clear();
        t++;
    }
    std::cout << "vinte:" << v << " " << "perse:" << p;
    /*for(int i = 0; i < 40; i++){
        std::cout << mazzo[i]->getNumero() << " " << mazzo[i]->getSeme() << std::endl;
    }*/
}

void Gioco :: giraCarta(int trovato){
    //Inserisco la carta nel campo e la rimuovo dal mazzo
    //std::cout << mazzo[carteMazzo - 1] << mazzo[carteMazzo - 1]->getNumero();
    /*std::cout << carteMazzo;
    std::cout << mazzo[carteMazzo - 1]->getNumero();
    std::cout << mazzo[carteMazzo - 1]->getNumero();*/
    for(int i = 0; i < trovato; i++){
        campo.pop_back();
    }
    campo.push_back(mazzo[carteMazzo - 1]);
    mazzo.pop_back();
    carteMazzo--;
    carteCampo++;
}

void Gioco :: controllaCorrispondenze(int &v, int&p){
    /*std::cout << (*it)->getSeme();
    auto it1 = campo.end() - 1;
    std::cout << (*it1)->getSeme();*/
    int trovato_coppia = 0;
    giraCarta(trovato_coppia);
    giraCarta(trovato_coppia);
    //ciclo iniziale: finchè continuo a beccare una coppia rimango bloccato qua
    while(carteCampo < 3){
        giraCarta(trovato_coppia);
        trovato_coppia = 0;
        if(seUguali(campo, carteCampo - 3, carteCampo - 1)){
            trovato_coppia++;
            campo[carteCampo - 3] = campo[carteCampo - 2];
            campo[carteCampo - 2] = campo[carteCampo - 1];
            carteCampo--;
        } 
    }

    //ciclo che tiene conto di tutti i casi in cui, pescando, ho almeno 4 carte sul campo
    while(carteMazzo > 0){
        giraCarta(trovato_coppia);
        trovato_coppia = 0;
        if(seUguali(campo, carteCampo - 3, carteCampo - 1)){
            trovato_coppia++;
            campo[carteCampo - 3] = campo[carteCampo - 2];
            campo[carteCampo - 2] = campo[carteCampo - 1];
            carteCampo--;
        } else { //se non ho trovato la coppia, ripesco
            continue;
        }

        while(carteCampo > 3){
            if(seUguali(campo, carteCampo - 4, carteCampo - 2)){
                trovato_coppia++;
                campo[carteCampo - 4] = campo[carteCampo - 3];
                campo[carteCampo - 3] = campo[carteCampo - 2];
                campo[carteCampo - 2] = campo[carteCampo - 1];
                carteCampo--;
            }
            else{
                if(seUguali(campo, carteCampo - 3, carteCampo - 1)){
                trovato_coppia++;
                campo[carteCampo - 3] = campo[carteCampo - 2];
                campo[carteCampo - 2] = campo[carteCampo - 1];
                carteCampo--;
            } else {
                break;
            }
            }
        }
        if(carteCampo == 3){
        if(seUguali(campo, carteCampo - 3, carteCampo - 1)){
            trovato_coppia++;
            campo[carteCampo - 3] = campo[carteCampo - 2];
            campo[carteCampo - 2] = campo[carteCampo - 1];
            carteCampo--;
        }
        }
        if(carteCampo == 2 && carteMazzo == 0){
            v++;
        }
        
    }
    if(carteCampo > 2 && carteMazzo == 0){
        p++;
    }
}

void creaMazzo(std::vector<Carta*> &mazzo){
    mazzo.clear();
    for(int i = 0; i < 40; i++){
        mazzo.push_back(new Carta("picche", (i + 1)));
        mazzo.push_back(new Carta("cuori", (i + 1)));
        mazzo.push_back(new Carta("quadri", (i + 1)));
        mazzo.push_back(new Carta("fiori", (i + 1)));
    }

    mescola(mazzo);
}

void mescola(std::vector<Carta*> &mazzo){
    srand(time(NULL));
    for (int i = 0; i < 40 ; i++)
    {
        // Random for remaining positions.
        int r = rand() % 40;
  
        scambia(mazzo, i, r);
    }
}

void scambia(std::vector<Carta*> &mazzo, int prev, int next){
    Carta* temp = mazzo[prev];
    mazzo[prev] = mazzo[next];
    mazzo[next] = temp;
}

/*Stabilisce se due carte, di indici i1 e i2 nel campo
hanno seme O numero uguale. */

bool seUguali(std::vector<Carta*> &campo, int i1, int i2){
    if(campo[i1] -> getNumero() == campo[i2] -> getNumero() || (campo[i1] -> getSeme()).compare(campo[i2]->getSeme()) == 0){
        return true;
    }
    return false;
}