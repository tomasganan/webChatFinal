# add_subdirectory(iniparser)

add_library(iniparser
  iniparser/src/dictionary.c
  iniparser/src/iniparser.c)

target_include_directories(iniparser PUBLIC ./iniparser/src/)

target_link_libraries(iniparser PRIVATE)

install(
  TARGETS iniparser
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib)
