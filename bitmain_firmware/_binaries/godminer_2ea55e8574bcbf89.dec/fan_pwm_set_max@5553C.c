int fan_pwm_set_max()
{
  int result; // r0

  if ( !byte_1741FC )
  {
    dword_174200 = pwm_init(0, 100);
    byte_1741FC = 1;
  }
  result = fan_pwm_get();
  if ( result != 100 )
    return pwm_set(dword_174200, 0x64u);
  return result;
}
