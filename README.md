# Simulation-of-viral-propagation
A simple visualization of the COVID-19 transmission.
对COVID-19的传播做简单的模拟，传播可视化和对一些指标进行统计。
上传了一个两分钟的视频展示大致结果:https://www.bilibili.com/video/BV14f4y1677p/

更加详细的介绍会在PPT中展示。

以下是运行的截图

![image](https://github.com/hzypro/Simulation-of-viral-propagation/blob/main/%E6%8D%95%E8%8E%B7.PNG)

运行需要使用c/c++EasyX图形库，下载地址：https://easyx.cn/

大致思路：

PartA:人群及其行动模式模型
  为降低工作量的同时保留一些核心特性：
  1，将城市/地区简单的分作高密度地区和低密度地区；
  2，让人群简单的按周期在两个地区间流动（一天为一个周期）；
  3，根据参考数据[1][2]，对人群按年龄进行简单的划分。对不同年龄阶段，要对其感染风险进行修正；
  4，人群的行动模式受防疫政策影响（可能被隔离）。
  粒子的坐标p[i].x,p[i].y受上述说明影响。

PartB：病毒传播模型
  采用了类似元胞自动机的思路：
  1.粒子i的感染风险受其已感染“近邻”的影响，反应在现实中可以理解为“密切接触”；
  2.粒子i的感染风险与已感染“近邻”的数量相关，使用Sigmoid函数来反应这种关系；
  3.粒子i的感染风险受防疫政策的影响；
  变量rate：综合感染率受上述说明影响。
  粒子是否感染受上述说明影响。

PartC：防疫政策模型
  目前仅设立了两种防疫政策：
  1.是否佩戴口罩，若佩戴口罩，可以降低感染概率；
  2.是否进行隔离政策，隔离政策是否严格；
  PartB中的要点3受上述说明影响。
  PartA中的要点4受上述说明影响。
  
 PartD：可视化
  使用C++图形库EasyX：
  1.对PartA中所述的场景和人群进行可视化；
  2.对关键指标R0，感染人数进行可视化。

参考了
[1]美国人口普查局2018年人口普查数据 http://www.census.gov
[2]美国疾病控制和预防中心CDC新冠肺炎数据 https://covid.cdc.gov/covid-data-tracker


