require go.inc

DEPENDS = "go-bootstrap-native"

SRC_URI = "${SRC_URI_PREFIX}/go${PV}.src.tar.gz;subdir=go-${PV}"
SRC_URI[md5sum] = "a30c3bd1a7fcc6a48acfb74936a19b4c"
SRC_URI[sha256sum] = "72680c16ba0891fcf2ccf46d0f809e4ecf47bbf889f5d884ccb54c5e9a17e1c0"

SRC_URI += "\
        file://fix-cross-compilation.patch \
        "

LIC_FILES_CHKSUM = "file://${WORKDIR}/go-${PV}/go/LICENSE;md5=5d4950ecb7b26d2c5e4e7b4e0dd74707"
