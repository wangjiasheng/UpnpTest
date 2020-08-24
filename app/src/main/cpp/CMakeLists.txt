cmake_minimum_required(VERSION 3.4.1)
SET(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -fPIC")
SET(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -fPIC")
include_directories(${PROJECT_SOURCE_DIR}/../include)

add_library(libavcodec STATIC IMPORTED)
set_target_properties(libavcodec PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/../jniLibs/${ANDROID_ABI}/libavcodec.a)

add_library(libavdevice STATIC IMPORTED)
set_target_properties(libavdevice PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/../jniLibs/${ANDROID_ABI}/libavdevice.a)

add_library(libavfilter STATIC IMPORTED)
set_target_properties(libavfilter PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/../jniLibs/${ANDROID_ABI}/libavfilter.a)

add_library(libavformat STATIC IMPORTED)
set_target_properties(libavformat PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/../jniLibs/${ANDROID_ABI}/libavformat.a)

add_library(libavutil STATIC IMPORTED)
set_target_properties(libavutil PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/../jniLibs/${ANDROID_ABI}/libavutil.a)

add_library(libswresample STATIC IMPORTED)
set_target_properties(libswresample PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/../jniLibs/${ANDROID_ABI}/libswresample.a)

add_library(libswscale STATIC IMPORTED)
set_target_properties(libswscale PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/../jniLibs/${ANDROID_ABI}/libswscale.a)

add_library(libixml STATIC IMPORTED)
set_target_properties(libixml PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/../jniLibs/${ANDROID_ABI}/libixml.a)

add_library(libdlna STATIC IMPORTED)
set_target_properties(libdlna PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/../jniLibs/${ANDROID_ABI}/libdlna.a)

add_library(libupnp STATIC IMPORTED)
set_target_properties(libupnp PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/../jniLibs/${ANDROID_ABI}/libupnp.a)

add_library(native-lib SHARED native-lib.cpp )

find_library(log-lib log )

target_link_libraries(native-lib
        libdlna
        libixml

        libavformat
        libavcodec
        libavdevice
        libavfilter
        libavutil
        libswresample
        libswscale

        -lz
        ${log-lib} )