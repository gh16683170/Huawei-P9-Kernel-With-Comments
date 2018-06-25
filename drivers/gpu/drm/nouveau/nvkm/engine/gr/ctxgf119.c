/*
 * Copyright 2013 Red Hat Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE COPYRIGHT HOLDER(S) OR AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * Authors: Ben Skeggs <bskeggs@redhat.com>
 */
#include "ctxgf100.h"

/*******************************************************************************
 * PGRAPH context register lists
 ******************************************************************************/

static const struct gf100_gr_init
gf119_grctx_init_icmd_0[] = {
	{ 0x001000,   1, 0x01, 0x00000004 },
	{ 0x0000a9,   1, 0x01, 0x0000ffff },
	{ 0x000038,   1, 0x01, 0x0fac6881 },
	{ 0x00003d,   1, 0x01, 0x00000001 },
	{ 0x0000e8,   8, 0x01, 0x00000400 },
	{ 0x000078,   8, 0x01, 0x00000300 },
	{ 0x000050,   1, 0x01, 0x00000011 },
	{ 0x000058,   8, 0x01, 0x00000008 },
	{ 0x000208,   8, 0x01, 0x00000001 },
	{ 0x000081,   1, 0x01, 0x00000001 },
	{ 0x000085,   1, 0x01, 0x00000004 },
	{ 0x000088,   1, 0x01, 0x00000400 },
	{ 0x000090,   1, 0x01, 0x00000300 },
	{ 0x000098,   1, 0x01, 0x00001001 },
	{ 0x0000e3,   1, 0x01, 0x00000001 },
	{ 0x0000da,   1, 0x01, 0x00000001 },
	{ 0x0000f8,   1, 0x01, 0x00000003 },
	{ 0x0000fa,   1, 0x01, 0x00000001 },
	{ 0x00009f,   4, 0x01, 0x0000ffff },
	{ 0x0000b1,   1, 0x01, 0x00000001 },
	{ 0x0000b2,  40, 0x01, 0x00000000 },
	{ 0x000210,   8, 0x01, 0x00000040 },
	{ 0x000400,  24, 0x01, 0x00000040 },
	{ 0x000218,   8, 0x01, 0x0000c080 },
	{ 0x000440,  24, 0x01, 0x0000c080 },
	{ 0x0000ad,   1, 0x01, 0x0000013e },
	{ 0x0000e1,   1, 0x01, 0x00000010 },
	{ 0x000290,  16, 0x01, 0x00000000 },
	{ 0x0003b0,  16, 0x01, 0x00000000 },
	{ 0x0002a0,  16, 0x01, 0x00000000 },
	{ 0x000420,  16, 0x01, 0x00000000 },
	{ 0x0002b0,  16, 0x01, 0x00000000 },
	{ 0x000430,  16, 0x01, 0x00000000 },
	{ 0x0002c0,  16, 0x01, 0x00000000 },
	{ 0x0004d0,  16, 0x01, 0x00000000 },
	{ 0x000720,  16, 0x01, 0x00000000 },
	{ 0x0008c0,  16, 0x01, 0x00000000 },
	{ 0x000890,  16, 0x01, 0x00000000 },
	{ 0x0008e0,  16, 0x01, 0x00000000 },
	{ 0x0008a0,  16, 0x01, 0x00000000 },
	{ 0x0008f0,  16, 0x01, 0x00000000 },
	{ 0x00094c,   1, 0x01, 0x000000ff },
	{ 0x00094d,   1, 0x01, 0xffffffff },
	{ 0x00094e,   1, 0x01, 0x00000002 },
	{ 0x0002ec,   1, 0x01, 0x00000001 },
	{ 0x000303,   1, 0x01, 0x00000001 },
	{ 0x0002e6,   1, 0x01, 0x00000001 },
	{ 0x000466,   1, 0x01, 0x00000052 },
	{ 0x000301,   1, 0x01, 0x3f800000 },
	{ 0x000304,   1, 0x01, 0x30201000 },
	{ 0x000305,   1, 0x01, 0x70605040 },
	{ 0x000306,   1, 0x01, 0xb8a89888 },
	{ 0x000307,   1, 0x01, 0xf8e8d8c8 },
	{ 0x00030a,   1, 0x01, 0x00ffff00 },
	{ 0x00030b,   1, 0x01, 0x0000001a },
	{ 0x00030c,   1, 0x01, 0x00000001 },
	{ 0x000318,   1, 0x01, 0x00000001 },
	{ 0x000340,   1, 0x01, 0x00000000 },
	{ 0x000375,   1, 0x01, 0x00000001 },
	{ 0x000351,   1, 0x01, 0x00000100 },
	{ 0x00037d,   1, 0x01, 0x00000006 },
	{ 0x0003a0,   1, 0x01, 0x00000002 },
	{ 0x0003aa,   1, 0x01, 0x00000001 },
	{ 0x0003a9,   1, 0x01, 0x00000001 },
	{ 0x000380,   1, 0x01, 0x00000001 },
	{ 0x000360,   1, 0x01, 0x00000040 },
	{ 0x000366,   2, 0x01, 0x00000000 },
	{ 0x000368,   1, 0x01, 0x00001fff },
	{ 0x000370,   2, 0x01, 0x00000000 },
	{ 0x000372,   1, 0x01, 0x003fffff },
	{ 0x00037a,   1, 0x01, 0x00000012 },
	{ 0x0005e0,   5, 0x01, 0x00000022 },
	{ 0x000619,   1, 0x01, 0x00000003 },
	{ 0x000811,   1, 0x01, 0x00000003 },
	{ 0x000812,   1, 0x01, 0x00000004 },
	{ 0x000813,   1, 0x01, 0x00000006 },
	{ 0x000814,   1, 0x01, 0x00000008 },
	{ 0x000815,   1, 0x01, 0x0000000b },
	{ 0x000800,   6, 0x01, 0x00000001 },
	{ 0x000632,   1, 0x01, 0x00000001 },
	{ 0x000633,   1, 0x01, 0x00000002 },
	{ 0x000634,   1, 0x01, 0x00000003 },
	{ 0x000635,   1, 0x01, 0x00000004 },
	{ 0x000654,   1, 0x01, 0x3f800000 },
	{ 0x000657,   1, 0x01, 0x3f800000 },
	{ 0x000655,   2, 0x01, 0x3f800000 },
	{ 0x0006cd,   1, 0x01, 0x3f800000 },
	{ 0x0007f5,   1, 0x01, 0x3f800000 },
	{ 0x0007dc,   1, 0x01, 0x39291909 },
	{ 0x0007dd,   1, 0x01, 0x79695949 },
	{ 0x0007de,   1, 0x01, 0xb9a99989 },
	{ 0x0007df,   1, 0x01, 0xf9e9d9c9 },
	{ 0x0007e8,   1, 0x01, 0x00003210 },
	{ 0x0007e9,   1, 0x01, 0x00007654 },
	{ 0x0007ea,   1, 0x01, 0x00000098 },
	{ 0x0007ec,   1, 0x01, 0x39291909 },
	{ 0x0007ed,   1, 0x01, 0x79695949 },
	{ 0x0007ee,   1, 0x01, 0xb9a99989 },
	{ 0x0007ef,   1, 0x01, 0xf9e9d9c9 },
	{ 0x0007f0,   1, 0x01, 0x00003210 },
	{ 0x0007f1,   1, 0x01, 0x00007654 },
	{ 0x0007f2,   1, 0x01, 0x00000098 },
	{ 0x0005a5,   1, 0x01, 0x00000001 },
	{ 0x000980, 128, 0x01, 0x00000000 },
	{ 0x000468,   1, 0x01, 0x00000004 },
	{ 0x00046c,   1, 0x01, 0x00000001 },
	{ 0x000470,  96, 0x01, 0x00000000 },
	{ 0x000510,  16, 0x01, 0x3f800000 },
	{ 0x000520,   1, 0x01, 0x000002b6 },
	{ 0x000529,   1, 0x01, 0x00000001 },
	{ 0x000530,  16, 0x01, 0xffff0000 },
	{ 0x000585,   1, 0x01, 0x0000003f },
	{ 0x000576,   1, 0x01, 0x00000003 },
	{ 0x00057b,   1, 0x01, 0x00000059 },
	{ 0x000586,   1, 0x01, 0x00000040 },
	{ 0x000582,   2, 0x01, 0x00000080 },
	{ 0x0005c2,   1, 0x01, 0x00000001 },
	{ 0x000638,   2, 0x01, 0x00000001 },
	{ 0x00063a,   1, 0x01, 0x00000002 },
	{ 0x00063b,   2, 0x01, 0x00000001 },
	{ 0x00063d,   1, 0x01, 0x00000002 },
	{ 0x00063e,   1, 0x01, 0x00000001 },
	{ 0x0008b8,   8, 0x01, 0x00000001 },
	{ 0x000900,   8, 0x01, 0x00000001 },
	{ 0x000908,   8, 0x01, 0x00000002 },
	{ 0x000910,  16, 0x01, 0x00000001 },
	{ 0x000920,   8, 0x01, 0x00000002 },
	{ 0x000928,   8, 0x01, 0x00000001 },
	{ 0x000648,   9, 0x01, 0x00000001 },
	{ 0x000658,   1, 0x01, 0x0000000f },
	{ 0x0007ff,   1, 0x01, 0x0000000a },
	{ 0x00066a,   1, 0x01, 0x40000000 },
	{ 0x00066b,   1, 0x01, 0x10000000 },
	{ 0x00066c,   2, 0x01, 0xffff0000 },
	{ 0x0007af,   2, 0x01, 0x00000008 },
	{ 0x0007f6,   1, 0x01, 0x00000001 },
	{ 0x0006b2,   1, 0x01, 0x00000055 },
	{ 0x0007ad,   1, 0x01, 0x00000003 },
	{ 0x000937,   1, 0x01, 0x00000001 },
	{ 0x000971,   1, 0x01, 0x00000008 },
	{ 0x000972,   1, 0x01, 0x00000040 },
	{ 0x000973,   1, 0x01, 0x0000012c },
	{ 0x00097c,   1, 0x01, 0x00000040 },
	{ 0x000979,   1, 0x01, 0x00000003 },
	{ 0x000975,   1, 0x01, 0x00000020 },
	{ 0x000976,   1, 0x01, 0x00000001 },
	{ 0x000977,   1, 0x01, 0x00000020 },
	{ 0x000978,   1, 0x01, 0x00000001 },
	{ 0x000957,   1, 0x01, 0x00000003 },
	{ 0x00095e,   1, 0x01, 0x20164010 },
	{ 0x00095f,   1, 0x01, 0x00000020 },
	{ 0x00097d,   1, 0x01, 0x00000020 },
	{ 0x000683,   1, 0x01, 0x00000006 },
	{ 0x000685,   1, 0x01, 0x003fffff },
	{ 0x000687,   1, 0x01, 0x00000c48 },
	{ 0x0006a0,   1, 0x01, 0x00000005 },
	{ 0x000840,   1, 0x01, 0x00300008 },
	{ 0x000841,   1, 0x01, 0x04000080 },
	{ 0x000842,   1, 0x01, 0x00300008 },
	{ 0x000843,   1, 0x01, 0x04000080 },
	{ 0x000818,   8, 0x01, 0x00000000 },
	{ 0x000848,  16, 0x01, 0x00000000 },
	{ 0x000738,   1, 0x01, 0x00000000 },
	{ 0x0006aa,   1, 0x01, 0x00000001 },
	{ 0x0006ab,   1, 0x01, 0x00000002 },
	{ 0x0006ac,   1, 0x01, 0x00000080 },
	{ 0x0006ad,   2, 0x01, 0x00000100 },
	{ 0x0006b1,   1, 0x01, 0x00000011 },
	{ 0x0006bb,   1, 0x01, 0x000000cf },
	{ 0x0006ce,   1, 0x01, 0x2a712488 },
	{ 0x000739,   1, 0x01, 0x4085c000 },
	{ 0x00073a,   1, 0x01, 0x00000080 },
	{ 0x000786,   1, 0x01, 0x80000100 },
	{ 0x00073c,   1, 0x01, 0x00010100 },
	{ 0x00073d,   1, 0x01, 0x02800000 },
	{ 0x000787,   1, 0x01, 0x000000cf },
	{ 0x00078c,   1, 0x01, 0x00000008 },
	{ 0x000792,   1, 0x01, 0x00000001 },
	{ 0x000794,   3, 0x01, 0x00000001 },
	{ 0x000797,   1, 0x01, 0x000000cf },
	{ 0x000836,   1, 0x01, 0x00000001 },
	{ 0x00079a,   1, 0x01, 0x00000002 },
	{ 0x000833,   1, 0x01, 0x04444480 },
	{ 0x0007a1,   1, 0x01, 0x00000001 },
	{ 0x0007a3,   3, 0x01, 0x00000001 },
	{ 0x000831,   1, 0x01, 0x00000004 },
	{ 0x00080c,   1, 0x01, 0x00000002 },
	{ 0x00080d,   2, 0x01, 0x00000100 },
	{ 0x00080f,   1, 0x01, 0x00000001 },
	{ 0x000823,   1, 0x01, 0x00000002 },
	{ 0x000824,   2, 0x01, 0x00000100 },
	{ 0x000826,   1, 0x01, 0x00000001 },
	{ 0x00095d,   1, 0x01, 0x00000001 },
	{ 0x00082b,   1, 0x01, 0x00000004 },
	{ 0x000942,   1, 0x01, 0x00010001 },
	{ 0x000943,   1, 0x01, 0x00000001 },
	{ 0x000944,   1, 0x01, 0x00000022 },
	{ 0x0007c5,   1, 0x01, 0x00010001 },
	{ 0x000834,   1, 0x01, 0x00000001 },
	{ 0x0007c7,   1, 0x01, 0x00000001 },
	{ 0x00c1b0,   8, 0x01, 0x0000000f },
	{ 0x00c1b8,   1, 0x01, 0x0fac6881 },
	{ 0x00c1b9,   1, 0x01, 0x00fac688 },
	{ 0x01e100,   1, 0x01, 0x00000001 },
	{ 0x001000,   1, 0x01, 0x00000002 },
	{ 0x0006aa,   1, 0x01, 0x00000001 },
	{ 0x0006ad,   2, 0x01, 0x00000100 },
	{ 0x0006b1,   1, 0x01, 0x00000011 },
	{ 0x00078c,   1, 0x01, 0x00000008 },
	{ 0x000792,   1, 0x01, 0x00000001 },
	{ 0x000794,   3, 0x01, 0x00000001 },
	{ 0x000797,   1, 0x01, 0x000000cf },
	{ 0x00079a,   1, 0x01, 0x00000002 },
	{ 0x000833,   1, 0x01, 0x04444480 },
	{ 0x0007a1,   1, 0x01, 0x00000001 },
	{ 0x0007a3,   3, 0x01, 0x00000001 },
	{ 0x000831,   1, 0x01, 0x00000004 },
	{ 0x01e100,   1, 0x01, 0x00000001 },
	{ 0x001000,   1, 0x01, 0x00000014 },
	{ 0x000351,   1, 0x01, 0x00000100 },
	{ 0x000957,   1, 0x01, 0x00000003 },
	{ 0x00095d,   1, 0x01, 0x00000001 },
	{ 0x00082b,   1, 0x01, 0x00000004 },
	{ 0x000942,   1, 0x01, 0x00010001 },
	{ 0x000943,   1, 0x01, 0x00000001 },
	{ 0x0007c5,   1, 0x01, 0x00010001 },
	{ 0x000834,   1, 0x01, 0x00000001 },
	{ 0x0007c7,   1, 0x01, 0x00000001 },
	{ 0x01e100,   1, 0x01, 0x00000001 },
	{ 0x001000,   1, 0x01, 0x00000001 },
	{ 0x00080c,   1, 0x01, 0x00000002 },
	{ 0x00080d,   2, 0x01, 0x00000100 },
	{ 0x00080f,   1, 0x01, 0x00000001 },
	{ 0x000823,   1, 0x01, 0x00000002 },
	{ 0x000824,   2, 0x01, 0x00000100 },
	{ 0x000826,   1, 0x01, 0x00000001 },
	{ 0x01e100,   1, 0x01, 0x00000001 },
	{}
};

