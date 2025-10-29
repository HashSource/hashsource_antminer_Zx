void __fastcall set_analog_mux_control(uint32_t value)
{
  uint8_t *chain_exist; // r5
  int v3; // r4
  int v4; // t1

  chain_exist = dev.chain_exist;
  LOBYTE(v3) = 0;
  do
  {
    v4 = *chain_exist++;
    if ( v4 == 1 )
      set_analog_mux_control_chain(v3, value);
    v3 = (unsigned __int8)(v3 + 1);
  }
  while ( v3 != 4 );
  cgsleep_ms(10);
}
