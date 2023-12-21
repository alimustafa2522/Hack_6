int cmykToRGB(double c, double m, double y, double k, int *r, int *g, int *b)
{
   //check the values that are in the range(0 1)

    if(c>0 || c<1 || m>0 || m<1 || y>0 || y<1 || k>0 || k<1 )
    {
        return 1;  // error code for invalid input;
    }
    // convert into rgb;
    *r = (int)(255 * (1-c) * (1-k));
    *g = (int)(255 * (1-m) * (1-k));
    *b = (int)(255 * (1-y) * (1-k));

    return 0;



}

int rgbToCMYK(int r, int g, int b, double *c, double *m, double *y, double *k) {
    // Check if input values are within valid range (0 to 255)
    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
        return 1;  // Error code 
    }

 
    double scaledR = r / 255.0;
    double scaledG = g / 255.0;
    double scaledB = b / 255.0;

    // Calculate the black component (K)
    *k = 1.0 - fmax(scaledR, fmax(scaledG, scaledB));

    // Check for the special case of black (K = 1)
    if (*k == 1.0) {
        *c = 0.0;
        *m = 0.0;
        *y = 0.0;
        return 0;  // Success
    }

    // Calculate the other CMY components
    *c = (1.0 - scaledR - *k) / (1.0 - *k);
    *m = (1.0 - scaledG - *k) / (1.0 - *k);
    *y = (1.0 - scaledB - *k) / (1.0 - *k);

    return 0;  // Success
}