const struct gf100_gr_pack
gf119_grctx_pack_icmd[] = {
	{ gf119_grctx_init_icmd_0 },
	{}
};

static const struct gf100_gr_init
gf119_grctx_init_90c0_0[] = {
	{ 0x002700,   8, 0x20, 0x00000000 },
	{ 0x002704,   8, 0x20, 0x00000000 },
	{ 0x002708,   8, 0x20, 0x00000000 },
	{ 0x00270c,   8, 0x20, 0x00000000 },
	{ 0x002710,   8, 0x20, 0x00014000 },
	{ 0x002714,   8, 0x20, 0x00000040 },
	{ 0x00030c,   1, 0x04, 0x00000001 },
	{ 0x001944,   1, 0x04, 0x00000000 },
	{ 0x000758,   1, 0x04, 0x00000100 },
	{ 0x0002c4,   1, 0x04, 0x00000000 },
	{ 0x000790,   5, 0x04, 0x00000000 },
	{ 0x00077c,   1, 0x04, 0x00000000 },
	{ 0x000204,   3, 0x04, 0x00000000 },
	{ 0x000214,   1, 0x04, 0x00000000 },
	{ 0x00024c,   1, 0x04, 0x00000000 },
	{ 0x000d94,   1, 0x04, 0x00000001 },
	{ 0x001608,   2, 0x04, 0x00000000 },
	{ 0x001664,   1, 0x04, 0x00000000 },
	{}
};

