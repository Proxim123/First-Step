#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
void dynamic_array()
{
	int insert(int *data);
	int delete(int *data);
	void display();
}
*/

void pointer_start()
{
	int t1 = 2, t2 = 4, t3 = 6;
	int *pt1, *pt2, *pt3;

    /* constant pointer 
	   1.initialization is a must
	   2.address modification is not allowed
	   3.value modification is allowed
	*/
	int * const c_pt1 = &t1;

	/* pointer to a constant variable
	   1.initialization is not a must
	   2.address modification is allowed
	   3.value modification is not allowed
	*/
	const int * c_pt2;
	c_pt2 = &t2;

	//constant pointer to a constant variable(you can guess the rest)
	const int * const c_pt3 = &t3;


	printf("[constant pointer 1] Addr:%p-%p, value:%d-%d\n", &t1, c_pt1, t1, *c_pt1);
	printf("[constant pointer 2] Addr:%p-%p, value:%d-%d\n", &t2, c_pt2, t2, *c_pt2);
	printf("[constant pointer 3] Addr:%p-%p, value:%d-%d\n", &t3, c_pt3, t3, *c_pt3);

	/**** Constant pointer and pointer to a constant variable ***/
	
	//[constant pointer]value modification
	*c_pt1 = 10;
	printf("[constant pointer 1] Addr:%p-%p, value:%d-%d\n", &t1, c_pt1, t1, *c_pt1);

	//[constant pointer]address modification
	//c_pt1 = &t3;
	//printf("[constant pointer 1] Addr:%p-%p, value:%d-%d\n", &t1, c_pt1, t1, *c_pt1);

	//address modification
	c_pt2 = &t3;
	printf("[constant pointer 3] Addr:%p-%p, value:%d-%d\n", &t3, c_pt3, t3, *c_pt3);

	//value modification
	//*c_pt2 = 11;
	//printf("[constant pointer 2] Addr:%p-%p, value:%d-%d\n", &t2, c_pt2, t2, *c_pt2);
}

void pointer_array()
{
	int arr[4] = {1, 2, 3, 4};
	int i = 0;

	//pointer to an integer: points to the element arr[0] or arr
	int *ptr;

	//array of pointers: array which can contain only pointer variable
	int *t_ptr[4];

	/*pointer to an array of 4 integers
	  1.array that points to the whole elements of the array arr
	  2.important when talking about multidimensional array
	  3.int (*t_ptr1)[4] is totally different from *ptr
	*/
	int (*t_ptr1)[4];

	//ptr points to the element 0 of the array
	ptr = arr;

	//t_ptr1 points to the whole array of 4 elements
	t_ptr1 = &arr;

	int *test1 = NULL;
	int *test2 = NULL;
	int *test3 = *t_ptr1;

	for ( i = 0; i < 4; i++) {
		t_ptr[i] = arr + i;

		/*points to the ith element in array of index 0 (the current and unique array)
		 */
		test1 = (t_ptr1[0] + i);  
		
		/* points to the ith array of a multidimensional array
		 */
		test2 = t_ptr1[i];
		printf("[%d] Addr:%p-%p-%p-%p-%p-%p, value:%d-%d-%d-%d-%d-%d-%d-%d\n", i+1, \
			   arr + i, ptr + i, t_ptr[i], test1, test3 + i, test2,         		\
			   arr[i], *(&arr[i]), *(arr + i), *(ptr + i), *(t_ptr[i]), *test1, *(test3 + i), *test2);
	}
}

void freestring(char *str)
{
	free(str);
}

