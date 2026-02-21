#pragma once

#ifndef MACROS_HPP
#define MACROS_HPP

#include <cstdio>
#include <iostream>

#define STR(x) #x

#ifdef DEBUGGING

#define ASSERT(eval) if(eval) \
printf("[assert] %s function on line %d : (%s) returns true\n",__func__,__LINE__,STR(eval)); \
else \
printf("[assert] %s function on line %d : (%s) returns false\n",__func__,__LINE__,STR(eval));

#else
#define ASSERT(eval)
#endif

#ifdef LOGGING
#define LOG(value) std::cout << "[log] " << __func__ << " function on line " << __LINE__ << " : value " << STR(value) << " is equal to " << value << "\n";
#else
#define LOG(value)
#endif

#endif // MACROS_HPP