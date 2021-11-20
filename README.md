# dux

[*dux*](https://mandelbrot.dk/delta/dux) is a free, open-source and portable general-purpose library for the C++ programming language.

It is intended as a modular, morden and stable replacement for the C++ standard library and other major libraries *(such as Boost)*. In the *features* section a list of fascilities included in this library is available.

## Genesis

*note: This section is outdated.*

dux started out in 2019 as a small, useless library under the name *duckGFX*. This library was capable of two things: opening windows, followed by closing them, both achieved using an Xlib back-end.

Progress stagnated following. The project was renamed to *duckFX*, and later to *dfx*, but during this time almost no development occured.

In March of 2020, dfx saw a significant rework. The library was renamed yet again, this time to *duX*. XLib was dropped in favour of XCB *(where possible)*, and Wayland support was planned, but didn't become of much.

In early April of 2020, duX was no longer a single-header header-only library. As a result of this, a build-system was logical, and so CMake was chosen. At the same time, support for Wayland was completely dropped.

In late April and early May of 2020, Wayland support slowly crawled back. macOS support was considered, but also very quickly dropped, as I had no way to debug it.

Later the same year, in an attempt of rebranding, the project was renamed to *duxXYZ*. It was actually planned to become a 3D-graphics engine, but development halted quickly. The project remained silent for almost a year from here, before any serious progress was made at least.

When the [*luma*](https://mandelbrot.dk/delta/luma) programming-language was started in the early 2021, duxXYZ was decided to become a part of the standard-library. Some development was made, but the adoption was ultimately repealed.

In the end of May of 2021, following the creation of the [*dux*](https://mandelbrot.dk/delta/dux) library, development returned again. All code from *duxXYZ* was rewritten from C++ to C, as the latter was my programming language of choice. The project as a whole was for the last time renamed, this time to *dux*. Contrary to what I once slated, Cocoa (replacing Quartz) and WinAPI was formally planned, however without a static date. An extension to this was the disposition that dux would also provide an interface for graphics rendering, with DirectX, Metal, OpenGL, and Vulkan back-ends all being planned, still without a static date. Wayland was also a top-priority.

In the beginning of this same month of May, *u8c* – a library for encoding and decoding UTF-8 messages in the C programming language – was started. This project evolved a lot, later offering replacemnts for the character classifications fascilities in the C standard library with support for Unicode characters.

After a few months, u8c was rewritten in C++. This new edition also offered compile-time *(constexpr)* replacements for some of the members of the C standard library, including the maths library and the string manipulation library.

As a reaction to the massive bloat of some C++ standard library implementations, u8c also had replacements for a lot of the C++ standard template library.

In October of 2021, progress on dux resumed. This was partly thanks to the maturity of u8c, as it [u8c] could now be used in other projects. Support for multithreading also started at this time.

In the same month, dux and u8c underwent a merge. This was planned for some time, but was not executed, as u8c was supposed to be as portable as possible. dux was not as portable. To combat this, the new merged library was made modular. End-users could specify what modules to be build, allowing for the same level of portability.

## Features

TBA

## Examples

TBA

## Installing

TBA

## Compiling

dux has been tested to work with Clang 14. A compiler conforming to the C++2b standard is required.

You may also directly install the header files (in `/include`) in case your system is not supported or you do not need the extra facilities.

1. Checkout dux using `git`:

    * Clone the repository: `git clone https://mandelbrot.dk/delta/dux.git`
    * Or do a shallow cone: `git clone --depth 1 https://mandelbrot.dk/delta/dux.git`

2. Configure the compilation of dux:

	* `cd dux`
	* `cmake -B build`

		You can append the following options to the command:

		* `-DCMAKE_BUILD_TYPE` — Set the build type. Can be either `Debug`or `Release`.

3. Build dux build

	* `cmake --build build`

## Contributing

dux does currently not accept **any** merge requests.

## Copyright & License

Copyright 2021 Gabriel Jensen

This file is part of dux.

dux is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

dux is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.

You should have received a copy of the GNU Affero General Public License along with dux. If not, see <https://www.gnu.org/licenses/>.