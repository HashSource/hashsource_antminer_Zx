void __cdecl set_PIC16F1704_voltage_z9(uint32_t i2c, uint8_t chain, uint16_t vol)
{
  uint16_t vola; // [sp+10h] [bp+0h] BYREF
  uint8_t chaina; // [sp+13h] [bp+3h]
  uint32_t i2ca; // [sp+14h] [bp+4h]
  size_t i; // [sp+1Ch] [bp+Ch]

  i2ca = i2c;
  chaina = chain;
  vola = vol;
  for ( i = 0; i <= 3; ++i )
  {
    PIC16F1704_i2c_forward_send(i2ca, chaina, isl68127_i2c_dev_addr[i], 0, 0, 1, 0);
    PIC16F1704_i2c_forward_send(i2ca, chaina, isl68127_i2c_dev_addr[i], 0, 0x21u, 2, (uint8_t *)&vola);
  }
}
