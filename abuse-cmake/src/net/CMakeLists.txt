add_library(netlib
    fileman.cpp
    fileman.h
    gclient.cpp
    gclient.h
    ghandler.h
    gserver.cpp
    gserver.h
    sock.cpp
    sock.h
    tcpip.cpp
    tcpip.h
    undrv.h
    )

target_compile_definitions(netlib 
    PUBLIC
        HAVE_NETINET_IN_H
)

target_include_directories(netlib
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

target_link_libraries(netlib
    PRIVATE
        abuselib
        imlib
        sdlportlib
)