#include <stdio.h>
#include <stdint.h>

#define NOB_IMPLEMENTATION
#include "nob.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

int main(int argc, char **argv)
{
    const char *program = nob_shift_args(&argc, &argv);

    if (argc <= 0) {
        nob_log(NOB_ERROR, "No input is provided");
        nob_log(NOB_INFO, "Usage: %s <input...>", program);
        return 1;
    }

    for (int i = 0; i < argc; ++i) {
        const char *input_file_path = argv[i];

        nob_log(NOB_INFO, "Reading file %s", input_file_path);

        int width, height;
        uint32_t *pixels = (uint32_t *)stbi_load(input_file_path, &width, &height, NULL, 4);
        if (pixels == NULL) {
            nob_log(NOB_ERROR, "Could not load file %s", input_file_path);
            continue;
        }

        const char *output_file_path = nob_temp_sprintf("%s.raw", input_file_path);
        if (!nob_write_entire_file(output_file_path, pixels, sizeof(uint32_t)*width*height)) continue;
        nob_log(NOB_INFO, "Generated %s", output_file_path);

        stbi_image_free(pixels);
        nob_temp_reset();
    }

    return 0;
}
