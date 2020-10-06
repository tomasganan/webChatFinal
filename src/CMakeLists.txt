set(RELEASE_BUILD_FLAGS "-Wall -Wextra")

set(RELEASE_EXTRA_LIBS ${RELEASE_EXTRA_LIBS})
# RELEASE link flags
# set(RELEASE_LINK_FLAGS "-pthread")

# Add packages here:
execute_process(COMMAND mysql_config --cflags
    OUTPUT_VARIABLE MYSQL_CFLAGS OUTPUT_STRIP_TRAILING_WHITESPACE)
execute_process(COMMAND mysql_config --libs
    OUTPUT_VARIABLE MYSQL_LIBS OUTPUT_STRIP_TRAILING_WHITESPACE)


# List all the sources files for compile
FILE(GLOB RELEASE_SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.c)
# Include the directory with the headers files
# Set the where the binary must be generated
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

# This flags is defined on the parent CMakeLists.txt. The first one are for
# build and the seconds for link
add_definitions(${RELEASE_BUILD_FLAGS})
set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${RELEASE_LINK_FLAGS}" )
# Generate the binary file with the same name of the project and all the sources
# files
add_executable(${PROJECT_NAME} ${RELEASE_SOURCE_FILES})
# Link all the libraries (If there are any)
target_link_libraries(${PROJECT_NAME} ${RELEASE_EXTRA_LIBS} ${MYSQL_LIBS})
target_compile_options(${PROJECT_NAME} PUBLIC ${MYSQL_CFLAGS})
