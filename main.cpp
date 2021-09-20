#include <RayTracer/render.h>
#include <RayTracer/color.h>

int main(int, char**) {
    
    render* Render = new render();
    Render->init();

    // Write to a file
    freopen("output.ppm","w",stdout);

    std::cout << "P3\n" << Render->image_width << ' ' << Render->image_height << "\n255\n";

    for (int j = Render->image_height-1; j >= 0; --j) 
    {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < Render->image_width; ++i) {
            
            // Set up UV
            double u = double(i) / (Render->image_width - 1.);
            double v = double(j) / (Render->image_height - 1.);
            
            ray r(Render->origin, Render->lower_left_corner + u * Render->horizontal + v * Render->vertical - Render->origin);
            color pixel_color(Render->ray_color(r, Render->world));
            write_color_ppm(std::cout, pixel_color);
        }
    }
    return 0;
}
