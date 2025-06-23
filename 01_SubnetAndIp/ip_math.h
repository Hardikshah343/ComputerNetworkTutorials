#ifndef __IP_MATH_H__
#define __IP_MATH_H__

#define PREFIX_LEN          (17u)

/* 
@name: get_broadcast_address
@input_params: 
ip_addr: IP Address of which broadcast address is to be derived
mask: mask value
@output_params:
output_buffer: Broadcast IP address
@return: void
*/
void get_broadcast_address(char *ip_addr, char mask, char* output_buffer);

/* 
@name: get_network_id
@input_params: 
ip_addr: IP Address of which network address is to be derived
mask: mask value
@output_params:
output_buffer: Network IP address
@return: void
*/
void get_network_id(char *ip_addr, char mask, char *output_buffer);

/* 
@name: check_ip_subnet_membership
@input_params: 
network_id: Network ip address
mask: mask value
check_ip: Ip address of which membership is to be checked
@output_params: NA
@return: 
0: check ip is member
-1: check ip is not member
*/
int check_ip_subnet_membership(char *network_id, char mask, char *check_ip);

/* 
@name: get_ip_integeral_equivalent
@input_params: 
ip_addr: IP Address of which ip integral needs to be calculated
@output_params: NA
@return: ip_integral_equivalent value in unsigned int
*/
unsigned int get_ip_integeral_equivalent(char *ip_address);

/* 
@name: get_abcd_ip_format
@input_params: 
ip_addr: ip address which needs to be formatted
@output_params: 
output_buffer: output needs to be stored 
@return: NA
*/
void get_abcd_ip_format(unsigned int ip_address, char *output_buffer);

/* 
@name: get_subnet_cardinality
@input_params: 
mask: subnet mask for which number of devices can be configured
@output_params: NA
@return: cardinality value in unsigned int
*/
unsigned int get_subnet_cardinality(unsigned char mask);



#endif /* __IP_MATH_H__ */
