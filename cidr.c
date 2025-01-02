#include <stdio.h>
#include <stdlib.h>

// Function to calculate subnet mask from CIDR prefix length
unsigned int calculate_subnet_mask(int prefix_length) {
    return (0xFFFFFFFF << (32 - prefix_length)) & 0xFFFFFFFF;
}

// Function to check if an IP in decimal format belongs to a CIDR range
int ip_belongs_to_cidr(unsigned int ip, unsigned int cidr_base_ip, int prefix_length) {
    unsigned int mask = calculate_subnet_mask(prefix_length);  // Calculate the subnet mask
    
    // Check if the network portion of the IP matches the CIDR base IP
    if ((ip & mask) == (cidr_base_ip & mask)) {
        return 1; // IP belongs to the CIDR range
    }

    return 0; // IP does not belong to the CIDR range
}

// Structure to store each CIDR range and the associated IP addresses
typedef struct {
    unsigned int cidr_base_ip; // Base IP of the CIDR range in decimal format
    int prefix_length;         // Prefix length of the CIDR range
    unsigned int ip_list[10];  // Array to store up to 10 IPs in decimal format
    int ip_count;              // Count of IPs in the list
} CIDRRange;

// Function to check all IPs against a CIDR range
void check_ips_in_cidr(CIDRRange *cidr_range) {
    printf("Checking CIDR Range: %u/%d\n", cidr_range->cidr_base_ip, cidr_range->prefix_length);
    
    for (int i = 0; i < cidr_range->ip_count; i++) {
        if (ip_belongs_to_cidr(cidr_range->ip_list[i], cidr_range->cidr_base_ip, cidr_range->prefix_length)) {
            printf("IP %u belongs to CIDR range %u/%d\n", cidr_range->ip_list[i], cidr_range->cidr_base_ip, cidr_range->prefix_length);
        } else {
            printf("IP %u does NOT belong to CIDR range %u/%d\n", cidr_range->ip_list[i], cidr_range->cidr_base_ip, cidr_range->prefix_length);
        }
    }
}

int main() {
    // Example CIDR ranges and IP addresses in decimal format
    CIDRRange cidr_ranges[2] = {
        {3232235776, 24, {3232235776, 3232235777, 3232235778}, 3}, // CIDR 192.168.1.0/24 with 3 IPs
        {3232236032, 28, {3232236032, 3232236034, 3232236040}, 3}  // CIDR 192.168.1.32/28 with 3 IPs
    };

    // Checking the IPs against their respective CIDR ranges
    for (int i = 0; i < 2; i++) {
        check_ips_in_cidr(&cidr_ranges[i]);
    }

    return 0;
}