const struct gf100_gr_pack
gf119_grctx_pack_mthd[] = {
	{ gf108_grctx_init_9097_0, 0x9097 },
	{ gf110_grctx_init_9197_0, 0x9197 },
	{ gf110_grctx_init_9297_0, 0x9297 },
	{ gf100_grctx_init_902d_0, 0x902d },
	{ gf100_grctx_init_9039_0, 0x9039 },
	{ gf119_grctx_init_90c0_0, 0x90c0 },
	{}
};

const struct gf100_gr_init
gf119_grctx_init_fe_0[] = {
	{ 0x404004,  10, 0x04, 0x00000000 },
	{ 0x404044,   1, 0x04, 0x00000000 },
	{ 0x404094,  13, 0x04, 0x00000000 },
	{ 0x4040c8,   1, 0x04, 0xf0000087 },
	{ 0x4040d0,   6, 0x04, 0x00000000 },
	{ 0x4040e8,   1, 0x04, 0x00001000 },
	{ 0x4040f8,   1, 0x04, 0x00000000 },
	{ 0x404130,   2, 0x04, 0x00000000 },
	{ 0x404138,   1, 0x04, 0x20000040 },
	{ 0x404150,   1, 0x04, 0x0000002e },
	{ 0x404154,   1, 0x04, 0x00000400 },
	{ 0x404158,   1, 0x04, 0x00000200 },
	{ 0x404164,   1, 0x04, 0x00000055 },
	{ 0x404168,   1, 0x04, 0x00000000 },
	{ 0x404178,   2, 0x04, 0x00000000 },
	{ 0x404200,   8, 0x04, 0x00000000 },
	{}
};

