//
// Created by Lokotochek on 11.05.16.
//

#include "CCamera.h"

void CCamera::set_view(const CVector3D& v) {
    m_view = v;
    m_view.normalize();
}