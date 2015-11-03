//
// Created by jens on 11/3/15.
//

#ifndef BOMB_LOG_H_H
#define BOMB_LOG_H_H

#include <android/log.h>

#define  LOG_TAG    "bomb"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  LOGV(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)

#endif //BOMB_LOG_H_H