static const struct gf100_gr_init
gf119_grctx_init_ds_0[] = {
	{ 0x405800,   1, 0x04, 0x0f8000bf },
	{ 0x405830,   1, 0x04, 0x02180218 },
	{ 0x405834,   1, 0x04, 0x08000000 },
	{ 0x405838,   1, 0x04, 0x00000000 },
	{ 0x405854,   1, 0x04, 0x00000000 },
	{ 0x405870,   4, 0x04, 0x00000001 },
	{ 0x405a00,   2, 0x04, 0x00000000 },
	{ 0x405a18,   1, 0x04, 0x00000000 },
	{}
};

static const struct gf100_gr_init
gf119_grctx_init_pd_0[] = {
	{ 0x406020,   1, 0x04, 0x000103c1 },
	{ 0x406028,   4, 0x04, 0x00000001 },
	{ 0x4064a8,   1, 0x04, 0x00000000 },
	{ 0x4064ac,   1, 0x04, 0x00003fff },
	{ 0x4064b4,   3, 0x04, 0x00000000 },
	{ 0x4064c0,   1, 0x04, 0x80140078 },
	{ 0x4064c4,   1, 0x04, 0x0086ffff },
	{}
};

const struct gf100_gr_init
gf119_grctx_init_be_0[] = {
	{ 0x408800,   1, 0x04, 0x02802a3c },
	{ 0x408804,   1, 0x04, 0x00000040 },
	{ 0x408808,   1, 0x04, 0x1043e005 },
	{ 0x408900,   1, 0x04, 0x3080b801 },
	{ 0x408904,   1, 0x04, 0x62000001 },
	{ 0x408908,   1, 0x04, 0x00c8102f },
	{ 0x408980,   1, 0x04, 0x0000011d },
	{}
};