void pointer_string()
{

	/* Simple operations on strings with pointers*/
#if 1
	char arr[6];
	char *ptr;

	printf("Input Hello\n");
	scanf("%s", arr);
	ptr = arr;
	while(*ptr != '\0') {
		printf("%c", *ptr);
		ptr++;
	}
	printf("\n");
#endif
	/* Array of strings */
	int i = 0;
	char one[4][6] = {
		"Mitch",
		"Rosie",
		"Shana",
		"Josie"
	};

	char* two[4];
	char tmp[32];
	for ( i = 0; i < 4; i++) {
		printf("Insert string\n");
		scanf("%s", tmp);
		printf("tmp[32] sizeof:%ld, strlen:%d char size:%ld\n", sizeof(tmp), (int)strlen(tmp), sizeof(char));
		two[i] = (char*)malloc(sizeof(char) * (strlen(tmp)+1));
		strcpy(two[i], tmp);
	}

	char** three = NULL;
	for ( i = 0; i < 4; i++) {
		printf("Insert Data:");
		scanf("%s",tmp);
		if (three == NULL) {
			three = (char**)malloc(sizeof(char*));
		} else {
			three = (char**)realloc(three, sizeof(char*)*(i+1));
		}
		three[i] = (char*)malloc(sizeof(char)*(strlen(tmp)+1));
		strcpy(three[i], tmp);
	}

	/*Display*/
	for (i = 0; i < 4; i++) {
		printf("%s:%s:%s\n", one[i], two[i], three[i]);
	}

	for( i = 0; i < 4; i++) {
		freestring(two[i]);
		freestring(three[i]);
	}

	free(three);
}

void multidimensional_array()
{
	int i = 0, j = 0, k =0, count = 0;
	int A[6] = {1,2,3,4,5,6};
	int B[3][5];
	int C[2][4][3] = {{{0},{0}}};

	int (*point2arr)[5];
	int *t_ptr;

	printf("Address of array A: %p\n", A);
	printf("Address of array B: %p\n", B);
	printf("Address of array C: %p\n", C);

	for (i = 0; i < sizeof(A)/sizeof(int); i++) {
		printf("[%d] addr:%p, value:%d\n", i, (A + i), *(A + i));
	}

	for (i = 0; i < sizeof(B)/sizeof(B[0]); i++) {
		for (j = 0; j < sizeof(B[i])/sizeof(int); j++) {
			B[i][j] = ++count;
			printf("[%d][%d] addr:%p, value:%d\n", i, j, (*(B + i) + j), *(*(B + i) + j));
		}
	}

	point2arr = B;
	count = sizeof(B)/sizeof(B[0]);
	for (i = 0; i < 3 /*count*/; i++) {
		t_ptr = (*point2arr + i*5);
		printf("Addr of the %d row: %p\n", i, (*point2arr + i));
		for ( j = 0; j < 5 /*sizeof(B[0])/sizeof(int)*/; j++) {
			printf("[%d][%d] Addr:%p value:%d\n", i, j, t_ptr, *(t_ptr));
			t_ptr++;
		}
	}

	count = 0;
	for ( i = 0; i < sizeof(C)/sizeof(C[0]); i++) {
		for (j = 0; j < sizeof(C[0])/sizeof(C[0][0]); j++) {
			for ( k = 0; k < sizeof(C[0][0])/sizeof(int); k++) {
				C[i][j][k] = ++count;
				printf("[%d][%d][%d] addr:%p, value:%d\n", i, j, k, (*(*(C+i)+j)+k), *(*(*(C+i)+j)+k));
			}
		}
	}

	t_ptr = NULL;
	for (i = 0; i < sizeof(C)/sizeof(C[0]); i++) {
		printf("3D row:%d", i);
		for (j = 0; j < sizeof(C[0])/sizeof(C[0][0]); j++) {
			printf("2D row:%d", j);
			t_ptr = *(C[i] + j);
			//t_ptr = C[i][j]; //this one is fine also
			for (k = 0; k < sizeof(C[0][0])/sizeof(int); k++) {
				printf("[%d]addr: %p, value:%d\n", k, t_ptr, *t_ptr++);
			}
		}
	}

	printf("sizeof: A[6]=>%ld, B[3][5]=>%ld, C[2][4][3]=>%ld B=>%ld C=>%ld\n", sizeof(A), sizeof(B), sizeof(C), sizeof(B)/sizeof(B[0]), sizeof(C)/sizeof(C[0]));
}

struct student {
	char name[16];
	int age;
};

