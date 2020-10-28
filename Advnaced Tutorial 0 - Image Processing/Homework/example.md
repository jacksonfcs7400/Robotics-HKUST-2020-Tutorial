# Example of median filter
```c
#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include "qdbmp.h"

int main(void) {
    BMP* imageIn = BMP_ReadFile("noise.bmp");
    BMP_CHECK_ERROR(stdout, -1);

    int height = BMP_GetHeight(imageIn);
    int width  = BMP_GetWidth(imageIn);

    BMP* imageOut = BMP_Create(width, height, 8);
    for (int i=0; i<256; i++) {
    	BMP_SetPaletteColor(imageOut, i, i, i, i);
    }

    uint8_t window[9];
    for (size_t y=1; y<height-1; y++) {
        for (size_t x=1; x<width-1; x++) {
            // Fill the 3x3 window
	        UINT k = 0;
            for (int u=x-1; u<=x+1; u++) {
                for (int v=y-1; v<=y+1; v++) {
                    window[k++] = BMP_GetPixelGray(imageIn, u, v);
                }
            }
            // Find the median
            for(uint8_t i=0; i<5; i++) {
                for (uint8_t j=i+1; j<9; j++) {
                    if (window[j] < window[i]) {
                        uint8_t temp = window[i];
                        window[i] = window[j];
                        window[j] = temp;
                    }
                }
            }

            BMP_SetPixelGray(imageOut, x, y, window[4]);
        }
    }

    BMP_WriteFile(imageOut, "output.bmp");

    BMP_Free(imageIn);
    BMP_Free(imageOut);
    return 0;
}
```
Input - noise.bmp:

<img width="360" alt="colored" src="./example_img/noise.bmp">

Output - output.bmp:

<img width="360" alt="colored" src="./example_img/noise_output.bmp">

### Additional library

In this example, we need to import a library to read and write bitmap file. Here is the original link of [QDBMP library](http://qdbmp.sourceforge.net/). However, we have created some additional functions to work better with 8-bit grayscale image. As a result, please make sure you **download the library from our Github repository** instead of the original link provided above.
