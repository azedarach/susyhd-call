DIR             := mathematica
LIBMATHLINK_DIR := $(DIR)
MODNAME         := mathlink

LIBMATHLINK_MK := \
		$(DIR)/module.mk

# source files
LIBMATHLINK_SRC := \
		$(DIR)/mathematica_link.cpp

# header files
LIBMATHLINK_CONFIG_HDR := \
		$(DIR)/mathematica_config.h

LIBMATHLINK_HDR := \
		$(DIR)/mathematica_error.hpp \
		$(DIR)/mathematica_error_code.hpp \
		$(DIR)/mathematica_link.hpp \
		$(DIR)/mathematica_packet.hpp \
		$(DIR)/mathematica_types.hpp

LIBMATHLINK_OBJ := \
		$(patsubst %.cpp, %.o, $(filter %.cpp, $(LIBMATHLINK_SRC)))

LIBMATHLINK_DEP := \
		$(LIBMATHLINK_OBJ:.o=.d)

LIBMATHLINK	:= $(DIR)/lib$(MODNAME)$(LIBEXT)

LIBMATHLINK_INSTALL_DIR := $(INSTALL_DIR)/$(DIR)

.PHONY:		all-$(MODNAME) clean-$(MODNAME) clean-$(MODNAME)-dep \
		clean-$(MODNAME)-obj distclean-$(MODNAME)

ifneq ($(INSTALL_DIR),)
install-addon::
		install -d $(LIBMATHLINK_INSTALL_DIR)
		install -m u=rw,g=r,o=r $(LIBMATHLINK_SRC) $(LIBMATHLINK_INSTALL_DIR)
		install -m u=rw,g=r,o=r $(LIBMATHLINK_HDR) $(LIBMATHLINK_INSTALL_DIR)
		install -m u=rw,g=r,o=r $(LIBMATHLINK_CONFIG_HDR) $(LIBMATHLINK_INSTALL_DIR)
		$(INSTALL_ADDON_MK) $(LIBMATHLINK_MK) $(LIBMATHLINK_INSTALL_DIR) -m u=rw,g=r,o=r
endif

all-$(MODNAME): $(LIBMATHLINK)

clean-$(MODNAME)-dep:
		-rm -f $(LIBMATHLINK_DEP)

clean-$(MODNAME)-obj:
		-rm -f $(LIBMATHLINK_OBJ)

clean-$(MODNAME): clean-$(MODNAME)-dep clean-$(MODNAME)-obj
		-rm -f $(LIBMATHLINK)

distclean-$(MODNAME): clean-$(MODNAME)
# BEGIN: NOT EXPORTED ##########################################
		-rm -f $(LIBMATHLINK_CONFIG_HDR)
# END:   NOT EXPORTED ##########################################

clean::		clean-$(MODNAME)

distclean::	distclean-$(MODNAME)

$(LIBMATHLINK_DEP) $(LIBMATHLINK_OBJ): CPPFLAGS += $(MLINKFLAGS) -I$(LIBMATHLINK_DIR)

ifeq ($(ENABLE_STATIC_LIBS),yes)
$(LIBMATHLINK): $(LIBMATHLINK_OBJ)
		$(MAKELIB) $@ $^
else
$(LIBMATHLINK): $(LIBMATHLINK_OBJ)
		$(MAKELIB) $@ $^ $(MLINKLIBS) $(EXTRA_MLINK_LIBS)
endif

SUSYHDCALL_ALLDEP += $(LIBMATHLINK_DEP)
SUSYHDCALL_ALLSRC += $(LIBMATHLINK_SRC)
SUSYHDCALL_ALLLIB += $(LIBMATHLINK)
SUSYHDCALL_MODNAMES += $(MODNAME)
