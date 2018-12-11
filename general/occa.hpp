// Copyright (c) 2010, Lawrence Livermore National Security, LLC. Produced at
// the Lawrence Livermore National Laboratory. LLNL-CODE-443211. All Rights
// reserved. See file COPYRIGHT for details.
//
// This file is part of the MFEM library. For more information and source code
// availability see http://mfem.org.
//
// MFEM is free software; you can redistribute it and/or modify it under the
// terms of the GNU Lesser General Public License (as published by the Free
// Software Foundation) version 2.1 dated February 1999.

#ifndef MFEM_OCCA_HPP
#define MFEM_OCCA_HPP

// *****************************************************************************
#ifdef MFEM_USE_OCCA

// Defines *********************************************************************
#define __OCCA__

// Includes ********************************************************************
#include <occa.hpp>
#ifdef __NVCC__
#include <occa/mode/cuda/utils.hpp>
#endif // __NVCC__

// Typedefs ********************************************************************
typedef occa::device OCCAdevice;
typedef occa::memory memory;

// Macros **********************************************************************
#define GET_OCCA_MEMORY(v) occa::memory o_##v = mm::Get().Memory(v)
#define GET_OCCA_CONST_MEMORY(v) GET_OCCA_MEMORY(v)
#define NEW_OCCA_PROPERTY(props) occa::properties props;
#define SET_OCCA_PROPERTY(props,name) props["defines/" #name] = name;
#define NEW_OCCA_KERNEL(ker,libray,filename,props)                      \
   static occa::kernel ker = NULL;                                      \
   if (ker==NULL) {                                                     \
      OCCAdevice device = config::OccaDevice();                         \
      const std::string fdk = "occa://" #libray "/" #filename;          \
      const std::string odk = occa::io::occaFileOpener().expand(fdk);   \
      ker = device.buildKernel(odk, #ker, props);                       \
   }

#else // MFEM_USE_OCCA ********************************************************

// Typedefs ********************************************************************
typedef void *OccaDevice;
typedef void *OccaMemory;

#endif // MFEM_USE_OCCA

// *****************************************************************************
namespace mfem
{

// *****************************************************************************
OccaDevice okWrapDevice(CUdevice,CUcontext);
OccaMemory okDeviceMalloc(OccaDevice, const size_t);
OccaMemory okWrapMemory(const OccaDevice, void*, const size_t);
void *okMemoryPtr(OccaMemory);
void okCopyFrom(OccaMemory, const void*);
void okCopyTo(OccaMemory, void*);

} // mfem

#endif // MFEM_OCCA_HPP