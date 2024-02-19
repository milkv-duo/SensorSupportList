#ifndef __F352_CMOS_PARAM_H_
#define __F352_CMOS_PARAM_H_

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#ifdef ARCH_CV182X
#include <linux/cvi_vip_cif.h>
#include <linux/cvi_vip_snsr.h>
#include "cvi_type.h"
#else
#include <linux/cif_uapi.h>
#include <linux/vi_snsr.h>
#include <linux/cvi_type.h>
#endif
#include "cvi_sns_ctrl.h"
#include "f352_cmos_ex.h"

static const F352_MODE_S g_astF352_mode[F352_MODE_NUM] = {
	[F352_MODE_1080P30] = {
		.name = "1080p30",
		.astImg[0] = {
			.stSnsSize = {
				.u32Width = 1920,
				.u32Height = 1080,
			},
			.stWndRect = {
				.s32X = 0,
				.s32Y = 0,
				.u32Width = 1920,
				.u32Height = 1080,
			},
			.stMaxSize = {
				.u32Width = 1920,
				.u32Height = 1080,
			},
		},
		.f32MaxFps = 30,
		.f32MinFps = 0.52, /* 1125 * 30 / 0xFFFF */
		.u32HtsDef = 2560,
		.u32VtsDef = 1125,
		.stExp[0] = {
			.u16Min = 1,
			.u16Max = 1125,
			.u16Def = 400,
			.u16Step = 1,
		},
		.stAgain[0] = {
			.u16Min = 1024,
			.u16Max = 63488,
			.u16Def = 1024,
			.u16Step = 1,
		},
		.stDgain[0] = {
			.u16Min = 1024,
			.u16Max = 4096,
			.u16Def = 1024,
			.u16Step = 1,
		},
		.u8DgainReg = 0xF0,
	},
	[F352_MODE_1080P30_WDR] = {
		.name = "1080p30wdr",
		.astImg[0] = {
			.stSnsSize = {
				.u32Width = 1928,
				.u32Height = 1088,
			},
			.stWndRect = {
				.s32X = 0,
				.s32Y = 0,
				.u32Width = 1920,
				.u32Height = 1080,
			},
			.stMaxSize = {
				.u32Width = 1928,
				.u32Height = 1088,
			},
		},
		.astImg[1] = {
			.stSnsSize = {
				.u32Width = 1928,
				.u32Height = 1088,
			},
			.stWndRect = {
				.s32X = 0,
				.s32Y = 0,
				.u32Width = 1920,
				.u32Height = 1080,
			},
			.stMaxSize = {
				.u32Width = 1928,
				.u32Height = 1088,
			},
		},
		.f32MaxFps = 30,
		.f32MinFps = 1.03, /* 1125 * 30 / 0xFFFF */
		.u32HtsDef = 2560,
		.u32VtsDef = 1125,
		.stExp[0] = {
			.u16Min = 1,
			.u16Max = 71,
			.u16Def = 7,
			.u16Step = 2,
		},
		.stExp[1] = {
			.u16Min = 71,
			.u16Max = 1047,	//1125-7-71
			.u16Def = 200,
			.u16Step = 1,
		},
		.stAgain[0] = {
			.u16Min = 1024,
			.u16Max = 1024,
			.u16Def = 1024,
			.u16Step = 1,
		},
		.stAgain[1] = {
			.u16Min = 1024,
			.u16Max = 63488,
			.u16Def = 1024,
			.u16Step = 1,
		},
		.stDgain[0] = {
			.u16Min = 1024,
			.u16Max = 1024,
			.u16Def = 1024,
			.u16Step = 1,
		},
		.stDgain[1] = {
			.u16Min = 1024,
			.u16Max = 4096,
			.u16Def = 1024,
			.u16Step = 1,
		},
		.u8DgainReg = 0xF0,
		.u32L2S_MAX = 0x12,
	},
};

