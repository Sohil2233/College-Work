# Name : aditya jadhav 
# Roll no: 2055
# class : sy
# batch:s3
# Demonstrate the following functions/methods which operates on sets in Python with
# suitable examples:
# i) add( ) ii) update( ) iii) copy( ) iv) pop( )
# v) remove( ) vi)discard( ) vii) clear( ) viii) union()
# ix) intersection( ) x) difference( )
set={1,2,3}
print(set)
set.add(4)
print(set)
set.update([8,9])
print(set)
copy=set.copy()
print(copy)
set.pop()
print(set)
set.remove(9)
print(set)
set.discard(8)
print(set)
set.discard(10)#no error
print(set)
print(set.clear())
s1={1,2,3}
s2={3,4,5}
union1=s1.union(s2)
print(union1)
inter=s1.intersection(s2)
print(inter)
diff=s1.difference(s2)
print(diff)
