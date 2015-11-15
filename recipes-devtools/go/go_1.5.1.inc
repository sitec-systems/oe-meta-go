require go.inc

LIC_FILES_CHKSUM += "file://${WORKDIR}/go-${PV}/go/LICENSE;md5=591778525c869cdde0ab5a1bf283cd81"
SRC_URI += "${SRC_URI_PREFIX}/go${PV}.src.tar.gz;name=go_1_5;subdir=go-${PV}"
SRC_URI[go_1_5.md5sum] = "4adfbdfca523cc1c229be8a321f3602f"
SRC_URI[go_1_5.sha256sum] = "a889873e98d9a72ae396a9b7dd597c29dcd709cafa9097d9c4ba04cff0ec436b"
S = "${WORKDIR}/go-${PV}/go"
