
###############################################################################
#
# Inclusive Makefile for the OFConnectionManager module.
#
# Autogenerated 2015-01-20 16:47:17.185057
#
###############################################################################
OFConnectionManager_BASEDIR := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
include $(OFConnectionManager_BASEDIR)/module/make.mk
include $(OFConnectionManager_BASEDIR)/module/auto/make.mk
include $(OFConnectionManager_BASEDIR)/module/src/make.mk
include $(OFConnectionManager_BASEDIR)/utest/_make.mk

