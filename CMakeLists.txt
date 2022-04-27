cmake_minimum_required(
	VERSION
	3.19
)

# Project:
project(
	dux
)

# Constants:
set(
	DUX_VERSION
	30.0
)

# Subdirectories
add_subdirectory(
	"dux"
)
if(
	DUX_ENABLE_DEMO
)
	add_subdirectory(
		"dux-demo"
	)
endif()
