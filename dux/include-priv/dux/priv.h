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

# include <fcntl.h>
# include <signal.h>
# include <sys/mman.h>
# include <sys/types.h>
# include <time.h>
# include <unistd.h>

dux_priv_begincdecls

dux_attr_const int * dux_priv_geterrnoptr(void);
# define dux_priv_errno (*dux_priv_geterrnoptr())

int    dux_priv_posix_clock_gettime(clockid_t               clockid,struct timespec *        tp);
pid_t  dux_priv_posix_getpid(       void);
pid_t  dux_priv_posix_gettid(       void);
int    dux_priv_posix_kill(         pid_t                   pid,    int                      sig);
void * dux_priv_posix_mmap(         void *                  addr,   dux_priv_uwrd            length,  int                prot,  int    flags,int fd,off_t offset);
int    dux_priv_posix_nanosleep(    struct timespec const * req,    struct timespec *        rem);
int    dux_priv_posix_openat(       int                     fd,     char const *             pathname,int                flags, mode_t mode);
int    dux_priv_posix_sigaction(    int                     signum, struct sigaction const * act,     struct sigaction * oldact);

int dux_priv_start(int argc,char const * const * argv);

dux_priv_endcdecls
