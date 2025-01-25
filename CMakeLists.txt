cmake_minimum_required(VERSION 3.23)
project(tests_sound_processor)

set(CMAKE_CXX_STANDART 14)

add_executable(tests_sound_processor tests/wav_parser_test.cpp tests/condition_keeper_test.cpp tests/config_parser_test.cpp)

add_compile_options(-fno-elide-constructors)

add_subdirectory(app/wav_parser)
add_subdirectory(app/exceptions)
add_subdirectory(app/config_parser)

target_include_directories(tests_sound_processor PRIVATE app/wav_parser app/exceptions app/config_parser)

include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/58d77fa8070e8cec2dc1ed015d66b454c8d78850.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

target_link_libraries(tests_sound_processor PRIVATE wav_parser_lib gtest_main exceptions_lib config_parser_lib)