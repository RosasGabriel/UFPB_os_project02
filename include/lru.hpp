#ifndef LRU_H
#define LRU_H

#include <string>
#include <vector>

class Lru
{
public:
    Lru();
    
    void readInputFile(const std::string& file_name);
    void execute();
    void displayResults();

private:
    std::vector<int> page_requests;

    int num_frames;
};

#endif // LRU_H