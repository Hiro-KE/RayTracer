#pragma once 

#include <RayTracer/hittable.h>
#include <RayTracer/material.h>

class sphere : public hittable
{

public:

    sphere(){};
    
    sphere(const location cen, const double r, shared_ptr<material> m) : center(cen), radius(r), mat_ptr(m) {};
    
    virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const override;

public:

    location center;
    double radius;
    shared_ptr<material> mat_ptr;

};
