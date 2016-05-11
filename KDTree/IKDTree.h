//
// Created by Lokotochek on 11.05.16.
//

#ifndef RAYTRACINGGL_IKDTREE_H
#define RAYTRACINGGL_IKDTREE_H

#include "../Geom/Geom.h"
#include "../Objects/IObject3D.h"

class IKDTree {
public:
    virtual bool find_intersection(const CVector3D& vector, IObject3D*& nearest_object, CPoint3D& nearest_intersect) = 0;
    virtual ~IKDTree() {}
};


#endif //RAYTRACINGGL_IKDTREE_H