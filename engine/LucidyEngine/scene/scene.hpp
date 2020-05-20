#ifndef SCENE_HPP
#define SCENE_HPP

#include "../generic/data_types.hpp"

namespace ly{

class Scene{
public:
    virtual void onEntry(){};
    virtual void onExit(){};
    virtual void onUpdate(const float_t& t_delta) = 0;
protected:
    cstring_t selectScene;
};

}

#endif // SCENE_HPP
