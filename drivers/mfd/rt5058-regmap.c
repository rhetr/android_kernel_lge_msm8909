/* drivers/mfd/rt5058-regmap.c
 * Source file for Richtek RT5058 debug interface
 *
 * Copyright (C) 2015 Richtek Technology Corp.
 * Jeff Chang <jeff_chang@richtek.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 */


#include <linux/module.h>
#include <linux/mfd/rt5058/rt5058.h>

#ifdef CONFIG_RT_REGMAP
/* RT5058 CORE */
RT_REG_DECL(RT5058_REG_DEVINFO, 1, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_CORECTRL1, 1, RT_NORMAL, {});
RT_REG_DECL(RT5058_REG_CORECTRL2, 1, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_RSTPASCODE1, 1, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_RSTPASCODE2, 1, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_PASCODE1, 1, RT_NORMAL, {});
RT_REG_DECL(RT5058_REG_PASCODE2, 1, RT_NORMAL, {});
RT_REG_DECL(RT5058_REG_IRQIND, 1, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_IRQMSK, 1, RT_NORMAL, {});
RT_REG_DECL(RT5058_REG_IRQSET, 1, RT_NORMAL, {});

/* RT5058 CHARGER */
RT_REG_DECL(RT5058_REG_MUICCTRL1, 1, RT_NORMAL, {});
RT_REG_DECL(RT5058_REG_MUICADC, 1, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_MUICTIMERSET, 1, RT_NORMAL, {});
RT_REG_DECL(RT5058_REG_MUICDEV1, 1, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_MUICDEV2, 1, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_MUICDEV3, 1, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_MUICBTN1, 1, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_MUICBTN2, 1, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_MUICMANSW1, 1, RT_NORMAL, {});
RT_REG_DECL(RT5058_REG_MUICMANSW2, 1, RT_NORMAL, {});
RT_REG_DECL(RT5058_REG_MUICSTBADC, 1, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_MUICCTRL2, 1, RT_NORMAL, {});
RT_REG_DECL(RT5058_REG_MUICCTRL3, 1, RT_NORMAL, {});
RT_REG_DECL(RT5058_REG_MUICCTRL4, 1, RT_NORMAL, {});
RT_REG_DECL(RT5058_REG_MUICUNSTBADC, 1, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_MUICHIDDEN1, 1, RT_NORMAL, {});
RT_REG_DECL(RT5058_REG_MUICHIDDEN2, 1, RT_NORMAL, {});

/* RT5058 MUIC */
RT_REG_DECL(RT5058_REG_CHGHIDDENCTRL1, 1, RT_NORMAL, {});
RT_REG_DECL(RT5058_REG_CHGHIDDENCTRL2, 1, RT_NORMAL, {});
RT_REG_DECL(RT5058_REG_CHGHIDDENCTRL3, 1, RT_NORMAL, {});
RT_REG_DECL(RT5058_REG_CHGHIDDENCTRL4, 1, RT_NORMAL, {});
RT_REG_DECL(RT5058_REG_CHGHIDDENCTRL5, 1, RT_NORMAL, {});
RT_REG_DECL(RT5058_REG_CHGHIDDENCTRL6, 1, RT_NORMAL, {});
RT_REG_DECL(RT5058_REG_CHGHIDDENCTRL7, 1, RT_NORMAL, {});
RT_REG_DECL(RT5058_REG_CHGHIDDENCTRL8, 1, RT_NORMAL, {});
RT_REG_DECL(RT5058_REG_CHGHIDDENCTRL9, 1, RT_NORMAL, {});
RT_REG_DECL(RT5058_REG_CHGSTAT, 1, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_CHGCTRL1, 1, RT_NORMAL, {});
RT_REG_DECL(RT5058_REG_CHGCTRL2, 1, RT_NORMAL, {});
RT_REG_DECL(RT5058_REG_CHGCTRL3, 1, RT_NORMAL, {});
/* AICR will be modified by AICL -> volatile */
RT_REG_DECL(RT5058_REG_CHGCTRL4, 1, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_CHGCTRL5, 1, RT_NORMAL, {});
RT_REG_DECL(RT5058_REG_CHGCTRL6, 1, RT_NORMAL, {});
RT_REG_DECL(RT5058_REG_CHGCTRL7, 1, RT_NORMAL, {});
RT_REG_DECL(RT5058_REG_CHGCTRL8, 1, RT_NORMAL, {});
RT_REG_DECL(RT5058_REG_CHGCTRL9, 1, RT_NORMAL, {});
RT_REG_DECL(RT5058_REG_CHGCTRL10, 1, RT_NORMAL, {});
RT_REG_DECL(RT5058_REG_CHGCTRL11, 1, RT_NORMAL, {});
RT_REG_DECL(RT5058_REG_CHGCTRL12, 1, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_CHGCTRL13, 1, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_CHGCTRL14, 1, RT_NORMAL, {});

