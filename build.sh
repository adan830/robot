#!/bin/sh

set -x

SOURCE_DIR=`pwd`
BINARY_DIR=`pwd`
BUILD_DIR=${BUILD_DIR:-../robotbuild}
BUILD_TYPE=${BUILD_TYPE:-release}
INSTALL_DIR=${INSTALL_DIR:-../${BUILD_TYPE}-install}
BUILD_NO_EXAMPLES=${BUILD_NO_EXAMPLES:-0}

mkdir -p $BUILD_DIR/$BUILD_TYPE \
  && cd $BUILD_DIR/$BUILD_TYPE \
  && cmake \
    -DCMAKE_BUILD_TYPE=$BUILD_TYPE \
    -DCMAKE_INSTALL_PREFIX=$INSTALL_DIR \
    -DBINARY_DIR=$BINARY_DIR \
    $SOURCE_DIR \
  && make $*

# cd $SOURCE_DIR && doxygen

