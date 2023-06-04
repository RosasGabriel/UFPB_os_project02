#include <iostream>
#include <fstream>

#include "../include/otm.hpp"

Otm::Otm()
{
    num_frames  = 0;
    page_faults = 0;
}

void Otm::readInputFile(const std::string& file_name)
{
    std::ifstream input_file(file_name);
    if (input_file.is_open())
    {
        // Read the number of frames
        input_file >> num_frames;
        
        // Read the page requests
        int page_request;
        while (input_file >> page_request)
        {
            page_requests.push_back(page_request);
        }
        
        input_file.close();
    }
    else
    {
        std::cout << "Unable to open input file: " << file_name << std::endl;
    }
}

void Otm::execute()
{

}

void Otm::displayResults()
{

}