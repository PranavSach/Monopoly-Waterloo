#ifndef __DISPLAY_H__
#define __DISPLAY_H__
#include <vector>
#include <string>

class Board;
class Display {
    Board* b;

public:
    Display(Board* b);
    void render();

};

#endif
