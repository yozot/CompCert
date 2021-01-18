// *****************************************************************
//
//               The Compcert verified compiler
//
//           Xavier Leroy, INRIA Paris
//
// Copyright (c) 2016 Institut National de Recherche en Informatique et
//  en Automatique.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//     * Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//     * Neither the name of the <organization> nor the
//       names of its contributors may be used to endorse or promote products
//       derived from this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT
// HOLDER> BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// *********************************************************************

// System dependencies

#if defined(SYS_linux) || defined(SYS_bsd)

#define GLOB(x) x
#define FUNCTION(f) \
	.text; \
	.globl f; \
	.align 16; \
f:

#define ENDFUNCTION(f) \
	.type f, @function; .size f, . - f

#endif

#if defined(SYS_macos)

#define GLOB(x) _##x
#define FUNCTION(f) \
	.text; \
	.globl _##f; \
	.align 4; \
_##f:

#define ENDFUNCTION(f)

#endif

#if defined(SYS_cygwin)

#define GLOB(x) x
#define FUNCTION(f) \
	.text; \
	.globl f; \
	.align 16; \
f:

#define ENDFUNCTION(f)

#endif

// Names for argument and result registers

#if defined(SYS_cygwin)
#define INT_ARG_1 %rcx
#else
#define INT_ARG_1 %rdi
#endif
#define FP_ARG_1 %xmm0
#define INT_RES %rax
#define FP_RES %xmm0

