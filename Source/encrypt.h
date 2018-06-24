//HEADER_GOES_HERE
#ifndef __ENCRYPT_H__
#define __ENCRYPT_H__

extern int encrypt_table[1280];
//int encrypt_52B564[257];

void encrypt_decrypt_block(void *block, int size, int key);
void encrypt_encrypt_block(void *block, int size, int key);
int encrypt_hash(char *s, int type);
void encrypt_init_lookup_table();
int encrypt_compress(void *buf, int size);
unsigned int encrypt_pkware_read(char *buf, unsigned int *size, void *param);
void encrypt_pkware_write(char *buf, unsigned int *size, void *param);
void encrypt_decompress(void *param, int recv_size, int dwMaxBytes);

#endif /* __ENCRYPT_H__ */
