#define NOB_IMPLEMENTATION
#include "nob.h"

int main(int argc, char **argv)
{
    NOB_GO_REBUILD_URSELF(argc, argv);

    const char *program = nob_shift_args(&argc, &argv);

    Nob_Cmd cmd = {0};
    Nob_Procs procs = {0};

    if (nob_needs_rebuild1("binviz", "binviz.c")) {
        cmd.count = 0;
        nob_cmd_append(&cmd, "cc");
        nob_cmd_append(&cmd, "-Wall", "-Wextra", "-ggdb", "-pedantic");
        nob_cmd_append(&cmd, "-o", "binviz", "binviz.c");
        nob_cmd_append(&cmd, "-lm");
        nob_da_append(&procs, nob_cmd_run_async(cmd));
    } else {
        nob_log(NOB_INFO, "binviz is fresh");
    }

    if (nob_needs_rebuild1("img2raw", "img2raw.c")) {
        cmd.count = 0;
        nob_cmd_append(&cmd, "cc");
        nob_cmd_append(&cmd, "-Wall", "-Wextra", "-ggdb", "-pedantic");
        nob_cmd_append(&cmd, "-o", "img2raw", "img2raw.c");
        nob_cmd_append(&cmd, "-lm");
        nob_da_append(&procs, nob_cmd_run_async(cmd));
    } else {
        nob_log(NOB_INFO, "img2raw is fresh");
    }

    if (!nob_procs_wait(procs)) return 1;

    if (argc > 0) {
        const char *subcmd = nob_shift_args(&argc, &argv);

        cmd.count = 0;
        if (strcmp(subcmd, "img2raw") == 0) {
            nob_cmd_append(&cmd, "./img2raw");
        } else if (strcmp(subcmd, "binviz") == 0) {
            nob_cmd_append(&cmd, "./binviz");
        } else {
            nob_log(NOB_ERROR, "Unknown subcommand %s", subcmd);
            return 1;
        }

        for (size_t i = 0; i < argc; ++i) {
            nob_cmd_append(&cmd, argv[i]);
        }
        if (!nob_cmd_run_sync(cmd)) return 1;
    }

    return 0;
}
