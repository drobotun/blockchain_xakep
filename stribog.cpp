#include "stribog.h"

std::string get_hash_stribog(std::string str)
{
    TGOSTHashContext *CTX;
    CTX = (TGOSTHashContext*)(malloc(sizeof(TGOSTHashContext)));
    const char *c = str.c_str();
    uint8_t *in_buffer;
    in_buffer = (uint8_t *)malloc(str.size());
    memcpy(in_buffer, c, str.size());

    GOSTHashInit(CTX, HASH_SIZE);
    GOSTHashUpdate(CTX, in_buffer, str.size());
    GOSTHashFinal(CTX);

    char out_buffer[2 * (HASH_SIZE / 8)];

    for (int i = 0; i < HASH_SIZE / 8; i++)
        sprintf(out_buffer + i * 2, "%02x", CTX->hash[i]);

    free(CTX);
    free(in_buffer);

    return std::string((const char *)out_buffer);

}
