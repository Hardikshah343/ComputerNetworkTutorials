#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ip_math.h"

void demo_function(void);

int main() {
    demo_function();
}


void demo_function(void)
{
    char ipadd_buffer[PREFIX_LEN] = {'\0'};
    memset(ipadd_buffer, 0, PREFIX_LEN);
    char *ip_add = "192.168.2.10";
    char mask = 20;
    get_broadcast_address(ip_add, mask, ipadd_buffer);
    printf("Broadcast address = %s\n", ipadd_buffer);

    get_network_id(ip_add, mask, ipadd_buffer);
    printf("Network address = %s\n", ipadd_buffer);

    printf("Subnet mask %d has cardinality %u\n", mask,  get_subnet_cardinality((unsigned char)mask));

    int checkNetwork = check_ip_subnet_membership(ipadd_buffer, mask, ip_add);
    if (checkNetwork == 0) {
        printf("Same subnet!\n");
    } else {
        printf("Different subnet!\n");
    }

    char *diff_ip = "192.167.2.10";
    checkNetwork = check_ip_subnet_membership(diff_ip, mask, ip_add);
    if (checkNetwork == 0) {
        printf("Same subnet!\n");
    } else {
        printf("Different subnet!\n");
    }
    return;
}