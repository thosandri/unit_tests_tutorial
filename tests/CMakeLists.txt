include(FetchContent)

FetchContent_Declare(gtest
	GIT_REPOSITORY https://github.com/google/googletest
	GIT_TAG v1.16.0
	GIT_SHALLOW TRUE
)

FetchContent_MakeAvailable(gtest)

add_subdirectory(factorial_test)