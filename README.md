# Embedded C Development Framework

Development Framework For Embedded C Firmware Projects


# Framework Hierarchy

The proposed embedded C Firmware development framework, is separated into two main regions, MCU Project is responsible for all Hardware-specific implementations, while Core Library (blue region) contains all systems implementations in a generic form. The main idea of this structure is to provide complete separation between hardware and system, allowing the reuse of Core Library in virtually any other MCU that supports the required features required by its specifications.

![hierarchy](images/hierarchy.png)

Besides portability, the framework provides organizational procedures to improve how firmware code is maintained. 


Embedded projects are, usually, implemented according to how a certain MCU and its peripherals work, which may introduce a great number of problems regarding portability and reuse aspects. Many embedded applications are conceived in the edge of available MCU resources, making this strategy the most efficient for that matter. However, a considerable slice of modern embedded projects to not exist in those limits, allowing their implementations to spent a little more resources in favor of other benefits.

MCU Project provides a region where all MCU-specific implementations can be freely developed without interacting with any system code. Besides that, developers will be oriented to implement standardize functions, provided by Core Library, that will act as a medium between the two framework regions.

<!-- The CORE region was designed to be fully HW decoupled and portable to any MCU in the specification domain. Also, this allows CORE to be run by the developers computer or continuous development applications, without any HW. As a result, the development time gets reduced since time consuming processes can be avoided. Also, FW developers are able to use sophisticated tools that could only be used by software developers. Finally, the whole system can be tested through unit testing without any HW emulation. -->


## Framework Elements Naming Conventions

TODO: Document

<!-- Modules -->
<!-- Components -->

<!-- The components layer is designed to allow code modulariza- tion and reuse. The main propose of components is to separate and specialize code implementation into small components that can be easily understood. Components are separated into two types:
a) External Components: are implementations that can be reused by multiple projects. They can be seen as inde- pendent modules that can be imported to the project. These components must be self contained and independent of other project specific components.
b) Project Components: are specific for the FW under development . They are not required to be reusable and may depend on other components. This flexibility is intended to reduce the development overhead for elements that should only exist for a single project. At the same time, these components should still be designed as a modular parts of the system. As a result, these components create an abstraction level between generic and system specific behaviours. Finally, Project Components are the only components that can, directly, import interfaces from layer 1.
Besides types, components are separated into three cat- egories. Each category is responsible for different type of modularization and have different design paths. -->

## Layer Documentations

- [Drivers and HALs](modules/layer%200/doc_layer_0.md)
- [Interfaces](modules/layer%201/doc_layer_1.md)
- [Devices](modules/layer%202/devices/doc_layer_2_devices.md)
- [Classes](modules/layer%202/classes/doc_layer_2_classes.md)
- [Libraries](modules/layer%202/libraries/doc_layer_2_libraries.md)
- [Application](modules/layer%203/doc_layer_3.md)




# MCU Project Specifications

TODO: Document
<!-- 1) MCU Project Specifications (SPECS): The framework’s PROJECT region was designed to support different MCUs. Developers may replace the current PROJECT repository by a different version created for another target MCU. To allow that, the system architect should define the required domain where his CORE should exist. The SPECS documen- tation should provide all information regarding the portability domain foreseen by this architect. In our experience, the common domain specifications are: MCU Specifications (bit depth, architecture, endianness, memory, frequency, required peripherals), compiler, peripheral configurations, operational system and third-party libraries.
These requirements are, however, not limited to this list, required or must coexist in every project. Instead, the system architect can define its domain as it sees fit. In this process, the architect may fell into trying to reduce the development complexity by restricting domain too much, or defining a wide portable domain that may result in the substantial increase of development complexity. Therefore, one must find a balance between those two edges, to provide a reasonable domain for the reality of the product under development. -->

# Novice Framework Choices (NFC)

TODO: Document
<!-- In addition, novice developers are often included into projects with few (or even none) supervision of other experienced developers. As a result, these developers may introduce problems to the system or violate the design choices made by the system architect. To address that, proposed framework ensures the standardization and accuracy for the development process. Also, it provides definitions called Novice Framework Choice (NFC), that, solely, aim to guide these developers and prevent their most common mistakes. -->

[Novice Choices Documentation](doc_novice_choices.md)

# Framework Conventions

TODO: Document

[Development Standard](doc_development_standard.md)

<!-- Another common mistake that many FW project present is the lack of development conventions. They, however, have a key importance in well organized environment and allowing the easy comprehension of the developed system. For that reason, the framework establishes a few conventions. Along with that, it is advised that the system architect defines his own conventions.
1) Module Prefixes: The framework recommends the prefix convention provided on table I. Other modules not listed in this table are not required to have prefixes. The prefixes should be used in module files and every public functions. Also, the framework advises their use by other code elements (typedefs and macros for example). The use of prefixes allows that developers easily locate and understand dependencies of the code they are working on, while also providing a better project organization.
2) Module Files: The framework defines that the modules can only be imported by their respective public headers. This allows developers to safely implement the their modules without an extensive documentation overhead of what should or not be used outside a module. Besides that, a set of standard files (Table II) are defined to provide a better module organization. This was made as a NFC to allow developers to get use to OOP access modifier. Finally, the public types header was added as another NFC as a simple solution to major recursive inclusion problems. With it, typedefs are separated from prototype functions, allowing modules to share types without dealing with conflicts.
3) Documentation: Every module must contain a documen- tation file. Since supported by most version control systems, the framework recommends the use of readme.md files writ- ten in markdown. On it, developers should provide essential information regarding module specifications, design choices, how-to-use tutorial, examples, reference links and files, state- flow diagrams and any other relevant information. Architects should also define an in-code documentation standard.
G. Final Considerations
The complete framework description would be to extensive for a single paper, therefore, only its main key features were described in this article. Besides that, the framework is under constant development. Readers can access the current framework state and the complete documentation on the pub- lic framework repository https://github.com/mauriciofarina/ Embedded-C-Development-Framework. -->