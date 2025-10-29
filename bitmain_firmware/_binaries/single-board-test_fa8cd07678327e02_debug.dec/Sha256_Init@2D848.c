void __cdecl Sha256_Init(CSha256 *p)
{
  p->state[0] = 1779033703;
  p->state[1] = -1150833019;
  p->state[2] = 1013904242;
  p->state[3] = -1521486534;
  p->state[4] = 1359893119;
  p->state[5] = -1694144372;
  p->state[6] = 528734635;
  p->state[7] = 1541459225;
  p->count = 0;
}
