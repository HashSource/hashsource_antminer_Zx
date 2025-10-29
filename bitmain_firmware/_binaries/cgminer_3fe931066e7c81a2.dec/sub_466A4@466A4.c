int __fastcall sub_466A4(int result)
{
  char v1[4100]; // [sp+0h] [bp-1004h] BYREF

  if ( result != 1 && result != 2 )
  {
    if ( (unsigned int)(result - 3) > 1 )
    {
      if ( (unsigned int)(result - 5) > 3 )
      {
        if ( (unsigned int)(result - 9) > 7 )
        {
          if ( (unsigned int)(result - 17) > 0xF )
          {
            if ( (unsigned int)(result - 33) > 0x1F )
            {
              if ( (unsigned int)(result - 65) > 0x3F )
              {
                if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
                {
                  snprintf(v1, 0x1000u, "actual_asic_number = %d, but it is error\n", result);
                  sub_38730(7, v1, 0);
                  return -1;
                }
                else
                {
                  return -1;
                }
              }
              else
              {
                return 128;
              }
            }
            else
            {
              return 64;
            }
          }
          else
          {
            return 32;
          }
        }
        else
        {
          return 16;
        }
      }
      else
      {
        return 8;
      }
    }
    else
    {
      return 4;
    }
  }
  return result;
}
