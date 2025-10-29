void __fastcall update_asic_vol(int which_chain, int which_asic, int vol)
{
  uint8_t v6; // r0
  unsigned __int16 g_vol; // [sp+6h] [bp-2h] BYREF

  pthread_mutex_lock(&iic_mutex);
  v6 = *((_BYTE *)&bitmainZCASH_drv + which_asic + 128);
  g_vol = 0;
  i2c_slave_addr = which_chain;
  ISL_get_voltage(v6, &g_vol);
  if ( g_vol > vol + 5 || g_vol < vol - 5 )
  {
    ISL_set_voltage_dynamic(*((_BYTE *)&bitmainZCASH_drv + which_asic + 128), vol);
    cgsleep_ms(200);
  }
  pthread_mutex_unlock(&iic_mutex);
}
