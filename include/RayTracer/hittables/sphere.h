#pragma once 

#include "hittable.h"

class sphere : public hittable
{

public:

    sphere(){};
    sphere(const location cen, const double r) : center(cen), radius(r) {};
    
    virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const override;

public:

    location center;
    double radius;

};

bool sphere::hit(const ray& r, double t_min, double t_max, hit_record& rec) const 
{
    location oc = r.origin() - center;
    
}
