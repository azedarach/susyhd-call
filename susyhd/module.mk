DIR               := susyhd
LIBSUSYHDLINK_DIR := $(DIR)
MODNAME           := susyhdlink

LIBSUSYHDLINK_MK := \
		$(DIR)/module.mk

# source files
LIBSUSYHDLINK_SRC := \
		$(DIR)/susyhd_link.cpp

# header files
LIBSUSYHDLINK_HDR := \
		$(DIR)/susyhd_higher_order_corrections.hpp \
		$(DIR)/susyhd_input_parameters.hpp \
		$(DIR)/susyhd_link.hpp \
		$(DIR)/susyhd_uncertainty_sources.hpp

LIBSUSYHDLINK_OBJ := \
		$(patsubst %.cpp, %.o, $(filter %.cpp, $(LIBSUSYHDLINK_SRC)))

LIBSUSYHDLINK_DEP := \
		$(LIBSUSYHDLINK_OBJ:.o=.d)

LIBSUSYHDLINK     := \
		$(DIR)/lib$(MODNAME)$(LIBEXT)

LIBSUSYHDLINK_INSTALL_DIR := $(INSTALL_DIR)/$(DIR)

.PHONY:         clean-$(MODNAME) clean-$(MODNAME)-dep clean-$(MODNAME)-obj \
		distclean-$(MODNAME)

ifneq ($(INSTALL_DIR),)
install-addon::
		install -d $(LIBSUSYHDLINK_INSTALL_DIR)
		install -m u=rw,g=r,o=r $(LIBSUSYHDLINK_SRC) $(LIBSUSYHDLINK_INSTALL_DIR)
		install -m u=rw,g=r,o=r $(LIBSUSYHDLINK_HDR) $(LIBSUSYHDLINK_INSTALL_DIR)
		$(INSTALL_ADDON_MK) $(LIBSUSYHDLINK_MK) $(LIBSUSYHDLINK_INSTALL_DIR) -m u=rw,g=r,o=r
endif

clean-$(MODNAME)-dep:
		-rm -f $(LIBSUSYHDLINK_DEP)

clean-$(MODNAME)-obj:
		-rm -f $(LIBSUSYHDLINK_OBJ)

clean-$(MODNAME): clean-$(MODNAME)-dep clean-$(MODNAME)-obj
		-rm -f $(LIBSUSYHDLINK)

distclean-$(MODNAME): clean-$(MODNAME)

clean::         clean-$(MODNAME)

distclean::     distclean-$(MODNAME)

$(LIBSUSYHDLINK_DEP) $(LIBSUSYHDLINK_OBJ): CPPFLAGS += $(MLINKFLAGS) -I$(LIBMATHLINK_DIR) -I$(LIBSUSYHDLINK_DIR)

$(LIBSUSYHDLINK): $(LIBSUSYHDLINK_OBJ) $(LIBMATHLINK)
		$(MAKELIB) $@ $^

SUSYHDCALL_ALLDEP += $(LIBSUSYHDLINK_DEP)
SUSYHDCALL_ALLSRC += $(LIBSUSYHDLINK_SRC)
SUSYHDCALL_ALLLIB += $(LIBSUSYHDLINK)
SUSYHDCALL_MODNAMES += $(MODNAME)