/* RT5058 FLASHLIGHT LED */
RT_REG_DECL(RT5058_REG_FLEDCFG, 1, RT_NORMAL, {});
RT_REG_DECL(RT5058_REG_STRBEN, 1, RT_NORMAL, {});
RT_REG_DECL(RT5058_REG_FLED1CTRL, 1, RT_NORMAL, {});
RT_REG_DECL(RT5058_REG_FLED1STRBCTRL1, 1, RT_NORMAL, {});
RT_REG_DECL(RT5058_REG_FLED1STRBCTRL2, 1, RT_NORMAL, {});
RT_REG_DECL(RT5058_REG_FLED1TORCTRL, 1, RT_NORMAL, {});
RT_REG_DECL(RT5058_REG_FLED2CTRL, 1, RT_NORMAL, {});
RT_REG_DECL(RT5058_REG_FLED2STRBCTRL1, 1, RT_NORMAL, {});
RT_REG_DECL(RT5058_REG_FLED2STRBCTRL2, 1, RT_NORMAL, {});
RT_REG_DECL(RT5058_REG_FLED2TORCTRL, 1, RT_NORMAL, {});
RT_REG_DECL(RT5058_REG_FLEDVMIDTRK_CTRL1, 1, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_FLEDVMIDRTM, 1, RT_NORMAL, {});
RT_REG_DECL(RT5058_REG_FLEDVMIDTRK_CTRL2, 1, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_FLEDTASTAT, 1, RT_VOLATILE, {});

/* RT5058 PMIC */
RT_REG_DECL(RT5058_REG_BUCK1CFG1, 1, RT_NORMAL, {});
RT_REG_DECL(RT5058_REG_BUCK1CFG2, 1, RT_NORMAL, {});
RT_REG_DECL(RT5058_REG_BUCK1VOUT, 1, RT_NORMAL, {});
RT_REG_DECL(RT5058_REG_LDO1CFG, 1, RT_NORMAL, {});
RT_REG_DECL(RT5058_REG_LDO1VOUT, 1, RT_NORMAL, {});
RT_REG_DECL(RT5058_REG_LDO2CFG, 1, RT_NORMAL, {});
RT_REG_DECL(RT5058_REG_LDO2VOUT, 1, RT_NORMAL, {});
RT_REG_DECL(RT5058_REG_LDO3CFG, 1, RT_NORMAL, {});
RT_REG_DECL(RT5058_REG_LDO3VOUT, 1, RT_NORMAL, {});
RT_REG_DECL(RT5058_REG_SLDO1CFG, 1, RT_NORMAL, {});
RT_REG_DECL(RT5058_REG_SLDO1VOUT, 1, RT_NORMAL, {});
RT_REG_DECL(RT5058_REG_SLDO2CFG, 1, RT_NORMAL, {});
RT_REG_DECL(RT5058_REG_SLDO2VOUT, 1, RT_NORMAL, {});
RT_REG_DECL(RT5058_REG_PMICSHDNCTRL1, 1, RT_NORMAL, {});
RT_REG_DECL(RT5058_REG_PMICSHDNCTRL2, 1, RT_NORMAL, {});
RT_REG_DECL(RT5058_REG_PMICOFFEVT, 1, RT_VOLATILE, {});

/* RT5058 DIGITAL */
RT_REG_DECL(RT5058_REG_HIDDEN_PAS_CODE1, 1, RT_NORMAL, {});
RT_REG_DECL(RT5058_REG_HIDDEN_PAS_CODE2, 1, RT_NORMAL, {});
RT_REG_DECL(RT5058_REG_HIDDEN_PAS_CODE3, 1, RT_NORMAL, {});
RT_REG_DECL(RT5058_REG_HIDDEN_PAS_CODE4, 1, RT_NORMAL, {});

