/*
 * This file is part of Crypt Underworld.
 *
 * Crypt Underworld is free software: you can redistribute it
 * and/or modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation, either
 * version 3 of the License, or (at your option) any later
 * version.
 *
 * Crypt Underworld is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE. See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with Crypt Underworld. If not, see
 * <https://www.gnu.org/licenses/>.
 *
 * Copyright (c) 2021 Zoë Sparks <zoe@milky.flowers>
 */

#ifndef k4808017bafe40e09a47f9ed7fa69735
#define k4808017bafe40e09a47f9ed7fa69735

#include "instance.hpp"

#include <vulkan/vulkan_core.h>

#include <memory>

namespace cu {

/*!
 * \brief A Vulkan debug messenger wrapper.
 */
class DebugMsgr {
public:
    /*!
     * \brief (constructor)
     *
     * \param inst The Instance in use.
     * \param debug_on Whether the Vulkan debug layer is enabled.
     * Only creates the messenger if this is true.
     */
    DebugMsgr(Instance::ptr inst, bool debug_on);

    DebugMsgr(DebugMsgr&&) = delete;
    DebugMsgr(const DebugMsgr&) = delete;
    DebugMsgr& operator=(const DebugMsgr&) = delete;

    ~DebugMsgr() noexcept;

private:
    VkDebugUtilsMessengerEXT msgr;

    PFN_vkCreateDebugUtilsMessengerEXT create_dbg_msgr;
    PFN_vkDestroyDebugUtilsMessengerEXT destroy_dbg_msgr;

    Instance::ptr inst;

    bool dbg_on;
};

} // namespace cu

#endif
