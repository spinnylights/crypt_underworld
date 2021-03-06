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

#include "engine.hpp"

namespace cu {

std::vector<const char*> Engine::layers()
{
    if (dbg) {
        return {"VK_LAYER_KHRONOS_validation"};
    } else {
        return {};
    }
}
std::vector<const char*> Engine::extensions()
{
    auto exts = sdl.get_req_vulk_exts();

    if (dbg) {
        exts.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
    }

    return exts;
}

Engine::Engine(bool debug)
    :dbg(debug),
     sdl{},
     vulk{extensions(),
          layers(),
          sdl,
          debug}
{}

} // namespace cu
