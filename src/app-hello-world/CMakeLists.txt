add_executable(app_hello)

target_sources(app_hello PRIVATE
	src/main.cpp
)

target_link_libraries(app_hello PRIVATE
	compiler_flags cxx_standard
)

set_target_properties(app_hello PROPERTIES
	DEBUG_POSTFIX _d
	RUNTIME_OUTPUT_DIRECTORY ${BIN_OUTPUT_DIR}
)