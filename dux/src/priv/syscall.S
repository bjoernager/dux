/*
	Copyright 2021, 2022 Gabriel Jensen.

	This file is part of dux.

	dux is free software: you can redistribute it and/or modify it under the
	terms of the GNU Affero General Public License as published by the Free
	Software Foundation, either version 3 of the License, or (at your
	option) any later version.

	dux is distributed in the hope that it will be useful, but WITHOUT ANY
	WARRANTY; without even the implied warranty of MERCHANTABILITY or
	FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public
	License for more details.

	You should have received a copy of the GNU Affero General Public License
	along with dux. If not, see <https://www.gnu.org/licenses/>.
*/

# include <dux/sysinfo.h>

.globl dux_priv_syscall

dux_priv_syscall:
# if defined(dux_arch_arm)
# if dux_wrdsz == 0x40
    mov w8,w0
    mov x0,x1
    mov x1,x2
    mov x2,x3
    mov x3,x4
    mov x4,x5
    mov x5,x6
    svc #0
    ret
# endif
# elif defined(dux_arch_x86)
# if dux_wrdsz == 0x40
    .intel_syntax noprefix
    mov rax,rdi /* Move first parameter (the syscall id) to rax. */
    mov rdi,rsi /* Shift all parameters. */
    mov rsi,rdx
    mov rdx,rcx
    mov r10,r8 /* Syscalls use r10 instead of rcx. */
    mov r8,r9
    mov r9,[rsp - 0x8] /* Extract the sixth argument from the stack. */
    syscall /* Slime incident */
    ret
# endif
# endif
