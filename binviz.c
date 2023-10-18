#include <stdio.h>
#include <stdint.h>
#include <math.h>

#define NOB_IMPLEMENTATION
#include "nob.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#define MAP_SIZE 256

static size_t map[MAP_SIZE][MAP_SIZE] = {0};
static uint32_t pixels[MAP_SIZE][MAP_SIZE] = {0};

int main(int argc, char **argv)
{
    const char *program = nob_shift_args(&argc, &argv);

    if (argc <= 0) {
        nob_log(NOB_ERROR, "No input is provided");
        nob_log(NOB_INFO, "Usage: %s <input>", program);
        return 1;
    }

    Nob_String_Builder content = {0};
    for (int i = 0; i < argc; ++i) {
        const char *input_file_path = argv[i];
        content.count = 0;
        nob_log(NOB_INFO, "Reading %s", input_file_path);
        if (!nob_read_entire_file(input_file_path, &content)) return 1;

        memset(map, 0, sizeof(map));
        if (content.count > 0) {
            for (size_t i = 0; i < content.count - 1; ++i) {
                uint8_t x = content.items[i];
                uint8_t y = content.items[i+1];
                map[y][x] += 1;
            }
        }

        float max = 0;

        for (size_t y = 0; y < MAP_SIZE; ++y) {
            for (size_t x = 0; x < MAP_SIZE; ++x) {
                float f = 0.0f;
                if (map[y][x] > 0) f = logf(map[y][x]);
                if (f > max) max = f;
            }
        }

        for (size_t y = 0; y < MAP_SIZE; ++y) {
            for (size_t x = 0; x < MAP_SIZE; ++x) {
                float t = logf(map[y][x])/max;
                uint32_t b = t*255;
                pixels[y][x] = 0xFF000000 | b | (b<<8) | (b<<16);
            }
        }

        const char *output_file_path = nob_temp_sprintf("%s.binviz.png", input_file_path);
        if (!stbi_write_png(output_file_path, MAP_SIZE, MAP_SIZE, 4, pixels, MAP_SIZE*sizeof(uint32_t))) {
            nob_log(NOB_ERROR, "Could not save image %s", output_file_path);
            return 1;
        }

        nob_log(NOB_INFO, "Generated %s", output_file_path);

        nob_temp_reset();
    }

    return 0;
}
