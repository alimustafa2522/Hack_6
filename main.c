#include<stdio.h>


int main()
{
    double c,m,y,k;
    int r,g,b;


    printf("Enter CMYK values in same line");
    scanf("%lf %lf %lf %lf",c,m,y,k);

    int result = cmykToRGB(c,m,y,k,&r,&g,&b);


    if(result)
    {
        printf("RGB VALUES :  %d/n %d/n %d " , r,g,b);

    }
    else{
        printf("please enter values in the range 0 & 1");

    }

  

   
    int result = rgbToCMYK(r, g, b, &c, &m, &y, &k);

    if (result == 0) {
        
        printf("CMYK values: %.2lf, %.2lf, %.2lf, %.2lf\n", c, m, y, k);
    } else {
    
        printf( "Please enter values in the range 0 to 255.\n");
    }

    return 0;
}

    


