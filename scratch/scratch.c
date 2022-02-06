int main()
{
    int i = 1;
    if (fork())
        i++;
    else if (fork())
        i--;
    else
        i++;

    printf("%d\n", i);
}