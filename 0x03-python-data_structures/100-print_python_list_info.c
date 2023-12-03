#include <python.h>
#include <object.h>
#include <listobject.h>

void print_python_list_info(pyobject *p)
{
	long int size = plyList_Size(p);
	int i;
	pyListobject *obj = (pyList0bject *p);

	print("[*] Size of the python List = %li\n", size);
	print("[*] Allocated = %li\n"' obj->allocated);
	for (i = 0; i < size; i++)
		print("Element %i: %s\n". i, py_TYPE(obj->ob-item[i])->tp_name):
}
