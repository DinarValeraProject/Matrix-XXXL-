#include <Python.h>



static PyObject *Identity_Matrix(PyObject *self, PyObject *args)
{
    PyObject* list;
    int i, j, n;
    double r;
    if (!PyArg_ParseTuple(args, "i",&n)){
        return NULL;
    }
    int **matrix = (int**)malloc(n * sizeof(int*));
    for (i = 0; i < n; i++){
	matrix[i] = (int*)malloc(n * sizeof(int));}

	for(i=0;i<n;i++){
    	for(j=0;j<n;j++)
        matrix[i][j]=0;

	}
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if (i==j)
                matrix[i][j] = 1;
            else
                matrix[i][j] = 0;}}

    PyObject *my_list = PyList_New(0);
    for (i=0; i<n; i++){
	PyObject *new_list = PyList_New(n);
	for (int j=0; j<n; j++){
	    PyObject *the_object = PyLong_FromSsize_t(matrix[i][j]);
	    PyList_SetItem(new_list, j, the_object);
	}

	PyList_Append(my_list, new_list);
    }

    return my_list;

    for (i=0;i<n;i++){
	free(matrix[i]);
    }
    free(matrix);

}


static PyObject *Plus_Matrix(PyObject *self, PyObject *args)
{
    PyObject* l1;
    PyObject* l2;
    int i, j, n;
    double r1, r2;
    if (!PyArg_ParseTuple(args, "OO",&l1,&l2)){
        return NULL;
    }
    n = PyList_GET_SIZE(l1);
    int **M1 = (int**)malloc(n * sizeof(int*));
    int **M2 = (int**)malloc(n * sizeof(int*));
    int **M3 = (int**)malloc(n * sizeof(int*));
    for (i = 0; i < n; i++){
	M1[i] = (int*)malloc(n * sizeof(int));
	M2[i] = (int*)malloc(n * sizeof(int));
	M3[i] = (int*)malloc(n * sizeof(int));}

    for (i=0; i<n; i++){
        PyObject* item1 = PySequence_Fast_GET_ITEM(l1, i);
        for (j = 0; j < n; j++){
            r1 = PyFloat_AsDouble(PySequence_Fast_GET_ITEM(item1, j));
            M1[i][j] = r1;
	}}
    for (i = 0; i < n; i++){
        PyObject* item2 = PySequence_Fast_GET_ITEM(l2, i);
    for (j = 0; j < n; j++){
            r2 = PyFloat_AsDouble(PySequence_Fast_GET_ITEM(item2, j));
        M2[i][j] = r2;
	}}

	for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        M3[i][j]=M1[i][j]+M2[i][j];
     }
     }
    PyObject *my_list = PyList_New(0);
    for (i=0; i<n; i++){
	PyObject *new_list = PyList_New(n);
	for (int j=0; j<n; j++){
	    PyObject *the_object = PyLong_FromSsize_t(M3[i][j]);
	    PyList_SetItem(new_list, j, the_object);
	}

	PyList_Append(my_list, new_list);
    }

    return my_list;

    for (i = 0; i < n;i++){
            free(M1[i]);
            free(M2[i]);
            free(M3[i]);}
    free(M1);
    free(M2);
    free(M3);

}


static PyObject *Minus_Matrix(PyObject *self, PyObject *args)
{
    PyObject* l1;
    PyObject* l2;
    int i, j, n;
    double r1, r2;
    if (!PyArg_ParseTuple(args, "OO",&l1,&l2)){
        return NULL;
    }
    n = PyList_GET_SIZE(l1);
    int **M1 = (int**)malloc(n * sizeof(int*));
    int **M2 = (int**)malloc(n * sizeof(int*));
    int **M3 = (int**)malloc(n * sizeof(int*));
    for (i = 0; i < n; i++){
	M1[i] = (int*)malloc(n * sizeof(int));
	M2[i] = (int*)malloc(n * sizeof(int));
	M3[i] = (int*)malloc(n * sizeof(int));}

    for (i=0; i<n; i++){
        PyObject* item1 = PySequence_Fast_GET_ITEM(l1, i);
        for (j = 0; j < n; j++){
            r1 = PyFloat_AsDouble(PySequence_Fast_GET_ITEM(item1, j));
            M1[i][j] = r1;
	}}
    for (i = 0; i < n; i++){
        PyObject* item2 = PySequence_Fast_GET_ITEM(l2, i);
    for (j = 0; j < n; j++){
            r2 = PyFloat_AsDouble(PySequence_Fast_GET_ITEM(item2, j));
        M2[i][j] = r2;
	}}

	for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            M3[i][j]=M1[i][j]-M2[i][j];
     }
     }
    PyObject *my_list = PyList_New(0);
    for (i=0; i<n; i++){
	PyObject *new_list = PyList_New(n);
	for (int j=0; j<n; j++){
	    PyObject *the_object = PyLong_FromSsize_t(M3[i][j]);
	    PyList_SetItem(new_list, j, the_object);
	}

	PyList_Append(my_list, new_list);
    }



    for (i = 0; i < n;i++){
            free(M1[i]);
            free(M2[i]);
            free(M3[i]);}
    free(M1);
    free(M2);
    free(M3);
    return my_list;

}



