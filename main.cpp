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
    fifo.readInputFile("input.txt");
    fifo.execute();
    fifo.displayResults();
    
    return 0;
}