void calibration_sensor_offset()
{
  int v0; // r4
  uint8_t *chain_exist; // r5
  int v2; // t1

  LOBYTE(v0) = 0;
  chain_exist = dev.chain_exist;
  do
  {
    v2 = *chain_exist++;
    if ( v2 == 1 )
    {
      calibration_sensor_offset_chain(v0);
      cgsleep_ms(200);
    }
    v0 = (unsigned __int8)(v0 + 1);
  }
  while ( v0 != 4 );
}
