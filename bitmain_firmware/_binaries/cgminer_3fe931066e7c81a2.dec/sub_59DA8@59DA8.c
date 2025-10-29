_DWORD *sub_59DA8()
{
  _DWORD *v0; // r0
  _DWORD *v1; // r4

  v0 = sub_5956C(0x24u);
  v1 = v0;
  if ( !v0 )
    return 0;
  v0[1] = 1;
  *v0 = 0;
  if ( sub_579F4(v0 + 2) )
  {
    sub_59594(v1);
    return 0;
  }
  else
  {
    v1[7] = 0;
    v1[8] = 0;
    return v1;
  }
}
