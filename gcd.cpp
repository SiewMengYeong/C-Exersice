int gcd(int a, int b)
{
if (a>b)
{
for (int i=b;i>=1;i--)
{
  if((a%i==0)&&(b%i==0))
{
  return i;
  break;
}
}
}

if (a<b)
{
for (int i=a;i>=1;i--)
{
  if((a%i==0)&&(b%i==0))
{
  return i;
  break;
}
}
}

if(a==b)
 return a;
}
