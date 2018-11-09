add_executable(abuse-tool
    abuse-tool.cpp 
)

target_link_libraries(abuse-tool
    PRIVATE 
        imlib 
)

install(TARGETS abuse-tool RUNTIME DESTINATION bin)