static const struct gf100_gr_pack
gf119_grctx_pack_hub[] = {
	{ gf100_grctx_init_main_0 },
	{ gf119_grctx_init_fe_0 },
	{ gf100_grctx_init_pri_0 },
	{ gf100_grctx_init_memfmt_0 },
	{ gf119_grctx_init_ds_0 },
	{ gf119_grctx_init_pd_0 },
	{ gf100_grctx_init_rstr2d_0 },
	{ gf100_grctx_init_scc_0 },
	{ gf119_grctx_init_be_0 },
	{}
};

const struct gf100_gr_init
gf119_grctx_init_prop_0[] = {
	{ 0x418400,   1, 0x04, 0x38004e00 },
	{ 0x418404,   1, 0x04, 0x71e0ffff },
	{ 0x41840c,   1, 0x04, 0x00001008 },
	{ 0x418410,   1, 0x04, 0x0fff0fff },
	{ 0x418414,   1, 0x04, 0x02200fff },
	{ 0x418450,   6, 0x04, 0x00000000 },
	{ 0x418468,   1, 0x04, 0x00000001 },
	{ 0x41846c,   2, 0x04, 0x00000000 },
	{}
};

const struct gf100_gr_init
gf119_grctx_init_gpc_unk_1[] = {
	{ 0x418600,   1, 0x04, 0x0000001f },
	{ 0x418684,   1, 0x04, 0x0000000f },
	{ 0x418700,   1, 0x04, 0x00000002 },
	{ 0x418704,   1, 0x04, 0x00000080 },
	{ 0x418708,   3, 0x04, 0x00000000 },
	{}
};

