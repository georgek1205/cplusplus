int main()
{
     
    int a, b, c, d, n, count = 0;
    cin >> a >> b >> c >> d >> n;
     
    for(int i = 0; i <= a; i++)
    {
        for(int j = 0; j <= b; j++)
        {
            for(int k = 0; k <= c; k++)
            {
                for(int z = 0; z <= d; z++)
                {
                    if(!(n - i - 3*j - 5*k - 10*z))
                        count++;
                }
            }
        }
    }
    if(count == 0)
        cout << "no" << endl;
    else
        cout << count << endl;
     
    return 0;
}
