# This CMake file is intended to register project-wide objects.
# This allows for reuse between deployments, or other projects.

add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/Components")
<<<<<<< HEAD
#add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/TestDeployment/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/Libs/")
#add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/CameraDeployment/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/CameraMLDeployment/")
=======
# add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/TestDeployment/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/Libs/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/CameraDeployment/")
>>>>>>> 94fd148 (Python working with CameraDeployment)
