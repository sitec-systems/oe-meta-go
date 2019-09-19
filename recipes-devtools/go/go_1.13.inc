require go.inc

DEPENDS = "go-bootstrap-native"

SSTATE_SCAN_CMD = "true"

SRC_URI = "${SRC_URI_PREFIX}/go${PV}.src.tar.gz;subdir=go-${PV}"
SRC_URI[md5sum] = "8d23207e431b8a8b2e26ce467777fda8"
SRC_URI[sha256sum] = "3fc0b8b6101d42efd7da1da3029c0a13f22079c0c37ef9730209d8ec665bf122"

LIC_FILES_CHKSUM = "file://${WORKDIR}/go-${PV}/go/LICENSE;md5=5d4950ecb7b26d2c5e4e7b4e0dd74707"
