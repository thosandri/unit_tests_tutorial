add_library(employees_management STATIC)

target_sources(employees_management
	PRIVATE
	src/employee.cpp
	src/employeeTable.cpp
)

target_include_directories(employees_management
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

set_target_properties(employees_management
	PROPERTIES
	DEBUG_POSTFIX _d
	ARCHIVE_OUTPUT_DIRECTORY ${LIB_OUTPUT_DIR}
)