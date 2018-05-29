#ifndef BLOCK_H
#define BLOCK_H

#include <ctime>
#include <vector>

#include "stribog.h"

struct STransaction {
    std::string sender;
    std::string recipient;
    uintmax_t amount;
};

class CBlock {
public:
    CBlock();
    CBlock(uint32_t index_in,
           const std::string &in_name_block,
           const std::string &in_sender,
           const std::string &in_recipient,
           uintmax_t in_amount);
    ~CBlock();

    std::string get_index();
    std::string get_time_stamp();
    std::string get_sender();
    std::string get_recipient();
    std::string get_amount();
    std::string get_proof();
    std::string get_previous_hash();
    std::string get_hash();

    void set_previous_hash(std::string in_previous_hash);
    void create_genesis_block();
    void mine_block(uint32_t diff);

private:
    uintmax_t index;
    std::string name_block;
    time_t time_stamp;
    STransaction transaction;
    uintmax_t proof;
    std::string previous_hash;
    std::string hash;

    std::string calc_hash() const;
};

#endif // BLOCK_H
