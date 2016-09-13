DESCRIPTION = "Leveled execution logs for Go"
SECTION = "net"
HOMEPAGE = "https://github.com/golang/glog"
LICENSE = "Apache-2.0"

LIC_FILES_CHKSUM = "file://src/${GO_IMPORT}/LICENSE;md5=19cbd64715b51267a47bf3750cc6a8a5"

GO_IMPORT = "github.com/golang/glog"

inherit go

SRC_URI = "\
	git://${GO_IMPORT}.git;protocol=https;destsuffix=${PN}-${PV}/src/${GO_IMPORT} \
	"

SRCREV = "23def4e6c14b4da8ac2ed8007337bc5eb5007998"
