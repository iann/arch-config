static int
shifttag(int dist)
{
    int i, curtags;
    int seltag = 0;

    curtags = selmon->tagset[selmon->seltags];
    for(i = 0; i < LENGTH(tags); i++) {
        if((curtags & (1 << i)) != 0) {
            seltag = i;
            break;
        }
    }

    seltag += dist;
    if(seltag < 0)
        seltag = LENGTH(tags) - 1;
    else
        seltag %= LENGTH(tags);
    return 1 << seltag;
}

static void
cycle(const Arg *arg)
{
    Arg a = { .i = shifttag(arg->i) };
    view(&a);
}

static void
tagcycle(const Arg *arg)
{
    Arg a = { .i = shifttag(arg->i) };
    tag(&a);
    view(&a);
}
