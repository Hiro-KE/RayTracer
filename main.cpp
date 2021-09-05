#include <RayTracer/engine.h>
#include <RayTracer/color.h>

int main(int, char**) {
    
    engine* Engine = new engine();
    
    // Write to a file
    freopen("output.ppm","w",stdout);

    std::cout << "P3\n" << Engine->image_width << ' ' << Engine->image_height << "\n255\n";

    for (int j = Engine->image_height-1; j >= 0; --j) 
    {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < Engine->image_width; ++i) {
            
            // Set up UV
            double u = double(i) / (Engine->image_width - 1.);
            double v = double(j) / (Engine->image_height - 1.);
            
            ray r(Engine->origin, Engine->lower_left_corner + u * Engine->horizontal + v * Engine->vertical - Engine->origin);
            color pixel_color(Engine->ray_color(r));
            write_color_ppm(std::cout, pixel_color);
        }
    }
    return 0;
}