void addStu1(struct student *stu)
{
	printf("%s, %d\n", __func__, __LINE__);
	stu = ((struct student *)malloc(sizeof(struct student)));
	printf("value:%p\n", stu);
	strcpy(stu->name,"Mitch");
	stu->age = 20;
	printf("name:%s, age:%d\n", stu->name, stu->age);
	printf("value:%p\n", stu);
}

void addStu2(struct student **stu)
{
	printf("\n%s, %d\n", __func__, __LINE__);
	*stu = (struct student *)malloc(sizeof(struct student));
	printf("value:%p\n", *stu);
	strcpy((*stu)->name,"Rich");
	(*stu)->age = 28;
	printf("name:%s, age:%d\n", (*stu)->name, (*stu)->age);
	printf("value:%p\n", *stu);
}

struct student addStu3(struct student stu)
{
	printf("\n%s, %d\n", __func__, __LINE__);
	strcpy(stu.name,"Mitch");
	stu.age = 20;
	printf("name:%s, age:%d\n", stu.name, stu.age);
	return stu;
}

void pointer_struct()
{
	/*
	  CPU reads/writes into memory via small chunks called word size(4bytes)
	  int(4 bytes, then ok)
	  char(1bytes, structure padding makes it 4bytes,
	       so the next elmt will start from a word size offset as well)
	  ex:
	     struct data {
		 int a; //sizeof(a):4bytes, normal
		 char b; //sizeof(b):1byte, structure padding
		 int c; //sizeof(c):4bytes, normal
		 }
	 */

	typedef struct itemqty {
		int softBeverage;
		int strongBeverage;
		char status;
		int tea;
		int cola;
	} Party;

	struct itemqty Party1 = {
		.softBeverage = 32,
		.strongBeverage = 64,
		.status = 'A',
		.tea = 8,
		.cola = 16
	};

	Party Party2 = {
		.status = 'B',
		.tea = 8,
		.cola = 16
	};

	printf("[Status] Party1:%c Party2:%c\n", Party1.status, Party2.status);

	struct student *stu1 = NULL;

/*
	printf("addr:%p, value:%p\n", &stu1, stu1);
	addStu1(stu1);
	printf("addr:%p, value:%p\n", &stu1, stu1);

    //next line is a mistake because stu1 is still NULL
	//printf("name:%s, age:%d\n", stu1->name, stu1->age);
*/
	struct student *stu2 = (struct student *)malloc(sizeof(struct student));
	//printf("[%s, %d]addr:%p, value:%p\n", __func__, __LINE__, &stu2, stu2);
	addStu1(stu2);
	//printf("addr:%p, value:%p\n", &stu2, stu2);
	//next line is a mistake(Obtain unexpected values because of malloc from addStu1)
	printf("name:%s, age:%d\n", stu2->name, stu2->age);


	//return values using the same parameters
	printf("[%s, %d]addr:%p, value:%p\n", __func__, __LINE__, &stu1, stu1);
	addStu2(&stu1);
	printf("addr:%p, value:%p\n", &stu1, stu1);
	printf("name:%s, age:%d\n", stu1->name, stu1->age);

	//return values via a struct student as return value
	struct student stu3;
	struct student stu_tmp;
	stu_tmp = addStu3(stu3);
	printf("[%s, %d]name:%s, age:%d\n", __func__, __LINE__, stu_tmp.name, stu_tmp.age);
}

struct signature {
	char sign;
	char version;
};

struct id {
	char id;
	char platform;
};

struct data {
	struct signature sig;
	struct id idv;
	char data[100];
	int rank;
};

void receivedata(struct data* data1) {
	data1->sig.sign = 'S';
	data1->sig.version = 'V';
	data1->idv.id = 'I';
	data1->idv.platform = 'P';
	strcpy(data1->data, "Copyright");

	data1->rank = 1;

	printf("sig: %c, version:%c, id:%c, platform:%c, data:%s, rank:%d\n", \
		   data1->sig.sign, data1->sig.version, data1->idv.id, data1->idv.platform, data1->data, data1->rank);
}

struct signature* extractsign(struct data* data){
	struct signature* sig = (struct signature*)data;
	return sig;
}

struct id* extractid(struct data* data){
	struct id* id = (struct id*)data + 1;
	return id;
}

