void reverse(NODE **temp)
    {

        NODE *q,*r,*s;
        q=*temp;
        r =NULL;
        while(q)
        {
            s=r;
            r=q;
            q=q->next;
            r->next=s;

        }
        *temp =r;
    }
