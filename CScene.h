//
// Created by Lokotochek on 11.05.16.
//

#ifndef RAYTRACINGGL_CSCENE_H
#define RAYTRACINGGL_CSCENE_H

#include <string>
#include <vector>
#include "csphere.h"

class CScene {
	private:
		std::vector<IObject3D*> m_objects;
	public:
		CScene() {}
		CScene(const CScene& s) = delete;
		void read(std::string filename);
		void render() const;
};


#endif //RAYTRACINGGL_CSCENE_H
