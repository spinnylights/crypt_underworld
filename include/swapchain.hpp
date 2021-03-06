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

#ifndef bfec49bf097c4235a5a04d7785daf8ff
#define bfec49bf097c4235a5a04d7785daf8ff

#include "image.hpp"
#include "image_view.hpp"
#include "device.hpp"

#include <vulkan/vulkan.h>

#include <vector>

namespace cu {

class Surface;
class Instance;
class SDL;

/*!
 * \brief A Vulkan swapchain wrapper.
 */
class Swapchain {
public:
    /*!
     * \brief (constructor)
     *
     * \param p_dev The PhysDevice in use.
     * \param l_dev The Device in use.
     * \param surf The Surface in use.
     * \param sdl The SDL instance in use.
     */
    Swapchain(PhysDevice& p_dev, Device::ptr l_dev, Surface& surf, SDL& sdl);

    Swapchain(Swapchain&&) = delete;
    Swapchain(const Swapchain&) = delete;
    Swapchain& operator=(const Swapchain&) = delete;

    ~Swapchain() noexcept;

private:
    VkSwapchainKHR swch;
    VkSwapchainKHR old_swch = VK_NULL_HANDLE;
    Device::ptr dev;
    std::vector<Image> imgs;
    std::vector<ImageView> _img_views;

    PFN_vkCreateSwapchainKHR create_swch;
    PFN_vkGetSwapchainImagesKHR get_swch_imgs;
    PFN_vkDestroySwapchainKHR destroy_swch;
};

} // namespace cu

#endif
