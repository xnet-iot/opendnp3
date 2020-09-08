#
# This software is licensed under the Public Domain.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=opendnp3
PKG_VERSION:=1.0
PKG_RELEASE:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/$(PKG_NAME)
	SECTION:=niseva
	CATEGORY:=xNet
	SUBMENU:=DNP3
	TITLE:=xNet OpenDNP3 Library
	DEPENDS:=+libstdcpp +libuci +libzmq-nc +libmodbus +libjson-c
	URL:=https://www.niseva.com
endef

define Package/$(PKG_NAME)/description
	xNet DNP3 Library
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./ $(PKG_BUILD_DIR)
endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)/usr/include
		$(CP) $(PKG_INSTALL_DIR)/usr/include/opendnp3 $(1)/usr/include/
	$(INSTALL_DIR) $(1)/usr/lib
		$(CP) $(PKG_INSTALL_DIR)/usr/lib/libopendnp3.so* $(1)/usr/lib/
endef

define Package/$(PKG_NAME)/install
 	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libopendnp3.so* $(1)/usr/lib/
endef

$(eval $(call BuildPackage,$(PKG_NAME)))
