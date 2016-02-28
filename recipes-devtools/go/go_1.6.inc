require go.inc

SRC_URI = "${SRC_URI_PREFIX}/go${PV}.src.tar.gz;name=go_1_6;subdir=go-${PV}"
SRC_URI[go_1_6.md5sum] = "e67833ea37fbc002fbe38efe6c1bcd98"
SRC_URI[go_1_6.sha256sum] = "a96cce8ce43a9bf9b2a4c7d470bc7ee0cb00410da815980681c8353218dcf146"

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
