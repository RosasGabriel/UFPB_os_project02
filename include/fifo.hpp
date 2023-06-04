#ifndef FIFO_H
#define FIFO_H

#include <string>
#include <vector>

class Fifo
{
public:
    Fifo();
    
    void readInputFile(const std::string& file_name);
    void execute();
    void displayResults();
    
private:
    std::vector<int> page_requests;

    int num_frames;
    int page_faults;
};


#endif // FIFO_H