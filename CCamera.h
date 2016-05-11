//
// Created by Lokotochek on 11.05.16.
//

#ifndef RAYTRACINGGL_CCAMERA_H
#define RAYTRACINGGL_CCAMERA_H

#include "geom.h"

class CCamera {

private:

	CPoint3D m_position;
	CVector3D m_view;

public:

	CCamera() {};

	CCamera(const CPoint3D& p,
			const CVector3D& v);

	CCamera(const CPoint3D& p,
			const CPoint3D& v);

	CPoint3D get_position() const;

	CVector3D get_view() const;

	void set_position(const CPoint3D& p);

	void set_view(const CVector3D& v);

};


#endif //RAYTRACINGGL_CCAMERA_H
