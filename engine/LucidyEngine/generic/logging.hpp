#ifndef LOGGING_HPP
#define LOGGING_HPP

#include <cassert>
#include <iostream>

#define ASSERT(x, msg) { if(!x){ std::cerr << msg << std::endl; assert(false); } }

#endif // LOGGING_HPP
