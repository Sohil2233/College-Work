import numpy as np
a=np.array([1,2,3])
print(a) 
b=np.array([[1,2,3,4,5],[2,0,3,0,5]])
print(b)
a.ndim
# get shape
a.shape
b.shape
# get type
a.dtype
type(a)
float_array = np.array([1.1, 2.2, 3.3, 4.4], dtype=float)

# Check properties
float_array_type = type(float_array)
float_array_axes = float_array.ndim
float_array_shape = float_array.shape
float_array_element_type = float_array.dtype
float_array = np.array([1.1, 2.2, 3.3, 4.4], dtype=float)
print( float_array.dtype)
print( type(float_array))
print( float_array.ndim)
print( float_array.shape)
zeros_array=np.zeros((3,4))
print(zeros_array)
tuple_arr=np.array(((1,2,3,4,5),(5,6,7,8,9)))
print(tuple_arr)
random_arr=np.random.random((3,4))
print(random_arr)
array_3*4 = np.arange(12).reshape(3, 4)
print(array_3*4)
array1=np.arrange(12).reshape(3,4)
array_3x4 = np.arange(12)
print(array_3x4)
array_3x4 = np.arange(12)
print(array_3x4)
print(array_3x4.reshape(3,4))
sequence_array = np.arange(0, 31, 5)
print(sequence_array)
reshape=array_3x4.reshape(3,4)
reshape=array_3x4.reshape(3,4)
flatten=reshape.flatten()
print(flatten)
complex_array = np.full((3, 3), 5 + 3j, dtype=complex)
print(complex_array)
      