#include <RayTracer/render.h>

int main(int, char**) {
    
    render* Render = new render();
    Render->init();
    Render->process();
    return 0;
}
