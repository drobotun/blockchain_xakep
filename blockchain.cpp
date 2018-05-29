#include "blockchain.h"

CBlockchain::CBlockchain(uint32_t in_diff) : diff(in_diff){
    chain.clear();

#ifdef PRINT_DATA_MODE
    std::cout << "Difficulty: " << diff << std::endl;
#endif
}

void CBlockchain::add_genesis_block(CBlock new_block){
    new_block.create_genesis_block();
    chain.emplace_back(new_block);

#ifdef PRINT_DATA_MODE
    std::cout << "Create genesis block" << std::endl;
    std::cout << "Timestamp: " << new_block.get_time_stamp();
    std::cout << "Random hash: " << new_block.get_previous_hash() << std::endl;
    std::cout << "Hash genesis block: " << new_block.get_hash() << std::endl;
    std::cout << "====================================================================================" << std::endl;
#endif
}

CBlockchain::~CBlockchain() {

}

void CBlockchain::add_block(CBlock new_block) {
    new_block.set_previous_hash(get_last_block().get_hash());
    new_block.mine_block(diff);
    chain.push_back(new_block);

#ifdef PRINT_DATA_MODE
    std::cout << "Index: " << new_block.get_index() << std::endl;
    std::cout << "Timestamp: " << new_block.get_time_stamp();
    std::cout << "Proof: " << new_block.get_proof() << std::endl;
    std::cout << "Previous hash: " << new_block.get_previous_hash() << std::endl;
    std::cout << "Sender: " << new_block.get_sender() << std::endl;
    std::cout << "Recipient: " << new_block.get_recipient() << std::endl;
    std::cout << "Ammount: " << new_block.get_amount() << std::endl;
#endif
    std::cout << "Block hash: " << new_block.get_hash() << std::endl;
    std::cout << "====================================================================================" << std::endl;
}


CBlock CBlockchain::get_last_block() const {
    return chain.back();
}


