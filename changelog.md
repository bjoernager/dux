# 22

* Remove documentation (too hight-maintainence).
* Rename `include/u8c/is.h` to `include/u8c/chk.h`
* Revert u8c-9 “Remove some optimisations, as they prevent C++ compatibility.”.
* Fix #1.
* Use binary literals for bitwise operations.
* Add more control characters to `u8c_iscntrl`.
* Change type of result of the `u8c_is`* functions fromt `uint_least8_t` to `bool`.
* Add more characters to `u8c_ispunct`.
* Update Makefile.
* Revert u8c-21 “Rename `u8c_unimax` to `u8c_u32max` and move it to `u8c/u32.h`.”.
* Add function for checking if a character is a surrogate point; `u8c_issurro`.
* Split `u8c_isalpha` into `u8c_islower` and `u8c_isupper`, move current mapping to `u8c_islower`. All characters that are neither upper case or lower case must be put in `u8c_isalpha`.
* Add function for getting the name of an Unicode codepoint; `u8c_uninm` (has currently only mapped around ⅔% of all Unicode characters).
* Revert accidental changes to changelog (please be more careful and observant in the future).
* Delete `u8c_errtyp_maxerrtyp` (in favour of `u8c_errtyp_all`).
* Switch the arguments of `u8c_seterr`.
* Add function for getting the name of the block an Unicode codepoint is located in; `u8c_uniblk` (has currently only mapped around 39% of the Unicode blocks).
* Rename all instances of `u32` to `str`.
* Optimise for size (`-Os` instead of `-O3`).
* Update Readme.
* **MAJOR**: Return a tuple (structures) in all returning functions, otherwise void.
* Add help screen to test program.
* Update Gitignore.
* Restructure test program.
* Add more characters to `u8c_islower`.
* Add more characters to `u8c_isupper`.
* Remove the `runtest` target (just use `make && export LD_LIBRARY_PATH=$PWD && ./test`, which can more easily be modified to pass arguments).
* Add more characters to `u8c_isalpha`.
* Fix incorrect error being set (somewhere, I forgot where).
* Fix `SIZE_C`.

# 21

* Update readme.
* Require C23 (C2x).
* Use GCC (has better C23 support).
* Cleanup UTF-8 decoder and encoder (using binary literals).
* Rename `u8c_unimax` to `u8c_u32max` and move it to `u8c/u32.h`.
* Don't clear last error message on calls to `u8c_geterr`.
* Restructure source files.
* Fix makefile.
* Update test program.

# 20

* Update documentation.
* Optimise `u8c_println`,
* Make `u8c_print`, `u8c_println`, and `u8c_vprint` thread-safe (if thread-safe is not disabled).
* Create base for UTF-16 related functions:
 	* Add function for allocating UTF-16 strings; `u8c_u16alloc`.
	* Add function for deallocating UTF-16 strings; `u8c_u16free`.
* Restructure headers:
	* `u8c/SIZE_C.h`:
		* `SIZE_C`
	* `u8c/err.h`:
		* `u8c_errtyp`
		* `u8c_errhandltyp`
		* `u8c_geterr`
		* `u8c_regerrhandl`
		* `u8c_seterr`
	* `u8c/fmt`:
		* `u8c_dbgprint`
		* `u8c_fmt`
		* `u8c_fmttyp`
		* `u8c_print`
		* `u8c_println`
		* `u8c_setfmt`
		* `u8c_vfmt`
		* `u8c_vprint`
	* `u8c/is.h`:
		* `u8c_isalnum`
		* `u8c_isalpha`
		* `u8c_iscntrl`
		* `u8c_isdigit`
		* `u8c_ispunct`
		* `u8c_isspace`
		* `u8c_isxdigit`
	* `u8c/main.h`:
		* `u8c_dbg`
		* `u8c_abrt`
		* `u8c_end`
		* `u8c_init`
		* `u8c_thrdsafe`
		* `u8c_unimax`
		* `u8c_ver`
	* `u8c/u16.h`:
		* `u8c_u16alloc`
		* `u8c_u16free`
	* `u8c/u32.h`:
		* `u8c_u32alloc`
		* `u8c_u32cat`
		* `u8c_u32cmp`
		* `u8c_u32cp`
		* `u8c_u32fndchr`
		* `u8c_u32fndpat`
		* `u8c_u32free`
		* `u8c_u32ins`
		* `u8c_u32substr`
		* `u8c_u32sz`
	* `u8c/u8.h`:
		* `u8c_u8alloc`
		* `u8c_u8dec`
		* `u8c_u8enc`
		* `u8c_u8free`
* Disable *-Wpadded*.
* Update `SIZE_C`.
* Always use character constants (instead of numerical values).

# 1↋

* Add more codepoints to `u8c_ispunct`.
* Don't use Zstandard for man page compression. Use Gzip.
* Remove Zstandard as a dependency.
* Update gitignore.

# 1↊

* Initialise error handler array.
* Initialise and destroy error handler array mutex.
* Fix Makefile.
* Update gitignore.

# 19

* Fix error when compiling with GCC: *src/u8c/dat.c:22:29: error: initializer element is not constant [-Wpedantic]*.
* Improve error handling:
	* Add enumeration type for error types; `u8c_errtyp`.
	* Add function for registering error handlers; `u8c_regerrhandl` (see `test.c`).
