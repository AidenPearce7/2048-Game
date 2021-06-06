#include "GameGrid.h"
#include <iostream>

void Move(GameGrid *game, bool *exit);

int main(int argc, char *argv[]) {
    bool Quit = false;
    GameGrid game{};
    std::cout << "Game Started" << std::endl;
    std::cout << "Use wasd to move (q to quit)" << std::endl;
    game.GetValues();
    do {
        Move(&game, &Quit);
        if (Quit)
            break;

        game.GetValues();
        if (game.GetHasWon())
            break;

    } while (game.GetMoves());

    if (Quit)
        std::cout << "Quitting";
    else if (game.GetHasWon())
        std::cout << "You have won the game.";
    else
        std::cout << "You have lost the game.";

    return 0;
}
void Move(GameGrid *Game, bool *QuitTheGame) {
    char key;
    std::cin >> key;
    switch (key) {
    case 'w':
    case 'W':
        if (!Game->Move(Game->Up)) {
            std::cout << "Movement up is not possible" << std::endl;
        }
        break;
    case 'a':
    case 'A':
        if (!Game->Move(Game->Left)) {
            std::cout << "Movement left is not possible" << std::endl;
        }
        break;
    case 's':
    case 'S':
        if (!Game->Move(Game->Down)) {
            std::cout << "Movement down is not possible" << std::endl;
        }
        break;
    case 'd':
    case 'D':
        if (!Game->Move(Game->Right)) {
            std::cout << "Movement right is not possible" << std::endl;
        }
        break;
    case 'q':
    case 'Q':
        *QuitTheGame = true;
        break;
    default:
        std::cout << "Use wasd to move (q to quit)" << std::endl;
    }
}