#include "Enemy.h"
#include <cstdlib>

Enemy::Enemy(int pocx, int pocy) : Character(pocx, pocy, 'E') {}

void Enemy::moving(int sirina, int visina, const std::vector<std::vector<char>>& mapa_pozadina) {


    int ex, ey;
    int novi_x, novi_y;
    int pokusaja = 0;
    const int max_pokusaja = 20;

    do {
        ex = (rand() % 3) - 1;
        ey = (rand() % 3) - 1;

        if ((ex == 0 && ey == 0) || (ex != 0 && ey != 0)) {
            continue;
        }

        novi_x = x + ex;
        novi_y = y + ey;

        pokusaja++;

        if (novi_x >= 0 && novi_x < sirina &&
            novi_y >= 0 && novi_y < visina &&
            mapa_pozadina[novi_y][novi_x] != '#') {
            break;
        }

    } while (pokusaja < max_pokusaja);

    if (pokusaja < max_pokusaja) {
        x = novi_x;
        y = novi_y;
    }
}


