igiven a 1TB file of serialized 4 byte integers, and 2GB of ram, sort the integers into a resulting 1TB file

sol-1

 Load data into memory 2GB at a time; sort the data and save the result to file system. We will end of with 500 sorted files.
- Merge the 500 sorted files into one file. Maintain a pointer of current position for each file and find the minimum numbers acorss the 500 files; move pointer for the file that contains minimum number. May use heap to help the task

sol-2

We have 2^31 (2GB) RAM and in the worst case there could be only one integer repeated 256 billion times. For this, we will need 64bit integer (8 bytes) to store the count. This will reduce the size of our array to 2^28 indices. We could divide the 4 billion integers into 16 ranges, each covering 2^28 integers.

In the first pass over the file, we will consider the integers between 1-256m (2^28) to fill the array. Increment the count of the index whenever it is hit. At the end of the pass, pass through the array and for all non-zero valued array indices write down the index count number of times.

Now, do the second pass over the file, consider integers between 256m-512m. Do the same as above.
Third pass 512m-768m, so on until we cover up to 4billion integers. Total of 16 passes thru the file.

At the end of it, we have a sorted file.
