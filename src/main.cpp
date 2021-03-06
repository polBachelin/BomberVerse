/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** main
*/

#include <memory>
#include "GlobalManager.hpp"
#include "SettingConf.hpp"

#define WIN_HEIGHT 1080
#define WIN_WIDTH 1920

int main()
{
    try {
        game::managers::GlobalManager manager;
        manager.run();
    } catch (IndieError &e) {
        std::cerr << "Indie Error : " << e.what() << std::endl << e.getComponent() << std::endl;
        return 84;
    }
    return 0;
}
