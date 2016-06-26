inherit cross

require go_${PV}.inc

GOROOT_FINAL="${libdir}/go"
export GOROOT_FINAL

do_compile() {
  export GOROOT_BOOTSTRAP="${GOROOT_BOOTSTRAP}"

  setup_go_arch

  setup_cgo_gcc_wrapper

  ## TODO: consider setting GO_EXTLINK_ENABLED
  export CGO_ENABLED="${GO_CROSS_CGO_ENABLED}"
  export CC=${BUILD_CC}
  export CC_FOR_TARGET="${WORKDIR}/${TARGET_PREFIX}gcc"
  export CXX_FOR_TARGET="${WORKDIR}/${TARGET_PREFIX}g++"
  export GO_GCFLAGS="${HOST_CFLAGS}"
  export GO_LDFLAGS="${HOST_LDFLAGS}"

  set > ${WORKDIR}/go-${PV}.env
  cd ${WORKDIR}/go-${PV}/go/src && bash -x ./make.bash

  # log the resulting environment
  env "GOROOT=${WORKDIR}/go-${PV}/go" "${WORKDIR}/go-${PV}/go/bin/go" env
}
