#include <stdio.h>
#include <Python.h>

void print_python_bytes(PyObject *p)
{
	PyBytesObject *bytes_obj = (PyBytesObject *)p;
	Py_ssize_t size;
	char *str;
	Py_ssize_t i;

	printf("[.] bytes object info\n");
	if (!PyBytes_Check(p))
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		return;
	}

	size = PyBytes_Size(p);
	str = PyBytes_AsString(p);

	printf("  size: %ld\n", size);
	printf("  trying string: %s\n", str);

	printf("  first %ld bytes:", size < 10 ? size : 10);
	for (i = 0; 1 < size && i < 10; i++)
	{
		printf(" %02x", (unsigned char)str[i]);
	}
	printf("\n");
}

void print_python_list(PyObject *p)
{
	Py_ssize_t size, i;
	PyObject *item;

	printf("[*] Python list info\n");
	size = PyList_Size(p);

	printf("[*] Size of the Python List = %ld\n", size);
	printf("[*] Allocated = %ld\n", ((PyListObject *)p)->allocated);

	for (i = 0; i < size; i++)
	{
		item = PyList_GetItem(p, i);
		printf("Element %ld: ", i);

		if (PyBytes_Check(item))
		{
			printf("bytes\n");
			print_python_bytes(item);
		}
		else
		{
			printf("%s\n", Py_TYPE(item)->tp_name);
		}
	}
}
