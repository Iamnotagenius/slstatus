#include <stdint.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>

#include "../util.h"

const char *
gpu_perc(const char *gpu) {
    uintmax_t perc;
    char path[PATH_MAX];

    if (esnprintf(path, sizeof(path), 
                "/sys/class/graphics/%s/device/gpu_busy_percent", gpu) < 0) {
        return NULL;
    };

    if (pscanf(path, "%d", &perc) != 1) {
        return NULL;
    }

    return bprintf("%d", perc);
}

const char *
gpu_mem_perc(const char *gpu) {
    uintmax_t perc;
    char path[PATH_MAX];

    if (esnprintf(path, sizeof(path), 
                "/sys/class/graphics/%s/device/mem_busy_percent", gpu) < 0) {
        return NULL;
    };
    
    if (pscanf(path, "%d", &perc) != 1) {
        return NULL;
    }
    
    return bprintf("%d", perc);
}

const char *
gpu_vram_used(const char *gpu) {
    uintmax_t used;
    char path[PATH_MAX];

    if (esnprintf(path, sizeof(path), 
                "/sys/class/graphics/%s/device/mem_info_vram_used", gpu) < 0) {
        return NULL;
    };
    
    if (pscanf(path, "%ju", &used) != 1) {
        return NULL;
    }
    
    return fmt_human(used, 1000);
}

const char *
gpu_vram_total(const char *gpu) {
    uintmax_t total;
    char path[PATH_MAX];

    if (esnprintf(path, sizeof(path), 
                "/sys/class/graphics/%s/device/mem_info_vram_total", gpu) < 0) {
        return NULL;
    };

    printf("%s\n", path);
    
    if (pscanf(path, "%ju", &total) != 1) {
        return NULL;
    }
    
    return fmt_human(total, 1000);
}
