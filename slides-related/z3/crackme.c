#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int check(unsigned char *p) {
    if (strlen((char*)p) != 6) return 0;

    if ((p[0] + p[1]) != 0xb8) return 0;
    if ((p[2] ^ p[3]) != 0x36) return 0;
    if ((p[1] - p[2]) != 0x22) return 0;
    if ((p[4] * 2)    != (p[5] + 0x7f)) return 0;
    if ((p[3] + p[5]) != 0xda) return 0;

    for (int i = 0; i < 6; i++)
        if (p[i] < 0x21 || p[i] > 0x7e) return 0;

    return 1;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <password>\n", argv[0]);
        return 1;
    }
    if (check((unsigned char*)argv[1])) {
        printf("[+] Correct! Flag: CTF{%s}\n", argv[1]);
    } else {
        printf("[-] Wrong password.\n");
    }
    return 0;
}
