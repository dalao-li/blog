<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-03-14 17:13:30
 * @LastEditors: DaLao
 * @LastEditTime: 2021-03-27 23:49:07
-->

| 名称        | 解释                                                                                        |
| ----------- | ------------------------------------------------------------------------------------------- |
| ceph-deploy | 集群部署节点，负责集群整体部署，也可以复用cpeh集群中的节点作为部署节点                      |
| mon         | 监视管理节点(monitor)，承担集群重要的管理任务，一般需要3或5个节点                           |
| mgr         | 集群管理节点(manager)，为外界提供统一的入口                                                 |
| rgw         | 对象网关服务，使客户端能够利用标准对象存储API来访问Ceph集群                                 |
| mds         | 元数据服务器(MetaData Server)，，主要保存的文件系统服务的元数据，使用文件存储时才需要该组件 |
| osd         | 存储节点(Object Storage Daemon)，实际负责数据存储的节点                                     |
                                                                                                                                                           
Ceph 存储集群的部署都始于部署一个个 Ceph 节点、网络和 Ceph 存储集群. 

Ceph 存储集群至少需要一个 Ceph Monitor 和两个 OSD 守护进程.  

运行 Ceph 文件系统客户端时，则必须要有元数据服务器(Metadata Server).

## Monitors

Monitor(ceph-mon)维护集群状态的映射，包括监视器映射，管理器映射，OSD映射，MDS映射和CRUSH映射，这些映射是Ceph守护程序相互协调所需的关键群集状态.  

监视器还负责管理守护程序和客户端之间的身份验证.

实现冗余和高可用性通常至少需三个监视器.

## Managers

Manager守护进程(ceph-mgr)负责跟踪运行时指标和Ceph集群的当前状态，包括存储利用率、当前性能指标和系统负载.  

Manager守护程序还托管基于python的模块，以管理和公开Ceph集群信息，包括基于Web的Ceph仪表板和REST API.

实现高可用性通常至少需要两个管理器.

##  OSD

OSD(对象存储守护程序，ceph-osd)存储数据，处理数据复制，恢复，重新平衡，并通过检查其他Ceph OSD守护程序的心跳来向Ceph监视器和管理器提供一些监视信息.

实现冗余和高可用性通常至少需要三个Ceph OSD.

## MDS

元数据服务器(MDS，ceph-mds)代表Ceph文件系统存储元数据(即Ceph块设备和Ceph对象存储不使用MDS).Ceph的元数据服务器允许POSIX文件系统的用户来执行基本的命令(如ls，find没有放置在一个Ceph存储集群的巨大负担，等等).

Ceph将数据作为对象存储在逻辑存储池中.使用CRUSH算法，Ceph计算哪个放置组应包含该对象，并进一步计算哪个Ceph OSD守护程序应存储该放置组.CRUSH算法使Ceph存储集群能够动态扩展，重新平衡和恢复.