#pragma once
#include "model.hpp"

class View {
	// ============== ATTRIBUTES ==============
	Model* _model;

	// ============== OPERATIONS ==============
public:
	// ----------- creating ------------
	View(Model* model);

	// ----------- contract ------------
	void run();
};
