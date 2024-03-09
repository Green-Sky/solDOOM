#pragma once

#include "./doom.hpp"

class DoomIMGUI {
	// inherit instead?
	Doom _doom;

	public:
		DoomIMGUI(
			TextureUploaderI& tu
		);
		~DoomIMGUI(void);

		// render imgui
		float render(float time_delta);
};
