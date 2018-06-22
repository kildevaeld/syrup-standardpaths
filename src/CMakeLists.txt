
set(SOURCES
    standardpaths.c
    features.c
)

if (APPLE)
    set(SOURCES ${SOURCES} standardpaths.m)
    set(LIBS ${LIBS} "-framework Foundation -framework Cocoa")
endif(APPLE)

add_library(syrup-standardpaths ${SOUCRES})
target_link_libraries(syrup-standardpaths ${LIBS})
target_include_directories(syryp-standardpaths PUBLIC ${PROJECT_SOURCE_DIR}/include)