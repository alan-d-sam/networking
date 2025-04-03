#include<stdio.h>
#include<string.h>
int main()
{
  int i;
  int no_of_queries,storage,input_pkt_size;
  int output_pkt_size,bucket_size,size_left;
  storage=0;
  no_of_queries=4;
  bucket_size=10;
  input_pkt_size=4;
  output_pkt_size=1;
  for(i=0;i<no_of_queries;i++)
  {
    size_left=buffer_size-storage;
    if(input_pkt_size<=size_left)
    {
      storage+=input_pkt_size;
      printf("buffer size=%d out of bucket size=%d",storage,bucket_size);
    }
    else
    {
      printf("packet loss=%d",input_pkt_size-size_left);
      storage=buffer_size;
      printf("buffer size=%d out of bucket size=%d",storage,bucket_size")
    }
    storage-=output_pkt_size;
  }
  return0;
}
