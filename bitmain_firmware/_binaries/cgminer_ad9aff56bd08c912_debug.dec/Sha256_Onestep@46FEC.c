void __fastcall Sha256_Onestep(const uint8_t *data, size_t size, uint8_t *digest)
{
  CSha256 p; // [sp+0h] [bp-68h] BYREF

  p.state[0] = 1779033703;
  p.state[1] = -1150833019;
  p.state[2] = 1013904242;
  p.state[3] = -1521486534;
  p.state[4] = 1359893119;
  p.state[6] = 528734635;
  p.state[7] = 1541459225;
  p.state[5] = -1694144372;
  p.count = 0;
  Sha256_Update(&p, data, size);
  Sha256_Final(&p, digest);
}
