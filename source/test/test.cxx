#include <iostream>
#include <wad.hxx>

int main() {
    wad::Wad wad;

    wad.loadFromFile("test.wad");

    wad::wadinfo_t wadinfo = wad.getWadinfo();

    printf(
        "DOOM %-4.4s data containing %d lumps\n\n",
        wadinfo.identification,
        wadinfo.numlumps
    );

    printf(
        "%-8.8s %-8.8s %-8.8s %-8.8s\n",
        "#",
        "FILEPOS",
        "SIZE",
        "NAME"
    );
    for(int32_t i = 0;i < wadinfo.numlumps;i++) {
        wad::filelump_t filelump = wad.getFilelump(i);
        printf(
            "%-8d %-8d %-8d %-8.8s\n",
            i,
            filelump.filepos,
            filelump.size,
            filelump.name
        );
    }
    printf("\n");

    wad::filelump_t __EUREKA_filelump = wad.getFilelump(wad.find("__EUREKA"));
    std::vector<uint8_t> __EUREKA;
    __EUREKA.resize(__EUREKA_filelump.size + 1);
    __EUREKA[__EUREKA_filelump.size + 1] = '\0';
    wad.getData(__EUREKA.data(), __EUREKA_filelump.filepos, __EUREKA_filelump.size);

    printf("\n== __EUREKA PRINT START ==\n");
    printf("%s", __EUREKA.data());
    printf("\n== __EUREKA PRINT END ==\n");

    printf("\nTEST SUCCESS\n\n");
    return EXIT_SUCCESS;
}
