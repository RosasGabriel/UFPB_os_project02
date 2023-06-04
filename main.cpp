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
    Otm otm;
    Lru lru;

    fifo.readInputFile("input.txt");
    fifo.execute();
    fifo.displayResults();

    otm.readInputFile("input.txt");
    otm.execute();
    otm.displayResults();
    
    lru.readInputFile("input.txt");
    lru.execute();
    lru.displayResults();

    return 0;
}