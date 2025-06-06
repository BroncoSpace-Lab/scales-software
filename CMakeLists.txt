####
# This sets up the build system for the 'PPythonF3' project, including
# components and deployments from project.cmake. In addition, it imports the core F Prime components.
####

cmake_minimum_required(VERSION 3.13)
project(PPythonF3 C CXX)
add_compile_options(-fPIC)


###
# F' Core Setup
# This includes all of the F prime core components, and imports the make-system.
###
include("${CMAKE_CURRENT_LIST_DIR}/fprime/cmake/FPrime.cmake")

# Comment this line out in order to create new deployment or component
register_fprime_target("${CMAKE_SOURCE_DIR}/fprime-python/cmake/target/pybind.cmake")
# NOTE: register custom targets between these two lines

fprime_setup_included_code()
# include("${CMAKE_SOURCE_DIR}/fprime-python/fprime-python.cmake")


# This includes project-wide objects
include("${CMAKE_CURRENT_LIST_DIR}/project.cmake")
