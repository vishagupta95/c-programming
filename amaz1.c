#include <stdio.h>
#include <limits.h>

/*
"Amazon Delivery Centers dispatch parcels every day. There are
 n delivery centers, each with an array parcel[i] representing the number of parcels to be delivered. On each day, an equal number of parcels are dispatched
from each delivery center that has at least one parcel remaining. Find the minimum number of days to deliver all the parcels from all delivery centers.

Example: parcels = [2, 3, 4, 3, 3],
n=5 delivery centers. All parcels will be delivered in 3 days.

Day 1: Deliver 2 parcels from each center.
Day 2: Deliver 1 parcel from the remaining centers.
Day 3: Deliver 1 parcel from the remaining centers
*/
#include <stdio.h>
#include <limits.h>

int min_days_to_deliver(int parcels[], int center_counts) {
    int days = 0;

    // Iterate until all parcels are delivered
    while (1) {
        int parcels_left = 0;

        // Check how many parcels are left to deliver across all centers
        for (int i = 0; i < center_counts; i++) {
            if (parcels[i] > 0) {
                parcels_left = 1;  // There are still parcels to deliver
                break;
            }
        }

        // If no parcels are left, exit the loop
        if (!parcels_left) {
            break;
        }

        // Find the number of parcels to dispatch today (minimum for all centers)
        int min_parcel = INT_MAX;
        for (int i = 0; i < center_counts; i++) {
            if (parcels[i] > 0 && parcels[i] < min_parcel) {
                min_parcel = parcels[i];
            }
        }

        // Deliver parcels for the day
        for (int i = 0; i < center_counts; i++) {
            if (parcels[i] > 0) {
                parcels[i] -= min_parcel;
            }
        }

        // Increment the day count
        days++;
    }

    return days;
}

int main() {
    int parcels[] = {2, 3, 4, 3, 3};  // Example: parcels at each delivery center
    int center_counts = sizeof(parcels) / sizeof(parcels[0]);
    int result = min_days_to_deliver(parcels, center_counts);
    printf("Minimum days to deliver all parcels: %d\n", result);
    return 0;
}

