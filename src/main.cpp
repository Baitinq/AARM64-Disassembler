#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "include/utils.hpp"
#include "include/disassemble.hpp"

/* AARM64 dissasembler */

int main(int argc, char** argv)
{
    (void)argc;
    int fd;
    uint64_t textstart;
    uint64_t textend;
    struct stat sb;
    uint8_t* buffer;

    fd = open(argv[1], O_RDONLY);
    fstat(fd, &sb);

    buffer = (uint8_t*)mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    textstart = 0;
    textend = sb.st_size;
    Utils::findelf(buffer, &textstart, &textend);

    uint32_t pos = 0;
    while((pos + textstart) < textend)
        pos += Disasm::disassemble(buffer, pos, textstart);

    munmap(buffer, sb.st_size);

    return 0;
}
