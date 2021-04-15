# Huffman-Encoding-Decoding
This is a C++ project (From a 2-nd year Data Structure course) to compress / decompress files, based on the algorithm of Huffman encoding and decoding.

# Test and Run

## Prepare
Please download the whole program first. You can input this script in UNIX shell command:
```bash
git clone https://github.com/AndyWangSFU/Huffman-Encoding-Decoding.git
cd Huffman-Encoding-Decoding
cd huff
```
Then, MAKE file on C++ command 
```
make
```
## Use
To compress:
```
$ ./huff -c original_file name.huff
```

To Decompress:
```
$ ./huff -d name.huff original_file
```

