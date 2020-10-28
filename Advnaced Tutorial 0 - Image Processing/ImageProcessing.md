# Image Processing

Author : Amrutavarsh Kinagi

Contact: askinagi@connect.ust.hk 

Author : Morris Tseng

Contact: mtseng@connect.ust.hk 

Updated by: Ho Yu Yat (yyhoai@connect.ust.hk) (2019)

Updated by: Tang Pok Lam (pltangab@connect.ust.hk) (2020)

## Image in Computer
Vision is one of the major preception systems in the Robotics field. 
The robot received image or video data from the camera module and stored it on the RAM.

Here is a camera module.

<img width="360" alt="camera module" src="https://upload.wikimedia.org/wikipedia/commons/4/4b/Raspberry_Pi_Camera_Module_-_Hand-Held_%2814672275231%29.jpg">

Images in computers or robots are stored in the **2D array**. You might have direct access to this array or only by a **pointer** given. Note that the coordinate system of image is different from the normal coordinate system in Mathematics. The origin (0, 0) is on the top-left corner of the iamge.

<img width="240" alt="coordinate system" src="http://pippin.gimp.org/image_processing/images/coord_sys.png">


## Image Processing

Image Processing are vital part in the Smart Car and ROV sub-team and the robot in the Robot Design Contest. Here is a quick and brief guide to it.

### Before Image Processing

Since the camera image is stored in pixels in a 2d array, it is important to know the concept and implementations of arrays.

Here is a 2D array with width 5 and height 3

| [0][0] | [0][1] | [0][2] | [0][3] | [0][4] |
| ------ | ------ | ------ | ------ | ------ |
| [1][0] | [1][1] | [1][2] | [1][3] | [1][4] |
| [2][0] | [2][1] | [2][2] | [2][3] | [2][4] |

Below is a demonstration of a typical way to manipulate a 2D array:

```c
#include <stdio.h>
#define WIDTH 5
#define HEIGHT 3
void print_array(int A[][WIDTH], int height){
    for(int i = 0; i<height; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int myArray[HEIGHT][WIDTH];
    for (int i = 0; i < HEIGHT; i++){
        for (int j=0; j < WIDTH; j++){
            myArray[i][j] = WIDTH * i + j;
        }
    }
    print_array(myArray, HEIGHT);
}
```

Output

```
0 1 2 3 4 
5 6 7 8 9 
10 11 12 13 14 
```

### 1. Image Type (Colored, Grayscale or Black&White)

Although you might not have to the color mode setting of the camera module in the emulator, this is still worth knowing. It is very important for real-life situations since it will affect the quality of the image you obtain.

#### Colored

<img width="360" alt="colored" src="https://user-images.githubusercontent.com/32810188/44947015-2f9d3180-ae39-11e8-854a-a32387a246ef.png">

#### GrayScale

<img width="360" alt="greyscale" src="https://user-images.githubusercontent.com/32810188/44947020-404da780-ae39-11e8-8c8b-f1113f03550c.png">

Please note that the images are rendered instead of taking in reality, so the image shown here may not fully represent the real image that you will be getting.

#### RGB565
If we want to have colored pictures, we also need information about the color. The color depth defines how many bits are used to represent a color. The more bits (information), the more colors we can display. There are different ways on how to represent a color but virtually all displays use RGB, where a color is represented by its Red Green and Blue components.

RGB565 requires only 16 (5+6+5) bits/2 bytes and is commonly used with embedded screens. Each pixel occupies 2 bytes, the bits are split into 3 groups to represent RGB respectively.

R: Occupies 5 bits, so its value range from 00000 to 11111.

G: Occupies 6 bits, so its value range from 000000 to 111111.

B: Occupies 5 bits, so its value range from 00000 to 11111.

Concatenate the 3 values in the order R, G, B. So if R=11011, G=110010 and B=11010, then the final RGB565 value is 1101111001011010.

<img width="480" alt="RGB565" src="https://www.newton.com.tw/img/7/e01/cGcq5SM0YDM5ADMkJGNxQmZ5QWM0UzMjJjN4AzLtVGdp9yYpB3LltWahJ2Lt92YuUHZpFmYuMmczdWbp9yL6MHc0RHa.jpg">

