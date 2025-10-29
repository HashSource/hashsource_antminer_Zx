int __cdecl sortValidator(void *data, const unsigned __int8 *soln)
{
  int v2; // r3
  unsigned int v3; // r0
  int v4; // r1
  int v5; // r2
  int v6; // r3
  int v7; // r1
  int v8; // r2
  uint8_t tmpHash[52]; // [sp+14h] [bp+Ch] BYREF
  int i_4; // [sp+48h] [bp+40h] BYREF
  unsigned __int8 hash_0[32]; // [sp+4Ch] [bp+44h] BYREF
  unsigned __int8 hash[32]; // [sp+6Ch] [bp+64h] BYREF
  uint8_t tmp_data[1344]; // [sp+8Ch] [bp+84h] BYREF
  uint32_t real_indices[512]; // [sp+5CCh] [bp+5C4h] BYREF
  uint8_t tmp_hash[32]; // [sp+DCCh] [bp+DC4h] BYREF
  uint8_t vHash[30]; // [sp+DECh] [bp+DE4h] BYREF
  uint32_t indices[512]; // [sp+E0Ch] [bp+E04h] BYREF
  uint8_t *__tmp_0; // [sp+160Ch] [bp+1604h]
  uint8_t *__tmp; // [sp+1610h] [bp+1608h]
  int i_0; // [sp+1614h] [bp+160Ch]
  char *hex_buff; // [sp+1618h] [bp+1610h]
  int solnr; // [sp+161Ch] [bp+1614h]
  int equihashSolutionSize; // [sp+1620h] [bp+1618h]
  int hashOutput; // [sp+1624h] [bp+161Ch]
  int indicesPerHashOutput; // [sp+1628h] [bp+1620h]
  uint32_t hashLength; // [sp+162Ch] [bp+1624h]
  int collisionByteLength; // [sp+1630h] [bp+1628h]
  int collisionBitLength; // [sp+1634h] [bp+162Ch]
  blake2b_state *digest; // [sp+1638h] [bp+1630h]
  int k; // [sp+163Ch] [bp+1634h]
  int n; // [sp+1640h] [bp+1638h]
  const validData *v; // [sp+1644h] [bp+163Ch]
  uint32_t index_0; // [sp+1648h] [bp+1640h]
  uint32_t j_3; // [sp+164Ch] [bp+1644h]
  int i_5; // [sp+1650h] [bp+1648h]
  int j_2; // [sp+1654h] [bp+164Ch]
  int i_3; // [sp+1658h] [bp+1650h]
  uint32_t level; // [sp+165Ch] [bp+1654h]
  int i_2; // [sp+1660h] [bp+1658h]
  uint32_t index; // [sp+1664h] [bp+165Ch]
  size_t j_1; // [sp+1668h] [bp+1660h]
  int i_1; // [sp+166Ch] [bp+1664h]
  uint32_t m; // [sp+1670h] [bp+1668h]
  int j_0; // [sp+1674h] [bp+166Ch]
  int j; // [sp+1678h] [bp+1670h]
  int i; // [sp+167Ch] [bp+1674h]
  uint32_t xc_size; // [sp+1680h] [bp+1678h]
  uint8_t *xc; // [sp+1684h] [bp+167Ch]
  uint8_t *x; // [sp+1688h] [bp+1680h]
  int err_type; // [sp+168Ch] [bp+1684h]
  uint32_t x_size; // [sp+1690h] [bp+1688h]
  uint32_t indicesLen; // [sp+1694h] [bp+168Ch]

  v = (const validData *)data;
  n = *(_DWORD *)data;
  k = *((_DWORD *)data + 1);
  digest = (blake2b_state *)*((_DWORD *)data + 2);
  collisionBitLength = n / (k + 1);
  v2 = collisionBitLength + 7;
  if ( collisionBitLength + 7 < 0 )
    v2 = collisionBitLength + 14;
  collisionByteLength = v2 >> 3;
  hashLength = (v2 >> 3) * (k + 1);
  indicesPerHashOutput = 512 / n;
  hashOutput = n * (512 / n) / 8;
  equihashSolutionSize = ((n / (k + 1) + 1) << k) / 8;
  solnr = 512;
  indicesLen = 4;
  x_size = 512;
  err_type = 0;
  compare_size = 3;
  expandArray(soln, equihashSolutionSize, (unsigned __int8 *)indices, 0x800u, collisionBitLength + 1, 1u);
  memset(vHash, 0, sizeof(vHash));
  x = (uint8_t *)malloc(0x4400u);
  xc = (uint8_t *)malloc(0x4400u);
  hex_buff = 0;
  xc_size = 0;
  memset(tmp_hash, 0, 0x1Eu);
  for ( i = 0; i < solnr; ++i )
  {
    for ( j = i + 1; j < solnr; ++j )
    {
      if ( indices[i] == indices[j] )
      {
        err_type = 1;
        goto failed;
      }
    }
  }
  for ( j_0 = 0; j_0 < solnr; ++j_0 )
  {
    i_0 = _bswap_32(indices[j_0]);
    generateHash(digest, i_0 / indicesPerHashOutput, tmpHash, hashOutput);
    expandArray(&tmpHash[n * (i_0 % indicesPerHashOutput) / 8], n / 8, hash, hashLength, collisionBitLength, 0);
    for ( m = 0; m < hashLength; ++m )
      vHash[m] ^= hash[m];
    memcpy(&x[j_0 * (indicesLen + hashLength)], hash, hashLength);
    memcpy(&x[hashLength + j_0 * (indicesLen + hashLength)], &indices[j_0], indicesLen);
  }
  if ( isZero(vHash, 0x1Eu) )
  {
    memset(vHash, 0, sizeof(vHash));
    for ( i_1 = 0; i_1 <= 8; ++i_1 )
    {
      qsort(x, x_size, hashLength + indicesLen, (__compar_fn_t)compareSR);
      xc_size = 0;
      for ( j_1 = 0; j_1 < x_size; j_1 += 2 )
      {
        for ( index = 0; index < hashLength; ++index )
          tmp_hash[index] = x[index + (j_1 + 1) * (indicesLen + hashLength)]
                          ^ x[index + j_1 * (indicesLen + hashLength)];
        memcpy(&xc[(j_1 >> 1) * (hashLength + 2 * indicesLen)], tmp_hash, hashLength);
        memcpy(
          &xc[hashLength + (j_1 >> 1) * (hashLength + 2 * indicesLen)],
          &x[hashLength + j_1 * (indicesLen + hashLength)],
          indicesLen);
        memcpy(
          &xc[indicesLen + (j_1 >> 1) * (hashLength + 2 * indicesLen) + hashLength],
          &x[hashLength + (j_1 + 1) * (indicesLen + hashLength)],
          indicesLen);
        ++xc_size;
      }
      indicesLen *= 2;
      __tmp = x;
      x = xc;
      xc = __tmp;
      x_size = xc_size;
      compare_size += 3;
    }
    for ( i_2 = 0; i_2 < 512; ++i_2 )
    {
      v3 = _bswap_32(*(_DWORD *)&x[4 * i_2 + hashLength]);
      real_indices[i_2] = v3;
    }
    for ( level = 0; level <= 8; ++level )
    {
      for ( i_3 = 0; i_3 < 512; i_3 += 2 << level )
        sort_pair(&real_indices[i_3], 1 << level);
    }
    indicesLen = 4;
    x_size = 512;
    for ( j_2 = 0; j_2 < solnr; ++j_2 )
    {
      i_4 = real_indices[j_2];
      generateHash(digest, i_4 / indicesPerHashOutput, tmpHash, hashOutput);
      expandArray(&tmpHash[n * (i_4 % indicesPerHashOutput) / 8], n / 8, hash_0, hashLength, collisionBitLength, 0);
      i_4 = _bswap_32(real_indices[j_2]);
      memcpy(&x[j_2 * (indicesLen + hashLength)], hash_0, hashLength);
      memcpy(&x[hashLength + j_2 * (indicesLen + hashLength)], &i_4, indicesLen);
      hex_buff = bin2hex(&x[j_2 * (indicesLen + hashLength)], 0x22u);
      free(hex_buff);
    }
    for ( i_5 = 0; i_5 <= 8; ++i_5 )
    {
      xc_size = 0;
      for ( j_3 = 0; j_3 < x_size; j_3 += 2 )
      {
        for ( index_0 = 0; index_0 < hashLength; ++index_0 )
          tmp_hash[index_0] = x[index_0 + (j_3 + 1) * (indicesLen + hashLength)]
                            ^ x[index_0 + j_3 * (indicesLen + hashLength)];
        memcpy(&xc[(j_3 >> 1) * (hashLength + 2 * indicesLen)], tmp_hash, hashLength);
        memcpy(
          &xc[hashLength + (j_3 >> 1) * (hashLength + 2 * indicesLen)],
          &x[hashLength + j_3 * (indicesLen + hashLength)],
          indicesLen);
        memcpy(
          &xc[indicesLen + (j_3 >> 1) * (hashLength + 2 * indicesLen) + hashLength],
          &x[hashLength + (j_3 + 1) * (indicesLen + hashLength)],
          indicesLen);
        ++xc_size;
      }
      indicesLen *= 2;
      __tmp_0 = x;
      x = xc;
      xc = __tmp_0;
      x_size = xc_size;
      compare_size += 3;
    }
    getIndices(x, hashLength, 0x800u, 0x14u, tmp_data, 0x540u);
    hex_buff = bin2hex(tmp_data, 0x540u);
    free(hex_buff);
    hex_buff = bin2hex(x, indicesLen + hashLength);
    free(hex_buff);
    v4 = *((_DWORD *)x + 1);
    v5 = *((_DWORD *)x + 2);
    v6 = *((_DWORD *)x + 3);
    *(_DWORD *)vHash = *(_DWORD *)x;
    *(_DWORD *)&vHash[4] = v4;
    *(_DWORD *)&vHash[8] = v5;
    *(_DWORD *)&vHash[12] = v6;
    v7 = *((_DWORD *)x + 5);
    v8 = *((_DWORD *)x + 6);
    *(_DWORD *)&vHash[16] = *((_DWORD *)x + 4);
    *(_DWORD *)&vHash[20] = v7;
    *(_DWORD *)&vHash[24] = v8;
    *(_WORD *)&vHash[28] = *((_WORD *)x + 14);
    if ( !isZero(vHash, 0x1Eu) )
      err_type = 3;
  }
  else
  {
    err_type = 2;
  }
failed:
  free(x);
  free(xc);
  return err_type;
}
