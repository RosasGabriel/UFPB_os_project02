#include <iostream>
#include <fstream>

#include "../include/fifo.hpp"

Fifo::Fifo()
{
    num_frames  = 0;
    page_faults = 0;
}

void Fifo::readInputFile(const std::string& file_name)
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

void Fifo::execute()
{
    std::vector<int> frame_buffer(num_frames, -1);  // Initialize frame buffer with -1
    
    int next_frame_index = 0;   // Index of the next frame to be replaced
    
    for (int page_request : page_requests)  // Iterate through page requests
    {
        bool page_found = false;    // Flag to indicate if page is already in frame buffer
        
        // Check if page is already in frame buffer
        for (int frame : frame_buffer)
        {
            if (frame == page_request)
            {
                page_found = true;
                break;
            }
        }
        
        if (!page_found)    // Page fault
        {
            frame_buffer[next_frame_index] = page_request;
            next_frame_index = (next_frame_index + 1) % num_frames;  // Circularly increment the next frame index
            page_faults++;
        }
    }
    
    // Test output
    // std::cout << "Page Faults: " << page_faults << std::endl;
}

void Fifo::displayResults()
{
    // Display any additional results or statistics specific to the FIFO algorithm
    std::cout << "FIFO " << page_faults << std::endl;
}