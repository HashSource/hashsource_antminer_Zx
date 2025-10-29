void __fastcall set_PWM(unsigned __int8 pwm_percent)
{
  int v1; // r0
  uint8_t v2; // r1
  unsigned int *v3; // r2

  if ( (int)pwm_percent <= 39 )
  {
    *(_DWORD *)&pwm_percent = 40;
  }
  else if ( (int)pwm_percent > 100 )
  {
    v1 = 6553600;
    v2 = 100;
    goto LABEL_7;
  }
  if ( gMinerStatus_Not_read_all_sensor )
  {
    v1 = 6553600;
    v2 = 100;
  }
  else
  {
    v2 = pwm_percent;
    v1 = (100 - pwm_percent) | (pwm_percent << 16);
  }
LABEL_7:
  v3 = axi_fpga_addr;
  dev.pwm_percent = v2;
  axi_fpga_addr[33] = v1;
  v3[40] = v1;
}
