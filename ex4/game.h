#ifndef CLASS_GAME_H
#define CLASS_GAME_H

#include "user.h"

class Game {
private:
    int grille[20][20];
    User* user1;
    User* user2;
public:
    void setUsers(User* user1, User* user2);
    void setUser1(User* user1);
    void setUser2(User* user2);
    User* getUser1() const;
    User* getUser2() const;


    void playUser(User* user);
    void init();
    void start();
    void print(int x1 = -1, int y1 = -1, int x2 = -1, int y2 = -1);
};


#endif //CLASS_GAME_H
