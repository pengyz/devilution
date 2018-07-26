cmake_minimum_required(VERSION 3.1.1)

include("cmake/HunterGate.cmake")


HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.23.4.tar.gz"
    SHA1 "8b2255921208517a55c9533c500131387e3c3dd0"
    LOCAL
)

project (Devilution)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

set(HUNTER_LIBS "")

# hunter_add_package(SDL2)
# find_Package(SDL2 CONFIG REQUIRED)
# set(HUNTER_LIBS ${HUNTER_LIBS} SDL2::SDL2)

# hunter_add_package(SDL_image)
# find_package(SDL_image CONFIG REQUIRED)
# set(HUNTER_LIBS ${HUNTER_LIBS} SDL_image::SDL_image)

# hunter_add_package(SDL_mixer)
# find_package(SDL_mixer CONFIG REQUIRED)
# set(HUNTER_LIBS ${HUNTER_LIBS} SDL_mixer::SDL_mixer)

hunter_add_package(glew)
find_package(glew CONFIG REQUIRED)
set(HUNTER_LIBS ${HUNTER_LIBS} glew::glew)

hunter_add_package(glfw)
find_package(glfw3 CONFIG REQUIRED)
set(HUNTER_LIBS ${HUNTER_LIBS} glfw)

hunter_add_package(glm)
find_package(glm CONFIG REQUIRED)
set(HUNTER_LIBS ${HUNTER_LIBS} glm)

hunter_add_package(PNG)
find_package(PNG CONFIG REQUIRED)
set(HUNTER_LIBS ${HUNTER_LIBS} PNG::png)

hunter_add_package(enet)
find_package(enet CONFIG REQUIRED)
set(HUNTER_LIBS ${HUNTER_LIBS} enet::enet)

hunter_add_package(ZLIB)
find_package(ZLIB CONFIG REQUIRED)
set(HUNTER_LIBS ${HUNTER_LIBS} ZLIB::zlib)

hunter_add_package(stormlib)
find_package(stormlib CONFIG REQUIRED)
set(HUNTER_LIBS ${HUNTER_LIBS} stormlib::stormlib)

# hunter_add_package(Boost COMPONENTS filesystem system program_options date_time regex)
# find_package(Boost CONFIG REQUIRED  filesystem system program_options date_time regex)
# set(HUNTER_BOOST_LIBS Boost::filesystem Boost::system Boost::program_options Boost::date_time Boost::regex)
# set(HUNTER_LIBS ${HUNTER_LIBS} ${HUNTER_BOOST_LIBS})

Find_Package(OpenGL REQUIRED)

set(DEVILUTION_COMPILER_FLAGS "")

# Use C++11
# if (CMAKE_VERSION VERSION_LESS "3.1")
#     if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
#         set (CMAKE_CXX_FLAGS "--std=gnu++17 ${CMAKE_CXX_FLAGS}")
#     endif ()
# else ()
set (CMAKE_CXX_STANDARD 17)
# endif ()
if(WIN32)
    add_definitions(-DNOMINMAX) # http://stackoverflow.com/questions/5004858/stdmin-gives-error
endif()

option (FA_TREAT_WARNINGS_AS_ERRORS "Treat warnings as errors")

if(UNIX)
    set(DEVILUTION_COMPILER_FLAGS "${DEVILUTION_COMPILER_FLAGS} -Wall -pedantic -Wextra -Wno-unknown-pragmas -Wno-missing-braces")
    SET(CMAKE_INCLUDE_SYSTEM_FLAG_CXX "-isystem ")
    if (FA_TREAT_WARNINGS_AS_ERRORS)
        set(DEVILUTION_COMPILER_FLAGS "${DEVILUTION_COMPILER_FLAGS} -Werror")
    endif()
endif()

if(MSVC)
    set(DEVILUTION_COMPILER_FLAGS "${DEVILUTION_COMPILER_FLAGS} /MP /W4 /D_CRT_SECURE_NO_WARNINGS /wd4244 /wd4100 /wd4611 /wd4458 /wd4459 /wd4127 /wd4800 /wd4267 /wd4172")
    # 4244 - e.g. 'argument': conversion from 'const long double' to 'double' -- boost headers
    # 4100 - unreferenced formal parameter -- boost headers
    # 4172 - boost headers
    # 4611 - interaction between '_setjmp' and C++ object destruction is non-portable -- savepng.cpp
    # 4458 - shadow for class member -- librocket headers
    # 4459 - declaration of 'self' hides global declaration
    # 4127 - conditional expression is constant, could be useful to check that both branches compilable.
    # 4267 -  conversion from 'size_t' to 'int', possible loss of data -- too many such warnings in 64-bit build currently
    # 4800 - forcing value to bool, stupid warning
    set(DEVILUTION_COMPILER_FLAGS "${DEVILUTION_COMPILER_FLAGS} /w44062")
    # 4061 - not all enumerator values are handled by the switch statement
    add_definitions (-D_SCL_SECURE_NO_WARNINGS -D_CRT_SECURE_NO_WARNINGS )
    # SCL - because current boost is too old and emits this warning
    # CRT - something in nuklear.h
    if (FA_TREAT_WARNINGS_AS_ERRORS)
        set(DEVILUTION_COMPILER_FLAGS "${DEVILUTION_COMPILER_FLAGS} /WX")
    endif()
endif()

#TODO: get rid of this?
include_directories("${PROJECT_SOURCE_DIR}/components/")

# allow the user to specify extra include dirs and defines on the command line
if(CLI_INCLUDE_DIRS)
    include_directories(${CLI_INCLUDE_DIRS})
endif()
if(CLI_DEFINES)
    add_definitions(${CLI_DEFINES})
endif()


# add_subdirectory (extern)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

add_subdirectory(src/diablo)
add_subdirectory(src/imgui)
