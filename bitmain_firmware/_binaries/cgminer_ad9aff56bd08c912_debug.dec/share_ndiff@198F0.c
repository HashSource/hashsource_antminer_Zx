uint64_t __fastcall share_ndiff(const work *work)
{
  double v2; // d9
  unsigned __int64 v3; // r0
  double v4; // d8

  if ( !work )
    return 0;
  v2 = 2.69595353e67;
  v3 = *(_QWORD *)&work->hash[24];
  if ( opt_scrypt )
    v2 = 1.7668201e72;
  v4 = (double)*(unsigned __int64 *)work->hash
     + (double)v3 * 6.27710174e57
     + (double)*(unsigned __int64 *)&work->hash[16] * 3.40282367e38
     + (double)*(unsigned __int64 *)&work->hash[8] * 1.84467441e19;
  if ( v4 == 0.0 )
    return 0;
  else
    return (unsigned __int64)(v2 / v4);
}
