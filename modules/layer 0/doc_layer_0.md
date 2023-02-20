# Layer 0 (Drivers and HALs)

TODO: Document


<!-- 2) Layer 0 - Drivers and HAL Layer: Besides portability, another framework goal is to facilitate and increase the con- tribution of novice developers. The first NFC in that direction allows developers to choose between developing drivers and Hardware Abstraction Layer (HAL) implementations from scratch or to make use of code generators or abstraction frameworks provided by vendors. Novice programmers can benefit from those tools by being excused of a deep under- standing of more complex driver implementations. In contrast, experienced programmers maintain the freedom to develop more sophisticated code.
Layer 0 is expected to contain all HW specific implementa- tions and be the only to access or reference the HW directly. To provide a medium between PROJECT and CORE, a set of interface functions are provided by layer 1 (section III-C). This functions should be implemented in layer 0 to provide an abstracted access to MCU’s resources, making CORE fully HW decoupled. For this layer, the framework only provides a single rule: layer 0 can only include headers from layer 1. -->