#include <fstream>

#include "wad.hxx"

namespace wad
{
    Wad::Wad() {
    }

    Wad::~Wad() {
    }

    void Wad::loadFromFile(const char *path) {
        std::ifstream fp(this->path = path, std::ios::binary);

        fp.read((char*)&wadinfo, sizeof(wadinfo_t));

        filelump.resize(wadinfo.numlumps);
        fp.seekg(wadinfo.infotableofs);
        fp.read((char*)filelump.data(), sizeof(filelump_t) * wadinfo.numlumps);

        fp.close();
    }

    const wadinfo_t* Wad::getWadinfo() {
        return &wadinfo;
    }

    const filelump_t* Wad::getFilelump() {
        return filelump.data();
    }

} // namespace wad