static ISP_CMOS_NOISE_CALIBRATION_S g_stIspNoiseCalibratio = {.CalibrationCoef = {
	{	//iso  100
		{0.04988861083984375000,	4.38765525817871093750}, //B: slope, intercept
		{0.04792890325188636780,	3.92597246170043945313}, //Gb: slope, intercept
		{0.04811932146549224854,	3.89808440208435058594}, //Gr: slope, intercept
		{0.05060157552361488342,	4.38360261917114257813}, //R: slope, intercept
	},
	{	//iso  200
		{0.05668020620942115784,	8.36383914947509765625}, //B: slope, intercept
		{0.05190096050500869751,	9.12379550933837890625}, //Gb: slope, intercept
		{0.05187550559639930725,	9.15234565734863281250}, //Gr: slope, intercept
		{0.05625439062714576721,	8.55138778686523437500}, //R: slope, intercept
	},
	{	//iso  400
		{0.06673676520586013794,	14.12210369110107421875}, //B: slope, intercept
		{0.05751207098364830017,	16.82577514648437500000}, //Gb: slope, intercept
		{0.05804729461669921875,	16.61601066589355468750}, //Gr: slope, intercept
		{0.06506298482418060303,	14.56138515472412109375}, //R: slope, intercept
	},
	{	//iso  800
		{0.08542215079069137573,	21.73256301879882812500}, //B: slope, intercept
		{0.06953971832990646362,	27.63131332397460937500}, //Gb: slope, intercept
		{0.06944745033979415894,	27.69048118591308593750}, //Gr: slope, intercept
		{0.08224378526210784912,	22.75174522399902343750}, //R: slope, intercept
	},
	{	//iso  1600
		{0.10555629432201385498,	33.52949905395507812500}, //B: slope, intercept
		{0.08282581716775894165,	43.78954315185546875000}, //Gb: slope, intercept
		{0.08244660496711730957,	43.95007705688476562500}, //Gr: slope, intercept
		{0.09990881383419036865,	35.52837753295898437500}, //R: slope, intercept
	},
	{	//iso  3200
		{0.13504384458065032959,	52.07051086425781250000}, //B: slope, intercept
		{0.10585222393274307251,	68.38363647460937500000}, //Gb: slope, intercept
		{0.10607221722602844238,	68.20414733886718750000}, //Gr: slope, intercept
		{0.12796562910079956055,	55.04695510864257812500}, //R: slope, intercept
	},
	{	//iso  6400
		{0.17905426025390625000,	79.02329254150390625000}, //B: slope, intercept
		{0.15150412917137145996,	96.57375335693359375000}, //Gb: slope, intercept
		{0.14989413321018218994,	96.65535736083984375000}, //Gr: slope, intercept
		{0.16942876577377319336,	83.51070404052734375000}, //R: slope, intercept
	},
	{	//iso  12800
		{0.17905426025390625000,	79.02329254150390625000}, //B: slope, intercept
		{0.15150412917137145996,	96.57375335693359375000}, //Gb: slope, intercept
		{0.14989413321018218994,	96.65535736083984375000}, //Gr: slope, intercept
		{0.16942876577377319336,	83.51070404052734375000}, //R: slope, intercept
	},
	{	//iso  25600
		{0.17905426025390625000,	79.02329254150390625000}, //B: slope, intercept
		{0.15150412917137145996,	96.57375335693359375000}, //Gb: slope, intercept
		{0.14989413321018218994,	96.65535736083984375000}, //Gr: slope, intercept
		{0.16942876577377319336,	83.51070404052734375000}, //R: slope, intercept
	},
	{	//iso  51200
		{0.17905426025390625000,	79.02329254150390625000}, //B: slope, intercept
		{0.15150412917137145996,	96.57375335693359375000}, //Gb: slope, intercept
		{0.14989413321018218994,	96.65535736083984375000}, //Gr: slope, intercept
		{0.16942876577377319336,	83.51070404052734375000}, //R: slope, intercept
	},
	{	//iso  102400
		{0.17905426025390625000,	79.02329254150390625000}, //B: slope, intercept
		{0.15150412917137145996,	96.57375335693359375000}, //Gb: slope, intercept
		{0.14989413321018218994,	96.65535736083984375000}, //Gr: slope, intercept
		{0.16942876577377319336,	83.51070404052734375000}, //R: slope, intercept
	},
	{	//iso  204800
		{0.17905426025390625000,	79.02329254150390625000}, //B: slope, intercept
		{0.15150412917137145996,	96.57375335693359375000}, //Gb: slope, intercept
		{0.14989413321018218994,	96.65535736083984375000}, //Gr: slope, intercept
		{0.16942876577377319336,	83.51070404052734375000}, //R: slope, intercept
	},
	{	//iso  409600
		{0.17905426025390625000,	79.02329254150390625000}, //B: slope, intercept
		{0.15150412917137145996,	96.57375335693359375000}, //Gb: slope, intercept
		{0.14989413321018218994,	96.65535736083984375000}, //Gr: slope, intercept
		{0.16942876577377319336,	83.51070404052734375000}, //R: slope, intercept
	},
	{	//iso  819200
		{0.17905426025390625000,	79.02329254150390625000}, //B: slope, intercept
		{0.15150412917137145996,	96.57375335693359375000}, //Gb: slope, intercept
		{0.14989413321018218994,	96.65535736083984375000}, //Gr: slope, intercept
		{0.16942876577377319336,	83.51070404052734375000}, //R: slope, intercept
	},
	{	//iso  1638400
		{0.17905426025390625000,	79.02329254150390625000}, //B: slope, intercept
		{0.15150412917137145996,	96.57375335693359375000}, //Gb: slope, intercept
		{0.14989413321018218994,	96.65535736083984375000}, //Gr: slope, intercept
		{0.16942876577377319336,	83.51070404052734375000}, //R: slope, intercept
	},
	{	//iso  3276800
		{0.17905426025390625000,	79.02329254150390625000}, //B: slope, intercept
		{0.15150412917137145996,	96.57375335693359375000}, //Gb: slope, intercept
		{0.14989413321018218994,	96.65535736083984375000}, //Gr: slope, intercept
		{0.16942876577377319336,	83.51070404052734375000}, //R: slope, intercept
	},
} };

