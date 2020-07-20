#include "include/utils.hpp"

void Utils::findelf(uint8_t* buffer, uint64_t* textstart, uint64_t* textend)
{
    Elf64_Ehdr  *elf;
    Elf64_Shdr  *shdr;
    char *strtab;
    int counter = 1;

    elf = (Elf64_Ehdr *)(buffer);
    shdr = (Elf64_Shdr *)((char *)buffer + elf->e_shoff);
    strtab = (char *)((char *)buffer + shdr[elf->e_shstrndx].sh_offset);
    while(counter < elf->e_shnum) {
        if(strcmp(&strtab[shdr[counter].sh_name], ".text"))
        {
            *textend = shdr[counter].sh_offset;
            return;
        }
        else
            *textstart = shdr[counter].sh_offset;
        counter++;
    }
}

void Utils::getbinaryrepresentation(uint8_t* bytes, size_t numbytes, uint8_t* buf)
{
    int counter = 0;
    for(int i = numbytes - 1; i >= 0; i--)
        for(int j = 7; j >= 0; j--)
            buf[counter++] = tobit(bytes[i], j) + '0';
}

uint8_t Utils::tobit(uint8_t byte, uint8_t pos)
{
    return byte & 1<< pos ? 1 : 0;
}
