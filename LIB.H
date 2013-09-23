typedef struct STASHtag{
	int size;
	int quantity;
	int next;
	unsigned char* storage;
} Stash;

void initialize(Stash* S, int size);
void cleanup(Stash* S);
void add(Stash *S, void* element);
void* fetch(Stash* S, int index);
int count(Stash *S);
void inflate(Stash* S, int increase);