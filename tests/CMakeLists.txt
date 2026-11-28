include(FetchContent)

FetchContent_Declare(gtest
	GIT_REPOSITORY https://github.com/google/googletest
	GIT_TAG v1.16.0
	GIT_SHALLOW TRUE
)

FetchContent_MakeAvailable(gtest)

function (add_unit_test ut_name)
	set(flags "")
	set(oneValueArg "")
	set(multipleValuesArgs SOURCES DEPENDENCIES)

	cmake_parse_arguments(ARG_UT 
		"${flags}"
		"${oneValueArg}"
		"${multipleValuesArgs}"
		${ARGN}
	)

	add_executable(${ut_name})

	target_sources(${ut_name} PRIVATE
		${ARG_UT_SOURCES}
	)

	target_link_libraries(${ut_name}
		PRIVATE
		${ARG_UT_DEPENDENCIES}
	)

	add_test(NAME ${ut_name} COMMAND $<TARGET_FILE:${ut_name}>)

	set_target_properties(${test_name}
		PROPERTIES DEBUG_POSTFIX _d
		RUNTIME_OUTPUT_DIRECTORY ${BIN_OUTPUT_DIR}/tests
	)

endfunction()

add_subdirectory(factorial_test)