//
// Created by jens on 11/11/15.
//

#ifndef BOMB_APPLICATION_H
#define BOMB_APPLICATION_H

class ResourceManager;
class GLContext;

class Application
{
public:
    virtual ~Application(){}

    virtual void loadResources(ResourceManager const& resource_manager) = 0;
    virtual void update(GLContext const& context) = 0;
};

#endif //BOMB_APPLICATION_H
