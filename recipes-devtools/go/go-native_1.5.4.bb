require go_${PV}.inc

GOROOT_FINAL="${STAGING_LIBDIR_NATIVE}/go"
export GOROOT_FINAL

inherit native

require go-common-tasks.inc
