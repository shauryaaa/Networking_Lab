#include<stdio.h>
unsigned fields[10];
unsigned short checksum(){
    int i;
    int sum=0;
    printf("Enter IP header in the format : 16 bit words");
    for(i=0;i<9;i++)
    {
        printf("\n Enter for field %d: ",i+1);
        scanf("%x",&fields[i]);

        sum=sum+ (unsigned short)fields[i];
        while(sum>>16)  // right shift sum, if 1, then add it to sum
        sum=(sum & 0xFFFF) + (sum>>16);
       // printf("\n sum at %d is : %x \n",i,sum);
    }
    sum=~sum;
    return (unsigned short)sum;
}
int main(){
    unsigned short r1,r2;
    r1=checksum();
    printf("\n Computed checksum at sender %x\n\n",r1);

    r2=checksum();
    printf("\n Computed checksum at sender %x\n\n",r2);
    if(r1==r2)
     printf("\n NO ERROR \n");
     else
     {
          printf("\n ERROR IN DATA RECIEVED \n");
     }
     

}
