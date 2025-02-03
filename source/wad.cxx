#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "wad.hxx"

namespace wad {
    Wad::Wad() {
        char path[] = "tmpXXXXXX";
        close(mkstemp(path));
        remove(path);
        this->path = path;
        this->path = this->path + ".wad";
    }

    Wad::~Wad() {
        remove(this->path.c_str());
    }

}
