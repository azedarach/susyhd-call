DIR      := test
MODNAME  := test

TEST_SRC := \
		$(DIR)/test_mathematica_link.cpp \
		$(DIR)/test_susyhd_link.cpp

TEST_OBJ := \
		$(patsubst %.cpp, %.o, $(filter %.cpp, $(TEST_SRC)))

TEST_DEP := \
		$(TEST_OBJ:.o=.d)

TEST_EXE := \
		$(TEST_OBJ:.o=.x)

TEST_EXE_LOG := $(TEST_EXE:.x=.x.log)

TEST_LOG     := $(TEST_EXE_LOG)

.PHONY:		all-$(MODNAME) clean-$(MODNAME) distclean-$(MODNAME) \
		clean-$(MODNAME)-log \
		execute-tests execute-compiled-tests

all-$(MODNAME): $(TEST_EXE)

clean-$(MODNAME)-dep:
		-rm -f $(TEST_DEP)

clean-$(MODNAME)-obj:
		-rm -f $(TEST_OBJ)

clean-$(MODNAME)-log:
		-rm -f $(TEST_LOG)

clean-$(MODNAME): clean-$(MODNAME)-dep clean-$(MODNAME)-obj \
                  clean-$(MODNAME)-log
		-rm -f $(TEST_EXE)

distclean-$(MODNAME): clean-$(MODNAME)

execute-tests:	$(TEST_LOG)

execute-compiled-tests:	$(TEST_EXE_LOG)

$(DIR)/test_mathematica_link.x: $(DIR)/test_mathematica_link.o $(LIBMATHLINK)
		$(CXX) -o $@ $(call abspathx,$^) $(MLINKLIBS)

$(DIR)/test_susyhd_link.x: $(DIR)/test_susyhd_link.o $(LIBSUSYHDLINK) $(LIBMATHLINK)
		$(CXX) -o $@ $(call abspathx,$^) $(MLINKLIBS)

clean::		clean-$(MODNAME)

distclean::	distclean-$(MODNAME)

$(TEST_OBJ) $(TEST_DEP): CPPFLAGS += $(MLINKFLAGS)

SUSYHDCALL_ALLDEP += $(TEST_DEP)
SUSYHDCALL_ALLTST += $(TEST_EXE)
