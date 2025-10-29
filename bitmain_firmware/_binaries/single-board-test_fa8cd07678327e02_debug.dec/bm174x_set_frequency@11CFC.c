void __cdecl bm174x_set_frequency(int fd, uint32_t freq)
{
  char tmp42[1024]; // [sp+Ch] [bp+Ch] BYREF
  base_type_t item; // [sp+40Ch] [bp+40Ch] BYREF
  uint32_t pll_value; // [sp+414h] [bp+414h] BYREF

  pll_value = 0;
  if ( use_syslog || opt_log_output || opt_log_level > 1 )
  {
    snprintf(tmp42, 0x400u, "Set frequency %u\n", freq);
    applog(2, tmp42, 0);
  }
  get_plldata(freq, &pll_value);
  item.chip_addr = 0;
  item.all = 1;
  item.addr = 12;
  item.data = pll_value;
  reg_value.pll_parameter = pll_value;
  midd_ioctl(fd, 1u, &item);
}
