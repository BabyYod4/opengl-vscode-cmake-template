#ifndef LIB_BASE_HPP
#define LIB_BASE_HPP

#include <glew/glew.h>

#include "data_types.hpp"
#include "logging.hpp"

namespace ly{

  static inline void initGraphicLib(){
      enum_t err = glewInit();
      if (err != GLEW_OK){
        ASSERT(false, "Could not initalize Graphics Library");
      }

      std::cout << "Graphics library initialized succesfully with OpenGL version " << glGetString(GL_VERSION) << std::endl;
  }

}

#endif // !LIB_BASE_HPP