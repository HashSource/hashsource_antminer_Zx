void __cdecl get_plldata(uint32_t freq, uint32_t *vil_data)
{
  uint32_t i; // [sp+Ch] [bp+Ch]

  for ( i = 0; i <= 0x6D && freq_pll[i].freq != freq; ++i )
    ;
  if ( i == 110 )
    i = 4;
  *vil_data = freq_pll[i].vilpll;
}
