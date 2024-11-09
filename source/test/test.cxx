#include <wad.hxx>

int main() {
    wad::Wad wad;

    wad.loadFromFile("test.wad");

    printf(
        "doom %-4.4s data containing %d lumps\n\n",
        wad.getWadinfo()->identification,
        wad.getWadinfo()->numlumps
    );

    printf(
        "%-8.8s %-8.8s %-8.8s %-8.8s\n",
        "INDEX",
        "POSITION",
        "SIZE",
        "NAME"
    );
    for(int32_t i = 0;i < wad.getWadinfo()->numlumps;i++) {
        printf(
            "%-8d %-8d %-8d %-8.8s\n",
            i,
            wad.getFilelump()[i].filepos,
            wad.getFilelump()[i].size,
            wad.getFilelump()[i].name
        );
    }
    printf("\n");

    std::vector<uint8_t> __EUREKA = wad.getData(wad.find("__EUREKA"));
    __EUREKA.push_back('\0');

    printf("\n== __EUREKA START ==\n");
    printf("%s", __EUREKA.data());
    printf("\n== __EUREKA END ==\n");

    printf("\n\nThe program was executed correctly\n");
    return 0;
}