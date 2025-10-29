void __cdecl sha2_process(sha2_context *ctx, const unsigned __int8 *data)
{
  unsigned int W; // [sp+8h] [bp+8h]
  unsigned int W_4; // [sp+Ch] [bp+Ch]
  unsigned int W_8; // [sp+10h] [bp+10h]
  unsigned int W_12; // [sp+14h] [bp+14h]
  unsigned int W_16; // [sp+18h] [bp+18h]
  unsigned int W_20; // [sp+1Ch] [bp+1Ch]
  unsigned int W_24; // [sp+20h] [bp+20h]
  unsigned int W_28; // [sp+24h] [bp+24h]
  unsigned int W_32; // [sp+28h] [bp+28h]
  unsigned int W_36; // [sp+2Ch] [bp+2Ch]
  unsigned int W_40; // [sp+30h] [bp+30h]
  unsigned int W_44; // [sp+34h] [bp+34h]
  unsigned int W_48; // [sp+38h] [bp+38h]
  unsigned int W_52; // [sp+3Ch] [bp+3Ch]
  unsigned int W_56; // [sp+40h] [bp+40h]
  unsigned int W_60; // [sp+44h] [bp+44h]
  unsigned int W_64; // [sp+48h] [bp+48h]
  unsigned int W_68; // [sp+4Ch] [bp+4Ch]
  unsigned int W_72; // [sp+50h] [bp+50h]
  unsigned int W_76; // [sp+54h] [bp+54h]
  unsigned int W_80; // [sp+58h] [bp+58h]
  unsigned int W_84; // [sp+5Ch] [bp+5Ch]
  unsigned int W_88; // [sp+60h] [bp+60h]
  unsigned int W_92; // [sp+64h] [bp+64h]
  unsigned int W_96; // [sp+68h] [bp+68h]
  unsigned int W_100; // [sp+6Ch] [bp+6Ch]
  unsigned int W_104; // [sp+70h] [bp+70h]
  unsigned int W_108; // [sp+74h] [bp+74h]
  unsigned int W_112; // [sp+78h] [bp+78h]
  unsigned int W_116; // [sp+7Ch] [bp+7Ch]
  unsigned int W_120; // [sp+80h] [bp+80h]
  unsigned int W_124; // [sp+84h] [bp+84h]
  unsigned int W_128; // [sp+88h] [bp+88h]
  unsigned int W_132; // [sp+8Ch] [bp+8Ch]
  unsigned int W_136; // [sp+90h] [bp+90h]
  unsigned int W_140; // [sp+94h] [bp+94h]
  unsigned int W_144; // [sp+98h] [bp+98h]
  unsigned int W_148; // [sp+9Ch] [bp+9Ch]
  unsigned int W_152; // [sp+A0h] [bp+A0h]
  unsigned int W_156; // [sp+A4h] [bp+A4h]
  unsigned int W_160; // [sp+A8h] [bp+A8h]
  unsigned int W_164; // [sp+ACh] [bp+ACh]
  unsigned int W_168; // [sp+B0h] [bp+B0h]
  unsigned int W_172; // [sp+B4h] [bp+B4h]
  unsigned int W_176; // [sp+B8h] [bp+B8h]
  unsigned int W_180; // [sp+BCh] [bp+BCh]
  unsigned int W_184; // [sp+C0h] [bp+C0h]
  unsigned int W_188; // [sp+C4h] [bp+C4h]
  unsigned int W_192; // [sp+C8h] [bp+C8h]
  unsigned int W_196; // [sp+CCh] [bp+CCh]
  unsigned int W_200; // [sp+D0h] [bp+D0h]
  unsigned int W_204; // [sp+D4h] [bp+D4h]
  unsigned int W_208; // [sp+D8h] [bp+D8h]
  unsigned int W_212; // [sp+DCh] [bp+DCh]
  unsigned int W_216; // [sp+E0h] [bp+E0h]
  unsigned int W_220; // [sp+E4h] [bp+E4h]
  unsigned int W_224; // [sp+E8h] [bp+E8h]
  unsigned int W_228; // [sp+ECh] [bp+ECh]
  unsigned int W_232; // [sp+F0h] [bp+F0h]
  unsigned int W_236; // [sp+F4h] [bp+F4h]
  unsigned int W_240; // [sp+F8h] [bp+F8h]
  unsigned int W_244; // [sp+FCh] [bp+FCh]
  uint32_t temp1; // [sp+10Ch] [bp+10Ch]
  uint32_t temp1a; // [sp+10Ch] [bp+10Ch]
  uint32_t temp1b; // [sp+10Ch] [bp+10Ch]
  uint32_t temp1c; // [sp+10Ch] [bp+10Ch]
  uint32_t temp1d; // [sp+10Ch] [bp+10Ch]
  uint32_t temp1e; // [sp+10Ch] [bp+10Ch]
  uint32_t temp1f; // [sp+10Ch] [bp+10Ch]
  uint32_t temp1g; // [sp+10Ch] [bp+10Ch]
  uint32_t temp1h; // [sp+10Ch] [bp+10Ch]
  uint32_t temp1i; // [sp+10Ch] [bp+10Ch]
  uint32_t temp1j; // [sp+10Ch] [bp+10Ch]
  uint32_t temp1k; // [sp+10Ch] [bp+10Ch]
  uint32_t temp1l; // [sp+10Ch] [bp+10Ch]
  uint32_t temp1m; // [sp+10Ch] [bp+10Ch]
  uint32_t temp1n; // [sp+10Ch] [bp+10Ch]
  uint32_t temp1o; // [sp+10Ch] [bp+10Ch]
  uint32_t temp1p; // [sp+10Ch] [bp+10Ch]
  uint32_t temp1q; // [sp+10Ch] [bp+10Ch]
  uint32_t temp1r; // [sp+10Ch] [bp+10Ch]
  uint32_t temp1s; // [sp+10Ch] [bp+10Ch]
  uint32_t temp1t; // [sp+10Ch] [bp+10Ch]
  uint32_t temp1u; // [sp+10Ch] [bp+10Ch]
  uint32_t temp1v; // [sp+10Ch] [bp+10Ch]
  uint32_t temp1w; // [sp+10Ch] [bp+10Ch]
  uint32_t temp1x; // [sp+10Ch] [bp+10Ch]
  uint32_t temp1y; // [sp+10Ch] [bp+10Ch]
  uint32_t temp1z; // [sp+10Ch] [bp+10Ch]
  uint32_t temp1ba; // [sp+10Ch] [bp+10Ch]
  uint32_t temp1bb; // [sp+10Ch] [bp+10Ch]
  uint32_t temp1bc; // [sp+10Ch] [bp+10Ch]
  uint32_t temp1bd; // [sp+10Ch] [bp+10Ch]
  uint32_t temp1be; // [sp+10Ch] [bp+10Ch]
  uint32_t temp1bf; // [sp+10Ch] [bp+10Ch]
  uint32_t temp1bg; // [sp+10Ch] [bp+10Ch]
  uint32_t temp1bh; // [sp+10Ch] [bp+10Ch]
  uint32_t temp1bi; // [sp+10Ch] [bp+10Ch]
  uint32_t temp1bj; // [sp+10Ch] [bp+10Ch]
  uint32_t temp1bk; // [sp+10Ch] [bp+10Ch]
  uint32_t temp1bl; // [sp+10Ch] [bp+10Ch]
  uint32_t temp1bm; // [sp+10Ch] [bp+10Ch]
  uint32_t temp1bn; // [sp+10Ch] [bp+10Ch]
  uint32_t temp1bo; // [sp+10Ch] [bp+10Ch]
  uint32_t temp1bp; // [sp+10Ch] [bp+10Ch]
  uint32_t temp1bq; // [sp+10Ch] [bp+10Ch]
  uint32_t temp1br; // [sp+10Ch] [bp+10Ch]
  uint32_t temp1bs; // [sp+10Ch] [bp+10Ch]
  uint32_t temp1bt; // [sp+10Ch] [bp+10Ch]
  uint32_t temp1bu; // [sp+10Ch] [bp+10Ch]
  uint32_t temp1bv; // [sp+10Ch] [bp+10Ch]
  uint32_t temp1bw; // [sp+10Ch] [bp+10Ch]
  uint32_t temp1bx; // [sp+10Ch] [bp+10Ch]
  uint32_t temp1by; // [sp+10Ch] [bp+10Ch]
  uint32_t temp1bz; // [sp+10Ch] [bp+10Ch]
  uint32_t temp1ca; // [sp+10Ch] [bp+10Ch]
  uint32_t temp1cb; // [sp+10Ch] [bp+10Ch]
  uint32_t temp1cc; // [sp+10Ch] [bp+10Ch]
  uint32_t temp1cd; // [sp+10Ch] [bp+10Ch]
  uint32_t temp1ce; // [sp+10Ch] [bp+10Ch]
  uint32_t temp1cf; // [sp+10Ch] [bp+10Ch]
  uint32_t temp1cg; // [sp+10Ch] [bp+10Ch]
  uint32_t temp1ch; // [sp+10Ch] [bp+10Ch]
  uint32_t temp1ci; // [sp+10Ch] [bp+10Ch]
  uint32_t temp1cj; // [sp+10Ch] [bp+10Ch]
  uint32_t temp1ck; // [sp+10Ch] [bp+10Ch]
  uint32_t H; // [sp+110h] [bp+110h]
  uint32_t Ha; // [sp+110h] [bp+110h]
  uint32_t Hb; // [sp+110h] [bp+110h]
  uint32_t Hc; // [sp+110h] [bp+110h]
  uint32_t Hd; // [sp+110h] [bp+110h]
  uint32_t He; // [sp+110h] [bp+110h]
  uint32_t Hf; // [sp+110h] [bp+110h]
  uint32_t Hg; // [sp+110h] [bp+110h]
  uint32_t Hh; // [sp+110h] [bp+110h]
  uint32_t Hi; // [sp+110h] [bp+110h]
  uint32_t Hj; // [sp+110h] [bp+110h]
  uint32_t Hk; // [sp+110h] [bp+110h]
  uint32_t Hl; // [sp+110h] [bp+110h]
  uint32_t Hm; // [sp+110h] [bp+110h]
  uint32_t Hn; // [sp+110h] [bp+110h]
  uint32_t Ho; // [sp+110h] [bp+110h]
  uint32_t G; // [sp+114h] [bp+114h]
  uint32_t Ga; // [sp+114h] [bp+114h]
  uint32_t Gb; // [sp+114h] [bp+114h]
  uint32_t Gc; // [sp+114h] [bp+114h]
  uint32_t Gd; // [sp+114h] [bp+114h]
  uint32_t Ge; // [sp+114h] [bp+114h]
  uint32_t Gf; // [sp+114h] [bp+114h]
  uint32_t Gg; // [sp+114h] [bp+114h]
  uint32_t Gh; // [sp+114h] [bp+114h]
  uint32_t Gi; // [sp+114h] [bp+114h]
  uint32_t Gj; // [sp+114h] [bp+114h]
  uint32_t Gk; // [sp+114h] [bp+114h]
  uint32_t Gl; // [sp+114h] [bp+114h]
  uint32_t Gm; // [sp+114h] [bp+114h]
  uint32_t Gn; // [sp+114h] [bp+114h]
  uint32_t Go; // [sp+114h] [bp+114h]
  uint32_t Gp; // [sp+114h] [bp+114h]
  uint32_t F; // [sp+118h] [bp+118h]
  uint32_t Fa; // [sp+118h] [bp+118h]
  uint32_t Fb; // [sp+118h] [bp+118h]
  uint32_t Fc; // [sp+118h] [bp+118h]
  uint32_t Fd; // [sp+118h] [bp+118h]
  uint32_t Fe; // [sp+118h] [bp+118h]
  uint32_t Ff; // [sp+118h] [bp+118h]
  uint32_t Fg; // [sp+118h] [bp+118h]
  uint32_t Fh; // [sp+118h] [bp+118h]
  uint32_t Fi; // [sp+118h] [bp+118h]
  uint32_t Fj; // [sp+118h] [bp+118h]
  uint32_t Fk; // [sp+118h] [bp+118h]
  uint32_t Fl; // [sp+118h] [bp+118h]
  uint32_t Fm; // [sp+118h] [bp+118h]
  uint32_t Fn; // [sp+118h] [bp+118h]
  uint32_t Fo; // [sp+118h] [bp+118h]
  uint32_t Fp; // [sp+118h] [bp+118h]
  uint32_t E; // [sp+11Ch] [bp+11Ch]
  uint32_t Ea; // [sp+11Ch] [bp+11Ch]
  uint32_t Eb; // [sp+11Ch] [bp+11Ch]
  uint32_t Ec; // [sp+11Ch] [bp+11Ch]
  uint32_t Ed; // [sp+11Ch] [bp+11Ch]
  uint32_t Ee; // [sp+11Ch] [bp+11Ch]
  uint32_t Ef; // [sp+11Ch] [bp+11Ch]
  uint32_t Eg; // [sp+11Ch] [bp+11Ch]
  uint32_t Eh; // [sp+11Ch] [bp+11Ch]
  uint32_t Ei; // [sp+11Ch] [bp+11Ch]
  uint32_t Ej; // [sp+11Ch] [bp+11Ch]
  uint32_t Ek; // [sp+11Ch] [bp+11Ch]
  uint32_t El; // [sp+11Ch] [bp+11Ch]
  uint32_t Em; // [sp+11Ch] [bp+11Ch]
  uint32_t En; // [sp+11Ch] [bp+11Ch]
  uint32_t Eo; // [sp+11Ch] [bp+11Ch]
  uint32_t D; // [sp+120h] [bp+120h]
  uint32_t Da; // [sp+120h] [bp+120h]
  uint32_t Db; // [sp+120h] [bp+120h]
  uint32_t Dc; // [sp+120h] [bp+120h]
  uint32_t Dd; // [sp+120h] [bp+120h]
  uint32_t De; // [sp+120h] [bp+120h]
  uint32_t Df; // [sp+120h] [bp+120h]
  uint32_t Dg; // [sp+120h] [bp+120h]
  uint32_t Dh; // [sp+120h] [bp+120h]
  uint32_t Di; // [sp+120h] [bp+120h]
  uint32_t Dj; // [sp+120h] [bp+120h]
  uint32_t Dk; // [sp+120h] [bp+120h]
  uint32_t Dl; // [sp+120h] [bp+120h]
  uint32_t Dm; // [sp+120h] [bp+120h]
  uint32_t Dn; // [sp+120h] [bp+120h]
  uint32_t Do; // [sp+120h] [bp+120h]
  uint32_t C; // [sp+124h] [bp+124h]
  uint32_t Ca; // [sp+124h] [bp+124h]
  uint32_t Cb; // [sp+124h] [bp+124h]
  uint32_t Cc; // [sp+124h] [bp+124h]
  uint32_t Cd; // [sp+124h] [bp+124h]
  uint32_t Ce; // [sp+124h] [bp+124h]
  uint32_t Cf; // [sp+124h] [bp+124h]
  uint32_t Cg; // [sp+124h] [bp+124h]
  uint32_t Ch; // [sp+124h] [bp+124h]
  uint32_t Ci; // [sp+124h] [bp+124h]
  uint32_t Cj; // [sp+124h] [bp+124h]
  uint32_t Ck; // [sp+124h] [bp+124h]
  uint32_t Cl; // [sp+124h] [bp+124h]
  uint32_t Cm; // [sp+124h] [bp+124h]
  uint32_t Cn; // [sp+124h] [bp+124h]
  uint32_t Co; // [sp+124h] [bp+124h]
  uint32_t Cp; // [sp+124h] [bp+124h]
  uint32_t B; // [sp+128h] [bp+128h]
  uint32_t Ba; // [sp+128h] [bp+128h]
  uint32_t Bb; // [sp+128h] [bp+128h]
  uint32_t Bc; // [sp+128h] [bp+128h]
  uint32_t Bd; // [sp+128h] [bp+128h]
  uint32_t Be; // [sp+128h] [bp+128h]
  uint32_t Bf; // [sp+128h] [bp+128h]
  uint32_t Bg; // [sp+128h] [bp+128h]
  uint32_t Bh; // [sp+128h] [bp+128h]
  uint32_t Bi; // [sp+128h] [bp+128h]
  uint32_t Bj; // [sp+128h] [bp+128h]
  uint32_t Bk; // [sp+128h] [bp+128h]
  uint32_t Bl; // [sp+128h] [bp+128h]
  uint32_t Bm; // [sp+128h] [bp+128h]
  uint32_t Bn; // [sp+128h] [bp+128h]
  uint32_t Bo; // [sp+128h] [bp+128h]
  uint32_t Bp; // [sp+128h] [bp+128h]
  uint32_t A; // [sp+12Ch] [bp+12Ch]
  uint32_t Aa; // [sp+12Ch] [bp+12Ch]
  uint32_t Ab; // [sp+12Ch] [bp+12Ch]
  uint32_t Ac; // [sp+12Ch] [bp+12Ch]
  uint32_t Ad; // [sp+12Ch] [bp+12Ch]
  uint32_t Ae; // [sp+12Ch] [bp+12Ch]
  uint32_t Af; // [sp+12Ch] [bp+12Ch]
  uint32_t Ag; // [sp+12Ch] [bp+12Ch]
  uint32_t Ah; // [sp+12Ch] [bp+12Ch]
  uint32_t Ai; // [sp+12Ch] [bp+12Ch]
  uint32_t Aj; // [sp+12Ch] [bp+12Ch]
  uint32_t Ak; // [sp+12Ch] [bp+12Ch]
  uint32_t Al; // [sp+12Ch] [bp+12Ch]
  uint32_t Am; // [sp+12Ch] [bp+12Ch]
  uint32_t An; // [sp+12Ch] [bp+12Ch]
  uint32_t Ao; // [sp+12Ch] [bp+12Ch]

  W = _byteswap_ulong(*(_DWORD *)data);
  W_4 = _byteswap_ulong(*((_DWORD *)data + 1));
  W_8 = _byteswap_ulong(*((_DWORD *)data + 2));
  W_12 = _byteswap_ulong(*((_DWORD *)data + 3));
  W_16 = _byteswap_ulong(*((_DWORD *)data + 4));
  W_20 = _byteswap_ulong(*((_DWORD *)data + 5));
  W_24 = _byteswap_ulong(*((_DWORD *)data + 6));
  W_28 = _byteswap_ulong(*((_DWORD *)data + 7));
  W_32 = _byteswap_ulong(*((_DWORD *)data + 8));
  W_36 = _byteswap_ulong(*((_DWORD *)data + 9));
  W_40 = _byteswap_ulong(*((_DWORD *)data + 10));
  W_44 = _byteswap_ulong(*((_DWORD *)data + 11));
  W_48 = _byteswap_ulong(*((_DWORD *)data + 12));
  W_52 = _byteswap_ulong(*((_DWORD *)data + 13));
  W_56 = _byteswap_ulong(*((_DWORD *)data + 14));
  W_60 = _byteswap_ulong(*((_DWORD *)data + 15));
  A = ctx->state[0];
  B = ctx->state[1];
  C = ctx->state[2];
  E = ctx->state[4];
  F = ctx->state[5];
  G = ctx->state[6];
  temp1 = (__ROR4__(E, 6) ^ __ROR4__(E, 11) ^ __ROR4__(E, 25)) + ctx->state[7] + (G ^ (F ^ G) & E) + W + 1116352408;
  D = temp1 + ctx->state[3];
  H = (C & (A | B) | A & B) + (__ROR4__(A, 2) ^ __ROR4__(A, 13) ^ __ROR4__(A, 22)) + temp1;
  temp1a = (__ROR4__(D, 6) ^ __ROR4__(D, 11) ^ __ROR4__(D, 25)) + G + (F ^ (E ^ F) & D) + W_4 + 1899447441;
  Ca = temp1a + C;
  Ga = (B & (H | A) | H & A) + (__ROR4__(H, 2) ^ __ROR4__(H, 13) ^ __ROR4__(H, 22)) + temp1a;
  temp1b = (__ROR4__(Ca, 6) ^ __ROR4__(Ca, 11) ^ __ROR4__(Ca, 25)) + F + (E ^ (D ^ E) & Ca) + W_8 - 1245643825;
  Ba = temp1b + B;
  Fa = (A & (Ga | H) | Ga & H) + (__ROR4__(Ga, 2) ^ __ROR4__(Ga, 13) ^ __ROR4__(Ga, 22)) + temp1b;
  temp1c = (__ROR4__(Ba, 6) ^ __ROR4__(Ba, 11) ^ __ROR4__(Ba, 25)) + E + (D ^ (Ca ^ D) & Ba) + W_12 - 373957723;
  Aa = temp1c + A;
  Ea = (H & (Fa | Ga) | Fa & Ga) + (__ROR4__(Fa, 2) ^ __ROR4__(Fa, 13) ^ __ROR4__(Fa, 22)) + temp1c;
  temp1d = (__ROR4__(Aa, 6) ^ __ROR4__(Aa, 11) ^ __ROR4__(Aa, 25)) + D + (Ca ^ (Ba ^ Ca) & Aa) + W_16 + 961987163;
  Ha = temp1d + H;
  Da = (Ga & (Ea | Fa) | Ea & Fa) + (__ROR4__(Ea, 2) ^ __ROR4__(Ea, 13) ^ __ROR4__(Ea, 22)) + temp1d;
  temp1e = (__ROR4__(Ha, 6) ^ __ROR4__(Ha, 11) ^ __ROR4__(Ha, 25)) + Ca + (Ba ^ (Aa ^ Ba) & Ha) + W_20 + 1508970993;
  Gb = temp1e + Ga;
  Cb = (Fa & (Da | Ea) | Da & Ea) + (__ROR4__(Da, 2) ^ __ROR4__(Da, 13) ^ __ROR4__(Da, 22)) + temp1e;
  temp1f = (__ROR4__(Gb, 6) ^ __ROR4__(Gb, 11) ^ __ROR4__(Gb, 25)) + Ba + (Aa ^ (Ha ^ Aa) & Gb) + W_24 - 1841331548;
  Fb = temp1f + Fa;
  Bb = (Ea & (Cb | Da) | Cb & Da) + (__ROR4__(Cb, 2) ^ __ROR4__(Cb, 13) ^ __ROR4__(Cb, 22)) + temp1f;
  temp1g = (__ROR4__(Fb, 6) ^ __ROR4__(Fb, 11) ^ __ROR4__(Fb, 25)) + Aa + (Ha ^ (Gb ^ Ha) & Fb) + W_28 - 1424204075;
  Eb = temp1g + Ea;
  Ab = (Da & (Bb | Cb) | Bb & Cb) + (__ROR4__(Bb, 2) ^ __ROR4__(Bb, 13) ^ __ROR4__(Bb, 22)) + temp1g;
  temp1h = (__ROR4__(Eb, 6) ^ __ROR4__(Eb, 11) ^ __ROR4__(Eb, 25)) + Ha + (Gb ^ (Fb ^ Gb) & Eb) + W_32 - 670586216;
  Db = temp1h + Da;
  Hb = (Cb & (Ab | Bb) | Ab & Bb) + (__ROR4__(Ab, 2) ^ __ROR4__(Ab, 13) ^ __ROR4__(Ab, 22)) + temp1h;
  temp1i = (__ROR4__(Db, 6) ^ __ROR4__(Db, 11) ^ __ROR4__(Db, 25)) + Gb + (Fb ^ (Eb ^ Fb) & Db) + W_36 + 310598401;
  Cc = temp1i + Cb;
  Gc = (Bb & (Hb | Ab) | Hb & Ab) + (__ROR4__(Hb, 2) ^ __ROR4__(Hb, 13) ^ __ROR4__(Hb, 22)) + temp1i;
  temp1j = (__ROR4__(Cc, 6) ^ __ROR4__(Cc, 11) ^ __ROR4__(Cc, 25)) + Fb + (Eb ^ (Db ^ Eb) & Cc) + W_40 + 607225278;
  Bc = temp1j + Bb;
  Fc = (Ab & (Gc | Hb) | Gc & Hb) + (__ROR4__(Gc, 2) ^ __ROR4__(Gc, 13) ^ __ROR4__(Gc, 22)) + temp1j;
  temp1k = (__ROR4__(Bc, 6) ^ __ROR4__(Bc, 11) ^ __ROR4__(Bc, 25)) + Eb + (Db ^ (Cc ^ Db) & Bc) + W_44 + 1426881987;
  Ac = temp1k + Ab;
  Ec = (Hb & (Fc | Gc) | Fc & Gc) + (__ROR4__(Fc, 2) ^ __ROR4__(Fc, 13) ^ __ROR4__(Fc, 22)) + temp1k;
  temp1l = (__ROR4__(Ac, 6) ^ __ROR4__(Ac, 11) ^ __ROR4__(Ac, 25)) + Db + (Cc ^ (Bc ^ Cc) & Ac) + W_48 + 1925078388;
  Hc = temp1l + Hb;
  Dc = (Gc & (Ec | Fc) | Ec & Fc) + (__ROR4__(Ec, 2) ^ __ROR4__(Ec, 13) ^ __ROR4__(Ec, 22)) + temp1l;
  temp1m = (__ROR4__(Hc, 6) ^ __ROR4__(Hc, 11) ^ __ROR4__(Hc, 25)) + Cc + (Bc ^ (Ac ^ Bc) & Hc) + W_52 - 2132889090;
  Gd = temp1m + Gc;
  Cd = (Fc & (Dc | Ec) | Dc & Ec) + (__ROR4__(Dc, 2) ^ __ROR4__(Dc, 13) ^ __ROR4__(Dc, 22)) + temp1m;
  temp1n = (__ROR4__(Gd, 6) ^ __ROR4__(Gd, 11) ^ __ROR4__(Gd, 25)) + Bc + (Ac ^ (Hc ^ Ac) & Gd) + W_56 - 1680079193;
  Fd = temp1n + Fc;
  Bd = (Ec & (Cd | Dc) | Cd & Dc) + (__ROR4__(Cd, 2) ^ __ROR4__(Cd, 13) ^ __ROR4__(Cd, 22)) + temp1n;
  temp1o = (__ROR4__(Fd, 6) ^ __ROR4__(Fd, 11) ^ __ROR4__(Fd, 25)) + Ac + (Hc ^ (Gd ^ Hc) & Fd) + W_60 - 1046744716;
  Ed = temp1o + Ec;
  Ad = (Dc & (Bd | Cd) | Bd & Cd) + (__ROR4__(Bd, 2) ^ __ROR4__(Bd, 13) ^ __ROR4__(Bd, 22)) + temp1o;
  W_64 = (__ROR4__(W_56, 17) ^ __ROR4__(W_56, 19) ^ (W_56 >> 10))
       + W_36
       + ((W_4 >> 3) ^ __ROR4__(W_4, 7) ^ __ROR4__(W_4, 18))
       + W;
  temp1p = (__ROR4__(Ed, 6) ^ __ROR4__(Ed, 11) ^ __ROR4__(Ed, 25)) + Hc + (Gd ^ (Fd ^ Gd) & Ed) + W_64 - 459576895;
  Dd = temp1p + Dc;
  Hd = (Cd & (Ad | Bd) | Ad & Bd) + (__ROR4__(Ad, 2) ^ __ROR4__(Ad, 13) ^ __ROR4__(Ad, 22)) + temp1p;
  W_68 = (__ROR4__(W_60, 17) ^ __ROR4__(W_60, 19) ^ (W_60 >> 10))
       + W_40
       + ((W_8 >> 3) ^ __ROR4__(W_8, 7) ^ __ROR4__(W_8, 18))
       + W_4;
  temp1q = (__ROR4__(Dd, 6) ^ __ROR4__(Dd, 11) ^ __ROR4__(Dd, 25)) + Gd + (Fd ^ (Ed ^ Fd) & Dd) + W_68 - 272742522;
  Ce = temp1q + Cd;
  Ge = (Bd & (Hd | Ad) | Hd & Ad) + (__ROR4__(Hd, 2) ^ __ROR4__(Hd, 13) ^ __ROR4__(Hd, 22)) + temp1q;
  W_72 = (__ROR4__(W_64, 17) ^ __ROR4__(W_64, 19) ^ (W_64 >> 10))
       + W_44
       + ((W_12 >> 3) ^ __ROR4__(W_12, 7) ^ __ROR4__(W_12, 18))
       + W_8;
  temp1r = (__ROR4__(Ce, 6) ^ __ROR4__(Ce, 11) ^ __ROR4__(Ce, 25)) + Fd + (Ed ^ (Dd ^ Ed) & Ce) + W_72 + 264347078;
  Be = temp1r + Bd;
  Fe = (Ad & (Ge | Hd) | Ge & Hd) + (__ROR4__(Ge, 2) ^ __ROR4__(Ge, 13) ^ __ROR4__(Ge, 22)) + temp1r;
  W_76 = (__ROR4__(W_68, 17) ^ __ROR4__(W_68, 19) ^ (W_68 >> 10))
       + W_48
       + ((W_16 >> 3) ^ __ROR4__(W_16, 7) ^ __ROR4__(W_16, 18))
       + W_12;
  temp1s = (__ROR4__(Be, 6) ^ __ROR4__(Be, 11) ^ __ROR4__(Be, 25)) + Ed + (Dd ^ (Ce ^ Dd) & Be) + W_76 + 604807628;
  Ae = temp1s + Ad;
  Ee = (Hd & (Fe | Ge) | Fe & Ge) + (__ROR4__(Fe, 2) ^ __ROR4__(Fe, 13) ^ __ROR4__(Fe, 22)) + temp1s;
  W_80 = (__ROR4__(W_72, 17) ^ __ROR4__(W_72, 19) ^ (W_72 >> 10))
       + W_52
       + ((W_20 >> 3) ^ __ROR4__(W_20, 7) ^ __ROR4__(W_20, 18))
       + W_16;
  temp1t = (__ROR4__(Ae, 6) ^ __ROR4__(Ae, 11) ^ __ROR4__(Ae, 25)) + Dd + (Ce ^ (Be ^ Ce) & Ae) + W_80 + 770255983;
  He = temp1t + Hd;
  De = (Ge & (Ee | Fe) | Ee & Fe) + (__ROR4__(Ee, 2) ^ __ROR4__(Ee, 13) ^ __ROR4__(Ee, 22)) + temp1t;
  W_84 = (__ROR4__(W_76, 17) ^ __ROR4__(W_76, 19) ^ (W_76 >> 10))
       + W_56
       + ((W_24 >> 3) ^ __ROR4__(W_24, 7) ^ __ROR4__(W_24, 18))
       + W_20;
  temp1u = (__ROR4__(He, 6) ^ __ROR4__(He, 11) ^ __ROR4__(He, 25)) + Ce + (Be ^ (Ae ^ Be) & He) + W_84 + 1249150122;
  Gf = temp1u + Ge;
  Cf = (Fe & (De | Ee) | De & Ee) + (__ROR4__(De, 2) ^ __ROR4__(De, 13) ^ __ROR4__(De, 22)) + temp1u;
  W_88 = (__ROR4__(W_80, 17) ^ __ROR4__(W_80, 19) ^ (W_80 >> 10))
       + W_60
       + ((W_28 >> 3) ^ __ROR4__(W_28, 7) ^ __ROR4__(W_28, 18))
       + W_24;
  temp1v = (__ROR4__(Gf, 6) ^ __ROR4__(Gf, 11) ^ __ROR4__(Gf, 25)) + Be + (Ae ^ (He ^ Ae) & Gf) + W_88 + 1555081692;
  Ff = temp1v + Fe;
  Bf = (Ee & (Cf | De) | Cf & De) + (__ROR4__(Cf, 2) ^ __ROR4__(Cf, 13) ^ __ROR4__(Cf, 22)) + temp1v;
  W_92 = (__ROR4__(W_84, 17) ^ __ROR4__(W_84, 19) ^ (W_84 >> 10))
       + W_64
       + ((W_32 >> 3) ^ __ROR4__(W_32, 7) ^ __ROR4__(W_32, 18))
       + W_28;
  temp1w = (__ROR4__(Ff, 6) ^ __ROR4__(Ff, 11) ^ __ROR4__(Ff, 25)) + Ae + (He ^ (Gf ^ He) & Ff) + W_92 + 1996064986;
  Ef = temp1w + Ee;
  Af = (De & (Bf | Cf) | Bf & Cf) + (__ROR4__(Bf, 2) ^ __ROR4__(Bf, 13) ^ __ROR4__(Bf, 22)) + temp1w;
  W_96 = (__ROR4__(W_88, 17) ^ __ROR4__(W_88, 19) ^ (W_88 >> 10))
       + W_68
       + ((W_36 >> 3) ^ __ROR4__(W_36, 7) ^ __ROR4__(W_36, 18))
       + W_32;
  temp1x = (__ROR4__(Ef, 6) ^ __ROR4__(Ef, 11) ^ __ROR4__(Ef, 25)) + He + (Gf ^ (Ff ^ Gf) & Ef) + W_96 - 1740746414;
  Df = temp1x + De;
  Hf = (Cf & (Af | Bf) | Af & Bf) + (__ROR4__(Af, 2) ^ __ROR4__(Af, 13) ^ __ROR4__(Af, 22)) + temp1x;
  W_100 = (__ROR4__(W_92, 17) ^ __ROR4__(W_92, 19) ^ (W_92 >> 10))
        + W_72
        + ((W_40 >> 3) ^ __ROR4__(W_40, 7) ^ __ROR4__(W_40, 18))
        + W_36;
  temp1y = (__ROR4__(Df, 6) ^ __ROR4__(Df, 11) ^ __ROR4__(Df, 25)) + Gf + (Ff ^ (Ef ^ Ff) & Df) + W_100 - 1473132947;
  Cg = temp1y + Cf;
  Gg = (Bf & (Hf | Af) | Hf & Af) + (__ROR4__(Hf, 2) ^ __ROR4__(Hf, 13) ^ __ROR4__(Hf, 22)) + temp1y;
  W_104 = (__ROR4__(W_96, 17) ^ __ROR4__(W_96, 19) ^ (W_96 >> 10))
        + W_76
        + ((W_44 >> 3) ^ __ROR4__(W_44, 7) ^ __ROR4__(W_44, 18))
        + W_40;
  temp1z = (__ROR4__(Cg, 6) ^ __ROR4__(Cg, 11) ^ __ROR4__(Cg, 25)) + Ff + (Ef ^ (Df ^ Ef) & Cg) + W_104 - 1341970488;
  Bg = temp1z + Bf;
  Fg = (Af & (Gg | Hf) | Gg & Hf) + (__ROR4__(Gg, 2) ^ __ROR4__(Gg, 13) ^ __ROR4__(Gg, 22)) + temp1z;
  W_108 = (__ROR4__(W_100, 17) ^ __ROR4__(W_100, 19) ^ (W_100 >> 10))
        + W_80
        + ((W_48 >> 3) ^ __ROR4__(W_48, 7) ^ __ROR4__(W_48, 18))
        + W_44;
  temp1ba = (__ROR4__(Bg, 6) ^ __ROR4__(Bg, 11) ^ __ROR4__(Bg, 25)) + Ef + (Df ^ (Cg ^ Df) & Bg) + W_108 - 1084653625;
  Ag = temp1ba + Af;
  Eg = (Hf & (Fg | Gg) | Fg & Gg) + (__ROR4__(Fg, 2) ^ __ROR4__(Fg, 13) ^ __ROR4__(Fg, 22)) + temp1ba;
  W_112 = (__ROR4__(W_104, 17) ^ __ROR4__(W_104, 19) ^ (W_104 >> 10))
        + W_84
        + ((W_52 >> 3) ^ __ROR4__(W_52, 7) ^ __ROR4__(W_52, 18))
        + W_48;
  temp1bb = (__ROR4__(Ag, 6) ^ __ROR4__(Ag, 11) ^ __ROR4__(Ag, 25)) + Df + (Cg ^ (Bg ^ Cg) & Ag) + W_112 - 958395405;
  Hg = temp1bb + Hf;
  Dg = (Gg & (Eg | Fg) | Eg & Fg) + (__ROR4__(Eg, 2) ^ __ROR4__(Eg, 13) ^ __ROR4__(Eg, 22)) + temp1bb;
  W_116 = (__ROR4__(W_108, 17) ^ __ROR4__(W_108, 19) ^ (W_108 >> 10))
        + W_88
        + ((W_56 >> 3) ^ __ROR4__(W_56, 7) ^ __ROR4__(W_56, 18))
        + W_52;
  temp1bc = (__ROR4__(Hg, 6) ^ __ROR4__(Hg, 11) ^ __ROR4__(Hg, 25)) + Cg + (Bg ^ (Ag ^ Bg) & Hg) + W_116 - 710438585;
  Gh = temp1bc + Gg;
  Ch = (Fg & (Dg | Eg) | Dg & Eg) + (__ROR4__(Dg, 2) ^ __ROR4__(Dg, 13) ^ __ROR4__(Dg, 22)) + temp1bc;
  W_120 = (__ROR4__(W_112, 17) ^ __ROR4__(W_112, 19) ^ (W_112 >> 10))
        + W_92
        + ((W_60 >> 3) ^ __ROR4__(W_60, 7) ^ __ROR4__(W_60, 18))
        + W_56;
  temp1bd = (__ROR4__(Gh, 6) ^ __ROR4__(Gh, 11) ^ __ROR4__(Gh, 25)) + Bg + (Ag ^ (Hg ^ Ag) & Gh) + W_120 + 113926993;
  Fh = temp1bd + Fg;
  Bh = (Eg & (Ch | Dg) | Ch & Dg) + (__ROR4__(Ch, 2) ^ __ROR4__(Ch, 13) ^ __ROR4__(Ch, 22)) + temp1bd;
  W_124 = (__ROR4__(W_116, 17) ^ __ROR4__(W_116, 19) ^ (W_116 >> 10))
        + W_96
        + ((W_64 >> 3) ^ __ROR4__(W_64, 7) ^ __ROR4__(W_64, 18))
        + W_60;
  temp1be = (__ROR4__(Fh, 6) ^ __ROR4__(Fh, 11) ^ __ROR4__(Fh, 25)) + Ag + (Hg ^ (Gh ^ Hg) & Fh) + W_124 + 338241895;
  Eh = temp1be + Eg;
  Ah = (Dg & (Bh | Ch) | Bh & Ch) + (__ROR4__(Bh, 2) ^ __ROR4__(Bh, 13) ^ __ROR4__(Bh, 22)) + temp1be;
  W_128 = (__ROR4__(W_120, 17) ^ __ROR4__(W_120, 19) ^ (W_120 >> 10))
        + W_100
        + ((W_68 >> 3) ^ __ROR4__(W_68, 7) ^ __ROR4__(W_68, 18))
        + W_64;
  temp1bf = (__ROR4__(Eh, 6) ^ __ROR4__(Eh, 11) ^ __ROR4__(Eh, 25)) + Hg + (Gh ^ (Fh ^ Gh) & Eh) + W_128 + 666307205;
  Dh = temp1bf + Dg;
  Hh = (Ch & (Ah | Bh) | Ah & Bh) + (__ROR4__(Ah, 2) ^ __ROR4__(Ah, 13) ^ __ROR4__(Ah, 22)) + temp1bf;
  W_132 = (__ROR4__(W_124, 17) ^ __ROR4__(W_124, 19) ^ (W_124 >> 10))
        + W_104
        + ((W_72 >> 3) ^ __ROR4__(W_72, 7) ^ __ROR4__(W_72, 18))
        + W_68;
  temp1bg = (__ROR4__(Dh, 6) ^ __ROR4__(Dh, 11) ^ __ROR4__(Dh, 25)) + Gh + (Fh ^ (Eh ^ Fh) & Dh) + W_132 + 773529912;
  Ci = temp1bg + Ch;
  Gi = (Bh & (Hh | Ah) | Hh & Ah) + (__ROR4__(Hh, 2) ^ __ROR4__(Hh, 13) ^ __ROR4__(Hh, 22)) + temp1bg;
  W_136 = (__ROR4__(W_128, 17) ^ __ROR4__(W_128, 19) ^ (W_128 >> 10))
        + W_108
        + ((W_76 >> 3) ^ __ROR4__(W_76, 7) ^ __ROR4__(W_76, 18))
        + W_72;
  temp1bh = (__ROR4__(Ci, 6) ^ __ROR4__(Ci, 11) ^ __ROR4__(Ci, 25)) + Fh + (Eh ^ (Dh ^ Eh) & Ci) + W_136 + 1294757372;
  Bi = temp1bh + Bh;
  Fi = (Ah & (Gi | Hh) | Gi & Hh) + (__ROR4__(Gi, 2) ^ __ROR4__(Gi, 13) ^ __ROR4__(Gi, 22)) + temp1bh;
  W_140 = (__ROR4__(W_132, 17) ^ __ROR4__(W_132, 19) ^ (W_132 >> 10))
        + W_112
        + ((W_80 >> 3) ^ __ROR4__(W_80, 7) ^ __ROR4__(W_80, 18))
        + W_76;
  temp1bi = (__ROR4__(Bi, 6) ^ __ROR4__(Bi, 11) ^ __ROR4__(Bi, 25)) + Eh + (Dh ^ (Ci ^ Dh) & Bi) + W_140 + 1396182291;
  Ai = temp1bi + Ah;
  Ei = (Hh & (Fi | Gi) | Fi & Gi) + (__ROR4__(Fi, 2) ^ __ROR4__(Fi, 13) ^ __ROR4__(Fi, 22)) + temp1bi;
  W_144 = (__ROR4__(W_136, 17) ^ __ROR4__(W_136, 19) ^ (W_136 >> 10))
        + W_116
        + ((W_84 >> 3) ^ __ROR4__(W_84, 7) ^ __ROR4__(W_84, 18))
        + W_80;
  temp1bj = (__ROR4__(Ai, 6) ^ __ROR4__(Ai, 11) ^ __ROR4__(Ai, 25)) + Dh + (Ci ^ (Bi ^ Ci) & Ai) + W_144 + 1695183700;
  Hi = temp1bj + Hh;
  Di = (Gi & (Ei | Fi) | Ei & Fi) + (__ROR4__(Ei, 2) ^ __ROR4__(Ei, 13) ^ __ROR4__(Ei, 22)) + temp1bj;
  W_148 = (__ROR4__(W_140, 17) ^ __ROR4__(W_140, 19) ^ (W_140 >> 10))
        + W_120
        + ((W_88 >> 3) ^ __ROR4__(W_88, 7) ^ __ROR4__(W_88, 18))
        + W_84;
  temp1bk = (__ROR4__(Hi, 6) ^ __ROR4__(Hi, 11) ^ __ROR4__(Hi, 25)) + Ci + (Bi ^ (Ai ^ Bi) & Hi) + W_148 + 1986661051;
  Gj = temp1bk + Gi;
  Cj = (Fi & (Di | Ei) | Di & Ei) + (__ROR4__(Di, 2) ^ __ROR4__(Di, 13) ^ __ROR4__(Di, 22)) + temp1bk;
  W_152 = (__ROR4__(W_144, 17) ^ __ROR4__(W_144, 19) ^ (W_144 >> 10))
        + W_124
        + ((W_92 >> 3) ^ __ROR4__(W_92, 7) ^ __ROR4__(W_92, 18))
        + W_88;
  temp1bl = (__ROR4__(Gj, 6) ^ __ROR4__(Gj, 11) ^ __ROR4__(Gj, 25)) + Bi + (Ai ^ (Hi ^ Ai) & Gj) + W_152 - 2117940946;
  Fj = temp1bl + Fi;
  Bj = (Ei & (Cj | Di) | Cj & Di) + (__ROR4__(Cj, 2) ^ __ROR4__(Cj, 13) ^ __ROR4__(Cj, 22)) + temp1bl;
  W_156 = (__ROR4__(W_148, 17) ^ __ROR4__(W_148, 19) ^ (W_148 >> 10))
        + W_128
        + ((W_96 >> 3) ^ __ROR4__(W_96, 7) ^ __ROR4__(W_96, 18))
        + W_92;
  temp1bm = (__ROR4__(Fj, 6) ^ __ROR4__(Fj, 11) ^ __ROR4__(Fj, 25)) + Ai + (Hi ^ (Gj ^ Hi) & Fj) + W_156 - 1838011259;
  Ej = temp1bm + Ei;
  Aj = (Di & (Bj | Cj) | Bj & Cj) + (__ROR4__(Bj, 2) ^ __ROR4__(Bj, 13) ^ __ROR4__(Bj, 22)) + temp1bm;
  W_160 = (__ROR4__(W_152, 17) ^ __ROR4__(W_152, 19) ^ (W_152 >> 10))
        + W_132
        + ((W_100 >> 3) ^ __ROR4__(W_100, 7) ^ __ROR4__(W_100, 18))
        + W_96;
  temp1bn = (__ROR4__(Ej, 6) ^ __ROR4__(Ej, 11) ^ __ROR4__(Ej, 25)) + Hi + (Gj ^ (Fj ^ Gj) & Ej) + W_160 - 1564481375;
  Dj = temp1bn + Di;
  Hj = (Cj & (Aj | Bj) | Aj & Bj) + (__ROR4__(Aj, 2) ^ __ROR4__(Aj, 13) ^ __ROR4__(Aj, 22)) + temp1bn;
  W_164 = (__ROR4__(W_156, 17) ^ __ROR4__(W_156, 19) ^ (W_156 >> 10))
        + W_136
        + ((W_104 >> 3) ^ __ROR4__(W_104, 7) ^ __ROR4__(W_104, 18))
        + W_100;
  temp1bo = (__ROR4__(Dj, 6) ^ __ROR4__(Dj, 11) ^ __ROR4__(Dj, 25)) + Gj + (Fj ^ (Ej ^ Fj) & Dj) + W_164 - 1474664885;
  Ck = temp1bo + Cj;
  Gk = (Bj & (Hj | Aj) | Hj & Aj) + (__ROR4__(Hj, 2) ^ __ROR4__(Hj, 13) ^ __ROR4__(Hj, 22)) + temp1bo;
  W_168 = (__ROR4__(W_160, 17) ^ __ROR4__(W_160, 19) ^ (W_160 >> 10))
        + W_140
        + ((W_108 >> 3) ^ __ROR4__(W_108, 7) ^ __ROR4__(W_108, 18))
        + W_104;
  temp1bp = (__ROR4__(Ck, 6) ^ __ROR4__(Ck, 11) ^ __ROR4__(Ck, 25)) + Fj + (Ej ^ (Dj ^ Ej) & Ck) + W_168 - 1035236496;
  Bk = temp1bp + Bj;
  Fk = (Aj & (Gk | Hj) | Gk & Hj) + (__ROR4__(Gk, 2) ^ __ROR4__(Gk, 13) ^ __ROR4__(Gk, 22)) + temp1bp;
  W_172 = (__ROR4__(W_164, 17) ^ __ROR4__(W_164, 19) ^ (W_164 >> 10))
        + W_144
        + ((W_112 >> 3) ^ __ROR4__(W_112, 7) ^ __ROR4__(W_112, 18))
        + W_108;
  temp1bq = (__ROR4__(Bk, 6) ^ __ROR4__(Bk, 11) ^ __ROR4__(Bk, 25)) + Ej + (Dj ^ (Ck ^ Dj) & Bk) + W_172 - 949202525;
  Ak = temp1bq + Aj;
  Ek = (Hj & (Fk | Gk) | Fk & Gk) + (__ROR4__(Fk, 2) ^ __ROR4__(Fk, 13) ^ __ROR4__(Fk, 22)) + temp1bq;
  W_176 = (__ROR4__(W_168, 17) ^ __ROR4__(W_168, 19) ^ (W_168 >> 10))
        + W_148
        + ((W_116 >> 3) ^ __ROR4__(W_116, 7) ^ __ROR4__(W_116, 18))
        + W_112;
  temp1br = (__ROR4__(Ak, 6) ^ __ROR4__(Ak, 11) ^ __ROR4__(Ak, 25)) + Dj + (Ck ^ (Bk ^ Ck) & Ak) + W_176 - 778901479;
  Hk = temp1br + Hj;
  Dk = (Gk & (Ek | Fk) | Ek & Fk) + (__ROR4__(Ek, 2) ^ __ROR4__(Ek, 13) ^ __ROR4__(Ek, 22)) + temp1br;
  W_180 = (__ROR4__(W_172, 17) ^ __ROR4__(W_172, 19) ^ (W_172 >> 10))
        + W_152
        + ((W_120 >> 3) ^ __ROR4__(W_120, 7) ^ __ROR4__(W_120, 18))
        + W_116;
  temp1bs = (__ROR4__(Hk, 6) ^ __ROR4__(Hk, 11) ^ __ROR4__(Hk, 25)) + Ck + (Bk ^ (Ak ^ Bk) & Hk) + W_180 - 694614492;
  Gl = temp1bs + Gk;
  Cl = (Fk & (Dk | Ek) | Dk & Ek) + (__ROR4__(Dk, 2) ^ __ROR4__(Dk, 13) ^ __ROR4__(Dk, 22)) + temp1bs;
  W_184 = (__ROR4__(W_176, 17) ^ __ROR4__(W_176, 19) ^ (W_176 >> 10))
        + W_156
        + ((W_124 >> 3) ^ __ROR4__(W_124, 7) ^ __ROR4__(W_124, 18))
        + W_120;
  temp1bt = (__ROR4__(Gl, 6) ^ __ROR4__(Gl, 11) ^ __ROR4__(Gl, 25)) + Bk + (Ak ^ (Hk ^ Ak) & Gl) + W_184 - 200395387;
  Fl = temp1bt + Fk;
  Bl = (Ek & (Cl | Dk) | Cl & Dk) + (__ROR4__(Cl, 2) ^ __ROR4__(Cl, 13) ^ __ROR4__(Cl, 22)) + temp1bt;
  W_188 = (__ROR4__(W_180, 17) ^ __ROR4__(W_180, 19) ^ (W_180 >> 10))
        + W_160
        + ((W_128 >> 3) ^ __ROR4__(W_128, 7) ^ __ROR4__(W_128, 18))
        + W_124;
  temp1bu = (__ROR4__(Fl, 6) ^ __ROR4__(Fl, 11) ^ __ROR4__(Fl, 25)) + Ak + (Hk ^ (Gl ^ Hk) & Fl) + W_188 + 275423344;
  El = temp1bu + Ek;
  Al = (Dk & (Bl | Cl) | Bl & Cl) + (__ROR4__(Bl, 2) ^ __ROR4__(Bl, 13) ^ __ROR4__(Bl, 22)) + temp1bu;
  W_192 = (__ROR4__(W_184, 17) ^ __ROR4__(W_184, 19) ^ (W_184 >> 10))
        + W_164
        + ((W_132 >> 3) ^ __ROR4__(W_132, 7) ^ __ROR4__(W_132, 18))
        + W_128;
  temp1bv = (__ROR4__(El, 6) ^ __ROR4__(El, 11) ^ __ROR4__(El, 25)) + Hk + (Gl ^ (Fl ^ Gl) & El) + W_192 + 430227734;
  Dl = temp1bv + Dk;
  Hl = (Cl & (Al | Bl) | Al & Bl) + (__ROR4__(Al, 2) ^ __ROR4__(Al, 13) ^ __ROR4__(Al, 22)) + temp1bv;
  W_196 = (__ROR4__(W_188, 17) ^ __ROR4__(W_188, 19) ^ (W_188 >> 10))
        + W_168
        + ((W_136 >> 3) ^ __ROR4__(W_136, 7) ^ __ROR4__(W_136, 18))
        + W_132;
  temp1bw = (__ROR4__(Dl, 6) ^ __ROR4__(Dl, 11) ^ __ROR4__(Dl, 25)) + Gl + (Fl ^ (El ^ Fl) & Dl) + W_196 + 506948616;
  Cm = temp1bw + Cl;
  Gm = (Bl & (Hl | Al) | Hl & Al) + (__ROR4__(Hl, 2) ^ __ROR4__(Hl, 13) ^ __ROR4__(Hl, 22)) + temp1bw;
  W_200 = (__ROR4__(W_192, 17) ^ __ROR4__(W_192, 19) ^ (W_192 >> 10))
        + W_172
        + ((W_140 >> 3) ^ __ROR4__(W_140, 7) ^ __ROR4__(W_140, 18))
        + W_136;
  temp1bx = (__ROR4__(Cm, 6) ^ __ROR4__(Cm, 11) ^ __ROR4__(Cm, 25)) + Fl + (El ^ (Dl ^ El) & Cm) + W_200 + 659060556;
  Bm = temp1bx + Bl;
  Fm = (Al & (Gm | Hl) | Gm & Hl) + (__ROR4__(Gm, 2) ^ __ROR4__(Gm, 13) ^ __ROR4__(Gm, 22)) + temp1bx;
  W_204 = (__ROR4__(W_196, 17) ^ __ROR4__(W_196, 19) ^ (W_196 >> 10))
        + W_176
        + ((W_144 >> 3) ^ __ROR4__(W_144, 7) ^ __ROR4__(W_144, 18))
        + W_140;
  temp1by = (__ROR4__(Bm, 6) ^ __ROR4__(Bm, 11) ^ __ROR4__(Bm, 25)) + El + (Dl ^ (Cm ^ Dl) & Bm) + W_204 + 883997877;
  Am = temp1by + Al;
  Em = (Hl & (Fm | Gm) | Fm & Gm) + (__ROR4__(Fm, 2) ^ __ROR4__(Fm, 13) ^ __ROR4__(Fm, 22)) + temp1by;
  W_208 = (__ROR4__(W_200, 17) ^ __ROR4__(W_200, 19) ^ (W_200 >> 10))
        + W_180
        + ((W_148 >> 3) ^ __ROR4__(W_148, 7) ^ __ROR4__(W_148, 18))
        + W_144;
  temp1bz = (__ROR4__(Am, 6) ^ __ROR4__(Am, 11) ^ __ROR4__(Am, 25)) + Dl + (Cm ^ (Bm ^ Cm) & Am) + W_208 + 958139571;
  Hm = temp1bz + Hl;
  Dm = (Gm & (Em | Fm) | Em & Fm) + (__ROR4__(Em, 2) ^ __ROR4__(Em, 13) ^ __ROR4__(Em, 22)) + temp1bz;
  W_212 = (__ROR4__(W_204, 17) ^ __ROR4__(W_204, 19) ^ (W_204 >> 10))
        + W_184
        + ((W_152 >> 3) ^ __ROR4__(W_152, 7) ^ __ROR4__(W_152, 18))
        + W_148;
  temp1ca = (__ROR4__(Hm, 6) ^ __ROR4__(Hm, 11) ^ __ROR4__(Hm, 25)) + Cm + (Bm ^ (Am ^ Bm) & Hm) + W_212 + 1322822218;
  Gn = temp1ca + Gm;
  Cn = (Fm & (Dm | Em) | Dm & Em) + (__ROR4__(Dm, 2) ^ __ROR4__(Dm, 13) ^ __ROR4__(Dm, 22)) + temp1ca;
  W_216 = (__ROR4__(W_208, 17) ^ __ROR4__(W_208, 19) ^ (W_208 >> 10))
        + W_188
        + ((W_156 >> 3) ^ __ROR4__(W_156, 7) ^ __ROR4__(W_156, 18))
        + W_152;
  temp1cb = (__ROR4__(Gn, 6) ^ __ROR4__(Gn, 11) ^ __ROR4__(Gn, 25)) + Bm + (Am ^ (Hm ^ Am) & Gn) + W_216 + 1537002063;
  Fn = temp1cb + Fm;
  Bn = (Em & (Cn | Dm) | Cn & Dm) + (__ROR4__(Cn, 2) ^ __ROR4__(Cn, 13) ^ __ROR4__(Cn, 22)) + temp1cb;
  W_220 = (__ROR4__(W_212, 17) ^ __ROR4__(W_212, 19) ^ (W_212 >> 10))
        + W_192
        + ((W_160 >> 3) ^ __ROR4__(W_160, 7) ^ __ROR4__(W_160, 18))
        + W_156;
  temp1cc = (__ROR4__(Fn, 6) ^ __ROR4__(Fn, 11) ^ __ROR4__(Fn, 25)) + Am + (Hm ^ (Gn ^ Hm) & Fn) + W_220 + 1747873779;
  En = temp1cc + Em;
  An = (Dm & (Bn | Cn) | Bn & Cn) + (__ROR4__(Bn, 2) ^ __ROR4__(Bn, 13) ^ __ROR4__(Bn, 22)) + temp1cc;
  W_224 = (__ROR4__(W_216, 17) ^ __ROR4__(W_216, 19) ^ (W_216 >> 10))
        + W_196
        + ((W_164 >> 3) ^ __ROR4__(W_164, 7) ^ __ROR4__(W_164, 18))
        + W_160;
  temp1cd = (__ROR4__(En, 6) ^ __ROR4__(En, 11) ^ __ROR4__(En, 25)) + Hm + (Gn ^ (Fn ^ Gn) & En) + W_224 + 1955562222;
  Dn = temp1cd + Dm;
  Hn = (Cn & (An | Bn) | An & Bn) + (__ROR4__(An, 2) ^ __ROR4__(An, 13) ^ __ROR4__(An, 22)) + temp1cd;
  W_228 = (__ROR4__(W_220, 17) ^ __ROR4__(W_220, 19) ^ (W_220 >> 10))
        + W_200
        + ((W_168 >> 3) ^ __ROR4__(W_168, 7) ^ __ROR4__(W_168, 18))
        + W_164;
  temp1ce = (__ROR4__(Dn, 6) ^ __ROR4__(Dn, 11) ^ __ROR4__(Dn, 25)) + Gn + (Fn ^ (En ^ Fn) & Dn) + W_228 + 2024104815;
  Co = temp1ce + Cn;
  Go = (Bn & (Hn | An) | Hn & An) + (__ROR4__(Hn, 2) ^ __ROR4__(Hn, 13) ^ __ROR4__(Hn, 22)) + temp1ce;
  W_232 = (__ROR4__(W_224, 17) ^ __ROR4__(W_224, 19) ^ (W_224 >> 10))
        + W_204
        + ((W_172 >> 3) ^ __ROR4__(W_172, 7) ^ __ROR4__(W_172, 18))
        + W_168;
  temp1cf = (__ROR4__(Co, 6) ^ __ROR4__(Co, 11) ^ __ROR4__(Co, 25)) + Fn + (En ^ (Dn ^ En) & Co) + W_232 - 2067236844;
  Bo = temp1cf + Bn;
  Fo = (An & (Go | Hn) | Go & Hn) + (__ROR4__(Go, 2) ^ __ROR4__(Go, 13) ^ __ROR4__(Go, 22)) + temp1cf;
  W_236 = (__ROR4__(W_228, 17) ^ __ROR4__(W_228, 19) ^ (W_228 >> 10))
        + W_208
        + ((W_176 >> 3) ^ __ROR4__(W_176, 7) ^ __ROR4__(W_176, 18))
        + W_172;
  temp1cg = (__ROR4__(Bo, 6) ^ __ROR4__(Bo, 11) ^ __ROR4__(Bo, 25)) + En + (Dn ^ (Co ^ Dn) & Bo) + W_236 - 1933114872;
  Ao = temp1cg + An;
  Eo = (Hn & (Fo | Go) | Fo & Go) + (__ROR4__(Fo, 2) ^ __ROR4__(Fo, 13) ^ __ROR4__(Fo, 22)) + temp1cg;
  W_240 = (__ROR4__(W_232, 17) ^ __ROR4__(W_232, 19) ^ (W_232 >> 10))
        + W_212
        + ((W_180 >> 3) ^ __ROR4__(W_180, 7) ^ __ROR4__(W_180, 18))
        + W_176;
  temp1ch = (__ROR4__(Ao, 6) ^ __ROR4__(Ao, 11) ^ __ROR4__(Ao, 25)) + Dn + (Co ^ (Bo ^ Co) & Ao) + W_240 - 1866530822;
  Ho = temp1ch + Hn;
  Do = (Go & (Eo | Fo) | Eo & Fo) + (__ROR4__(Eo, 2) ^ __ROR4__(Eo, 13) ^ __ROR4__(Eo, 22)) + temp1ch;
  W_244 = (__ROR4__(W_236, 17) ^ __ROR4__(W_236, 19) ^ (W_236 >> 10))
        + W_216
        + ((W_184 >> 3) ^ __ROR4__(W_184, 7) ^ __ROR4__(W_184, 18))
        + W_180;
  temp1ci = (__ROR4__(Ho, 6) ^ __ROR4__(Ho, 11) ^ __ROR4__(Ho, 25)) + Co + (Bo ^ (Ao ^ Bo) & Ho) + W_244 - 1538233109;
  Gp = temp1ci + Go;
  Cp = (Fo & (Do | Eo) | Do & Eo) + (__ROR4__(Do, 2) ^ __ROR4__(Do, 13) ^ __ROR4__(Do, 22)) + temp1ci;
  temp1cj = (__ROR4__(Gp, 6) ^ __ROR4__(Gp, 11) ^ __ROR4__(Gp, 25))
          + Bo
          + (Ao ^ (Ho ^ Ao) & Gp)
          + (__ROR4__(W_240, 17) ^ __ROR4__(W_240, 19) ^ (W_240 >> 10))
          + W_220
          + ((W_188 >> 3) ^ __ROR4__(W_188, 7) ^ __ROR4__(W_188, 18))
          + W_184
          - 1090935817;
  Fp = temp1cj + Fo;
  Bp = (Eo & (Cp | Do) | Cp & Do) + (__ROR4__(Cp, 2) ^ __ROR4__(Cp, 13) ^ __ROR4__(Cp, 22)) + temp1cj;
  temp1ck = (__ROR4__(Fp, 6) ^ __ROR4__(Fp, 11) ^ __ROR4__(Fp, 25))
          + Ao
          + (Ho ^ (Gp ^ Ho) & Fp)
          + (__ROR4__(W_244, 17) ^ __ROR4__(W_244, 19) ^ (W_244 >> 10))
          + W_224
          + ((W_192 >> 3) ^ __ROR4__(W_192, 7) ^ __ROR4__(W_192, 18))
          + W_188
          - 965641998;
  ctx->state[0] += (Do & (Bp | Cp) | Bp & Cp) + (__ROR4__(Bp, 2) ^ __ROR4__(Bp, 13) ^ __ROR4__(Bp, 22)) + temp1ck;
  ctx->state[1] += Bp;
  ctx->state[2] += Cp;
  ctx->state[3] += Do;
  ctx->state[4] += temp1ck + Eo;
  ctx->state[5] += Fp;
  ctx->state[6] += Gp;
  ctx->state[7] += Ho;
}
