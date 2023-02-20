# Layer 2 (Classes)

TODO: Document


<!-- 2) Classes: One great advantage of modern programming languages is the build-in support to OOP. Unfortunately, C is a procedural language that does not include these features. Thankfully, it is possible to replicate some of the core features of OOP in C by following a design guideline called OOC[8]. OOC classes inherit the following OOP features: Encapsula- tion, Inheritance, Interface and Polymorphism. Also, they can be presented into two forms:
a) Interface Classes: are responsible for enforcing a required signature to methods of classes that implement it.
b) Classes: are any other type of class. They may inherit interface class or other classes to provide specialized behavior. Every class should provide an initialization (input argument) and instance (output argument) structures that are used by the class constructor method. If another class is inherited, both these structures must contain the respective parent structures, named as super, as their initial elements. It is of extremely importance that the inherited class structures be the first element of the child to provide subtyping behaviour. Finally,
only single inheritance is allowed.
Project classes can be bare-metal or Real-Time Operational
System (RTOS), while, external classes should always be bare- metal. If external classes required RTOS functionalities, they should be provided in an abstracted format as arguments of the initialization structure. As a NFC, classes should only contain private elements. Therefore, only the class itself can access variables from the instance handler directly. Any other external access should, always, be done by getter and setter methods. -->