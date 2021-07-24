#include "header/vec4.h"
#include "header/color.h"

int main()
{
    const int image_width = 256;
    const int image_height = 256;

    // Write to a file
    freopen("output.ppm","w",stdout);

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = image_height-1; j >= 0; --j) 
    {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            color pixel_color(double(i)/(image_width-1), double(j)/(image_height-1), 0.25, 1.);
            write_color_ppm(std::cout, pixel_color);
        }
    }

    return 0;
};