#include <stdio.h>
#include <math.h>

void main()
{
    int N,c,i,j;
    c=1;
    
    printf("Input the number of rows : ");
    
    scanf("%d",&N);
    for(i=N;i>=0;i--)
    {
    
		for(c=N-1;c>=i-N;c--)
		
        printf("  ");
        
        for(j=0;j<=i;j++)
        {
            if (j==0||i==0)
                c=1;
            else
               c=c*(i-j+1)/j;
            printf("%4d",c);
        }
    
        printf("\n");
        
    	
    }
    
}
