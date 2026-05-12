cmake_minimum_required(VERSION 3.14)

include(cmake/prelude.cmake)

project(
    MonteCarloPiEstimator
    VERSION 0.1.0
    DESCRIPTION "Short description"
    HOMEPAGE_URL "https://example.com/"
    LANGUAGES CXX
)

include(cmake/project-is-top-level.cmake)
include(cmake/variables.cmake)

# ---- Declare library ----

add_library(
    MonteCarloPiEstimator_lib OBJECT
    source/lib.cpp
)

target_include_directories(
    MonteCarloPiEstimator_lib ${warning_guard}
    PUBLIC
    "\$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/source>"
)

target_compile_features(MonteCarloPiEstimator_lib PUBLIC cxx_std_17)

# ---- Declare executable ----

add_executable(MonteCarloPiEstimator_exe source/main.cpp)
add_executable(MonteCarloPiEstimator::exe ALIAS MonteCarloPiEstimator_exe)

set_property(TARGET MonteCarloPiEstimator_exe PROPERTY OUTPUT_NAME MonteCarloPiEstimator)

target_compile_features(MonteCarloPiEstimator_exe PRIVATE cxx_std_17)

target_link_libraries(MonteCarloPiEstimator_exe PRIVATE MonteCarloPiEstimator_lib)

# ---- Install rules ----

if(NOT CMAKE_SKIP_INSTALL_RULES)
  include(cmake/install-rules.cmake)
endif()

# ---- Developer mode ----

if(NOT MonteCarloPiEstimator_DEVELOPER_MODE)
  return()
elseif(NOT PROJECT_IS_TOP_LEVEL)
  message(
      AUTHOR_WARNING
      "Developer mode is intended for developers of MonteCarloPiEstimator"
  )
endif()

include(cmake/dev-mode.cmake)
