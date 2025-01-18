#include "./doom_imgui.hpp"

#include <imgui.h>

#include <vector>

DoomIMGUI::DoomIMGUI(
	TextureUploaderI& tu
) : _doom(tu) {
}

DoomIMGUI::~DoomIMGUI(void) {
}

const static std::vector<std::pair<ImGuiKey, doom_key_t>> g_all_keys {
	{ImGuiKey_A, DOOM_KEY_A},
	{ImGuiKey_Tab, DOOM_KEY_TAB},
	{ImGuiKey_Enter, DOOM_KEY_ENTER},
	{ImGuiKey_Escape, DOOM_KEY_ESCAPE},
	{ImGuiKey_Space, DOOM_KEY_SPACE},
	{ImGuiKey_Apostrophe, DOOM_KEY_APOSTROPHE},
	{ImGuiKey_KeypadMultiply, DOOM_KEY_MULTIPLY}, // keypad?
	{ImGuiKey_Comma, DOOM_KEY_COMMA},
	{ImGuiKey_Minus, DOOM_KEY_MINUS},
	{ImGuiKey_Period, DOOM_KEY_PERIOD},
	{ImGuiKey_Slash, DOOM_KEY_SLASH},
	{ImGuiKey_0, DOOM_KEY_0},
	{ImGuiKey_1, DOOM_KEY_1},
	{ImGuiKey_2, DOOM_KEY_2},
	{ImGuiKey_3, DOOM_KEY_3},
	{ImGuiKey_4, DOOM_KEY_4},
	{ImGuiKey_5, DOOM_KEY_5},
	{ImGuiKey_6, DOOM_KEY_6},
	{ImGuiKey_7, DOOM_KEY_7},
	{ImGuiKey_8, DOOM_KEY_8},
	{ImGuiKey_9, DOOM_KEY_9},
	{ImGuiKey_Semicolon, DOOM_KEY_SEMICOLON},
	{ImGuiKey_Equal, DOOM_KEY_EQUALS},
	{ImGuiKey_LeftBracket, DOOM_KEY_LEFT_BRACKET},
	{ImGuiKey_RightBracket, DOOM_KEY_RIGHT_BRACKET},
	{ImGuiKey_A, DOOM_KEY_A},
	{ImGuiKey_B, DOOM_KEY_B},
	{ImGuiKey_C, DOOM_KEY_C},
	{ImGuiKey_D, DOOM_KEY_D},
	{ImGuiKey_E, DOOM_KEY_E},
	{ImGuiKey_F, DOOM_KEY_F},
	{ImGuiKey_G, DOOM_KEY_G},
	{ImGuiKey_H, DOOM_KEY_H},
	{ImGuiKey_I, DOOM_KEY_I},
	{ImGuiKey_J, DOOM_KEY_J},
	{ImGuiKey_K, DOOM_KEY_K},
	{ImGuiKey_L, DOOM_KEY_L},
	{ImGuiKey_M, DOOM_KEY_M},
	{ImGuiKey_N, DOOM_KEY_N},
	{ImGuiKey_O, DOOM_KEY_O},
	{ImGuiKey_P, DOOM_KEY_P},
	{ImGuiKey_Q, DOOM_KEY_Q},
	{ImGuiKey_R, DOOM_KEY_R},
	{ImGuiKey_S, DOOM_KEY_S},
	{ImGuiKey_T, DOOM_KEY_T},
	{ImGuiKey_U, DOOM_KEY_U},
	{ImGuiKey_V, DOOM_KEY_V},
	{ImGuiKey_W, DOOM_KEY_W},
	{ImGuiKey_X, DOOM_KEY_X},
	{ImGuiKey_Y, DOOM_KEY_Y},
	{ImGuiKey_Z, DOOM_KEY_Z},
	{ImGuiKey_Backspace, DOOM_KEY_BACKSPACE},
	{ImGuiKey_ModCtrl, DOOM_KEY_CTRL},
	{ImGuiKey_LeftArrow, DOOM_KEY_LEFT_ARROW},
	{ImGuiKey_UpArrow, DOOM_KEY_UP_ARROW},
	{ImGuiKey_RightArrow, DOOM_KEY_RIGHT_ARROW},
	{ImGuiKey_DownArrow, DOOM_KEY_DOWN_ARROW},
	{ImGuiKey_ModShift, DOOM_KEY_SHIFT},
	{ImGuiKey_ModAlt, DOOM_KEY_ALT},
	{ImGuiKey_F1, DOOM_KEY_F1},
	{ImGuiKey_F2, DOOM_KEY_F2},
	{ImGuiKey_F3, DOOM_KEY_F3},
	{ImGuiKey_F4, DOOM_KEY_F4},
	{ImGuiKey_F5, DOOM_KEY_F5},
	{ImGuiKey_F6, DOOM_KEY_F6},
	{ImGuiKey_F7, DOOM_KEY_F7},
	{ImGuiKey_F8, DOOM_KEY_F8},
	{ImGuiKey_F9, DOOM_KEY_F9},
	{ImGuiKey_F10, DOOM_KEY_F10},
	{ImGuiKey_F11, DOOM_KEY_F11},
	{ImGuiKey_F12, DOOM_KEY_F12},
	{ImGuiKey_Pause, DOOM_KEY_PAUSE},
};

float DoomIMGUI::render(float time_delta) {
	float doom_interval {1.f};

	if (ImGui::Begin("doom", nullptr, ImGuiWindowFlags_AlwaysAutoResize)) {
		ImGui::SliderFloat("scale", &_size_scaler, 1.f, 5.f);

		const bool window_focused = ImGui::IsWindowFocused();
		for (const auto& [imkey, dokey] : g_all_keys) {
			if (window_focused && ImGui::IsKeyPressed(imkey, false)) {
				_doom.doomKeyDown(dokey);
			}
			if (ImGui::IsKeyReleased(imkey)) {
				_doom.doomKeyUp(dokey);
			}
		}

		doom_interval = _doom.render(time_delta);
		ImGui::Image(_doom.getTexID(), {_size_scaler * 320, _size_scaler * 200 * 1.2f});
	}
	ImGui::End();

	return doom_interval;
}

