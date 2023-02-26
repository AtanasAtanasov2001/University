#include <iostream>
#include <vector>
#include <array>
#include <iterator>
#include <numeric>
#include <algorithm>

// You have three stacks of cylinders where each cylinder has the same diameter, 
// but they may vary in height. You can change the height of a stack by removing and discarding its topmost cylinder any number of times.

// Find the maximum possible height of the stacks such that all of the stacks are exactly the same height. This means you must remove zero or 
// more cylinders from the top of zero or more of the three stacks until they are all the same height, then return the height.
const int NUMBER_OF_STACKS = 3;
int main() {
    std::array<int, NUMBER_OF_STACKS> numberOfElementsForEachStack{};
    for (auto& i: numberOfElementsForEachStack)
    {
        std::cin >> i;
    }

    std::array<std::vector<int>, NUMBER_OF_STACKS> stacks;
    std::array<int, NUMBER_OF_STACKS> heights{};

    const int numberOfElementsSize = numberOfElementsForEachStack.size();
    for (auto i = 0; i < numberOfElementsSize; i++)
    {
        auto &s = stacks[i];
        s.resize(numberOfElementsForEachStack[i]);
        std::copy_n(std::istream_iterator<int>(std::cin), numberOfElementsForEachStack[i], std::begin(s));
        std::reverse(std::begin(s), std::end(s));
        heights[i] = std::accumulate(std::begin(s), std::end(s), 0);
    }

    while(!std::equal(std::next(std::begin(heights)), std::end(heights), std::begin(heights))) {
        auto maxHeightIterator = std::max_element(std::begin(heights), std::end(heights));
        auto maxHeightDistance = std::distance(std::begin(heights), maxHeightIterator);
        heights[maxHeightDistance] -= stacks[maxHeightDistance].back();
        stacks[maxHeightDistance].pop_back();
    }    
    std::cout << heights.front();

    return 0;
}