void __fastcall update_asics_voltage(int vol)
{
  char reg_data[4]; // [sp+4h] [bp-4h] BYREF

  *(_DWORD *)reg_data = 0;
  ISL_get_i2c_data(0, (uint8_t *)reg_data, 1);
  if ( (unsigned __int8)(reg_data[0] - 2) > 0xFCu )
    update_asics_vol(vol);
  else
    XDPED_update_asics_vol(vol);
  sleep(1u);
}
