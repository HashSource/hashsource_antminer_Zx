int __cdecl equihash_nonce_verify(nonce_verify_info_t *verify_info, int *tm, uint32_t shift)
{
  validData valData; // [sp+14h] [bp+14h] BYREF
  blake2b_state digest[1]; // [sp+20h] [bp+20h] BYREF
  int valid; // [sp+18Ch] [bp+18Ch]

  memcpy(&verify_info->work[verify_info->work_len - shift - 4], verify_info->nonce, verify_info->nonce_len);
  valData.n = 200;
  valData.k = 9;
  valData.digest = digest;
  digestInit(digest, 200, 9);
  blake2b_update(digest, verify_info->work, verify_info->work_len);
  valid = sortValidator(&valData, verify_info->sol);
  *tm = targetValidator(verify_info->work, verify_info->sol, verify_info->target);
  return valid;
}
