#pragma once

#include "./texture_uploader.hpp"

#include <PureDOOM/PureDOOM.h>

class Doom {
	TextureUploaderI& _tu;
	uint32_t _width {320};
	uint32_t _height {200};
	uint64_t _render_texture {0};

	public:
		Doom(
			TextureUploaderI& tu
		);
		~Doom(void);

		float render(float time_delta);

	public: // custom doom api
		uint64_t getTexID(void);

// since we dont have an abstraction for this, or wont know what to do with it
// these have to be called from the outside
//void doom_key_down(doom_key_t key);
//void doom_key_up(doom_key_t key);
//void doom_button_down(doom_button_t button);
//void doom_button_up(doom_button_t button);
//void doom_mouse_move(int delta_x, int delta_y);

//void doom_set_default_int(const char* name, int value);
//void doom_set_default_string(const char* name, const char* value);


// TODO: do we implement these?
//typedef void(*doom_print_fn)(const char* str);
//typedef void*(*doom_malloc_fn)(int size);
//typedef void(*doom_free_fn)(void* ptr);
//typedef void*(*doom_open_fn)(const char* filename, const char* mode);
//typedef void(*doom_close_fn)(void* handle);
//typedef int(*doom_read_fn)(void* handle, void *buf, int count);
//typedef int(*doom_write_fn)(void* handle, const void *buf, int count);
//typedef int(*doom_seek_fn)(void* handle, int offset, doom_seek_t origin);
//typedef int(*doom_tell_fn)(void* handle);
//typedef int(*doom_eof_fn)(void* handle);
//typedef void(*doom_gettime_fn)(int* sec, int* usec);
//typedef void(*doom_exit_fn)(int code);
//typedef char*(*doom_getenv_fn)(const char* var);
//// set callbacks
//void doom_set_print(doom_print_fn print_fn);
//void doom_set_malloc(doom_malloc_fn malloc_fn, doom_free_fn free_fn);
//void doom_set_file_io(doom_open_fn open_fn,
                      //doom_close_fn close_fn,
                      //doom_read_fn read_fn,
                      //doom_write_fn write_fn,
                      //doom_seek_fn seek_fn,
                      //doom_tell_fn tell_fn,
                      //doom_eof_fn eof_fn);
//void doom_set_gettime(doom_gettime_fn gettime_fn);
//void doom_set_exit(doom_exit_fn exit_fn);
//void doom_set_getenv(doom_getenv_fn getenv_fn);

};

