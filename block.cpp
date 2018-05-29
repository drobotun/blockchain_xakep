#include "block.h"

CBlock::CBlock() : index(0),
                   name_block("Genesis block"),
                   transaction {"None", "None", 0},
                   proof(0)
{
    time_stamp = time(nullptr);
}

CBlock::CBlock(uint32_t index_in,
             const std::string &in_name_block,
             const std::string &in_sender,
             const std::string &in_recipient,
             uintmax_t in_amount) :
             index(index_in),
             name_block(in_name_block),
             transaction {in_sender, in_recipient, in_amount},
             proof(0)
{
    time_stamp = time(nullptr);
}

CBlock::~CBlock() {

}

std::string CBlock::get_hash() {
    return hash;
}

std::string CBlock::get_index(){
    std::stringstream ss;
    ss << index;
    return ss.str();
}

std::string CBlock::get_sender(){
    return transaction.sender;
}

std::string CBlock::get_recipient(){
    return transaction.recipient;
}

std::string CBlock::get_amount(){
    std::stringstream ss;
    ss << transaction.amount;
    return ss.str();
}

std::string CBlock::get_proof(){
    std::stringstream ss;
    ss << proof;
    return ss.str();
}

std::string CBlock::get_time_stamp(){
    std::stringstream ss;
    ss << ctime(&time_stamp);
    return ss.str();
}

std::string CBlock::get_previous_hash(){
    return previous_hash;
}

void CBlock::set_previous_hash(std::string in_previous_hash){
    previous_hash = in_previous_hash;
}


void CBlock::create_genesis_block(){
    srand(time(nullptr));
    std::stringstream ss;
    ss << rand();
    previous_hash = get_hash_stribog(ss.str());
    hash = calc_hash();
}

void CBlock::mine_block(uint32_t diff) {
    char zero_ch[diff];
    std::cout << "Mining block: " << get_index() << std::endl;
    memset(zero_ch, '0', diff);
    zero_ch[diff] = '\0';
    std::string zero_str(zero_ch);
    do {
        hash = calc_hash();
        proof++;
    } while (hash.substr(0, diff) != zero_str);
}

std::string CBlock::calc_hash() const {
    std::stringstream ss;
    ss << index <<
          time_stamp <<
          transaction.sender <<
          transaction.recipient <<
          transaction.amount <<
          proof <<
          previous_hash;
    return get_hash_stribog(ss.str());
}
