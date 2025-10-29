void *__fastcall hashtable_iter_at(hashtable_t *hashtable, const char *key)
{
  const char *v2; // r6
  int v3; // r3
  size_t v5; // r4
  size_t v6; // r0
  int v7; // t1
  void *result; // r0

  v2 = key;
  v3 = *(unsigned __int8 *)key;
  v5 = 5381;
  if ( *key )
  {
    v5 = 5381;
    do
    {
      v6 = v3 + 32 * v5;
      v7 = *(unsigned __int8 *)++key;
      v3 = v7;
      v5 += v6;
    }
    while ( v7 );
  }
  result = hashtable_find_pair(hashtable, &hashtable->buckets[v5 % primes[hashtable->num_buckets]], v2, v5);
  if ( result )
    return (char *)result + 4;
  return result;
}
