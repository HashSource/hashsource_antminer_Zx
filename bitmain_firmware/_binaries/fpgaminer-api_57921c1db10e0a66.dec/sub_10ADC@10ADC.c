void sub_10ADC()
{
  __asm { VMRS            R3, FPSCR }
  _R3 |= 0x1000000u;
  __asm { VMSR            FPSCR, R3 }
}
