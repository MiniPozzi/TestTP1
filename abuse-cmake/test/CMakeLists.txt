add_executable(abuse-test
    abuse-test.cpp
    catch.hpp
)

target_link_libraries(abuse-test
    PRIVATE 
        imlib
        abuselib
)

install(TARGETS abuse-test RUNTIME DESTINATION bin)