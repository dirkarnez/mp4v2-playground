cmake_minimum_required(VERSION 3.14)

project(mp4v2-playground)

add_compile_definitions(MP4V2_EXPORTS)
add_compile_definitions(MP4V2_USE_STATIC_LIB)

add_library(mp4v2 STATIC IMPORTED)

set_property(
  TARGET mp4v2 APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE
)

set_target_properties(mp4v2 PROPERTIES
  IMPORTED_LOCATION_RELEASE "${mp4v2_ROOT}/lib/libmp4v2.a"
)
  
set_target_properties(mp4v2 PROPERTIES
  MAP_IMPORTED_CONFIG_MINSIZEREL Release
  MAP_IMPORTED_CONFIG_RELWITHDEBINFO Release
)

message(STATUS "${mp4v2_ROOT}")
target_include_directories(mp4v2 INTERFACE "${mp4v2_ROOT}/include")







add_library(x264 STATIC IMPORTED)

set_property(
  TARGET x264 APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE
)

set_target_properties(x264 PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${X264_ROOT}/lib/libx264.a"
)
  
set_target_properties(x264 PROPERTIES
  MAP_IMPORTED_CONFIG_MINSIZEREL Release
  MAP_IMPORTED_CONFIG_RELWITHDEBINFO Release
)

target_include_directories(x264 INTERFACE "${X264_ROOT}/include")



SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")

add_executable(${PROJECT_NAME}
    "src/main.v2.cpp"
)

target_link_libraries(${PROJECT_NAME} mp4v2 x264)
