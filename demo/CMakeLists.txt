cmake_minimum_required(VERSION 3.10)
project(S600L_client LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

get_filename_component(SDK_ROOT "${CMAKE_CURRENT_LIST_DIR}/../sdk" ABSOLUTE)
set(SDK_INCLUDE_DIR "${SDK_ROOT}/include")

if(WIN32)
    set(SDK_LIBRARY_DIR "${SDK_ROOT}/lib/win/x86")
    set(SPEAKER_INTERFACE_LIB "${SDK_LIBRARY_DIR}/speaker_interface.lib")
    set(SPEAKER_INTERFACE_DLL "${SDK_LIBRARY_DIR}/speaker_interface.dll")
else()
    if(NOT DEFINED SDK_VERSION)
        set(SDK_VERSION "24.04")
    endif()
    set(SDK_LIBRARY_DIR "${SDK_ROOT}/lib/linux/x86/${SDK_VERSION}")
    set(SPEAKER_INTERFACE_LIB "${SDK_LIBRARY_DIR}/libspeaker_interface.so")
endif()

add_executable(S600L_client
    main.cpp
    speaker_utils.cpp
)

target_include_directories(S600L_client PRIVATE
    "${CMAKE_CURRENT_LIST_DIR}"
    "${SDK_INCLUDE_DIR}"
)

target_link_libraries(S600L_client PRIVATE "${SPEAKER_INTERFACE_LIB}")

if(WIN32)
    file(GLOB SDK_RUNTIME_DLLS "${SDK_LIBRARY_DIR}/*.dll")

    add_custom_command(TARGET S600L_client POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${SDK_RUNTIME_DLLS}
            "$<TARGET_FILE_DIR:S600L_client>"
    )
else()
    set_target_properties(S600L_client PROPERTIES
        BUILD_RPATH "$ORIGIN"
    )
    add_custom_command(TARGET S600L_client POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${SPEAKER_INTERFACE_LIB}"
            "$<TARGET_FILE_DIR:S600L_client>"
    )
endif()