void struct_pointer_typecasting() {
	struct data* img = (struct data *)malloc(sizeof(struct data));
	receivedata(img);
	printf("*sig: %c, version:%c, id:%c, platform:%c, data:%s, rank:%d\n", \
		   img->sig.sign, img->sig.version, img->idv.id, img->idv.platform, img->data, img->rank);

	struct signature* sign = extractsign(img);
	printf("sig:%c, ver:%c\n", sign->sign, sign->version);
	struct id* id = extractid(img);	
	printf("id:%c, platform:%c\n", id->id, id->platform);
}

/*
  self referential structures: structures that contain pointer variable of the same type
  usually used for: linked lists, trees, graphs, ...
*/

void linkedlist()
{
	struct node {
		int data;
		struct node* next;
	};

	struct node* createNode(int data) {
		struct node* tmp = (struct node*)malloc(sizeof(struct node));
		tmp->data = data;
		tmp->next = NULL;
		return tmp;
	};

	void addNode(struct node** root, struct node* n){
		struct node* tmp = *root;
		if (tmp == NULL) {
			*root = n;
		} else {
			while(tmp->next != NULL) {
				printf("%d\n", tmp->data);
				tmp = tmp->next;
			}
			tmp->next = n;
		}
	}

	struct node *root = NULL, *tmp;
	int i = 0;
	for (i = 0; i < 10; i++) {
		addNode(&root, createNode(i));
	}

	tmp = root;
	while(tmp->next != NULL) {
		printf("data:%d\n", tmp->data);
		tmp = tmp->next;
	}

}

/*
  function pointers:
*/
int add1(int x, int y)
{
	return x + y;
}

int sub1(int x, int y)
{
	int ret = 0;

	(x > y)? (ret = x-y) : (ret = y-x);
	return ret;
}

int mul1(int x, int y)
{
	return x * y;
}

int div1(int x, int y)
{
	int ret = 0;

	return x/y;
}

int operation(int (*funcptr)(int, int), int x, int y)
{
	return (*funcptr)(x, y);
}

void ops(void)
{
	int choose = 0, result = 0;
	//array of function pointers used for addition
	int (*opfuncptr[4])(int x, int y) = {add1, sub1, mul1, div1};

	//returnin function pointers from function(callback)

	printf("choose your op:\n");
	printf("1.addition\n 2.substraction\n 3.multiplication\n 4.division\n 5.cancel\n");

	while(choose != 5) {
		printf("Input: ");
		scanf("%d", &choose);
#if 1
		switch(choose) {
		case 1:
			//result = operation(add1, 4, 5);
			result = opfuncptr[0](4, 5);
			break;
		case 2:
			result = operation(sub1, 4, 5);
			break;
		case 3:
			result = operation(mul1, 4, 5);
			break;
		case 4:
			result = operation(div1, 4, 5);
			break;
		case 5:
			break;
		default:
			printf("wrong value: choose between 1 to 5\n");
		}
#else
		if(choose == 1)
			result = operation(add1, 10, 5);
		if(choose == 2)
			result = operation(sub1, 10, 5);
		if(choose == 3)
			result = operation(mul1, 10, 5);
		if(choose == 4)
			result = operation(div1, 10, 5);
		if(choose == 5)
			break;
#endif
		printf("result: %d\n", result);
	}
}

void func_ptr_from_func()
{
	int result = 0;

	//return function pointer from function, with parameters
	int (*sub1ptr)(int x, int y);
	sub1ptr = sub1;

	result = ((sub1ptr)(4, 5));
	printf("result: %d\n", result);

	//return function pointer from function, without parameters
	int (*sub1funcptr)(void);
	//int (*sub1funcptr(void))(int, int);
	sub1funcptr = sub1;
	result = (sub1funcptr)();
	printf("2 result: %d\n", result);
}

int main(int argc, char *argv[])
{
	//pointer_start();
	//pointer_array();
	//pointer_string();
	//multidimensional_array();
	//pointer_struct();
	//struct_pointer_typecasting();
	//linkedlist();

	//function pointers application
	ops();

	func_ptr_from_func();


	return 0;
}
