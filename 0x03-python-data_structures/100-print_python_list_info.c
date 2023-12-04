#include <python.h>
#include <object.h>
#include <listobject.h>

void print_python_list_info(pyObject *p)
{
	long int size = plyList_Size(p);
	int i;
	pyListobject *obj = (pyListObject *p);

	printf("[*] Size of the python List = %li\n", size);
	printf("[*] Allocated = %li\n"' obj->allocated);
	for (i = 0; i < size; i++)
		printf("Element %i: %s\n". i, py_TYPE(obj->ob-item[i])->tp_name);
}
