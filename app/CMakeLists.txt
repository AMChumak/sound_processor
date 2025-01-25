cmake_minimum_required(VERSION 3.23)
project(sound_processor)

set(CMAKE_CXX_STANDARD 14)

add_executable(sound_processor sound_processor.cpp)


#выключает copy elision
add_compile_options(-fno-elide-constructors)

add_subdirectory(convertor)
add_subdirectory(config_parser)
add_subdirectory(exceptions)
add_subdirectory(injector)
add_subdirectory(processor)
add_subdirectory(wav_parser)


target_include_directories(sound_processor PUBLIC config_parser convertor injector processor utils wav_parser exceptions)


target_link_libraries(sound_processor PUBLIC config_parser_lib convertor_lib injector_lib processor_lib  wav_parser_lib exceptions_lib)