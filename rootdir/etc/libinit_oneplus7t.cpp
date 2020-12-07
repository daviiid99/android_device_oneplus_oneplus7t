/*
 * Copyright (C) 2020 Paranoid Android
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <android-base/properties.h>

#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

using android::base::GetProperty;

/*
 * SetProperty does not allow updating read only properties and as a result
 * does not work for our use case. Write "OverrideProperty" to do practically
 * the same thing as "SetProperty" without this restriction.
 */
void OverrideProperty(const std::string& name, const std::string& value) {
    size_t valuelen = value.size();

    prop_info* pi = (prop_info*)__system_property_find(name.c_str());
    if (pi != nullptr) {
        __system_property_update(pi, value.c_str(), valuelen);
    } else {
        __system_property_add(name.c_str(), name.size(), value.c_str(), valuelen);
    }
}

/*
 * Only for read-only properties. Properties that can be wrote to more
 * than once should be set in a typical init script (e.g. init.oneplus.rc)
 * after the original property has been set.
 */
void vendor_load_properties() {
    std::string variant = GetProperty("ro.boot.prj_version", "");
	if (variant == "5") {
        OverrideProperty("ro.product.system.device", "OnePlus7T");
        OverrideProperty("ro.product.device", "OnePlus7T");
        OverrideProperty("ro.sf.lcd_density", "420");
        OverrideProperty("ro.als.pos.x", "645");
        OverrideProperty("ro.als.pos.y", "205");
        OverrideProperty("ro.fod.pos.x", "437");
        OverrideProperty("ro.fod.pos.y", "1959");
        OverrideProperty("ro.fod.size", "204");
	} else if (variant == "4") {
        OverrideProperty("ro.product.system.device", "OnePlus7TPro");
        OverrideProperty("ro.product.device", "OnePlus7TPro");
        OverrideProperty("ro.sf.lcd_density", "560");
        OverrideProperty("ro.als.pos.x", "1000");
        OverrideProperty("ro.als.pos.y", "260");
        OverrideProperty("ro.fod.pos.x", "610");
        OverrideProperty("ro.fod.pos.y", "2618");
        OverrideProperty("ro.fod.size", "220");
	} else if (variant == "2") {
        OverrideProperty("ro.product.system.device", "oneplus7tpronr");
        OverrideProperty("ro.product.system.model", "OnePlus 7T Pro NR");
        OverrideProperty("ro.product.system.device", "OnePlus7TProNR");
        OverrideProperty("ro.product.device", "OnePlus7TProNR");
        OverrideProperty("ro.sf.lcd_density", "560");
        OverrideProperty("ro.als.pos.x", "900");
        OverrideProperty("ro.als.pos.y", "260");
        OverrideProperty("ro.fod.pos.x", "562");
        OverrideProperty("ro.fod.pos.y", "2278");
        OverrideProperty("ro.fod.size", "316");
        OverrideProperty("ro.vendor.boot.project_name", "19861");
        OverrideProperty("ro.boot.project_name", "19861");
	}

	// Common Properties

	// Dalvik
	OverrideProperty("dalvik.vm.heapstartsize", "16m");
	OverrideProperty("dalvik.vm.heapgrowthlimit", "256m");
	OverrideProperty("dalvik.vm.heapsize", "512m");
	OverrideProperty("dalvik.vm.heaptargetutilization", "0.5");
	OverrideProperty("dalvik.vm.heapminfree", "8m");
	OverrideProperty("dalvik.vm.heapmaxfree", "32m");
}