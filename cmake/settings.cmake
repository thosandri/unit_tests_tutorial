add_library(compiler_flags INTERFACE)

target_compile_options(compiler_flags INTERFACE
	$<$<CXX_COMPILER_ID:MSVC>:/W4 /MP>
	$<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>>:-Wall -Wextra -Wpedantic>
)

target_compile_options(compiler_flags INTERFACE
	$<$<AND:$<CXX_COMPILER_ID:MSVC>,$<BOOL:${WARNINGS_AS_ERROR}>>:/WX>
	$<$<AND:$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>>,$<BOOL:${WARNINGS_AS_ERROR}>>:-Werror>
)

add_library(cxx_standard INTERFACE)

target_compile_features(cxx_standard INTERFACE
	cxx_std_20
)

if (NOT CMAKE_CONFIGURATION_TYPES)
	set(BIN_OUTPUT_DIR ${CMAKE_BINARY_DIR}/bin)
	set(LIB_OUTPUT_DIR ${CMAKE_BINARY_DIR}/lib)
else()
	set(BIN_OUTPUT_DIR ${CMAKE_BINARY_DIR}/$<CONFIG>/bin)
	set(LIB_OUTPUT_DIR ${CMAKE_BINARY_DIR}/$<CONFIG>/lib)
endif()