* Add function for inserting UTF-32 strings into UTF-32 strings; `u8c_u32ins`.
* Enable more warnings.
* Add man pages.
* Fix `u8c_u32cat` skipping the last character in `lstr`.
* Remove the `uninstall` target (it was deemed to unsafe).
* Add *Zstandard* as a dependency.

# 18

* Update `.gitignore`.
* Remove core dump.

# 17

* Create new logo.
* Update headers.
* Invert status values.

# 16

* Add function for concatenating UTF-32 strings; `u8c_u32cat`.
* Add functions for allocating UTF-32 and UTF-8 strings; `u8c_u32alloc` and `u8c_u8alloc`.
* Add function for finding a given codepoint in an UTF-32 string; `u8c_u32fndchr`.
* Add function for finding a given pattern (string) in an UTF-32 string; `u8c_u32fndpat`.
* Update `SIZE_C`.
* Add function for aborting; `u8c_abrt`.
* Rename `u8c_debug` to `u8c_dbg`.
* Use `bool` (`_Bool`) for return values instead of `uint_least8_t`.
* Add more format types.
* Fix incorrect unabbreviated names in headers.
* Add another function from `ctypes.h`; `u8c_isxdigit`.
* Use `char32_t` (from `uchar.h`) instead of `uint_least32_t` in UTF-32.
* Use `unsigned char` instead of `uint_least8_t` in UTF-8.
* Move all data into `u8c_dat` (of type `struct u8c_dattyp`).
* Add function for setting the format (base and endian) of `u8c_fmt` and company; `u8c_setfmt`.
* Remove `u8c_txt` in favour of Unicode string literals (much clearer code, but less portable).
* Add function for getting a sub-string of an UTF-32 string; `u8c_u32substr`.
* Don't count the null-terminator in string sizes.
* Add macro for maximum valid Unicode codepoint; `u8c_unimax`.
* Remove `txttolit`.
* Add function for deallocating UTF-8 strings; `u8c_u8free`.
* Turn both `u8c_dbg` and `u8c_thrdsafe` into type `bool` from `uint_least8_t`.
* Add more letters to `u8c_isalpha`.

# 15

* Add missing include directives to `include/u8c/u32free.h` and `include/u8c/u8free.h`.

# 14

* Free error message when `u8c_geterr` is called (after copying, of course).
* Update `u8c_freeu8`.
* Rename `u8c_freeu32` to and `u8c_u32free` and `u8c_freeu8` to `u8c_u8free`.

# 13

* Fix `u8c_txt` in C++.

# 12

* Use `u8c_println` instead of `u8c_print` in `u8c_dbgprint`.

# 11

* Update README.
* Update Makefile.
* Use constant variables more.
* Create macro for creating human-readable UTF-32 strings; `u8c_txt`.
* Add macros for deallocating UTF-32 and UTF-8 strings (use these instead of `free` or `std::free`); `u8c_u32free` and `u8c_u8free`.
* Optimisations.

# 10

* Make `u8c_seterr` public.
* Update logo.

# ↋

* Fix `u8c_ver`.
* Add Turkish letters to `u8c_isalpha`.

# ↊

* Add UTF-32 alternatives to some of the functions from `ctypes.h`; `u8c_isalnum`, `u8c_isalpha`, `u8c_iscntrl`, `u8c_isdigit`, `u8c_isspace`, and `u8c_ispunct`.
* Add assertions.
* Create new logo (move old logo to `u8c_old.svg`).

# 9

* Optimisations.
* Remove some optimisations, as they prevent C++ compatibility.
* Fix memory leak in test program.
* Add function for comparing UTF-32 strings; `u8c_u32cmp`.

# 8

* Optimisations.

# 7

* Optimisations.

# 6

* Remove unneeded include directives.
* Update `SIZE_C` to utilise the C++23 `std::size_t` literal suffix (`uz`).
* Fix include guard in `include/u8c/stat.h`.
* Add more error messages.

# 5

* Add logo (`u8c.svg`).
* Fix UTF-8 decoder.
* Update README.

# 4

* Add link to PKGBUILD in README.

# 3

* Remove `include/u8c.h`.
* Fix minor errors.

# 2

* Move PKGBUILD to seperate project.
* Create a *master* header that includes every other header.
* Create `size_t` constant macro.
* Add colour to text formatting.
* Specify what file to print to in `u8c_print`.
* Add C++ compatibility to headers.
* Add functions for initialising and ending *u8c*.
* Add dedicated function for text formatting (altough not working at the moment); `u8c_fmt`.
* Remove `u8c_free`.
* Improve error handling in the form of error messages (which can be retrieved by the programmer via `u8c_geterr`).
* Split `u8c_print` into two functions: `u8c_print` and `u8c_println`.
* Break the UTF-8 decoder somehow.
* Add compile-time option to be thread-safe (requiring C11 threads if enabled).
* Add function for copying UTF-32; `u8c_u32cp`.
* Add function for getting the size of an UTF-32 array; `u8c_u32sz`.
* Add `va_list` alternatives to `u8c_fmt` and `u8c_print`; `u8c_vfmt` and `u8c_vprint`.
* Add test-program (run via `make runtest`).
* Add program to make human-readable UTF-32 strings machine-readable.
* Turn `u8c_ver` into a compile-time macro.
* Enable more warnings when compiling.
* Add assertions.

# 1

* Fix Makefile compiling *u8c.so* instead of *libu8c.so*.
* Add global variable for version control.

# 0

* Fork from *luma*.
