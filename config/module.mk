DIR          := config
MODNAME      := config

CONFIG_MK    := \
		$(DIR)/module.mk

CONFIG_TMPL  := \
		$(DIR)/abspathx.mk \
		$(DIR)/mathematica_config.h.in

MAKEFILE_IN  := \
		$(DIR)/Makefile.in

SUSYHDCALL_VERSION_FILE := \
		$(DIR)/version

.PHONY:		all-$(MODNAME) clean-$(MODNAME) distclean-$(MODNAME)

all-$(MODNAME):

clean-$(MODNAME):

distclean-$(MODNAME): clean-$(MODNAME)
		-rm -f $(SUSYHDCALL_VERSION_FILE)

clean::		clean-$(MODNAME)

distclean::	distclean-$(MODNAME)
