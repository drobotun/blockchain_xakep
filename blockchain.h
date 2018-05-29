#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include "block.h"

#define PRINT_DATA_MODE

class CBlockchain {
public:
    CBlockchain(uint32_t in_diff);
    ~CBlockchain();

    void add_genesis_block(CBlock new_block);
    void add_block(CBlock new_block);
private:
    uint32_t diff;
    std::vector<CBlock> chain;

    CBlock get_last_block() const;
};

#endif // BLOCKCHAIN_H
