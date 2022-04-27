cmake_minimum_required(
	VERSION
	3.19
)

# Language Standards:
set(
	CMAKE_C_STANDARD
	11
)
set(
	CMAKE_C_STANDARD_REQUIRED
	TRUE
)
set(
	CMAKE_CXX_STANDARD
	20
)
set(
	CMAKE_CXX_STANDARD_REQUIRED
	TRUE
)

# Project:
project(
	dux-demo
	LANGUAGES
	C
	CXX
	VERSION
	${DUX_VERSION}
)

# Target:
add_executable(
	dux-demo
	"ctest.c"
	"main.cc"
)

# Dependencies:
target_link_libraries(
	dux-demo
	dux
)