static const struct gf100_gr_init
gf119_grctx_init_setup_0[] = {
	{ 0x418800,   1, 0x04, 0x7006860a },
	{ 0x418808,   3, 0x04, 0x00000000 },
	{ 0x418828,   1, 0x04, 0x00008442 },
	{ 0x418830,   1, 0x04, 0x10000001 },
	{ 0x4188d8,   1, 0x04, 0x00000008 },
	{ 0x4188e0,   1, 0x04, 0x01000000 },
	{ 0x4188e8,   5, 0x04, 0x00000000 },
	{ 0x4188fc,   1, 0x04, 0x20100008 },
	{}
};

const struct gf100_gr_init
gf119_grctx_init_crstr_0[] = {
	{ 0x418b00,   1, 0x04, 0x00000006 },
	{ 0x418b08,   1, 0x04, 0x0a418820 },
	{ 0x418b0c,   1, 0x04, 0x062080e6 },
	{ 0x418b10,   1, 0x04, 0x020398a4 },
	{ 0x418b14,   1, 0x04, 0x0e629062 },
	{ 0x418b18,   1, 0x04, 0x0a418820 },
	{ 0x418b1c,   1, 0x04, 0x000000e6 },
	{ 0x418bb8,   1, 0x04, 0x00000103 },
	{}
};

static const struct gf100_gr_pack
gf119_grctx_pack_gpc[] = {
	{ gf100_grctx_init_gpc_unk_0 },
	{ gf119_grctx_init_prop_0 },
	{ gf119_grctx_init_gpc_unk_1 },
	{ gf119_grctx_init_setup_0 },
	{ gf100_grctx_init_zcull_0 },
	{ gf119_grctx_init_crstr_0 },
	{ gf108_grctx_init_gpm_0 },
	{ gf100_grctx_init_gcc_0 },
	{}
};

