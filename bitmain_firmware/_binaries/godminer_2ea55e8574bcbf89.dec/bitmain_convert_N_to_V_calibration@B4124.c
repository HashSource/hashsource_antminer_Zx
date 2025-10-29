void bitmain_convert_N_to_V_calibration()
{
  char *v0; // r12
  double *v1; // r2

  if ( dword_18578C > 1 )
  {
    v0 = (char *)&unk_185791;
    v1 = &dbl_1857E0;
    do
    {
      ++v0;
      ++v1;
    }
    while ( &byte_185790[dword_18578C] != v0 );
  }
}
