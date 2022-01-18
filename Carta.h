#include <iostream>

class Carta{
    private:
    const std::string seme;
    const int numero;
    public:
    Carta(): seme{"null"}, numero{-1}{
    }
    Carta(std::string seme_, int numero_): seme{seme_}, numero{numero_}{
    }
    Carta(const Carta &c):seme{c.seme}, numero{c.numero}{
    }

    std::string getSeme() const {
        return seme;
    }

    int getNumero() const {
        return numero;
    }
};