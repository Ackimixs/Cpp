#ifndef TP7_PERSONNAGE_H
#define TP7_PERSONNAGE_H

#include <cstring>

class Weapon {
private:
    int degats;

public:
    Weapon(int degats) : degats(degats) {}
    int tape() const {
        return this->degats;
    }
};

class Epee : public Weapon {
public:
    Epee() : Weapon(10) {}
};

class Katana : public Weapon {
public:
    Katana() : Weapon(20) {}
};

class Pistolet : public Weapon {
public:
    Pistolet() : Weapon(30) {}
};

template<class T> class Fourreau {
private:
    T* arme;
public:
    Fourreau(T* arme) : arme(arme) {}
    int degaine_et_tape() const {
        return this->arme->tape();
    }
};

template<class T> class Personnage {
private:
    int vie;
    char* name;
    Fourreau<T>* arme;

public:
    Personnage(int vie, char* name, Fourreau<T>* arme) : vie(vie), arme(arme) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    void setLife(int vie) {
        this->vie = vie;
    }

    int getLife() const {
        return this->vie;
    }

    template<class P> void attaque(Personnage<P>& p) const {
        if (p.getLife() > 0) {
            if (p.getLife() < this->arme->degaine_et_tape()) {
                p.setLife(0);
            } else {
                p.setLife(p.getLife() - this->arme->degaine_et_tape());
            }
        }
    }

    void display() const {
        std::cout << this->name << " : " << this->vie << std::endl;
    }
};


#endif //TP7_PERSONNAGE_H
