/* register_types.cpp */

#include "register_types.h"

#include "carcassonne.hpp"
#include "core/object/class_db.h"

void initialize_carcassonne_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
			return;
	}
	ClassDB::register_class<Carcassonne>();
}

void uninitialize_carcassonne_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
			return;
	}
	// Nothing to do here in this example.
}
