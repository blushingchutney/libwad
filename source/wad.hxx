#pragma once

#include <vector>
#include <string>

#include <stdint.h>

namespace wad {
    struct wadinfo_t {
        uint8_t identification[4];
        int32_t numlumps;
        int32_t infotableofs;
    };

    struct filelump_t {
        int32_t filepos;
        int32_t size;
        uint8_t name[8];
    };

    class Wad {
        private:
            wadinfo_t wadinfo;
            std::vector<filelump_t> filelump;
            std::string path;
        
            void reload();
        public:
            Wad();
            ~Wad();

            void loadFromFile(const char *path);
            void loadFromMemory(const void *data, std::streamsize size);

            const wadinfo_t& getWadinfo();
            const filelump_t& getFilelump(int32_t index);
    };
}
