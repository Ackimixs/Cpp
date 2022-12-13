#include "game.h"

int main() {

    User* user1 = new User("user1");
    User* user2 = new User("user2");

    Weapon* weapon1;
    Weapon** weaponList = weapon1->initWeapon();

    user1->setWeapon(weaponList[0]);
    user2->setWeapon(weaponList[1]);

    Game game;
    game.init();

    game.setUsers(user1, user2);

    game.start();


    return 0;
}