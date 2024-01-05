
# YACSWL library
file (GLOB YACSWL_SOURCE_FILES "src/*.c")
add_library(yacswl STATIC 
    ${YACSWL_SOURCE_FILES}
)
target_include_directories(yacswl PUBLIC ${CMAKE_CURRENT_LIST_DIR}/inc)
target_link_libraries(yacswl PUBLIC yacsgl)
