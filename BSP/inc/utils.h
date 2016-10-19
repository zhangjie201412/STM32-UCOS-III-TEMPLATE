#ifndef __BSP_H__
#define __BSP_H__

#include "stdio.h"
#include "stm32f10x.h"

extern uint8_t DEBUG_MODE;

enum {
    LOG_ERROR       = 1 << 0,
    LOG_INFO        = 1 << 1,
    LOG_WARN        = 1 << 2,
    LOG_DEBUG       = 1 << 3,
};

#define logi(fmt, ...)                                     \
    do {                                                   \
        if(DEBUG_MODE & LOG_INFO)                          \
            printf("[INFO]: " fmt "\n", ##__VA_ARGS__);    \
    } while(0)

#define logw(fmt, ...)                                     \
    do {                                                   \
        if(DEBUG_MODE & LOG_WARN)                          \
            printf("[WARN]: " fmt "\n", ##__VA_ARGS__);    \
    } while(0)

#define logd(fmt, ...)                                     \
    do {                                                   \
        if(DEBUG_MODE & LOG_DEBUG)                         \
            printf("[DEBUG]: " fmt "\n", ##__VA_ARGS__);   \
    } while(0)

#define loge(fmt, ...)                                     \
    do {                                                   \
        if(DEBUG_MODE & LOG_ERROR)                         \
            printf("[ERR]: " fmt "\n", ##__VA_ARGS__);     \
    } while(0)

#endif
