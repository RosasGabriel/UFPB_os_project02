#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>

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
    std::vector<int> page_table(num_frames, -1);    // Initialize page table with -1

    for (const auto& page_request : page_requests)  // Iterate through page requests
    {
        auto iterator = std::find(page_table.begin(), page_table.end(), page_request);  // Check if page is already in page table
        if (iterator == page_table.end())
        {
            int page_to_replace = -1;
            int max_distance    = -1;

            for (int i = 0; i < page_table.size(); ++i) // Iterate through page table
            {
                int future_distance = 0;

                bool found_reference = false;

                for (int j = 0; j < page_requests.size(); j++)
                {
                    if (page_requests[j] == page_table[i])  // Check if page is referenced again
                    {
                        found_reference = true;
                        future_distance = j;
                        break;
                    }
                }

                if (!found_reference)   // Page is not referenced again
                {
                    page_to_replace = i;
                    break;
                }

                if (future_distance > max_distance) // Page is referenced again, but not as far in the future
                {
                    max_distance    = future_distance;
                    page_to_replace = i;
                }
            }

            page_table[page_to_replace] = page_request;
            page_faults++;
        }
    }

    // Test output
    // std::cout << "Page Faults: " << page_faults << std::endl;
}

void Otm::displayResults()
{
    std::cout << "OTM: " << page_faults << std::endl;
}