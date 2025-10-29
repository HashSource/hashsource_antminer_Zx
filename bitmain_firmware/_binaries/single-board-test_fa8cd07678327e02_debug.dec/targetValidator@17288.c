uint32_t __cdecl targetValidator(const uint8_t *work, const uint8_t *nonce, uint8_t *target)
{
  int v3; // r1
  int v4; // r2
  int v5; // r3
  int v6; // r1
  int v7; // r2
  int v8; // r3
  uint8_t output[32]; // [sp+14h] [bp+14h] BYREF
  uint8_t tmphash[32]; // [sp+34h] [bp+34h] BYREF
  uint8_t input[1487]; // [sp+54h] [bp+54h] BYREF
  uint8_t str[3]; // [sp+624h] [bp+624h]

  *(_WORD *)str = 16637;
  str[2] = 5;
  memset(input, 0, sizeof(input));
  memset(tmphash, 0, sizeof(tmphash));
  memset(output, 0, sizeof(output));
  memcpy(input, work, 0x8Cu);
  *(_WORD *)&input[140] = 16637;
  input[142] = 5;
  memcpy(&input[143], nonce, 0x540u);
  Sha256_Onestep(input, 0x5CFu, tmphash);
  Sha256_Onestep(tmphash, 0x20u, output);
  v3 = *(_DWORD *)&output[4];
  v4 = *(_DWORD *)&output[8];
  v5 = *(_DWORD *)&output[12];
  *(_DWORD *)target = *(_DWORD *)output;
  *((_DWORD *)target + 1) = v3;
  *((_DWORD *)target + 2) = v4;
  *((_DWORD *)target + 3) = v5;
  v6 = *(_DWORD *)&output[20];
  v7 = *(_DWORD *)&output[24];
  v8 = *(_DWORD *)&output[28];
  *((_DWORD *)target + 4) = *(_DWORD *)&output[16];
  *((_DWORD *)target + 5) = v6;
  *((_DWORD *)target + 6) = v7;
  *((_DWORD *)target + 7) = v8;
  return target_zero_cal(output);
}
