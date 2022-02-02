#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if(argc <= 2 || (strcmp(argv[1], "pal") != 0 && strcmp(argv[1], "ntsc") != 0)) {
        printf("NES Music File NTSC/PAL System Changer\nUsage: nsf-setsystem ntsc/pal filename.nsf\n");
    } else {
        unsigned char systembyte = strcmp(argv[1], "ntsc") == 0 ? 0 : 1;
        for(int i = 2; i < argc; i++){
            FILE *f = fopen(argv[i], "rb+");
            if(f) {
                fseek(f, 0x7A, 0);
                fwrite(&systembyte, 1, 1, f);
                printf("%s set to %s\n", argv[i], argv[1]);
                fclose(f);
            } else {
                printf("File could not open %s\n", argv[i]);
            }
        }
    }
    return 0;
}
