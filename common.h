#ifndef COMMON_H
#define COMMON_H

struct Position {
    int x;
    int y;
};

enum class CellType : unsigned char {Empty, Wall, Floor, Exit};

#endif
