#include "game.h"


void Game::setUsers(User *user1, User *user2) {
    this->user1 = user1;
    this->user2 = user2;
}

void Game::setUser1(User *user1) {
    this->user1 = user1;
}

void Game::setUser2(User *user2) {
    this->user2 = user2;
}

User *Game::getUser1() const {
    return user1;
}

User *Game::getUser2() const {
    return user2;
}

void Game::init() {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            grille[i][j] = 0;
        }
    }
}

void Game::print(int x1, int y1, int x2, int y2) {
    cout << "--------------------" << endl;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (j == x1 && i == y1) {
                cout << "X";
            } else if (j == x2 && i == y2) {
                cout << "O";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
    cout << "--------------------" << endl;
}

void Game::playUser(User *user) {
    cout << "User " << user->getName() << " is playing" << endl;
    cout << "zqsd or a for attack  ";
    char input;
    cin >> input;
    switch (input) {
        case 'z':
            user->setPosition(user->getX(), user->getY() - 1);
            break;
        case 'q':
            user->setPosition(user->getX() - 1, user->getY());
            break;
        case 's':
            user->setPosition(user->getX(), user->getY() + 1);
            break;
        case 'd':
            user->setPosition(user->getX() + 1, user->getY());
            break;
        case 'a':
            if (user == user1) {
                user1->attack(user2);
            } else {
                user2->attack(user1);
            }
            break;
        default:
            cout << "Invalid input" << endl;
            break;
    }


    print(user1->getX(), user1->getY(), user2->getX(), user2->getY());
}

void Game::start() {
    print(user1->getX(), user1->getY(), user2->getX(), user2->getY());
    while (user1->getIsAlive() && user2->getIsAlive()) {
        playUser(user1);

        if (!user2->getIsAlive()) {
            cout << "User " << user2->getName() << " is dead" << endl;
            print(user1->getX(), user1->getY(), user2->getX(), user2->getY());
            break;
        }

        playUser(user2);

        if (!user1->getIsAlive()) {
            cout << "User " << user1->getName() << " is dead" << endl;
            print(user1->getX(), user1->getY(), user2->getX(), user2->getY());
            break;
        }
    }
}
