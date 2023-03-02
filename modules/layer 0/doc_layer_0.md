# Layer 0 (Drivers and HALs)

Besides portability, another framework goal is to facilitate and increase the contribution of novice developers. To do that, the framework allows developers to choose between developing drivers and Hardware Abstraction Layer (HAL) implementations from scratch or to make use of code generators or abstraction frameworks provided by vendors. Novice programmers can benefit from those tools by being excused of a deep understanding of more complex driver implementations. In contrast, experienced programmers maintain the freedom to develop more sophisticated code.

Layer 0 is expected to contain all Hardware-specific implementations and be the only to access or reference the Hardware directly. 

To provide a medium between MCU Project and Core Library, a set of interface functions are provided by layer 1. This functions should be implemented in layer 0 to provide an abstracted access to MCU’s resources, making Core Library fully HW decoupled. For this layer, the framework only provides a single rule: **layer 0 can only include headers from layer 1.**

