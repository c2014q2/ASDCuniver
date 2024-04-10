using namespace std;
#include <span>
#include <array>
#include <iostream>

struct SearchResult
{
    bool isElementFound;
    size_t foundIndex;
};

SearchResult linearSearch(std::span<int> arr, int element)
{
    for (size_t i = 0; i<arr.size();i++ )
    {
        if (element == arr[i])
        {
            return{true, i};
        }
    }
    return {false, 0};
}





int main ()
{
    
    std::array<int, 5> arr = {1,2,3,4,5};
    SearchResult result = linearSearch(arr,5);
    if (result.isElementFound == true)
    {
        std::cout << "Element was found at -> " << result.foundIndex; 
    }
    else std::cout << "Element has not been found ";

    return 0;
}



