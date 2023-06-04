#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "include/fifo.hpp"
#include "include/otm.hpp"
#include "include/lru.hpp"

int main()
{
    Fifo fifo;
    Lru lru;
    Otm otm;

    fifo.readInputFile("input.txt");
    fifo.execute();
    fifo.displayResults();

    lru.readInputFile("input.txt");
    lru.execute();
    lru.displayResults();
    
    otm.readInputFile("input.txt");
    otm.execute();
    otm.displayResults();

    return 0;
}