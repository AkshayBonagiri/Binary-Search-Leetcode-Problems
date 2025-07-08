#include <iostream>
using namespace std;

int main() {
    int piles[] = {30, 11, 23, 4, 20};
    int h = 5;

    int start = 1;
    int end = INT_MIN;

    // Find the max pile size (upper limit for speed)
    for (int i : piles) {
        if (i > end) end = i;
    }

    // Binary search to find minimum eating speed
    while (start < end) {
        int mid = start + (end - start) / 2;
        int hours = 0;

        // Calculate total hours needed at speed = mid
        for (int i : piles) {
            hours += (i + mid - 1) / mid; // ceil(i / mid)
        }

        // If too slow, increase speed
        if (hours > h) start = mid + 1;
        // Else, try slower speed
        else end = mid;
    }

    // Minimum valid speed
    std::cout << start;
}