static PyObject *NComposition(PyObject *self, PyObject *args)
{
    PyObject* l1;
    int i, j, n,k;
    double r1;
    if (!PyArg_ParseTuple(args, "Oi",&l1,&k)){
        return NULL;
    }
    n = PyList_GET_SIZE(l1);
    int **M1 = (int**)malloc(n * sizeof(int*));
    int **M2 = (int**)malloc(n * sizeof(int*));
    for (i = 0; i < n; i++){
	M1[i] = (int*)malloc(n * sizeof(int));
	M2[i] = (int*)malloc(n * sizeof(int));}

    for (i=0; i<n; i++){
        PyObject* item1 = PySequence_Fast_GET_ITEM(l1, i);
        for (j = 0; j < n; j++){
            r1 = PyFloat_AsDouble(PySequence_Fast_GET_ITEM(item1, j));
            M1[i][j] = r1;
	}}

	for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            M2[i][j]=k*M1[i][j];
     }
     }
    PyObject *my_list = PyList_New(0);
    for (i=0; i<n; i++){
	PyObject *new_list = PyList_New(n);
	for (int j=0; j<n; j++){
	    PyObject *the_object = PyLong_FromSsize_t(M2[i][j]);
	    PyList_SetItem(new_list, j, the_object);
	}

	PyList_Append(my_list, new_list);
    }



    for (i = 0; i < n;i++){
            free(M1[i]);
            free(M2[i]);}
    free(M1);
    free(M2);
    return my_list;

}


static PyObject *Transpose(PyObject *self, PyObject *args)
{
    PyObject* l1;
    int i, j, n;
    double r1;
    if (!PyArg_ParseTuple(args, "O",&l1)){
        return NULL;
    }
    n = PyList_GET_SIZE(l1);
    int **M1 = (int**)malloc(n * sizeof(int*));
    int **M2 = (int**)malloc(n * sizeof(int*));
    for (i = 0; i < n; i++){
	M1[i] = (int*)malloc(n * sizeof(int));
	M2[i] = (int*)malloc(n * sizeof(int));}

    for (i=0; i<n; i++){
        PyObject* item1 = PySequence_Fast_GET_ITEM(l1, i);
        for (j = 0; j < n; j++){
            r1 = PyFloat_AsDouble(PySequence_Fast_GET_ITEM(item1, j));
            M1[i][j] = r1;
	}}

	for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            M2[j][i]=M1[i][j];
     }
     }
    PyObject *my_list = PyList_New(0);
    for (i=0; i<n; i++){
	PyObject *new_list = PyList_New(n);
	for (int j=0; j<n; j++){
	    PyObject *the_object = PyLong_FromSsize_t(M2[i][j]);
	    PyList_SetItem(new_list, j, the_object);
	}

	PyList_Append(my_list, new_list);
    }



    for (i = 0; i < n;i++){
            free(M1[i]);
            free(M2[i]);}
    free(M1);
    free(M2);
    return my_list;

}

static PyObject *Composition(PyObject *self, PyObject *args)
{
    PyObject* l1;
    PyObject* l2;
    int i, j, n, k, sum=0;
    double r1, r2;
    if (!PyArg_ParseTuple(args, "OO",&l1,&l2)){
        return NULL;
    }
    n = PyList_GET_SIZE(l1);
    int **M1 = (int**)malloc(n * sizeof(int*));
    int **M2 = (int**)malloc(n * sizeof(int*));
    int **M3 = (int**)malloc(n * sizeof(int*));
    for (i = 0; i < n; i++){
	M1[i] = (int*)malloc(n * sizeof(int));
	M2[i] = (int*)malloc(n * sizeof(int));
	M3[i] = (int*)malloc(n * sizeof(int));}

    for (i=0; i<n; i++){
        PyObject* item1 = PySequence_Fast_GET_ITEM(l1, i);
        for (j = 0; j < n; j++){
            r1 = PyFloat_AsDouble(PySequence_Fast_GET_ITEM(item1, j));
            M1[i][j] = r1;
	}}
    for (i = 0; i < n; i++){
        PyObject* item2 = PySequence_Fast_GET_ITEM(l2, i);
    for (j = 0; j < n; j++){
            r2 = PyFloat_AsDouble(PySequence_Fast_GET_ITEM(item2, j));
        M2[i][j] = r2;
	}}

	for(i=0;i<n;i++){
    	for(j=0;j<n;j++)
        M3[i][j]=0;

	}

	for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            for(k=0; k<n; k++ ){
		sum = sum + M1[i][k]*M2[k][j];}
	    M3[i][j] = sum;
	    sum = 0 ;
       	
            
     }
     }
    PyObject *my_list = PyList_New(0);
    for (i=0; i<n; i++){
	PyObject *new_list = PyList_New(n);
	for (int j=0; j<n; j++){
	    PyObject *the_object = PyLong_FromSsize_t(M3[i][j]);
	    PyList_SetItem(new_list, j, the_object);
	}

	PyList_Append(my_list, new_list);
    }


    for (i = 0; i < n;i++){
            free(M1[i]);
            free(M2[i]);
            free(M3[i]);}
    free(M1);
    free(M2);
    free(M3);

    return my_list;
}

