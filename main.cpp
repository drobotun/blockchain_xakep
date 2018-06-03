#include "blockchain.h"

void get_time_start(){
    time_t time_start = time(nullptr);
    std::cout << "Start of mining: " << ctime(&time_start);
}

void get_time_end(){
    time_t time_end = time(nullptr);
    std::cout << "End of mining: " << ctime(&time_end);
}

int main() {
    CBlockchain blockchain = CBlockchain(7);

    get_time_start();
    std::cout << "====================================================================================" << std::endl;
    blockchain.add_genesis_block(CBlock());

    blockchain.add_block(CBlock(1, "Block", "Lozovsky", "Drobotun", 342500));

    blockchain.add_block(CBlock(2, "Block", "Petrov", "Ivanov", 15418));

    blockchain.add_block(CBlock(3, "Block", "Sidorov", "Kozlov", 12));

    get_time_end();

    return 0;
}
