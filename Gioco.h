#include "Carta.h"
#include <vector>
#include <iostream>

class Gioco{
    private:
        std::vector<Carta*> campo;
        std::vector<Carta*> mazzo;
        int carteCampo;
        int carteMazzo;
    public:
        Gioco();
        void giraCarta(int);
        void controllaCorrispondenze(int&, int&);
};