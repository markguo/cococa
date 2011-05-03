include $(top_srcdir)/common.mk

WEBSPIDER_BIN_TOOLS=bin/SiteToDomain  \
		     bin/sohu_spider  \
		     bin/UrlToSite \
		     bin/sitespeed_reader \
		     bin/test_url_transform \
		     bin/url_filter

WEB_DATAMINE_BIN_TOOLS=bin/dbnetget

LOCAL_SCRIPTS_TOOLS=bin/NoSortUniq.pl 
LOCAL_BIN_TOOS=bin/snapshot_reader

all-local: $(WEBSPIDER_BIN_TOOLS) $(WEB_DATAMINE_BIN_TOOLS) $(LOCAL_SCRIPTS_TOOLS) $(LOCAL_BIN_TOOS) make_spiderlib_ln

$(WEBSPIDER_BIN_TOOLS):bin/%: $(WEBSPIDER_ROOT)/Binary/%
	mkdir -p bin
	ln -sf --target-directory=bin/ $<

$(WEB_DATAMINE_BIN_TOOLS):bin/%: $(WEB_DATAMINE_ROOT)/Binary/%
	mkdir -p bin
	ln -sf --target-directory=bin/ $<
 
$(LOCAL_SCRIPTS_TOOLS):bin/%: $(top_srcdir)/scripts/%
	mkdir -p bin
	ln -sf --target-directory=bin/ $(addprefix $(CURDIR)/, $<)

$(LOCAL_BIN_TOOS):bin/%: $(top_srcdir)/Binary/%
	mkdir -p bin
	ln -sf --target-directory=bin/ $(addprefix $(CURDIR)/, $<)

make_spiderlib_ln:
	ln -sf  $(WEBSPIDER_ROOT)/Binary webspider_lib

SUBDIRS=@PACKAGE_DEPENDENCIES@ src
export @MODULE_ROOT_VARS@
export BUILD_DEPENDENCIES

EXTRA_DIST=GNUmakefile
