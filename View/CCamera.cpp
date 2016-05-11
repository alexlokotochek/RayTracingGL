//
// Created by Lokotochek on 11.05.16.
//

#include "CCamera.h"

void CCamera::set_view(const CVector3D& v) {
    m_view = v;
    m_view.normalize();
}

CCamera::CCamera() {
    m_position = CPoint3D();
    m_view = CVector3D();
}

CCamera::CCamera(const CPoint3D& p,
        const CVector3D& v) {
    m_position = p;
    m_view = v;
    m_view.normalize();
}

CCamera::CCamera(const CPoint3D& p,
        const CPoint3D& v) {
    m_position = p;
    m_view = CVector3D(p, v));
    m_view.normalize();
}

CPoint3D CCamera::get_position() const {
    return m_position;
}

CVector3D CCamera::get_view() const {
    return m_view;
}

void CCamera::set_position(const CPoint3D& p) {
    m_position = p;
}