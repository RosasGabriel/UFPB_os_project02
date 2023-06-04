#include <iostream>
#include <fstream>
#include <algorithm>
#include <deque>

#include "../include/lru.hpp"

Lru::Lru()
{
    num_frames  = 0;
    page_faults = 0;
}

void Lru::readInputFile(const std::string& file_name)
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

void Lru::execute()
{
    std::deque<int> frame_queue;    // Frame queue

    for (int page_request : page_requests)
    {
        auto iterator = std::find(frame_queue.begin(), frame_queue.end(), page_request);    // Find page in frame queue
        if (iterator != frame_queue.end())
        {
            frame_queue.erase(iterator);    // Remove page from frame queue
        }
        else
        {
            if (frame_queue.size() == num_frames)   // If frame queue is full, remove the last page
            {
                frame_queue.pop_back();
                page_faults++;
            }
        }

        frame_queue.push_front(page_request);   // Add page to the front of the frame queue
    }

    // Test output
    // std::cout << "Page faults: " << page_faults << std::endl;
}

void Lru::displayResults()
{
    std::cout << "LRU " << page_faults << std::endl;
}