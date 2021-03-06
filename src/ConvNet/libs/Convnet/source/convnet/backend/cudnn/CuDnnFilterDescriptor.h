/*
 * C++ Convnet Implementation - Distributed for "Mental Image Retrieval" implementation
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

#ifndef CUDNNFILTERDESCRIPTOR_H
#define CUDNNFILTERDESCRIPTOR_H

#include <cudnn.h>

#include <vector>

namespace cudnn {

class CuDnnFilterDescriptor
{
    public:
        CuDnnFilterDescriptor(const CuDnnFilterDescriptor&) = delete;
        CuDnnFilterDescriptor(const CuDnnFilterDescriptor&&) = delete;
        CuDnnFilterDescriptor& operator=(const CuDnnFilterDescriptor&) = delete;
        CuDnnFilterDescriptor& operator=(const CuDnnFilterDescriptor&&) = delete;

        CuDnnFilterDescriptor();
        ~CuDnnFilterDescriptor();

        void setupTightlyPacked(const std::vector<unsigned> &dimensions, cudnnDataType_t dataType = CUDNN_DATA_FLOAT);

        inline cudnnFilterDescriptor_t getDescriptor() const { return m_desc; }
    protected:
        cudnnFilterDescriptor_t m_desc;
};

}

#endif // CUDNNFILTERDESCRIPTOR_H
