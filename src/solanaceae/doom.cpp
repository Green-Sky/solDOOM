#include "./doom.hpp"

#include <PureDOOM/PureDOOM.h>

#include <vector>

#include <cstdlib>
#include <cstdio>

#include <iostream>

void my_doom_print(const char* str) {
	std::printf("%s", str);
}

// evil global
static volatile double g_time {0};

void my_doom_gettime(int* sec, int* usec) {
	const int tmp_sec = g_time; // cast to full sec
	if (sec != nullptr) {
		*sec = tmp_sec;
	}
	if (usec != nullptr) {
		const float rest_time = g_time - tmp_sec;
		*usec = rest_time * 1'000 * 1'000;
	}
}

//static const char* doom_argv[] {
	//"self.exe",
	//"-timedemo",
	//"",
//};

Doom::Doom(
	TextureUploaderI& tu
) : _tu(tu) {
	doom_set_getenv(&std::getenv);

	doom_set_print(&my_doom_print);

	// TODO: replace this with exception?
	doom_set_exit(&std::exit);

	doom_set_gettime(&my_doom_gettime);

	// Change default bindings to modern
	doom_set_default_int("key_up", DOOM_KEY_W);
	doom_set_default_int("key_down", DOOM_KEY_S);
	doom_set_default_int("key_strafeleft", DOOM_KEY_A);
	doom_set_default_int("key_straferight", DOOM_KEY_D);
	doom_set_default_int("key_use", DOOM_KEY_E);
	doom_set_default_int("mouse_move", 0); // Mouse will not move forward

	// does not actually work
	doom_set_resolution(_width, _height);

	// HATE
	//doom_init(2, const_cast<char**>(doom_argv), 0);
	doom_init(0, nullptr, 0);

	std::vector<uint8_t> tmp_vec(4 * _width * _height, 0x00); // the api requires data for texture creation
	_render_texture = _tu.uploadRGBA(tmp_vec.data(), _width, _height, TextureUploaderI::NEAREST, TextureUploaderI::STREAMING);
}

Doom::~Doom(void) {
	// no reset?
	//doom_
	_tu.destroy(_render_texture);
}

float Doom::render(float time_delta) {
	g_time += time_delta;

	doom_update();

	const uint8_t* new_image = doom_get_framebuffer(4);
	_tu.updateRGBA(_render_texture, new_image, 4 * _width * _height);

	return 1.f/60.f;
}

uint64_t Doom::getTexID(void) {
	return _render_texture;
}

void Doom::doomKeyDown(doom_key_t key) {
	doom_key_down(key);
}

void Doom::doomKeyUp(doom_key_t key) {
	doom_key_up(key);
}

void Doom::doomButtonDown(doom_button_t button) {
	doom_button_down(button);
}

void Doom::doomButtonUp(doom_button_t button) {
	doom_button_up(button);
}

void Doom::doomMouseMove(int delta_x, int delta_y) {
	doom_mouse_move(delta_x, delta_y);
}

