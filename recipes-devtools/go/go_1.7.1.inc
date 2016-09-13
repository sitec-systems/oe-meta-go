require go.inc

DEPENDS = "go-bootstrap-native"

SRC_URI = "${SRC_URI_PREFIX}/go${PV}.src.tar.gz;subdir=go-${PV}"
SRC_URI[md5sum] = "433e2158e5c28fe24b11622df393cc46"
SRC_URI[sha256sum] = "2b843f133b81b7995f26d0cb64bbdbb9d0704b90c44df45f844d28881ad442d3"

SRC_URI += "\
        file://fix-cross-compilation.patch \
        "

LIC_FILES_CHKSUM = "file://${WORKDIR}/go-${PV}/go/LICENSE;md5=5d4950ecb7b26d2c5e4e7b4e0dd74707"
