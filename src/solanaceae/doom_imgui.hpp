#pragma once

#include "./doom.hpp"

class DoomIMGUI {
	// inherit instead?
	Doom _doom;

	float _size_scaler {2.f};

	public:
		DoomIMGUI(
			TextureUploaderI& tu
		);
		~DoomIMGUI(void);

		// render imgui
		float render(float time_delta);
};

