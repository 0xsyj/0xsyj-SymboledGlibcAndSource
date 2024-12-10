## download
通过网盘分享的文件：glibc.tar.gz
链接: https://pan.baidu.com/s/1P3WSpzEUP9D9ewERT6qkkA 提取码: nvgc
## install
压缩包移动到根目录下，然后：

```
tar -xzvf glibc.tar.gz
```

执行完后根目录会出现一个glibc目录

## supported glibc
均是https://ftp.gnu.org/gnu/glibc/上下的libc然后编译的.

```
root@b66dc9ad3851:/glibc# ls -l
drwxr-xr-x  1 root root 4096 Oct 23  2023 2.19
drwxr-xr-x  1 root root 4096 Oct 23  2023 2.23
drwxr-xr-x  1 root root 4096 Oct 23  2023 2.24
drwxr-xr-x  1 root root 4096 Oct 23  2023 2.27
drwxr-xr-x  1 root root 4096 Oct 23  2023 2.28
drwxr-xr-x  1 root root 4096 Oct 23  2023 2.29
drwxr-xr-x  1 root root 4096 Oct 23  2023 2.30
drwxr-xr-x  4 root root 4096 Dec 10 17:38 2.31
drwxr-xr-x  1 root root 4096 Oct 23  2023 2.33
drwxr-xr-x  1 root root 4096 Oct 23  2023 2.34
drwxr-xr-x  1 root root 4096 Oct 23  2023 2.35
drwxr-xr-x  1 root root 4096 Oct 23  2023 2.36
drwxr-xr-x  4 root root 4096 Dec 10 18:20 2.37
drwxr-xr-x  4 root root 4096 Dec 10 18:03 2.38
drwxr-xr-x 16 root root 4096 Dec 10 18:11 src
```

## test example

```
#include <stdio.h>
#include <stdlib.h>

int main(){
    char* s = (char*)malloc(256);
    scanf("%s", s);
    printf("Hello, %s!\n", s);
}
```

## how to use
要用哪个版本的libc就这样强制改ld和libc:
```

patchelf --set-interpreter /glibc/2.27/64/lib/ld-2.27.so ./test

patchelf --replace-needed libc.so.6 /glibc/2.27/64/lib/libc-2.27.so ./test
```
如果发现改了后调试到malloc内部依然无源码, 就这样在程序同目录下创建一个文件夹符号链接:
```
ln -s /glibc/src/glibc-2.27 glibc-2.27
```