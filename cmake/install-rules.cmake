install(
    TARGETS MonteCarloPiEstimator_exe
    RUNTIME COMPONENT MonteCarloPiEstimator_Runtime
)

if(PROJECT_IS_TOP_LEVEL)
  include(CPack)
endif()
