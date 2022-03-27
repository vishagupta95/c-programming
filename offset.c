typedef struct st0a_init_addr_msg
{
    struct
    {
      BYTE NC[4];     
    } s1;
    BYTE  st0p1_param1_ptr;               /* pointer to parameter 1 */
    BYTE  st0p2_param2_ptr;               /* pointer to parameter 2 */
    BYTE  st0p3_opt_param_ptr;            /* pointer to optional parameters */

}st0a_MSG;

#define ST6Z sizeof(struct st0a_init_addr_msg)
#define offsetof(struct_type,element)  (WORD)(&((struct_type*) 0)->element)
#define ELEMEO(struct_name,element)  offsetof(struct_name,element)
#define ST6P1O  ELEMEO(st0a_MSG, st0p1_param1_ptr)

main()
{
 st0a_MSG *ptr;
 printf("%d \n",(BYTE)(&((st0a_MSG*) 0)->st0p1_param1_ptr));
 printf("%d \n",ST6Z);
 printf("%u\n",((BYTE  *)&ptr->st0p1_param1_ptr)- (BYTE *)(ptr));
 printf(" ELEMEO %d \n",ST6P1O);
 printf("%d \n",ST6Z -(((BYTE  *)&ptr->st0p1_param1_ptr)- (BYTE *)(ptr)));
 printf(" ELEMEO diff  %d \n",ST6Z - ST6P1O);
}

