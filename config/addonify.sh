#!/bin/sh

# This script replaces the definition of the DIR variable
# with $(SUSYHDCALL_BASEDIR)/$(DIR) in the given file
# (or stdin), and modifies the install rules appropriately

standalone_dir_defn="^\([ \t]*DIR[ \t]*:=[ \t]*\)\(.*\)"
addon_dir_defn="\1\$\(SUSYHDCALL_BASEDIR\)\/\2"
install_addon_rule="install-addon::"
install_src_rule="install-src::"
install_script_rule="^\t\t\$(INSTALL_ADDON_MK) *\(.*\) -m u=rw,g=r,o=r"
install_module_rule="\t\tinstall -m u=rw,g=r,o=r \1"

if test $# -lt 1 ; then
    # read from stdin
    if [ ! -t 0 ] ; then
        sed -e "s/${standalone_dir_defn}/${addon_dir_defn}/" \
	    -e "s/${install_addon_rule}/${install_src_rule}/" \
	    -e "s/${install_script_rule}/${install_module_rule}/" \
	< /dev/stdin
    fi
else
    # read from file
    input_file="$1"
    sed -e "s/${standalone_dir_defn}/${addon_dir_defn}/" \
	-e "s/${install_addon_rule}/${install_src_rule}/" \
	-e "s/${install_script_rule}/${install_module_rule}/" \
	${input_file}
fi
