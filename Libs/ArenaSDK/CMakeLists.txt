# add_library(Camera RunLucidCamera.cpp)
# add_subdirectory(Camera)
# target_link_libraries(FPrime PUBLIC Camera)

set(MODULE_NAME Libs_ArenaSDK)

add_library(${MODULE_NAME} INTERFACE)
# add_executable(camera ${PROJECT_SOURCE_DIR}/Components/RunLucidCamera/RunLucidCamera.cpp)
target_include_directories(${MODULE_NAME} INTERFACE
	${CMAKE_CURRENT_LIST_DIR}/include/Arena
	${CMAKE_CURRENT_LIST_DIR}/GenICam/library/CPP/include
	${CMAKE_CURRENT_LIST_DIR}/include/Save
	${CMAKE_CURRENT_LIST_DIR}/include/GenTL
	)

target_link_libraries(${MODULE_NAME} INTERFACE
    # Your existing libraries
    Components_RunLucidCamera
    
    # Arena SDK libraries - provide full paths to .so or .a files
    ${CMAKE_CURRENT_LIST_DIR}/lib/libarena.so          # Core Arena library
    ${CMAKE_CURRENT_LIST_DIR}/lib/libsavec.so          # Save functionality
    ${CMAKE_CURRENT_LIST_DIR}/lib/libgentl.so          # GenTL functionality
    ${CMAKE_CURRENT_LIST_DIR}/lib/liblucidlog.so       # Lucid logging
	${CMAKE_CURRENT_LIST_DIR}/lib/libsave.so
	${CMAKE_CURRENT_LIST_DIR}/lib/libarenac.so

	${CMAKE_CURRENT_LIST_DIR}/ffmpeg/libavcodec.so
	${CMAKE_CURRENT_LIST_DIR}/ffmpeg/libavformat.so
	${CMAKE_CURRENT_LIST_DIR}/ffmpeg/libavutil.so
	${CMAKE_CURRENT_LIST_DIR}/ffmpeg/libswresample.so


    # GenICam libraries
    ${CMAKE_CURRENT_LIST_DIR}/GenICam/library/lib/Linux64_ARM/libGenApi_gcc54_v3_3_LUCID.so
    ${CMAKE_CURRENT_LIST_DIR}/GenICam/library/lib/Linux64_ARM/libGCBase_gcc54_v3_3_LUCID.so
    ${CMAKE_CURRENT_LIST_DIR}/GenICam/library/lib/Linux64_ARM/libMathParser_gcc54_v3_3_LUCID.so
    ${CMAKE_CURRENT_LIST_DIR}/GenICam/library/lib/Linux64_ARM/liblog4cpp_gcc54_v3_3_LUCID.so
    ${CMAKE_CURRENT_LIST_DIR}/GenICam/library/lib/Linux64_ARM/libLog_gcc54_v3_3_LUCID.so
    ${CMAKE_CURRENT_LIST_DIR}/GenICam/library/lib/Linux64_ARM/libNodeMapData_gcc54_v3_3_LUCID.so
    ${CMAKE_CURRENT_LIST_DIR}/GenICam/library/lib/Linux64_ARM/libXmlParser_gcc54_v3_3_LUCID.so
)
# add_executable(runlucidcamera 
# 	${PROJECT_SOURCE_DIR}/Components/RunLucidCamera/RunLucidCamera.cpp
# 	)
# target_sources(runlucidcamera PRIVATE ${PROJECT_SOURCE_DIR}/Components/RunLucidCamera/RunLucidCamera.cpp)
# target_link_libraries(runlucidcamera PRIVATE ${MODULE_NAME})

# find_library(ARENASDK Arena_SDK "/Libs/ArenaSDK")
# add_library(Arena_SDK SHARED IMPORTED GLOBAL)
# set_property(TARGET Arena_SDK PROPERTY IMPORTED_LOCATION ${ARENASDK})

# include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/Arena)