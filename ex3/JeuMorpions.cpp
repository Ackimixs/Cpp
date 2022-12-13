#include "JeuMorpions.h"

void JeuMorpions::init() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            grille[i][j] = VIDE;
        }
    }
}

void JeuMorpions::setNameUser1(string name) {
    nameUser1 = name;
}

void JeuMorpions::setNameUser2(string name) {
    nameUser2 = name;
}

bool JeuMorpions::placer_coup(int ligne, int colonne, Content c) {
    grille[ligne][colonne] = c;
    return true;
}

bool JeuMorpions::placer_rond(int ligne, int colonne) {
    if (ligne < 0 || ligne > 2 || colonne < 0 || colonne > 2) {
        return false;
    } else if (grille[ligne][colonne] == VIDE) {
        placer_coup(ligne, colonne, ROND);
        return true;
    } else {
        return false;
    }
}

bool JeuMorpions::placer_croix(int ligne, int colonne) {
    if (ligne < 0 || ligne > 2 || colonne < 0 || colonne > 2) {
        return false;
    } else if (grille[ligne][colonne] == VIDE) {
        placer_coup(ligne, colonne, CROIX);
        return true;
    } else {
        return false;
    }
}

void JeuMorpions::print() {
    system("clear");
    Color::Modifier red(Color::FG_RED);
    Color::Modifier green(Color::FG_GREEN);
    Color::Modifier bold(Color::BOLD);
    Color::Modifier reset(Color::RESET);
    for (int i = 0; i < 3; i++) {
        std::cout << "|";
        for (int j = 0; j < 3; j++) {
            if (grille[i][j] == VIDE) {
                std::cout << " ";
            } else if (grille[i][j] == ROND) {
                std::cout << red << bold <<  "O" << reset;
            } else {
                std::cout << green << bold << "X" << reset;
            }
            std::cout << "|";
        }
        if (i == 2) {
            std::cout << std::endl;
        } else {
            std::cout << std::endl << "-------" << std::endl;
        }
    }
}

void JeuMorpions::setUser() {
    std::cout << "====================================" << std::endl;
    std::cout << "Nom du joueur 1: ";
    std::cin >> nameUser1;
    std::cout << "Nom du joueur 2: ";
    std::cin >> nameUser2;
    std::cout << "====================================" << std::endl;
    setNameUser1(nameUser1);
    setNameUser2(nameUser2);
}

bool JeuMorpions::playUser1() {
    int ligne, colonne;
    std::cout << "Joueur 0: " << getNameUser1() << std::endl;
    std::cout << "Ligne: ";
    std::cin >> ligne;
    std::cout << "Colonne: ";
    std::cin >> colonne;
    if (placer_rond(ligne-1, colonne-1)) {
        return true;
    } else {
        std::cout << "Erreur: Vous ne pouvez pas jouer ici." << std::endl;
        return false;
    }
}

bool JeuMorpions::playUser2() {
int ligne, colonne;
    std::cout << "Joueur X: " << getNameUser2() << std::endl;
    std::cout << "Ligne: ";
    std::cin >> ligne;
    std::cout << "Colonne: ";
    std::cin >> colonne;
    if (placer_croix(ligne-1, colonne-1)) {
        return true;
    } else {
        std::cout << "Erreur: Vous ne pouvez pas jouer ici." << std::endl;
        return false;
    }
}


void JeuMorpions::game() {
    system("clear");

    setUser();

    bool result = false;

    while (!result) {
        bool played = false;

        do {
            played = playUser1();
            system("clear");
        } while (!played);

        print();
        result = win();
        if (result) {
            std::cout << getNameUser1() << " a gagne!" << std::endl;
            break;
        }

        played = false;

        do {
            played = playUser2();
            system("clear");
        } while (!played);

        print();
        result = win();
        if (result) {
            std::cout << getNameUser2() << " a gagne!" << std::endl;
            break;
        }
    }

}

bool JeuMorpions::win() {
    if (grille[0][0] == grille[0][1] && grille[0][1] == grille[0][2] && grille[0][0] != VIDE) {
        return true;
    } else if (grille[1][0] == grille[1][1] && grille[1][1] == grille[1][2] && grille[1][0] != VIDE) {
        return true;
    } else if (grille[2][0] == grille[2][1] && grille[2][1] == grille[2][2] && grille[2][0] != VIDE) {
        return true;
    } else if (grille[0][0] == grille[1][0] && grille[1][0] == grille[2][0] && grille[0][0] != VIDE) {
        return true;
    } else if (grille[0][1] == grille[1][1] && grille[1][1] == grille[2][1] && grille[0][1] != VIDE) {
        return true;
    } else if (grille[0][2] == grille[1][2] && grille[1][2] == grille[2][2] && grille[0][2] != VIDE) {
        return true;
    } else if (grille[0][0] == grille[1][1] && grille[1][1] == grille[2][2] && grille[0][0] != VIDE) {
        return true;
    } else if (grille[0][2] == grille[1][1] && grille[1][1] == grille[2][0] && grille[0][2] != VIDE) {
        return true;
    } else {
        return false;
    }
}
