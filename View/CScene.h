//
// Created by Lokotochek on 11.05.16.
//

#ifndef RAYTRACINGGL_CSCENE_H
#define RAYTRACINGGL_CSCENE_H
#include <string>
#include <vector>
#include "../Objects/CSphere.h"
#include "../Parser/CParser.h"
#include "../Rendering/CRenderer.h"
#include "../KDTree/CKDTreeCPU.h"
#include "CCamera.h"
#include "../Parser/IParser.h"
#include "../Light/CLighter.h"

class CScene {
private:
	std::vector<IObject3D*> m_objects;
	std::vector<CLighter> m_lighters;
	CCamera m_camera;
	int m_width;
	int m_height;
public:
	CScene(int w, int h) : m_width(w), m_height(h) {}
	CScene(const CScene& s) = delete;
	void load_file(IParser* parser, const std::string& filename);
	void load_object(IObject3D* object);
	void render(double backlight, bool gpu_process, bool testing, bool fullscreen);
};

#endif //RAYTRACINGGL_CSCENE_H
