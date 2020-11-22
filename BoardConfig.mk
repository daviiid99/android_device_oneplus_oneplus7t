#
# Copyright (C) 2020 Paranoid Android
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

# Inherit from oneplus sm8150-common
-include device/oneplus/sm8150-common/BoardConfigCommon.mk

DEVICE_PATH := device/oneplus/oneplus7t

TARGET_OTA_ASSERT_DEVICE := oneplus7t,oneplus7tpro,OnePlus7T,OnePlus7TPro

BOARD_SUPER_PARTITION_SIZE := 15032385536
BOARD_SUPER_PARTITION_GROUPS := oneplus_dynamic_partitions
TARGET_ENFORCE_AB_OTA_PARTITION_LIST := true
BOARD_ONEPLUS_DYNAMIC_PARTITIONS_PARTITION_LIST := system product system_ext
BOARD_ONEPLUS_DYNAMIC_PARTITIONS_SIZE := 7511998464
TARGET_USES_PREBUILT_DYNAMIC_PARTITIONS := true

BOARD_RECOVERYIMAGE_PARTITION_SIZE := 100663296
BOARD_USERDATAIMAGE_PARTITION_SIZE := 115601780736
BOARD_DTBOIMG_PARTITION_SIZE := 25165824

BOARD_PRODUCTIMAGE_FILE_SYSTEM_TYPE := ext4
BOARD_SYSTEM_EXTIMAGE_FILE_SYSTEM_TYPE := ext4

TARGET_COPY_OUT_PRODUCT := product
TARGET_COPY_OUT_SYSTEM_EXT := system_ext

# Recovery
BOARD_USES_RECOVERY_AS_BOOT := false
TARGET_NO_RECOVERY := false
TARGET_RECOVERY_FSTAB := $(DEVICE_PATH)/rootdir/etc/fstab.qcom

# Verified Boot
BOARD_AVB_VBMETA_SYSTEM := system product system_ext
BOARD_AVB_VBMETA_SYSTEM_KEY_PATH := external/avb/test/data/testkey_rsa2048.pem
BOARD_AVB_VBMETA_SYSTEM_ALGORITHM := SHA256_RSA2048
BOARD_AVB_VBMETA_SYSTEM_ROLLBACK_INDEX := $(PLATFORM_SECURITY_PATCH_TIMESTAMP)
BOARD_AVB_VBMETA_SYSTEM_ROLLBACK_INDEX_LOCATION := 1

# inherit from the proprietary version
-include vendor/oneplus/oneplus7t/BoardConfigVendor.mk