#include "main.h"

/**
 * init_prmtr - clearsthe field in struct and resets the buf
 * @prmtr: tis is the struct of the parameter
 * @ap: pointer to argument
 * Return: void
 */

void init_prmtr(pmtrs_t *prmtr, va_list ap)
{
	prmtr->usg = 0;

	prmtr->flg_pls = 0;
	prmtr->flg_sp = 0;
	prmtr->flg_htag = 0;
	prmtr->flg_z = 0;
	prmtr->flg_ms = 0;

	prmtr->width = 0;
	prmtr->precision = UINT_MAX;

	prmtr->modi_h = 0;
	prmtr->l_modifier = 0;
	(void)ap;
}
