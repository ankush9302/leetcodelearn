#include <iostream>
#include <list>

int main()
{
    std::list<int> mylist;

    // Add elements
    mylist.push_back(10);
    mylist.push_front(5);
    mylist.push_back(15);

    // Insert an element
    auto it = mylist.begin();
    ++it;                 // Move iterator to second position
    mylist.insert(it, 7); // Insert 7 between 5 and 10

    // Display list elements
    for (int val : mylist)
    {
        std::cout << val << " "; // Output: 5 7 10 15
    }
    std::cout << std::endl;

    // Remove an element
    mylist.pop_front(); // Removes 5

    // Display list elements again
    for (int val : mylist)
    {
        std::cout << val << " "; // Output: 7 10 15
    }

    return 0;
}
