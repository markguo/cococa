collectlib_DIR=$(top_builddir)/Library/Linux
collectbin_DIR=$(top_builddir)/Binary

#collectlib_DIR_CONTENTS=
#collectbin_DIR_CONTENTS=

collectLIBRARIES=$(lib_LIBRARIES) $(pkglib_LIBRARIES)
collectPROGRAMS=$(bin_PROGRAMS) $(sbin_PROGRAM) $(pkglib_PROGRAMS) $(libexec_PROGRAMS)

AM_LDFLAGS+=-L$(collectlib_DIR)

all-local:	collectlib-local collectbin-local

collectlib-local: $(addprefix $(collectlib_DIR)/, $(collectLIBRARIES) $(collectLTLIBRARIES))
collectbin-local: $(addprefix $(collectbin_DIR)/, $(collectPROGRAMS))

$(collectlib_DIR)/%.a: %.a
	mkdir -p $(collectlib_DIR)
	ln -sf --target-directory=$(collectlib_DIR)/ $(addprefix $(CURDIR)/, $<)

$(collectbin_DIR)/%: %
	mkdir -p $(collectbin_DIR)
	ln -sf --target-directory=$(collectbin_DIR)/ $(addprefix $(CURDIR)/, $<)

MOSTLYCLEANFILES+=$(foreach t, $(collectLIBRARIES), $(collectlib_DIR)/$(t))
MOSTLYCLEANFILES+=$(foreach t, $(collectPROGRAMS), $(collectlib_DIR)/$(t))

#UILT_SOURCES+=$(collectlib_DIR) $(collectbin_DIR)

.PHONY: mkdir-collect

all: mkdir-collect

mkdir-collect: $(collectlib_DIR) $(collectbin_DIR)

$(collectlib_DIR) $(collectbin_DIR):
	mkdir -p $@

