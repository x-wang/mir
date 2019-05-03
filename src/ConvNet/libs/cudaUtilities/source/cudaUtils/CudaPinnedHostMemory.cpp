/*
 * Cuda Utilities - Distributed for "Mental Image Retrieval" implementation
 * Copyright (C) 2017-2019  Andreas Ley <mail@andreas-ley.com>
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */

#include "CudaPinnedHostMemory.h"

#include "CudaDriver.h"

namespace CudaUtils {

CudaPinnedHostMemory::CudaPinnedHostMemory(unsigned flags) : m_flags(flags)
{

}

CudaPinnedHostMemory::~CudaPinnedHostMemory()
{
    if (m_ptr != NULL)
        cuMemFreeHost(m_ptr);
}

void CudaPinnedHostMemory::resize(size_t size)
{
    if (size > m_reserved) {
        if (m_ptr != NULL)
            cuMemFreeHost(m_ptr);
        m_reserved = size;
        CudaDriver::throwOnCudaError(cuMemHostAlloc(&m_ptr, m_reserved, m_flags), __FILE__, __LINE__);
    }
    m_size = size;
}


}