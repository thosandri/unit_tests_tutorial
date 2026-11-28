add_unit_test(TEST_factorial
	SOURCES 
		TEST_factorial.cpp
	DEPENDENCIES
		compiler_flags 
		cxx_standard 
		GTest::gtest_main
)
