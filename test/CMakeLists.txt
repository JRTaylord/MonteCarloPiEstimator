# Parent project does not export its library target, so this CML implicitly
# depends on being added from it, i.e. the testing is done only from the build
# tree and is not feasible from an install location

project(MonteCarloPiEstimatorTests LANGUAGES CXX)

# ---- Tests ----

add_executable(MonteCarloPiEstimator_test source/MonteCarloPiEstimator_test.cpp)
target_link_libraries(MonteCarloPiEstimator_test PRIVATE MonteCarloPiEstimator_lib)
target_compile_features(MonteCarloPiEstimator_test PRIVATE cxx_std_17)

add_test(NAME MonteCarloPiEstimator_test COMMAND MonteCarloPiEstimator_test)

# ---- End-of-file commands ----

add_folders(Test)
