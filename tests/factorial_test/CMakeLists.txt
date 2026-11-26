add_executable(TEST_factorial)

target_sources(TEST_factorial
	PRIVATE
	TEST_factorial.cpp
)

target_link_libraries(TEST_factorial
	PRIVATE
	compiler_flags
	cxx_standard
	GTest::gtest_main
)

set_target_properties(TEST_factorial
	PROPERTIES DEBUG_POSTFIX _d
	RUNTIME_OUTPUT_DIRECTORY ${BIN_OUTPUT_DIR}/tests
)

add_test(NAME TEST_factorial COMMAND $<TARGET_FILE:TEST_factorial>)
