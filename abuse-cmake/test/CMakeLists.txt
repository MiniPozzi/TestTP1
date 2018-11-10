add_executable(abuse-test
    abuse-test.cpp
    catch.hpp
    test-lcache.cpp
    test-timer.cpp
    test-matrix.cpp
    test-linked.cpp
)

target_link_libraries(abuse-test
    PRIVATE 
        imlib
        abuselib
)

install(TARGETS abuse-test RUNTIME DESTINATION bin)