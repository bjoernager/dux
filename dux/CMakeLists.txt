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
	dux
	DESCRIPTION
	"General purpose library."
	HOMEPAGE_URL
	"https://mandelbrot.dk/dux/about/"
	LANGUAGES
	C
	CXX
	ASM # CMake recommends placing assembly as the last entry in the list of languages.
	VERSION
	${DUX_VERSION}
)

# Target:
add_library(
	dux
	SHARED
	"src/priv/posix/clock_gettime.c"
	"src/priv/posix/close.c"
	"src/priv/posix/fsync.c"
	"src/priv/posix/getpid.c"
	"src/priv/posix/getrandom.c"
	"src/priv/posix/kill.c"
	"src/priv/posix/mmap.c"
	"src/priv/posix/nanosleep.c"
	"src/priv/posix/openat.c"
	"src/priv/posix/read.c"
	"src/priv/posix/sigaction.c"
	"src/priv/posix/write.c"
	"src/priv/alloc.cc"
	"src/priv/assfail.c"
	"src/priv/cpy.c"
	"src/priv/curerrcd.c"
	"src/priv/dbglog.c"
	"src/priv/dbgunreach.c"
	"src/priv/dup.c"
	"src/priv/fill.c"
	"src/priv/free.cc"
	"src/priv/geterrnoptr.c"
	"src/priv/logstderr.c"
	"src/priv/nomedia.c"
	"src/priv/plot.c"
	"src/priv/start.cc"
	"src/priv/syscall.S"
	"src/abrt.cc"
	"src/alloc.cc"
	"src/crtfile.cc"
	"src/errcdnm.cc"
	"src/exit.cc"
	"src/file.cc"
	"src/fndchr.cc"
	"src/free.cc"
	"src/freernd.cc"
	"src/getallocsz.cc"
	"src/getenv.cc"
	"src/getmainparam.cc"
	"src/getnummainparams.cc"
	"src/gettime.cc"
	"src/ismainthrd.cc"
	"src/mainparams.cc"
	"src/memeq.cc"
	"src/onexit.cc"
	"src/raise.cc"
	"src/realloc.cc"
	"src/rnd.cc"
	"src/setsighandl.cc"
	"src/sleep.cc"
	"src/strcmp.cc"
	"src/strcpy.cc"
	"src/strdup.cc"
	"src/streq.cc"
	"src/strlen.cc"
	"src/trap.cc"
)

# Compiler Settings:
target_compile_options(
	dux
	PRIVATE
	-Wfatal-errors
	-Wall
	-Wconversion
	-Werror
	-Wextra
	-Wunreachable-code
	-Wunused
	-fdiagnostics-color=always
	-g
	-pedantic-errors
	$<$<STREQUAL:${CMAKE_BUILD_TYPE},Debug>:-Og>
	$<$<STREQUAL:${CMAKE_BUILD_TYPE},Release>:-O3>
	$<$<COMPILE_LANGUAGE:C,CXX>:-Wmissing-declarations>
	$<$<COMPILE_LANGUAGE:C>:-Wmissing-prototypes>
	$<$<OR:$<COMPILE_LANG_AND_ID:C,Clang>,$<COMPILE_LANG_AND_ID:CXX,Clang>>:-Wnewline-eof>
	$<$<COMPILE_LANGUAGE:Fortran>:-Wno-compare-reals>
)

# Include Directories:
target_include_directories(
	dux
	PUBLIC
	"include"
)
target_include_directories(
	dux
	PRIVATE
	"include-priv"
)

# Macro Definitions:
if(
	DUX_DISABLE_MEDIA
)
	target_compile_definitions(
		dux
		PRIVATE
		dux_priv_dis_media
	)
endif()
