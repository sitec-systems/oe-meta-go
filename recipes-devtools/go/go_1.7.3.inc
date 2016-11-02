require go.inc

DEPENDS = "go-bootstrap-native"

SRC_URI = "${SRC_URI_PREFIX}/go${PV}.src.tar.gz;subdir=go-${PV}"
SRC_URI[md5sum] = "83d1b7bd4281479ab7d153e5152c9fc9"
SRC_URI[sha256sum] = "79430a0027a09b0b3ad57e214c4c1acfdd7af290961dd08d322818895af1ef44"

SRC_URI += "\
        file://fix-cross-compilation.patch \
        "

LIC_FILES_CHKSUM = "file://${WORKDIR}/go-${PV}/go/LICENSE;md5=5d4950ecb7b26d2c5e4e7b4e0dd74707"
