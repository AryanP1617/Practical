#include <stdio.h>

int custom_log(int a)
{
    int i=-1;
    while(a>0)
    {
        a=a/2;
        i++;
    }

    return i;
}

void direct_mapping(int mm_blocks,int cache_block,int block_size,int mm_address_bits)
{
    int offset_bits=custom_log(block_size);
    int cache_bits=custom_log(cache_block);
    int tag_bits=mm_address_bits-cache_bits-offset_bits;
    int block_num;
    printf("Tag bits:%d || Cache bits:%d || Offset bits: %d\n",tag_bits,cache_bits,offset_bits);
    printf("Enter the block number(0 to %d): ",mm_blocks-1);
    scanf("%d",&block_num);
    
    if(block_num<mm_blocks)
    {
        printf("Block: %d maps to cache line: %d\n",block_num,(block_num%cache_block));
    }
}

void associative_mapping(int mm_blocks,int cache_block,int block_size,int mm_address_bits)
{
    int offset_bits=custom_log(block_size);
    int tag_bits=mm_address_bits-offset_bits;
    int block_num;
    printf("Tag bits:%d || Offset bits: %d\n",tag_bits,offset_bits);
    printf("Enter the block number(0 to %d): ",mm_blocks-1);
    scanf("%d",&block_num);
    printf("Block:%d maps to any cache line from %d to %d\n",block_num,cache_block);
}

void set_associative_mapping(int mm_blocks,int cache_block,int block_size,int mm_address_bits,int k)
{
    int offset_bits=custom_log(block_size);
    int set=cache_block/k;
    int set_bits=custom_log(set);
    int tag_bits=mm_address_bits-set_bits-offset_bits;
    int block_num;
    printf("Tag bits:%d || Set bits:%d ||Offset bits:%d\n");
    printf("Enter the block number(0 to %d): ",mm_blocks-1);
    scanf("%d",&block_num);
    int set_num=block_num%set;
    printf("Block:%d maps to set%d(cache lines from %d to %d)\n",block_num,set_num,set_num*k,(set_num*k)+k-1);
}
int main()
{
    int mm_size;
    int cache_size;
    int block_size;
    int k,choice;

    printf("Enter main memory size(in MB): ");
    scanf("%d",&mm_size);
    printf("Enter cache_size(in KB): ");
    scanf("%d",&cache_size);
    printf("Enter block_size(in Bytes): ");
    scanf("%d",&block_size);
    printf("Enter value of k: ");
    scanf("%d",&k);

    int mm_size_bytes=mm_size*1024*1024;
    int cache_size_bytes=cache_size*1024;
    
    int mm_blocks=mm_size_bytes/block_size;
    int cache_block=cache_size_bytes/block_size;

    int physical_address_bits=custom_log(mm_size_bytes);

    direct_mapping(mm_blocks,cache_block,block_size,physical_address_bits);
    associative_mapping(mm_blocks,cache_block,block_size,physical_address_bits);
    set_associative_mapping(mm_blocks,cache_block,block_size,physical_address_bits,k);
    return 0;
}