#ifndef MENU_HPP_INCLUDED
#define MENU_HPP_INCLUDED

#include "list.hpp"
#include <conio.h>

class Menu {
    private:
        List playlist;
    public:
        void showMenu();
        void addSong();
        void addSongbyPosition();
        void deleteSong();
        void pressToContinue();
    };

#endif // MENU_HPP_INCLUDED
