#pragma once

#include <vector>
#include <utility>

class PmergeMe
{
public:
    static void Merge(std::vector<int>& input);

private:
    std::vector<int> MergePairRecursive(std::vector<int> idx);

private:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
};