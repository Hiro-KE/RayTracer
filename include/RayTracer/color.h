#pragma once

#include <iostream>
#include <RayTracer/utility.h>

void write_color_ppm(std::ostream &out, color pixel_color, int samples_per_pixel)
{
    double r = pixel_color.x();
    double g = pixel_color.y();
    double b = pixel_color.z();

    //Divide the color by the number of samples
    auto scale = 1. / samples_per_pixel;
    r *= scale;
    g *= scale;
    b *= scale;

    // Write the thranslated [0, 255] value of each color component.
    out << static_cast<int>(256 * clamp(r, 0., 0.999)) << ' '
        << static_cast<int>(256 * clamp(g, 0., 0.999)) << ' '
        << static_cast<int>(256 * clamp(b, 0., 0.999)) << '\n';
}