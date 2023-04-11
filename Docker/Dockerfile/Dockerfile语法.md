<!--

 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao@xxx.com
 * @Date: 2021-03-17 17:13:31
 * @LastEditors: Li Yuanhao
 * @LastEditTime: 2023-04-09 00:28:30
-->


# Dockerfile



## RUN

执行指令

```sh
RUN [指令]
```


## COPY

拷贝文件

```sh
COPY [源路径] [目标路径]
```

`COPY` 将从构建上下文目录中的源路径的文件/目录复制到新的一层的镜像内的目标路径/位置


## ADD

复制文件

```sh
ADD [源路径] [目标路径]
```

若源路径为tar压缩文件且压缩格式为 gzip, bzip2, xz, ADD 指令将会自动解压缩文件到目标路径


## CMD

### shell格式

```sh
CMD [命令]
```

- 执行Python指令

```sh
CMD python3 manage.py runserver 0.0.0.0:8000
```

### exec格式

```sh
CMD ["可执行文件", "参数1", "参数2", ...
```

- 执行Python指令

```sh
CMD ["python3", "manage.py", "runserver 0.0.0.0: 8000"]
```

### 区别

`CMD` 在`docker run`时运行, Dockerfile中只能在末尾有**一条**CMD指令

`RUN` 在 `docker build`时运行, 可出现若干次