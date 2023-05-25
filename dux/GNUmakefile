ifneq "$(dbg)" "true"
dbg := false
endif

OBJS := \
	source/dux/abr.o    \
	source/dux/errmsg.o \
	source/dux/getenv.o \
	                    \
	source/fs/crtdir.o  \
	source/fs/cpy.o     \
	source/fs/curdir.o  \
	source/fs/homdir.o  \
	source/fs/mov.o     \
	source/fs/setprm.o  \
	source/fs/sttpth.o  \
	                    \
	source/io/cls.o     \
	source/io/crt.o     \
	source/io/opn.o     \
	source/io/red.o     \
	source/io/wrt.o

HDRS := \
	include/dux/dux.h             \
	include/dux/io.h              \
	include-private/dux/prv/dux.h

CFLAGS := \
	-D_GNU_SOURCE        \
	-Ddux_prv_dbg=$(dbg) \
	-Iinclude            \
	-Iinclude-private    \
	-Ofast               \
	-Wall                \
	-Wextra              \
	-Wmissing-prototypes \
	-Wpedantic           \
	-fpic                \
	-fshort-enums        \
	-g                   \
	-pipe                \
	-std=c99

LDFLAGS := \
	-shared

LDLIBS := \
	-lzp

LIB = libdux.so

.PHONY: clean install purge

$(LIB): $(OBJS)
	$(CC) $(LDFLAGS) -o$(@) $(OBJS) $(LDLIBS)

$(OBJS): $(HDRS)

install: $(LIB)
	mkdir -pvm755 "$(HDRDIR)/dux"
	mkdir -pvm755 "$(LIBDIR)"
	install -vm644 "include/dux/"{"dux","io","thr"}".h" "$(HDRDIR)/dux"
	install -vm755 "$(LIB)" "$(LIBDIR)"

clean:
	$(RM) $(OBJS)

purge: clean
	$(RM) $(LIB)
