#include "./doom_imgui.hpp"

#include <imgui.h>

DoomIMGUI::DoomIMGUI(
	TextureUploaderI& tu
) : _doom(tu) {
}

DoomIMGUI::~DoomIMGUI(void) {
}

float DoomIMGUI::render(float time_delta) {
	// tick doom either way
	// while this is computing, and as such could be run in tick(), its still rendering
	const float doom_interval = _doom.render(time_delta);

	if (ImGui::Begin("doom")) {
		ImGui::Image(reinterpret_cast<void*>(_doom.getTexID()), {320, 200});
	}
	ImGui::End();

	return doom_interval;
}

