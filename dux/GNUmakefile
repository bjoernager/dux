ifneq "$(dbg)" "true"
dbg := false
endif

OBJS := \
	source/dux/errmsg.o

HDRS := \
	include/dux/dux.h             \
	include/dux/io.h              \
	include/dux/thr.h             \
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
	mkdir -pvm755 "$(HDRDIR)/dux/imp"
	mkdir -pvm755 "$(LIBDIR)"
	install -vm644 "include/dux/"{"bs","fs","io"}{"",".h"} "$(HDRDIR)/dux"
	install -vm644 "include/dux/imp/"{"bs","fs","io"}".ii" "$(HDRDIR)/dux/imp"
	install -vm755 "$(LIB)" "$(LIBDIR)"

clean:
	$(RM) $(OBJS)

purge: clean
	$(RM) $(LIB)
