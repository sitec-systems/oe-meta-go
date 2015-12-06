require go.inc

SRC_URI = "${SRC_URI_PREFIX}/go${PV}.src.tar.gz;name=go_1_5;subdir=go-${PV}"
SRC_URI[go_1_5.md5sum] = "4adfbdfca523cc1c229be8a321f3602f"
SRC_URI[go_1_5.sha256sum] = "a889873e98d9a72ae396a9b7dd597c29dcd709cafa9097d9c4ba04cff0ec436b"

LIC_FILES_CHKSUM = "file://${WORKDIR}/go-${PV}/go/LICENSE;md5=591778525c869cdde0ab5a1bf283cd81"

S = "${WORKDIR}/go-${PV}/go"

DEPENDS = "go-bootstrap"

SRC_URI += "\
        file://Fix-ccache-compilation-issue.patch \
        file://fix-cross-compilation.patch \
        "

setup_cgo_gcc_wrapper() {
  # Is there a bug in the cross-compiler support for CGO? Can't get it
  # to work without this wrapper
  for t in gcc g++ ; do
    cat > ${WORKDIR}/${TARGET_PREFIX}${t} <<EOT
#!/bin/sh
exec ${TARGET_PREFIX}${t} ${TARGET_CC_ARCH} --sysroot=${STAGING_DIR_TARGET} "\$@"
EOT
    chmod +x ${WORKDIR}/${TARGET_PREFIX}${t}
  done
}

do_install() {
  GOROOT_FINAL="${D}${libdir}/go"

  install -d "${D}${bindir}" "${GOROOT_FINAL}"
  tar -C "${WORKDIR}/go-${PV}/go" -cf - bin lib src pkg test |
  tar -C "${GOROOT_FINAL}" -xpf -
  mv "${GOROOT_FINAL}/bin/"* "${D}${bindir}/"

  for t in gcc g++ ; do
    cat > ${GOROOT_FINAL}/bin/${TARGET_PREFIX}${t} <<EOT
#!/bin/sh
exec ${TARGET_PREFIX}${t} ${TARGET_CC_ARCH} --sysroot=${STAGING_DIR_TARGET} "\$@"
EOT
    chmod +x ${GOROOT_FINAL}/bin/${TARGET_PREFIX}${t}
  done
}

## TODO: implement do_clean() and ensure we actually do rebuild super cleanly