/* RT5058 IRQ MASK and Status */
RT_REG_DECL(RT5058_REG_MUIC_IRQ1, 1, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_MUIC_IRQ2, 1, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_MUIC_IRQ3, 1, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_CHG_IRQ1, 1, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_CHG_IRQ2, 1, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_CHG_IRQ3, 1, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_CHG_IRQ4, 1, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_CHG_IRQ5, 1, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_FLED_IRQ1, 1, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_FLED_IRQ2, 1, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_PMIC_IRQ1, 1, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_PMIC_IRQ2, 1, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_MUIC_STAT1, 1, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_MUIC_STAT2, 1, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_MUIC_STAT3, 1, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_CHG_STAT1, 1, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_CHG_STAT2, 1, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_CHG_STAT3, 1, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_CHG_STAT4, 1, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_CHG_STAT5, 1, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_FLED_STAT1, 1, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_FLED_STAT2, 1, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_PMIC_STAT1, 1, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_PMIC_STAT2, 1, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_MUIC_MASK1, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(RT5058_REG_MUIC_MASK2, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(RT5058_REG_MUIC_MASK3, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(RT5058_REG_CHG_MASK1, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(RT5058_REG_CHG_MASK2, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(RT5058_REG_CHG_MASK3, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(RT5058_REG_CHG_MASK4, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(RT5058_REG_CHG_MASK5, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(RT5058_REG_FLED_MASK1, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(RT5058_REG_FLED_MASK2, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(RT5058_REG_PMIC_MASK1, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(RT5058_REG_PMIC_MASK2, 1, RT_NORMAL_WR_ONCE, {});

/* RT5058 FUEL GAUGE */
RT_REG_DECL(RT5058_REG_FGOCV, 2, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_FGVBAT, 2, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_FGSOC, 2, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_FGCTRL, 2, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_FGVER, 2, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_FGCURR, 2, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_FGTEMP, 2, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_FGAI, 2, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_FGAV, 2, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_FGAT, 2, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_FGINTT, 2, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_FGDSNCAP, 2, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_FGBATCAP, 2, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_FGCYCCNT, 2, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_FGCYCBUF, 2, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_FGBATDETV, 2, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_FGOPCFG1, 2, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_FGOPCFG2, 2, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_FGOPCFG3, 2, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_FGSOCCFG1, 2, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_FGAGEFCT, 2, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_FGVGCOMP1_2, 2, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_FGVGCOMP3_4, 2, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_FGCSCOMP1, 2, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_FGCSCOMP2, 2, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_FGCSCOMP3, 2, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_FGCSCOMP4, 2, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_FGMFA, 2, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_FG_OTUTDET, 2, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_FG_UVDET, 2, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_FG_OSDET, 2, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_FG_USDET, 2, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_FG_SLP_V, 2, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_FG_CURRCALI, 2, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_FG_VOLTCALI, 2, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_FG_OEPTH, 2, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_FG_DEADBAND, 2, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_FGSOCCFG2, 2, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_FG_STATUS1, 2, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_FG_STATUS2, 2, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_FG_MASK1, 2, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(RT5058_REG_FG_MASK2, 2, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(RT5058_REG_FG_IRQ1, 2, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_FG_IRQ2, 2, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_FG_HIDDEN1, 2, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_FG_HIDDEN2, 2, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_FG_HIDDEN3, 2, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_FG_HIDDEN4, 2, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_FG_HIDDEN5, 2, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_FG_HIDDEN6, 2, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_FG_HIDDEN7, 2, RT_VOLATILE, {});
RT_REG_DECL(RT5058_REG_FG_HIDDEN8, 2, RT_VOLATILE, {});


static const rt_register_map_t rt5058_chip_regmap[] = {
	RT_REG(RT5058_REG_DEVINFO),
	RT_REG(RT5058_REG_CORECTRL1),
	RT_REG(RT5058_REG_CORECTRL2),
	RT_REG(RT5058_REG_RSTPASCODE1),
	RT_REG(RT5058_REG_RSTPASCODE2),
	RT_REG(RT5058_REG_PASCODE1),
	RT_REG(RT5058_REG_PASCODE2),
	RT_REG(RT5058_REG_IRQIND),
	RT_REG(RT5058_REG_IRQMSK),
	RT_REG(RT5058_REG_IRQSET),
	RT_REG(RT5058_REG_MUICCTRL1),
	RT_REG(RT5058_REG_MUICADC),
	RT_REG(RT5058_REG_MUICTIMERSET),
	RT_REG(RT5058_REG_MUICDEV1),
	RT_REG(RT5058_REG_MUICDEV2),
	RT_REG(RT5058_REG_MUICDEV3),
	RT_REG(RT5058_REG_MUICBTN1),
	RT_REG(RT5058_REG_MUICBTN2),
	RT_REG(RT5058_REG_MUICMANSW1),
	RT_REG(RT5058_REG_MUICMANSW2),
	RT_REG(RT5058_REG_MUICSTBADC),
	RT_REG(RT5058_REG_MUICCTRL2),
	RT_REG(RT5058_REG_MUICCTRL3),
	RT_REG(RT5058_REG_MUICCTRL4),
	RT_REG(RT5058_REG_MUICUNSTBADC),
	RT_REG(RT5058_REG_MUICHIDDEN1),
	RT_REG(RT5058_REG_MUICHIDDEN2),
	RT_REG(RT5058_REG_CHGHIDDENCTRL1),
	RT_REG(RT5058_REG_CHGHIDDENCTRL2),
	RT_REG(RT5058_REG_CHGHIDDENCTRL3),
	RT_REG(RT5058_REG_CHGHIDDENCTRL4),
	RT_REG(RT5058_REG_CHGHIDDENCTRL5),
	RT_REG(RT5058_REG_CHGHIDDENCTRL6),
	RT_REG(RT5058_REG_CHGHIDDENCTRL7),
	RT_REG(RT5058_REG_CHGHIDDENCTRL8),
	RT_REG(RT5058_REG_CHGHIDDENCTRL9),
	RT_REG(RT5058_REG_CHGSTAT),
	RT_REG(RT5058_REG_CHGCTRL1),
	RT_REG(RT5058_REG_CHGCTRL2),
	RT_REG(RT5058_REG_CHGCTRL3),
	RT_REG(RT5058_REG_CHGCTRL4),
	RT_REG(RT5058_REG_CHGCTRL5),
	RT_REG(RT5058_REG_CHGCTRL6),
	RT_REG(RT5058_REG_CHGCTRL7),
	RT_REG(RT5058_REG_CHGCTRL8),
	RT_REG(RT5058_REG_CHGCTRL9),
	RT_REG(RT5058_REG_CHGCTRL10),
	RT_REG(RT5058_REG_CHGCTRL11),
	RT_REG(RT5058_REG_CHGCTRL12),
	RT_REG(RT5058_REG_CHGCTRL13),
	RT_REG(RT5058_REG_CHGCTRL14),
	RT_REG(RT5058_REG_FLEDCFG),
	RT_REG(RT5058_REG_STRBEN),
	RT_REG(RT5058_REG_FLED1CTRL),
	RT_REG(RT5058_REG_FLED1STRBCTRL1),
	RT_REG(RT5058_REG_FLED1STRBCTRL2),
	RT_REG(RT5058_REG_FLED1TORCTRL),
	RT_REG(RT5058_REG_FLED2CTRL),
	RT_REG(RT5058_REG_FLED2STRBCTRL1),
	RT_REG(RT5058_REG_FLED2STRBCTRL2),
	RT_REG(RT5058_REG_FLED2TORCTRL),
	RT_REG(RT5058_REG_FLEDVMIDTRK_CTRL1),
	RT_REG(RT5058_REG_FLEDVMIDRTM),
	RT_REG(RT5058_REG_FLEDVMIDTRK_CTRL2),
	RT_REG(RT5058_REG_FLEDTASTAT),
	RT_REG(RT5058_REG_BUCK1CFG1),
	RT_REG(RT5058_REG_BUCK1CFG2),
	RT_REG(RT5058_REG_BUCK1VOUT),
	RT_REG(RT5058_REG_LDO1CFG),
	RT_REG(RT5058_REG_LDO1VOUT),
	RT_REG(RT5058_REG_LDO2CFG),
	RT_REG(RT5058_REG_LDO2VOUT),
	RT_REG(RT5058_REG_LDO3CFG),
	RT_REG(RT5058_REG_LDO3VOUT),
	RT_REG(RT5058_REG_SLDO1CFG),
	RT_REG(RT5058_REG_SLDO1VOUT),
	RT_REG(RT5058_REG_SLDO2CFG),
	RT_REG(RT5058_REG_SLDO2VOUT),
	RT_REG(RT5058_REG_PMICSHDNCTRL1),
	RT_REG(RT5058_REG_PMICSHDNCTRL2),
	RT_REG(RT5058_REG_PMICOFFEVT),
	RT_REG(RT5058_REG_HIDDEN_PAS_CODE1),
	RT_REG(RT5058_REG_HIDDEN_PAS_CODE2),
	RT_REG(RT5058_REG_HIDDEN_PAS_CODE3),
	RT_REG(RT5058_REG_HIDDEN_PAS_CODE4),
	RT_REG(RT5058_REG_MUIC_IRQ1),
	RT_REG(RT5058_REG_MUIC_IRQ2),
	RT_REG(RT5058_REG_MUIC_IRQ3),
	RT_REG(RT5058_REG_CHG_IRQ1),
	RT_REG(RT5058_REG_CHG_IRQ2),
	RT_REG(RT5058_REG_CHG_IRQ3),
	RT_REG(RT5058_REG_CHG_IRQ4),
	RT_REG(RT5058_REG_CHG_IRQ5),
	RT_REG(RT5058_REG_FLED_IRQ1),
	RT_REG(RT5058_REG_FLED_IRQ2),
	RT_REG(RT5058_REG_PMIC_IRQ1),
	RT_REG(RT5058_REG_PMIC_IRQ2),
	RT_REG(RT5058_REG_MUIC_STAT1),
	RT_REG(RT5058_REG_MUIC_STAT2),
	RT_REG(RT5058_REG_MUIC_STAT3),
	RT_REG(RT5058_REG_CHG_STAT1),
	RT_REG(RT5058_REG_CHG_STAT2),
	RT_REG(RT5058_REG_CHG_STAT3),
	RT_REG(RT5058_REG_CHG_STAT4),
	RT_REG(RT5058_REG_CHG_STAT5),
	RT_REG(RT5058_REG_FLED_STAT1),
	RT_REG(RT5058_REG_FLED_STAT2),
	RT_REG(RT5058_REG_PMIC_STAT1),
	RT_REG(RT5058_REG_PMIC_STAT2),
	RT_REG(RT5058_REG_MUIC_MASK1),
	RT_REG(RT5058_REG_MUIC_MASK2),
	RT_REG(RT5058_REG_MUIC_MASK3),
	RT_REG(RT5058_REG_CHG_MASK1),
	RT_REG(RT5058_REG_CHG_MASK2),
	RT_REG(RT5058_REG_CHG_MASK3),
	RT_REG(RT5058_REG_CHG_MASK4),
	RT_REG(RT5058_REG_CHG_MASK5),
	RT_REG(RT5058_REG_FLED_MASK1),
	RT_REG(RT5058_REG_FLED_MASK2),
	RT_REG(RT5058_REG_PMIC_MASK1),
	RT_REG(RT5058_REG_PMIC_MASK2),
	/* fuel gauge */
	RT_REG(RT5058_REG_FGOCV),
	RT_REG(RT5058_REG_FGVBAT),
	RT_REG(RT5058_REG_FGSOC),
	RT_REG(RT5058_REG_FGCTRL),
	RT_REG(RT5058_REG_FGVER),
	RT_REG(RT5058_REG_FGCURR),
	RT_REG(RT5058_REG_FGTEMP),
	RT_REG(RT5058_REG_FGAI),
	RT_REG(RT5058_REG_FGAV),
	RT_REG(RT5058_REG_FGAT),
	RT_REG(RT5058_REG_FGINTT),
	RT_REG(RT5058_REG_FGDSNCAP),
	RT_REG(RT5058_REG_FGBATCAP),
	RT_REG(RT5058_REG_FGCYCCNT),
	RT_REG(RT5058_REG_FGCYCBUF),
	RT_REG(RT5058_REG_FGBATDETV),
	RT_REG(RT5058_REG_FGOPCFG1),
	RT_REG(RT5058_REG_FGOPCFG2),
	RT_REG(RT5058_REG_FGOPCFG3),
	RT_REG(RT5058_REG_FGSOCCFG1),
	RT_REG(RT5058_REG_FGAGEFCT),
	RT_REG(RT5058_REG_FGVGCOMP1_2),
	RT_REG(RT5058_REG_FGVGCOMP3_4),
	RT_REG(RT5058_REG_FGCSCOMP1),
	RT_REG(RT5058_REG_FGCSCOMP2),
	RT_REG(RT5058_REG_FGCSCOMP3),
	RT_REG(RT5058_REG_FGCSCOMP4),
	RT_REG(RT5058_REG_FGMFA),
	RT_REG(RT5058_REG_FG_OTUTDET),
	RT_REG(RT5058_REG_FG_UVDET),
	RT_REG(RT5058_REG_FG_OSDET),
	RT_REG(RT5058_REG_FG_USDET),
	RT_REG(RT5058_REG_FG_SLP_V),
	RT_REG(RT5058_REG_FG_CURRCALI),
	RT_REG(RT5058_REG_FG_VOLTCALI),
	RT_REG(RT5058_REG_FG_OEPTH),
	RT_REG(RT5058_REG_FG_DEADBAND),
	RT_REG(RT5058_REG_FGSOCCFG2),
	RT_REG(RT5058_REG_FG_STATUS1),
	RT_REG(RT5058_REG_FG_STATUS2),
	RT_REG(RT5058_REG_FG_MASK1),
	RT_REG(RT5058_REG_FG_MASK2),
	RT_REG(RT5058_REG_FG_IRQ1),
	RT_REG(RT5058_REG_FG_IRQ2),
	RT_REG(RT5058_REG_FG_HIDDEN1),
	RT_REG(RT5058_REG_FG_HIDDEN2),
	RT_REG(RT5058_REG_FG_HIDDEN3),
	RT_REG(RT5058_REG_FG_HIDDEN4),
	RT_REG(RT5058_REG_FG_HIDDEN5),
	RT_REG(RT5058_REG_FG_HIDDEN6),
	RT_REG(RT5058_REG_FG_HIDDEN7),
	RT_REG(RT5058_REG_FG_HIDDEN8),
};
#define RT5058_CHIP_REGMAP_SIZE ARRAY_SIZE(rt5058_chip_regmap)

static struct rt_access_group rt5058_access_group[] = {
	{RT5058_REG_DEVINFO, RT5058_REG_PMIC_MASK2, RT_1BYTE_MODE},
	{RT5058_REG_FGOCV, RT5058_REG_FG_IRQ1, RT_2BYTE_MODE},
	{},
};

static struct rt_regmap_fops rt5058_regmap_fops = {
	.read_device = rt5058_read_device,
	.write_device = rt5058_write_device,
};

static struct rt_regmap_properties rt5058_chip_regmap_prop = {
	.register_num = RT5058_CHIP_REGMAP_SIZE,
	.rm = rt5058_chip_regmap,
	.group = rt5058_access_group,
	.rt_regmap_mode = RT_MULTI_BYTE | RT_CACHE_DISABLE |
				RT_IO_PASS_THROUGH | RT_DBG_GENERAL,
	.name = "rt5058",
	.aliases = "rt5058",
	.io_log_en = 0,
};
#endif /* #ifdef CONFIG_RT_REGMAP */

void rt5058_write_back_all_cache(struct rt5058_mfd_chip *chip)
{
	#ifdef CONFIG_RT_REGMAP
	int i = 0;

	for (i = 0; i < ARRAY_SIZE(rt5058_chip_regmap); i++) {
		rt_regmap_cache_write_back(chip->m_dev,
					rt5058_chip_regmap[i]->addr);
	}
	#endif /* CONFIG_RT_REGMAP */
}
EXPORT_SYMBOL(rt5058_write_back_all_cache);

int rt5058_regmap_init(struct rt5058_mfd_chip *chip)
{
#ifdef CONFIG_RT_REGMAP
	chip->m_dev = rt_regmap_device_register(&rt5058_chip_regmap_prop,
			&rt5058_regmap_fops, chip->dev, chip->client, chip);
	if (!chip->m_dev) {
		dev_err(chip->dev, "rt5058 chip rt_regmap register fail\n");
		return -EINVAL;
	}
#endif /* #ifdef CONFIG_RT_REGMAP */
	return 0;
}

int rt5058_regmap_deinit(struct rt5058_mfd_chip *chip)
{
#ifdef CONFIG_RT_REGMAP
	rt_regmap_device_unregister(chip->m_dev);
#endif /* #ifdef CONFIG_RT_REGMAP */
	return 0;
}