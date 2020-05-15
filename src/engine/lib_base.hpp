#ifndef LIB_BASE_HPP
#define LIB_BASE_HPP

#include <glew/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <string>
#include <cassert>
#include <iostream>

#define ASSERT(x, msg) { if(!x){ std::cerr << msg << std::endl; assert(false); } }

typedef GLuint uint_tp;
typedef GLint int_tp;
typedef float float_tp;
typedef GLenum enum_tp;
typedef std::string string_tp;

typedef glm::vec2 vec2_tp;
typedef glm::vec3 vec3_tp;
typedef glm::vec4 vec4_tp;
typedef glm::mat4 mat4_tp;

#endif // !LIB_BASE_HPP