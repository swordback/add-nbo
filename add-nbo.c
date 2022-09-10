#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>
#include <string.h>

uint32_t read_bin(char* bin_file) {
    uint32_t num;
    FILE* fstream;
    char num_data[5] = {0};

    fstream = fopen(bin_file, "r");
    if (fstream) {
        fread(num_data, sizeof(char), 4, fstream);
    }
    memcpy(&num, num_data, 4);
    return num;
}

void main(int argc, char* argv[]) {
    uint32_t num1_nbo = 0;
    uint32_t num2_nbo = 0;
    
    uint32_t num1_hbo = 0;
    uint32_t num2_hbo = 0;

    uint32_t res = 0;

    if (argc != 3) {
        printf("error in parameter input, please check input");
        return -1;
    }

    num1_nbo = read_bin(argv[1]);
    num2_nbo = read_bin(argv[2]);

    num1_hbo = ntohl(num1_nbo);
    num2_hbo = ntohl(num2_nbo);

    res = num1_hbo + num2_hbo;
    
    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", num1_hbo, num1_hbo, num2_hbo, num2_hbo, res, res);
    return;
}