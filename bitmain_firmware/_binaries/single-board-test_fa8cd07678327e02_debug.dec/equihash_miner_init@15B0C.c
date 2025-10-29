void __cdecl equihash_miner_init(runtime_base_t *runtime)
{
  runtime->nonce_submit = (void (*)(uint8_t *, uint8_t *, int, char *))equihash_nonce_submit;
}
