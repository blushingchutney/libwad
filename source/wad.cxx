#include <fstream>
#include <filesystem>

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

    void Wad::reload() {
        std::ifstream fp;
        fp.open(path, std::ios::binary);

        fp.read((char*)&wadinfo, sizeof(wadinfo_t));

        filelump.resize(wadinfo.numlumps);

        fp.seekg(wadinfo.infotableofs);
        fp.read((char*)filelump.data(), sizeof(filelump_t) * wadinfo.numlumps);

        fp.close();
    }
    
    void Wad::loadFromFile(const char *path) {
        std::filesystem::copy(path, this->path);
        reload();
    }

    void Wad::loadFromMemory(const void *data, std::streamsize size) {
        std::ofstream fp;
        fp.open(path, std::ios::binary);
        fp.write((char*)data, size);
        fp.close();
        reload();
    }

    const wadinfo_t& Wad::getWadinfo() {
        return wadinfo;
    }

    const filelump_t& Wad::getFilelump(int32_t index) {
        return filelump[index];
    }

    void Wad::getData(void *buffer, int32_t position, int32_t size) {
        std::ifstream fp;
        fp.open(path, std::ios::binary);
        fp.seekg(position);
        fp.read((char*)buffer, size);
        fp.close();
    }

}
