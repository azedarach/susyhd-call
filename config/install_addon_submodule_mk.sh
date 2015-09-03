#!/bin/sh

# This script installs a Makefile module [$1] for an addon submodule
# to a destination [$2], modifying the paths and make rules as
# appropriate.  Optional install arguments can be given in [$3]

if test $# -lt 2 ; then
    echo "Usage: ./`basename $0` source destination [install args]"
    exit 1
fi

# directory of this script
BASEDIR=$(dirname $0)

source="$1"
shift
dest="$1"
shift
args="$*"

if test ! -e "${source}" ; then
    echo "Error: source does not exist: ${source}"
    exit 1
fi

addon_source="${source}.addon"

# change to addon appropriate paths and rules
${BASEDIR}/addonify.sh ${source} > ${addon_source}

if test -d "${dest}" ; then
    dest="${dest}/`basename ${source}`"
fi

install ${args} ${addon_source} ${dest}

rm -f ${addon_source}
