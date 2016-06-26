inherit native

require go_${PV}.inc

GOROOT_FINAL="${STAGING_LIBDIR_NATIVE}/go"
export GOROOT_FINAL

do_compile() {
  setup_go_arch

  export CGO_ENABLED="1"
  ## TODO: consider setting GO_EXTLINK_ENABLED

  export CC="${BUILD_CC}"

  cd src && bash -x ./make.bash

  # log the resulting environment
  env "GOROOT=${WORKDIR}/go-${PV}/go" "${WORKDIR}/go-${PV}/go/bin/go" env
}