static const struct gf100_gr_init
gf119_grctx_init_tex_0[] = {
	{ 0x419a00,   1, 0x04, 0x000001f0 },
	{ 0x419a04,   1, 0x04, 0x00000001 },
	{ 0x419a08,   1, 0x04, 0x00000023 },
	{ 0x419a0c,   1, 0x04, 0x00020000 },
	{ 0x419a10,   1, 0x04, 0x00000000 },
	{ 0x419a14,   1, 0x04, 0x00000200 },
	{ 0x419a1c,   1, 0x04, 0x00000000 },
	{ 0x419a20,   1, 0x04, 0x00000800 },
	{ 0x419ac4,   1, 0x04, 0x0017f440 },
	{}
};

static const struct gf100_gr_init
gf119_grctx_init_mpc_0[] = {
	{ 0x419c00,   1, 0x04, 0x0000000a },
	{ 0x419c04,   1, 0x04, 0x00000006 },
	{ 0x419c08,   1, 0x04, 0x00000002 },
	{ 0x419c20,   1, 0x04, 0x00000000 },
	{ 0x419c24,   1, 0x04, 0x00084210 },
	{ 0x419c28,   1, 0x04, 0x3cf3cf3c },
	{}
};

const struct gf100_gr_init
gf119_grctx_init_sm_0[] = {
	{ 0x419e04,   3, 0x04, 0x00000000 },
	{ 0x419e10,   1, 0x04, 0x00000002 },
	{ 0x419e44,   1, 0x04, 0x001beff2 },
	{ 0x419e48,   1, 0x04, 0x00000000 },
	{ 0x419e4c,   1, 0x04, 0x0000000f },
	{ 0x419e50,  17, 0x04, 0x00000000 },
	{ 0x419e98,   1, 0x04, 0x00000000 },
	{ 0x419ee0,   1, 0x04, 0x00010110 },
	{ 0x419f30,  11, 0x04, 0x00000000 },
	{}
};

static const struct gf100_gr_pack
gf119_grctx_pack_tpc[] = {
	{ gf108_grctx_init_pe_0 },
	{ gf119_grctx_init_tex_0 },
	{ gf108_grctx_init_wwdx_0 },
	{ gf119_grctx_init_mpc_0 },
	{ gf104_grctx_init_l1c_0 },
	{ gf108_grctx_init_tpccs_0 },
	{ gf119_grctx_init_sm_0 },
	{}
};

/*******************************************************************************
 * PGRAPH context implementation
 ******************************************************************************/

struct nvkm_oclass *
gf119_grctx_oclass = &(struct gf100_grctx_oclass) {
	.base.handle = NV_ENGCTX(GR, 0xd9),
	.base.ofuncs = &(struct nvkm_ofuncs) {
		.ctor = gf100_gr_context_ctor,
		.dtor = gf100_gr_context_dtor,
		.init = _nvkm_gr_context_init,
		.fini = _nvkm_gr_context_fini,
		.rd32 = _nvkm_gr_context_rd32,
		.wr32 = _nvkm_gr_context_wr32,
	},
	.main  = gf100_grctx_generate_main,
	.unkn  = gf108_grctx_generate_unkn,
	.hub   = gf119_grctx_pack_hub,
	.gpc   = gf119_grctx_pack_gpc,
	.zcull = gf100_grctx_pack_zcull,
	.tpc   = gf119_grctx_pack_tpc,
	.icmd  = gf119_grctx_pack_icmd,
	.mthd  = gf119_grctx_pack_mthd,
	.bundle = gf100_grctx_generate_bundle,
	.bundle_size = 0x1800,
	.pagepool = gf100_grctx_generate_pagepool,
	.pagepool_size = 0x8000,
	.attrib = gf108_grctx_generate_attrib,
	.attrib_nr_max = 0x324,
	.attrib_nr = 0x218,
	.alpha_nr_max = 0x324,
	.alpha_nr = 0x218,
}.base;
