#include<stdio.h>
#include<stdlib.h>

    int NAND(int a,b){return !(a&&b);}
    int NOT(int a){return NAND(a,a);}
    int AND(int a,b){return NOT(NAND(a,b));}
    int OR(int a,b){return NOT(AND(NOT(a),NOT(b)));}
    int XOR(int a,b){return OR((AND(a,!b)),AND(!a,b));}
    int MUX(int s,a,b){return OR((AND(a,!s)),(AND(b,s)));}
    int DMUXA(int x,s){return AND(x,!s);}
    int DMUXB(int x,s){return AND(x,s);}
    
int main()
    {
        int a,b,s,x;
        int in1[16];
        int in2[16];
        int out[16];
        
        printf("Testing Chips 1-4\n");
        printf("| a | b | a NAND b | NOT a | a AND b | a OR b |\n");
        printf("+---+---+----------+-------+---------+--------+\n");
        for(a=0;a<2;a++)
            for(b=0;b<2;b++)
            {
                printf("| %d | %d |     %d    |   %d   |    %d    |    %d   |\n",a,b,NAND(a,b),NOT(a),AND(a,b),OR(a,b));
                printf("+---+---+----------+-------+---------+--------+\n");
            }
        
        printf("Testing Chips 5-8\n");
        
        printf("XOR\n");
        printf("| a | b | a XOR b  |\n");
        printf("+---+---+----------+\n");
        for(a=0;a<2;a++)
        {
            for(b=0;b<2;b++)
            {  
                printf("| %d | %d |     %d    |\n",a,b,XOR(a,b));
                printf("+---+---+----------+\n");
            }
        }
                
        printf("MUX\n");
        printf("| s | a | b | a MUX b |\n");
        printf("+---+---+---+----------+\n");
        for(s=0;s<2;s++)
        {
            for(a=0;a<2;a++)
            {
                for(b=0;b<2;b++)
                {  
                    printf("| %d | %d | %d |     %d    |\n",s,a,b,MUX(s,a,b));
                    printf("+---+---+---+----------+\n");
                }
            }
        }
        
        printf("DMUX\n");
        printf("| x | s | DMUX a | DMUX b |\n");
        printf("+---+---+--------+--------+\n");
        for(x=0;x<2;x++)
        {
            for(s=0;s<2;s++)
            {  
                printf("| %d | %d |    %d    |   %d   |\n",x,s,DMUXA(x,s),DMUXB(x,s));
                printf("+---+---+---------+-------+\n");
                
            }
        }
        printf("NOT16\n");
        printf("| in | out |");
        printf("+----+-----+");
        for(x=0;x<=15;x++)
        {
            in1[x] = 1;
            printf("|  %d  |   %d  |",in1[x],out[x]);
        }
                
    }
