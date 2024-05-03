#include "PmergeMe.hpp"
#include <iostream>
#include <algorithm>

std::vector<int> PmergeMe::MergePairRecursive(std::vector<int> idx)
{
    if (idx.size() == 1)
        return idx;
    std::vector<std::pair<int, int>> pairs;
    std::vector<int> newIdx;
    for (int i = 0; i < idx.size() / 2; i = i + 2)
    {
        if (pairs[i].second < pairs[i + 1].first)
            pairs.push_back(std::make_pair(pairs[i].first, pairs[i + 1].second));
        else
            pairs.push_back(std::make_pair(pairs[i].first, pairs[i].second));
        newIdx.push_back(i);
    }
}

void PmergeMe::Merge(std::vector<int>& input)
{
    // sort here
    std::cout << "Merge Insertion Sort started!" << std::endl;
    std::sort(input.begin(), input.end());
    std::cout << "Merge Insertion Sort finished!" << std::endl;

    std::vector<std::pair<int, int>> pairs;

    for (int i = 0; i < input.size() / 2; i = i + 2)
        pairs.push_back(std::make_pair(input[i], input[i + 1]));
    MergePairRecursive(pairs);
}