static ISP_CMOS_BLACK_LEVEL_S g_stIspBlcCalibratio = {
	.bUpdate = CVI_TRUE,
	.blcAttr = {
		.Enable = 1,
		.enOpType = OP_TYPE_AUTO,
		.stManual = {64, 64, 64, 64, 0, 0, 0, 0
#ifdef ARCH_CV182X
			, 1096, 1096, 1096, 1096
#endif
		},
		.stAuto = {
			{64, 64, 64, 64, 64, 64, 64, 64, 64, /*8*/64, 64, 64, 64, 64, 64, 64},
			{64, 64, 64, 64, 64, 64, 64, 64, 64, /*8*/64, 64, 64, 64, 64, 64, 64},
			{64, 64, 64, 64, 64, 64, 64, 64, 64, /*8*/64, 64, 64, 64, 64, 64, 64},
			{64, 64, 64, 64, 64, 64, 64, 64, 64, /*8*/64, 64, 64, 64, 64, 64, 64},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
#ifdef ARCH_CV182X
			{1040, 1040, 1040, 1040, 1042, 1059, 1097, 1091,
					/*8*/1091, 1091, 1091, 1091, 1091, 1091, 1091, 1091},
			{1040, 1040, 1040, 1040, 1042, 1059, 1092, 1091,
					/*8*/1091, 1091, 1091, 1091, 1091, 1091, 1091, 1091},
			{1040, 1040, 1040, 1040, 1042, 1057, 1097, 1096,
					/*8*/1091, 1091, 1091, 1091, 1097, 1091, 1091, 1091},
			{1040, 1040, 1040, 1040, 1042, 1057, 1092, 1096,
					/*8*/1091, 1091, 1091, 1091, 1091, 1091, 1091, 1091},
#endif
		},
	},
};

struct combo_dev_attr_s f352_rx_attr = {
	.input_mode = INPUT_MODE_MIPI,
	.mac_clk = RX_MAC_CLK_200M,
	.mipi_attr = {
		.raw_data_type = RAW_DATA_10BIT,
		.lane_id = {2, 3, 1, -1, -1},
		.pn_swap = {1, 1, 1, 0, 0},
		.wdr_mode = CVI_MIPI_WDR_MODE_MANUAL,
		.dphy = {
			.enable = 1,
			.hs_settle = 6,
		},
	},
	.mclk = {
		.cam = 0,
		.freq = CAMPLL_FREQ_24M,
	},
	.devno = 0,
};

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* End of #ifdef __cplusplus */


#endif /* __F352_CMOS_PARAM_H_ */
