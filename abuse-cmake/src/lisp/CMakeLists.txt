add_library(lisplib
    lisp.cpp
    lisp.h
    lisp_gc.cpp
    lisp_gc.h
    lisp_opt.cpp
    lisp_opt.h
    stack.h
    symbols.h
    trig.cpp
    )

target_include_directories(lisplib
PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

target_link_libraries(lisplib
    abuselib
    imlib
)