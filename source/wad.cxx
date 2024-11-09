#include <fstream>

#include <string.h>

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

    int32_t Wad::find(const char *_name, int32_t start, int32_t end) {
        if(start < 0) start = 0;
        if(end < 0) end = wadinfo.numlumps;

        std::string name = _name;
        name.resize(8);

        for(int i = 0;i < 8;i++) {
            name[i] = toupper(name[i]);
        }

        for(int32_t i = start;(i < end) && (i < wadinfo.numlumps);i++) {
            if(!memcmp(name.c_str(), filelump[i].name, 8)) {
                return i;
            }
        }

        return -1;
    }


} // namespace wad
