//
// Created by jens on 11/3/15.
//

#include <android/native_activity.h>

#include "AndroidApp.h"


#ifndef BOMB_BOMBAPPLICATION_H
#define BOMB_BOMBAPPLICATION_H


class BombApplication : public AndroidApp
{
public:
    BombApplication(ANativeActivity * activity);

    void run() override;

};


#endif //BOMB_BOMBAPPLICATION_H
