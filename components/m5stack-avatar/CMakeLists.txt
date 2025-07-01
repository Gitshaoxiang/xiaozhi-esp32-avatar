set(COMPONENT_ADD_INCLUDEDIRS
    src
    )
file(GLOB SRCS
     src/*.cpp
     )
set(COMPONENT_SRCS ${SRCS})

set(COMPONENT_REQUIRES M5GFX M5Unified)

register_component()