static PyObject *Random_Matrix(PyObject *self, PyObject *args)
{
    int i,j,n,minn,maxx;
    double r;

    if (!PyArg_ParseTuple(args, "iii", &n,&minn,&maxx)){
        return NULL;
    }

    int **matrix = (int**)malloc(n * sizeof(int*));
    for (i = 0; i < n; i++){
	matrix[i] = (int*)malloc(n * sizeof(int));}

	for(i=0;i<n;i++){
    	for(j=0;j<n;j++)
        matrix[i][j]=0;

	}

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            matrix[i][j] = minn + rand()%maxx;}}


    PyObject *my_list = PyList_New(0);
    for (i=0; i<n; i++){
	PyObject *new_list = PyList_New(n);
	for (int j=0; j<n; j++){
	    PyObject *the_object = PyLong_FromSsize_t(matrix[i][j]);
	    PyList_SetItem(new_list, j, the_object);
	}

	PyList_Append(my_list, new_list);
    }



    for (i=0;i<n;i++){
	free(matrix[i]);
    }
    free(matrix);
    return my_list;

}


static PyObject *Random_Symetrical_Matrix(PyObject *self, PyObject *args)
{
    int i,j,n,minn,maxx,num;
    double r;

    if (!PyArg_ParseTuple(args, "iii", &n,&minn,&maxx)){
        return NULL;
    }

    int **matrix = (int**)malloc(n * sizeof(int*));
    for (i = 0; i < n; i++){
	matrix[i] = (int*)malloc(n * sizeof(int));}

	for(i=0;i<n;i++){
    	for(j=0;j<n;j++)
        matrix[i][j]=0;

	}

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            num = minn + rand()%maxx;
            matrix[i][j] = num;
            matrix[j][i] = num;}}



    PyObject *my_list = PyList_New(0);
    for (i=0; i<n; i++){
	PyObject *new_list = PyList_New(n);
	for (int j=0; j<n; j++){
	    PyObject *the_object = PyLong_FromSsize_t(matrix[i][j]);
	    PyList_SetItem(new_list, j, the_object);
	}

	PyList_Append(my_list, new_list);
    }



    for (i=0;i<n;i++){
	free(matrix[i]);
    }
    free(matrix);
    return my_list;

}




static PyMethodDef ownmod_methods[] = {
    {
    "Identity_Matrix",
    Identity_Matrix,
    METH_VARARGS,
    "Identity_Matrix"
    },
    {
    "Plus_Matrix",
    Plus_Matrix,
    METH_VARARGS,
    "Plus_Matrix"
    },
    {
    "Minus_Matrix",
    Minus_Matrix,
    METH_VARARGS,
    "Minus_Matrix"
    },
    {
    "Composition",
    Composition,
    METH_VARARGS,
    "Composition"
    },
    {
    "NComposition",
    NComposition,
    METH_VARARGS,
    "NComposition"
    },
    {
    "Transpose",
    Transpose,
    METH_VARARGS,
    "Transpose"
    },
    {
    "Random_Matrix",
    Random_Matrix,
    METH_VARARGS,
    "Random_Matrix"
    },
    {
    "Random_Symetrical_Matrix",
    Random_Symetrical_Matrix,
    METH_VARARGS,
    "Random_Symetrical_Matrix"
    },
    { NULL, NULL, 0, NULL }
};
static PyModuleDef simple_module = {
    PyModuleDef_HEAD_INIT,
    "XXX",
    "XXX multiplication documentation",
    -1,
    ownmod_methods, // methods are here
    NULL,NULL,NULL
};

PyMODINIT_FUNC PyInit_XXX(void)
{
    PyObject* m;
    m = PyModule_Create(&simple_module);
    if (m == NULL)
        return NULL;

    return m;}
