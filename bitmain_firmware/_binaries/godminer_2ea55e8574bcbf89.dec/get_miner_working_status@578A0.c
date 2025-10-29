int __fastcall get_miner_working_status(int result)
{
  int v1; // r1
  char v2; // r3

  if ( !byte_17427C )
  {
    byte_174280 = 0;
    byte_174281 = 0;
    byte_174282 = 0;
    byte_174283 = 0;
    byte_174284 = 0;
    byte_174285 = 0;
    byte_174287 = 0;
    byte_174288 = 0;
    byte_17427C = 1;
    byte_174286 = pools_active == 0;
  }
  v1 = *(_DWORD *)&byte_174284;
  v2 = byte_174288;
  *(_DWORD *)result = *(_DWORD *)&byte_174280;
  *(_DWORD *)(result + 4) = v1;
  *(_BYTE *)(result + 8) = v2;
  return result;
}
