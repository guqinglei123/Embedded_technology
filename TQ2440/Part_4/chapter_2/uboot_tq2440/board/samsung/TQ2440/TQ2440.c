/*
 * (C) Copyright 2002
 * Sysgo Real-Time Solutions, GmbH <www.elinos.com>
 * Marius Groeger <mgroeger@sysgo.de>
 *
 * (C) Copyright 2002, 2010
 * David Mueller, ELSOFT AG, <d.mueller@elsoft.ch>
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#include <common.h>
#include <netdev.h>
#include <asm/io.h>
#include <asm/arch/s3c24x0_cpu.h>

void display_p15_c1c2c3(void)
{
    unsigned int iCP15_Cx_Data = 0;
	asm("mrc p15, 0, %0, c1, c0, 0" : "=r" (iCP15_Cx_Data) : : "cc");
	printf("    p15->c1 = 0x%X\n", iCP15_Cx_Data);
	asm("mrc p15, 0, %0, c2, c0, 0" : "=r" (iCP15_Cx_Data) : : "cc");
	printf("    p15->c2 = 0x%X\n", iCP15_Cx_Data);
	asm("mrc p15, 0, %0, c3, c0, 0" : "=r" (iCP15_Cx_Data) : : "cc");
	printf("    p15->c3 = 0x%X\n", iCP15_Cx_Data);
}


DECLARE_GLOBAL_DATA_PTR;       //register volatile gd_t *gd asm ("r8")

#define M_MDIV	117
#define M_PDIV	3
#define M_SDIV	1

#define U_M_MDIV	56
#define U_M_PDIV	2
#define U_M_SDIV	2

static inline void pll_delay(unsigned long loops)
{
	__asm__ volatile ("1:\n"
	  "subs %0, %1, #1\n"
	  "bne 1b":"=r" (loops):"0" (loops));
}

/*
 * Miscellaneous platform dependent initialisations
 */

int board_early_init_f(void)
{
	struct s3c24x0_clock_power * const clk_power =
					s3c24x0_get_base_clock_power();
	struct s3c24x0_gpio * const gpio = s3c24x0_get_base_gpio();

	/* to reduce PLL lock time, adjust the LOCKTIME register */
	writel(0xFFFFFF, &clk_power->locktime);

	__asm__(
    	"mrc    p15, 0, r1, c1, c0, 0\n"        // �������ƼĴ��� 
    	"orr    r1, r1, #0xc0000000\n"          // ����Ϊ��asynchronous bus mode��
    	"mcr    p15, 0, r1, c1, c0, 0" 	        // д����ƼĴ���
    	::
    	);

	writel((U_M_MDIV << 12) + (U_M_PDIV << 4) + U_M_SDIV,
	       &clk_power->upllcon);

	pll_delay(4000);

	writel((M_MDIV << 12) + (M_PDIV << 4) + M_SDIV,
	       &clk_power->mpllcon);

	writel(0x007FFFFF, &gpio->gpacon);
	writel(0x00295555, &gpio->gpbcon);
	writel(0x000007FF, &gpio->gpbup); 
	writel(0xAAAA02A8, &gpio->gpccon);
	writel(0x00000000, &gpio->gpcup);
	writel(0xAAAAAAAA, &gpio->gpdcon);
	writel(0x00000000, &gpio->gpdup);
	writel(0xAAAAAAAA, &gpio->gpecon);
	writel(0x0000FFFF, &gpio->gpeup); 
	writel(0x0000AAAA, &gpio->gpfcon);
	writel(0x00000000, &gpio->gpfup);
	writel(0x56A9ABBA, &gpio->gpgcon); 
	writel(0x0000FC10, &gpio->gpgup); 
	writel(0x0028FAAA, &gpio->gphcon);
	writel(0x00000000, &gpio->gphup);
	
	return 0;
}

int board_init(void)
{
	/* arch number of S3C2440-Board */
	gd->bd->bi_arch_number = MACH_TYPE_S3C2440;
	/************************************************/

	/* adress of boot parameters */
	gd->bd->bi_boot_params = 0x30000100;

	icache_enable();
	dcache_enable();
	
	puts("Caches & MMU :\n");
    display_p15_c1c2c3();

	return 0;
}

int dram_init(void)
{
	/* dram_init must store complete ramsize in gd->ram_size */
	gd->ram_size = PHYS_SDRAM_1_SIZE;
	return 0;
}

#ifdef CONFIG_CMD_NET
int board_eth_init(bd_t *bis)
{
	int rc = 0;	
#ifdef CONFIG_DRIVER_DM9000
    rc = dm9000_initialize(gd->bd);
#endif
	return rc;
}
#endif

/*
 * Hardcoded flash setup:
 * Flash 0 is a non-CFI AMD AM29LV800BB flash.
 */
#ifndef CONFIG_SYS_NO_FLASH
ulong board_flash_get_legacy(ulong base, int banknum, flash_info_t *info)
{
	info->portwidth = FLASH_CFI_16BIT;
	info->chipwidth = FLASH_CFI_BY16;
	info->interface = FLASH_CFI_X16;
	return 1;
}
#endif



