#include "ip_math.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Logic
"192.168.2.10" | 20
Convert to int

32-20 = 12
just make them OR with 12 1's at end

convert to string
*/
void get_broadcast_address(char *ip_addr, char mask, char* output_buffer) {
    unsigned int ip_integer = get_ip_integeral_equivalent(ip_addr);   

    /* Create broadcast mask */
    unsigned int broadcast_mask = ~(0xFFFFFFFFu << (32 - mask));

    /* OR with ip address in int*/
    ip_integer |= broadcast_mask;
    
    /* storing back to output_buffer */
    get_abcd_ip_format(ip_integer, output_buffer);
}

void get_network_id(char *ip_addr, char mask, char* output_buffer) {
    unsigned int ip_integer = get_ip_integeral_equivalent(ip_addr);   

    /* Create broadcast mask */
    unsigned int networkMask = (0xFFFFFFFFu << (32 - mask));

    /* OR with ip address in int*/
    ip_integer &= networkMask;
    
    /* storing back to output_buffer */
    get_abcd_ip_format(ip_integer, output_buffer);
}

int check_ip_subnet_membership(char *network_id, char mask, char *check_ip) {
    unsigned int network_ip_int = get_ip_integeral_equivalent(network_id);
    char buffer[PREFIX_LEN] = {'\0'};
    get_network_id(check_ip, mask, buffer);

    if (get_ip_integeral_equivalent(buffer) == network_ip_int) {
        return 0;
    }
    return -1;
}

unsigned int get_ip_integeral_equivalent(char *ip_address) {
    unsigned int octet1 = 0, octet2 = 0, octet3 = 0, octet4 = 0;
    unsigned int ip_integer = 0;

    /* Convert string to integer */
    sscanf(ip_address, "%u.%u.%u.%u", &octet1, &octet2, &octet3, &octet4);
    ip_integer = (octet1 << 24) | (octet2 << 16) | (octet3 << 8) | octet4;

    return ip_integer;
}

void get_abcd_ip_format(unsigned int ip_address, char *output_buffer) {
    snprintf(output_buffer, PREFIX_LEN, "%u.%u.%u.%u", (ip_address >> 24) & 0xFF, (ip_address >> 16) & 0xFF, (ip_address >> 8) & 0xFF, ip_address & 0xFF);
}

unsigned int get_subnet_cardinality(unsigned char mask) {
    if (mask >= 32) return 0; 
    return pow(2, (32 - mask)) - 2;
}