We can also **convert RGB565 image to grayscale image**.

You can get the RGB value respecively by bit shifting operation.
```C++
int16_t pixel = *buffer;
int16_t red = ((pixel & 0xF800)>>11);
int16_t green = ((pixel & 0x07E0)>>5);
int16_t blue = (pixel & 0x001F);
```
Then, you need to combine red, green and blue value with weights to generate grayscale value.

A common ratio (weights) is **R: 0.2989, G: 0.5870, B: 0.1140**

Try it yourself.

Note that the Green component have 6 bit, not because it needs to have higher values but because it needs higher resolution ([see RGB 565 - Why 6 Bits for Green Color](https://stackoverflow.com/questions/25467682/rgb-565-why-6-bits-for-green-color)).

#### Pros and Cons

- Colored: (colors are stored as RGB in the MCU)
    - Pros: Contains lot of details
    - Cons: Hard to control
- GreyScale: (range from 0 ~ 255, which black = 0 and white = 255)  **Recommended**
    - Pros: Easier to control(compared to Colored image), able to use gradient to differentiate features
    - Cons: 
- Black & White: (represented by 1 and 0, which black = 1 and white = 0)
    - Pros: Easiest to control
    - Cons: Hard to adjust thresholding for the image, have minimal information

These pros and cons are just a means to guide you. However, these rules aren't set in stone. It is general that for image processing, we would usually choose greyscale or black&white images to analyze as they provide adequate information in order to handle the dynamics of the car. The use of Colored image may provide more information but it is upto you to determine if the extra information available is of any substantial benefit.

### 2.Brightness & Intensity

Apart from color choices, the brightness and the intensity of the image captured also affect the quality of the image you obtain, which in turn affect the ability to extract good data from it.

**Low Intensity**

<img width="360" alt="lowintense" src="https://user-images.githubusercontent.com/32810188/44949429-b49d4080-ae63-11e8-902e-17e64f7caf88.png">

**Medium Intensity**

<img width="360" alt="mediumintense" src="https://user-images.githubusercontent.com/32810188/44949432-b961f480-ae63-11e8-8896-d919740a78bd.png">

**High Intensity**

<img width="360" alt="highintense" src="https://user-images.githubusercontent.com/32810188/44949434-bbc44e80-ae63-11e8-8e68-152058dd8f3a.png">

If you do not find the proper intensity, your image might contains noise that would deter you from processing the information accurately. It is important that the program you write is able to adjust the brightness and intensity based on different lighting conditions as it is against the rules to flash your program during the competition.

Here is a guideline if you want to write code to adjust the brightness and intensity of the image

https://pippin.gimp.org/image-processing/chap_point.html

## Convolution of image

#### Introduce to kernel

A kernel is a square matrix that specifies spatial weights of various pixels in an image. Different image processing have different kernels.

<img width="480" alt="wrxle" src="https://user-images.githubusercontent.com/32810188/45767787-afb2fc00-bc6d-11e8-81a5-29ba95f1c94a.png">

#### Convolution Process

Convolution of a matrix involves laying a matrix over another and then calculating the weighted sum of all pixel values.In this example, it is using an 3x3 kernel for convolution. If the input image is a mxn array, then the ouput array should be (m-2)x(n-2).

<img width="480" height="360" src="https://user-images.githubusercontent.com/32810188/45766774-f6ebbd80-bc6a-11e8-9aed-c7f57fe57159.JPG">

105*(0)+102*(-1)+100*(0)+103*(-1)... = 89

More examples:

<img width="480" height="360" src="https://user-images.githubusercontent.com/32810188/45768526-bb9fbd80-bc6f-11e8-9d93-120bb90f9175.gif">

## Application for convolution - Reducing Noise

Usually image generated might contain noise and will have to be **filtered/ smoothened** to prevent it from affecting the image analysis. 

There are mainly two types of noise which are salt-and-pepper noise and gaussian noise.

### Salt-and-pepper Noise - Median Filter
Salt-and-pepper noise is a form of noise sometimes seen on images. It is also known as impulse noise. This noise can be caused by sharp and sudden disturbances in the image signal. It presents itself as sparsely occurring white and black pixels.

<img width="480" alt=" salt-and-pepper noise" src="https://static-01.hindawi.com/articles/tswj/volume-2014/826405/figures/826405.fig.0010a.jpg">

For salt-and-pepper noise, we can use median filter.

<img width="480" alt="median filter" src="https://www.researchgate.net/profile/Vu_Hoang_Minh/publication/320547422/figure/fig4/AS:551864018141185@1508586043638/3-3-kernel-in-median-filter.png">

Use of a median filter to improve an image severely corrupted by defective pixels

<img width="480" alt="colored" src="https://i.imgur.com/v9DjmbP.png">

Example Code:

```c++
void medianFilter(const uint8_t *cameraDataPtr, uint8_t *processedDataPtr, uint16_t width, uint16_t height) {
    uint8_t window[9];
    // Loop though entire image array
    // ignored the outer edge of the image to simplify the code
    for (uint16_t x=1; x<width-1; x++) {
        for (uint16_t y=1; y<height-1; y++) {
            // Fill the 3x3 window
	    uint8_t k = 0;
            for (int u=x-1; u<=x+1; u++) {
                for (int v=y-1; v<=y+1; v++) {
                    window[k++] = *(cameraDataPtr + width * v + u);
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
            // Assign the median to the processed image array
            *(processedDataPtr + width * y + x) = window[4];
        }
    }
}
```

### Gaussian Noise - Gaussian Filter
Gaussian noise is statistical noise having a probability density function equal to that of the normal distribution, which is also known as the Gaussian distribution. In other words, the values that the noise can take on are Gaussian-distributed.

<img width="480" alt="gaussian noise" src="https://www.researchgate.net/publication/252066070/figure/fig2/AS:361043193810945@1463090813645/Noisy-image-Gaussian-noise-with-mean-and-variance-0005_Q640.jpg">

<img width="480" alt="gaussian noise" src="https://www.sfu.ca/sonic-studio-webdav/handbook/Graphics/Gaussian.gif">

<img width="640" alt="gaussian noise" src="https://miro.medium.com/max/3264/1*nOkI4VIQKM5FaSVBP8TiZw.png">

For Gaussian noise, we can use Gaussian filter kernel.

<img width="240" alt="Gaussian filter kernel" src="https://4.bp.blogspot.com/-v4dH8qhFnEE/WqHaTPel8RI/AAAAAAAAI8g/AxIVu5i7mHU5UDcu6BkJQJj_UO11sMomwCLcBGAs/s1600/3x3%2BGaussian%2BKernel.png">

## Application for convolution - Feature Dectection

Here are some images that have gone through the convolution.

<img width="480" alt="colored" src="https://i.imgur.com/T17jDCz.png">

### Edge detection - Sobel filter
Sobel filter can create an image emphasising edges which is very useful.

<img width="640" alt="colored" src="https://slideplayer.com/slide/14419272/90/images/8/Sobel+operator+In+practice%2C+it+is+common+to+use%3A+Magnitude%3A.jpg">

Before:

<img width="360" alt="colored" src="https://upload.wikimedia.org/wikipedia/commons/thumb/3/3f/Bikesgray.jpg/300px-Bikesgray.jpg">

After:

<img width="360" alt="colored" src="https://upload.wikimedia.org/wikipedia/commons/thumb/2/24/Bikesgray_sobel.JPG/300px-Bikesgray_sobel.JPG">

Convolutions can extended to further detect other vital features of the track. Another key term to keep in mind is **Gradient**.

<img width="480" alt="colored" src="https://i.imgur.com/AbQLWej.png">


**Points to remember:**

1. Real life situations largely vary from digital replicated simulations. Application of algorithms should thus be geared to tackle the blemishes you would face.
2. Analyse features and algorithms from a mathematical and physical perspective. 
3. Keep the program robust in order to tackle the worst cases possible. 
4. Tuning the physical properties of the car is allowed and remains essential for ensuring the car runs according to plan.
5. As images are stored in the form of matrices, keep in mind the run time of your program during feature extraction or **path planning.**

### Further Pondering

- Applying convolution to the whole image is an processor-intensive task, and might produce a large amount of unnecessary information. How to extract only the needed information in your application?
- Or even better, only produce the needed information? (This will be crucial in our application)
