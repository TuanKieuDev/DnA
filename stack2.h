typedef struct{
	char name[30];
	int tel;
	char email[30];
	struct Address *link;
}Address;

typedef struct AddressList{
    struct AddressList *next;
    Address addr;
}AddressList;


AddressList *root = NULL;

Address *push(AddressList *p, Address ad);
Address *pop(Address *p, Address *ad);
