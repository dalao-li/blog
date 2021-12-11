<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-03-10 13:19:22
 * @LastEditors: DaLao
 * @LastEditTime: 2021-11-14 14:19:05
-->

OpenStack是一个开源的云计算管理平台项目，由几个主要的组件组合起来完成具体工作

OpenStack支持几乎所有类型的云环境，项目目标是提供实施简单、可大规模扩展、丰富、标准统一的云计算管理平台

OpenStack通过各种互补的服务提供了基础设施即服务(IaaS)的解决方案，每个服务提供API以进行集成.

常见组件

| 组件         | 功能             |
| ------------ | ---------------- |
| Dashboard    | Web项目          |
| Keystone     | 权限管理         |
| Nova         | 管理虚拟机       |
| Nova-network | 管理网络流量和IP |
| Glance       | 镜像管理项目     |
| Cinder       | 磁盘管理         |
| Swift        | 网盘，对象       |