cmake_minimum_required(VERSION 3.12)
project(abuseIGL601
    VERSION 0.3
    LANGUAGES C CXX
    DESCRIPTION "Abuse video game project")

include(ExternalProject)
include(GNUInstallDirs)

find_package(Threads REQUIRED)

set(EXTERNAL_DIR ${CMAKE_BINARY_DIR}/external)
set(EXTERNAL_SRC ${EXTERNAL_DIR}/src)

ExternalProject_Add(external_sdl
    PREFIX ${EXTERNAL_DIR}
    URL "https://www.libsdl.org/release/SDL-1.2.15.tar.gz"
    URL_HASH SHA256=d6d316a793e5e348155f0dd93b979798933fb98aa1edebcc108829d6474aad00
    CONFIGURE_COMMAND ${EXTERNAL_SRC}/external_sdl/./configure --prefix=${EXTERNAL_DIR}
    COMMAND sed -i "/_XData32/s:register long:register _Xconst long:" ${EXTERNAL_SRC}/external_sdl/src/video/x11/SDL_x11sym.h 
    BUILD_COMMAND make
)

ExternalProject_Add(external_sdl_mixer
    DEPENDS external_sdl
    PREFIX ${EXTERNAL_DIR}
    URL "https://www.libsdl.org/projects/SDL_mixer/release/SDL_mixer-1.2.12.tar.gz"
    URL_HASH SHA256=1644308279a975799049e4826af2cfc787cad2abb11aa14562e402521f86992a
    CONFIGURE_COMMAND ${EXTERNAL_SRC}/external_sdl_mixer/./configure --prefix=${EXTERNAL_DIR}
    BUILD_COMMAND make
)

function(ExternalLibAdd externalProjectName libName)
    set_target_properties(${externalProjectName} PROPERTIES EXCLUDE_FROM_ALL TRUE)
    set(EXTERNAL_LIB lib${externalProjectName})

    ExternalProject_Get_Property(${externalProjectName} INSTALL_DIR)
    set(SDL_INSTALL_DIR ${INSTALL_DIR})
    add_library(${EXTERNAL_LIB} STATIC IMPORTED)
    set_property(TARGET ${EXTERNAL_LIB} PROPERTY IMPORTED_LOCATION ${SDL_INSTALL_DIR}/lib/lib${libName}.a)
    add_dependencies(${EXTERNAL_LIB} ${externalProjectName})
    include_directories(${SDL_INSTALL_DIR}/include/SDL)

    target_link_libraries(${EXTERNAL_LIB}
        INTERFACE
            ${ARGN}
    )
endfunction(ExternalLibAdd)

ExternalLibAdd(external_sdl SDL ${CMAKE_THREAD_LIBS_INIT} ${CMAKE_DL_LIBS})
ExternalLibAdd(external_sdl_mixer SDL_mixer libexternal_sdl)

set(ASSETS_DIR ${CMAKE_INSTALL_PREFIX}/share/games/abuse)

add_subdirectory(src)
add_subdirectory(data)
add_subdirectory(doc)
add_subdirectory(test)
