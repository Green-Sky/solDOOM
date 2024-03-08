#include "./doom.hpp"

#include <PureDOOM/PureDOOM.h>

#include <vector>

Doom::Doom(
	TextureUploaderI& tu
) : _tu(tu) {

	// Change default bindings to modern
	doom_set_default_int("key_up", DOOM_KEY_W);
	doom_set_default_int("key_down", DOOM_KEY_S);
	doom_set_default_int("key_strafeleft", DOOM_KEY_A);
	doom_set_default_int("key_straferight", DOOM_KEY_D);
	doom_set_default_int("key_use", DOOM_KEY_E);
	doom_set_default_int("mouse_move", 0); // Mouse will not move forward

	doom_set_resolution(_width, _height);

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
	doom_update();

	const uint8_t* new_image = doom_get_framebuffer(4);
	_tu.updateRGBA(_render_texture, new_image, 4 * _width * _height);

	return 1.f/60.f;
}

uint64_t Doom::getTexID(void) {
	return _render_texture;
}

