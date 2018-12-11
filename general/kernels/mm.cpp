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

#include "../okina.hpp"

// *****************************************************************************
namespace mfem
{

// ******************************************************************************
void* kH2D(void *dest, const void *src, size_t bytes, const bool async)
{
   BUILTIN_TRAP;
   assert(false);
   GET_ADRS(src);
   GET_ADRS(dest);
   if (not async) { okMemcpyHtoD(d_dest, d_src, bytes); }
   else { okMemcpyHtoDAsync(d_dest, d_src, bytes, config::Stream()); }
   return dest;
}

// *****************************************************************************
void* kD2H(void *dest, const void *src, size_t bytes, const bool async)
{
   BUILTIN_TRAP;
   assert(false);
   GET_ADRS(src);
   GET_ADRS(dest);
   if (not async) { okMemcpyDtoH(d_dest, d_src, bytes); }
   else { okMemcpyDtoHAsync(d_dest, d_src, bytes, config::Stream()); }
   return dest;
}

// *****************************************************************************
void* kD2D(void *dest, const void *src, size_t bytes, const bool async)
{
   BUILTIN_TRAP;
   assert(false);
   GET_ADRS(src);
   GET_ADRS(dest);
   if (not async) { okMemcpyDtoD(dest, (void*)src, bytes); }
   else { okMemcpyDtoDAsync(dest, (void*)src, bytes, config::Stream()); }
   return dest;
}

// *****************************************************************************
} // namespace mfem