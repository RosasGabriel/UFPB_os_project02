#ifndef OTM_H
#define OTM_H

#include <string>
#include <vector>

class Otm
{
public:
    Otm();
    
    void readInputFile(const std::string& file_name);
    void execute();
    void displayResults();
    
private:
    std::vector<int> page_requests;

    int num_frames;
    int page_faults;
};

#endif // OTM_H